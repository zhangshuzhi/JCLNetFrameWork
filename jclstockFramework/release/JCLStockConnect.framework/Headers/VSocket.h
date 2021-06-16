#pragma once

#import <atomic>
#import <string>
#import <unistd.h>
#import <sys/types.h>
#import <sys/socket.h>
#import <arpa/inet.h>
#import <netinet/tcp.h>
#import <netinet/in.h>
#import <sys/fcntl.h>
#import <netdb.h>
#import <signal.h>

typedef union
{
    sockaddr_storage storage_;
    sockaddr_in ipv4_;
    sockaddr_in6 ipv6_;
}SocketAddress_t;

////////////////////////////
// Socket implementation
class VSocket
{
public:
	// Constructor/Destructor
	VSocket(sa_family_t family = AF_INET, int sock = -1);
    VSocket(const VSocket&) = delete;
	VSocket(VSocket&& other);

	virtual ~VSocket();
                      
    const VSocket& operator=(const VSocket&) = delete;
	const VSocket& operator=(VSocket&& other);

	////////////////////////////
	// Socket implementation

	// Create
	//		Create a socket and attach it to this VSocket object
	bool Create();

	// Shutdown
	//		Shutdown the currently attached socket
	bool Shutdown();

	// Close
	//		Close the currently attached socket
	bool Close();

	bool GetBlock();

	bool SetBlock(bool bBlock = true);

	bool Select(int secs,int flag = SHUT_RDWR);
	// Bind
	//		Bind the attached socket to the specified port
	//		If localOnly is true then the socket is bound only
	//		to the loopback adapter.
	bool Bind(int port, const bool localOnly=false);

	// Connect
	//		Make a stream socket connection to the specified port
	//		on the named machine.
	bool Connect(const char* address, int port,int outime = 25);

	// IsConnected
	//		Test a stream socket connection is still connected to
	//		the server.
	bool IsConnected();

	// Listen
	//		Set the attached socket to listen for connections
	bool Listen();

	// Accept
	//		If the attached socket is set to listen then this
	//		call blocks waiting for an incoming connection, then
	//		returns a new socket object for the new connection
	bool Accept(VSocket& s);

	// GetPeerName
	//		If the socket is connected then this returns the name
	//		of the machine to which it is connected.
	std::string GetPeerName(int& port);

	// GetSockName
	//		If the socket exists then the name of the local machine
	//		is returned.
    std::string GetSockName(int& port);

	// SetTimeout
	//		Sets the socket timeout on reads and writes.
	bool SetTimeout(int secs);

	// SetKeepAlive
	//		Sets the socket keepalive
	bool SetKeepAlive(int nIdleTime = 30, int nInterval = 1);

	// I/O routines

	// Send and Read return the number of bytes sent or recieved.
	int Send(const char *buff, int bufflen);
	int Read(char *buff, int bufflen);

	// SendExact and ReadExact attempt to send and recieve exactly
	// the specified number of bytes.
	bool SendExact(const char *buff, int bufflen);
	bool ReadExact(char *buff, int bufflen);

    int GetFd();

	////////////////////////////
	// Internal structures
protected:
	// The internal socket family
	sa_family_t family_;
	// The internal socket id
	int sock_;

private:
	bool GetSockAddress(SocketAddress_t& addr);

	bool GetPeerAddress(SocketAddress_t& addr);

	bool ReceiveLine(char* buff, int len);

	bool SkipLength(int len);

    // Resolve
    //		Uses the Winsock API to resolve the supplied DNS name to
    //		an IP address and returns it as an Int32
	static bool Resolve(int af, const char* addr, int port, SocketAddress_t& sockaddr, int& socklen);

private:
    // Create one or more VSocketSystem objects per application
    static void Initialise();
    static void UnInitialise();
    static std::atomic_int initialised_;
};

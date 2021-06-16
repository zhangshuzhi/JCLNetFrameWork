#pragma once

#import <stdint.h>
#import <mutex>
#import <thread>
#import <vector>
#import <map>

#import "IProtocolCommunication.h"
#import "VSocket.h"
#import "QuoteStruct.h"

/**
 * @brief	服务器优选数据结构
*/
struct ServerResult : public QuoteServerInfo
{
	bool bHQ;//服务器是否可用
	uint64_t idx, level, weights;	//level=1 正常使用 level=2 跳转使用 level=3 无法连接 level=UINT64_MAX 数据源已坏
	std::thread t;

	ServerResult() : QuoteServerInfo()
	{
		bHQ = true;
		idx = level = weights = UINT64_MAX;
	}

	explicit ServerResult(const QuoteServerInfo& info) : QuoteServerInfo(info)
	{
		bHQ = true;
		idx = level = weights = UINT64_MAX;
	}

	ServerResult(const ServerResult& other) : QuoteServerInfo()
	{
		*this = other;
	}

	bool operator < (const ServerResult& other) const
	{
		if (level == other.level) return weights < other.weights;
		return level < other.level;
	}

	const ServerResult& operator = (const ServerResult& other)
	{
		reinterpret_cast<QuoteServerInfo&>(*this) = other;
		bHQ = other.bHQ;
		idx = other.idx;
		level = other.level;
		weights = other.weights;
		return *this;
	}
};

/**
 * @brief	金策略行情后台通讯接口实现类
*/
@interface DjrjCommunication : NSObject<ProtocolCommunication>
	/**
	 * @brief	查询行情后台服务监控信息接口
	 * @param	ip			行情后台服务IP
	 * @param	port		行情后台服务端口
	 * @return	是否查询成功
	*/
	+ (monitorinfo_ans*) HOST_MONITOR_INFO:(const char*)ip Port:(int) port;

	/**
	 * @brief	依据响应速度和后台负载优选行情服务器，会将服务器从优到差依次排列
	 * @param	servers		待优选的服务器列表
	 * @param	second		等待优选结果的时间
	*/
	+ (void) sortBestServer:(std::vector<ServerResult>&) servers waitForSeconds:(int)second;

    @property (atomic) int source_type;
    @property (retain) NSObject<ProtocolHandler>* handler;
	@property std::vector<ServerResult> servers;
    @property (atomic) bool stop;
    @property (retain) NSThread* recvThread;
    @property (atomic) VSocket* socket;
    @property (atomic) bool connected;

    @property (retain) NSTimer* resubTimer;
    @property int subscrubeNum;
    @property (retain) NSRecursiveLock* subscribeLock;
    @property std::map<uint64_t, int> subscribed, needSubscribe;	//订阅的推送行情
@end

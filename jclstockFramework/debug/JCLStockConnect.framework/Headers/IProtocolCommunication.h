#pragma once

#import "QuoteStruct.h"
#import "Jclprotocol.pbobjc.h"

@protocol ProtocolCommunication;
/**
 * @brief	行情通讯接口回调接口类
*/
@protocol ProtocolHandler <NSObject>
	/**
	 * @brief	当行情通讯接口连接建立成功后回调该函数
	 * @param	comm		行情通讯接口对象
	*/
	- (void) onConnected:(NSObject<ProtocolCommunication>*) comm;

	/**
	 * @brief	当行情通讯接口连接断开后回调该函数
	 * @param	comm		行情通讯接口对象
	 * @param	reason		行情连接断开原因
	*/
	- (void) onDisconnected:(NSObject<ProtocolCommunication>*) comm reasonString:(NSString*) reason;

	/**
	 * @brief	当行情通讯接口需要退化时回调该函数
	 * @param	comm		发生退化的行情通讯接口对象
	*/
	- (void) onConnectionDegeneration:(NSObject<ProtocolCommunication>*) comm;

	/**
	 * @brief	当行情通讯接口发生错误时回调该函数，若行情接口不能从错误中恢复会自动断开连接 @see onDisconnected
	 * @param	comm		行情通讯接口对象
	 * @param	errormsg	错误描述信息
	*/
	- (void) onError:(NSObject<ProtocolCommunication>*)comm errorString:(NSString*) errormsg;

	/**
	 * @brief	当行情通讯接口收到行情数据时回调该函数
	 * @param	comm		行情通讯接口对象
	 * @param	package		行情数据包
	*/
	- (void) handleData:(NSObject<ProtocolCommunication>*)comm AnswerHead:(const tagAnsHeader*)head Package:(report_package*)package;
@end

/**
 * @brief	行情通讯接口抽象基类
*/
@protocol ProtocolCommunication <NSObject>
    /**
     * @brief    构造函数
     * @param    source_type    数据源类型
     * @param    handler        回调接口对象
     * @param    servers        后台服务器列表
    */
    - (instancetype) initWithType:(int) source_type DataHandler:(NSObject<ProtocolHandler>*)handler ServerAddresses:(std::vector<QuoteServerInfo>)servers;
	/**
	 * @brief	连接状态
	 * @return	是否连接
	*/
	- (bool) isConnected;
	/**
	* @brief	推送服务连接状态
	* @return	是否连接
	*/
	- (bool) isPushConnected;
	/**
	 * @brief	行情推送订阅接口
	 * @param	stocks		待订阅的行情品种
	 * @return	是否订阅成功
	*/
	- (bool) pushSubscribe:(NSArray<tagCodeWithNkey*>*) stocks;
	/**
	 * @brief	行情推送取消订阅接口
	 * @param	stocks		待取消订阅的行情品种
	 * @return	是否取消订阅成功
	*/
	- (bool) pushUnSubscribe:(NSArray<tagCodeWithNkey*>*) stocks;
	/**
	 * @brief	行情推送取消订阅所有品种接口
	 * @return	是否取消订阅成功
	*/
	- (bool) pushUnSubscribeAll;

	/**
	 * @brief	行情数据请求发送函数，行情通讯接口管理类已做排队逻辑
	 * @param	request		行情数据请求包
	 * @return	是否发送成功
	*/
	- (bool) sendRequest:(NSData*) request;

	/**
	 * @brief	行情通讯接口连接信息
	 * @return	连接信息
	*/
	- (QuoteServerInfo) serverInfo;

	/**
	 * @brief	行情通讯接口数据源类型
	 * @return	返回数据源类型
	*/
    - (int) sourceType;
@end


#pragma once

#import "IProtocolCommunication.h"
#import "QuoteRequest.h"

@protocol QuoteCommunicateObserver <NSObject>

@optional
- (void) connected;
- (void) disconnected:(NSString* _Nonnull) reason;
- (void) complete:(bool) success;
- (void) marketComplete;
- (void) sourceTypeChanged:(int) type;
- (void) pushServerStateUpdate;
- (void) initializeProgress:(NSString* _Nonnull) describe andTotal:(int) total andStep:(int) step;
- (void) quoteChanged:(NSArray<CurrStockDataBEx*>* _Nonnull) data;
- (void) tickChanged:(NSArray<TickInfo*>* _Nonnull) data;
- (void) authorized:(bool) success withReason:(NSString* _Nonnull) reason;
@end

@interface QuoteComm : NSObject<ProtocolHandler>

@property (class,readonly,nullable) QuoteComm* shared;

@property (nonnull) class QuoteCommData* data;

- (nullable instancetype) init;
- (void) dealloc;
//通知
- (void) InstallObserver:(NSObject<QuoteCommunicateObserver>* _Nonnull) ob;
- (void) RemoveObserver:(NSObject<QuoteCommunicateObserver>* _Nonnull) ob;
//连接
- (bool) Connect:(std::vector<QuoteServerInfo>) servers sourceType:(int) request_type;
- (bool) Disconnect;
- (bool) IsConnected;
- (bool) IsPushConnected;
- (bool) IsInitialized;
- (QuoteServerInfo) GetConnectionInfo;
// 从推送服务器订阅: 股票池，大数据，自选股
- (bool) PushSubscribe:(NSArray<tagCodeWithNkey*>* _Nonnull)stocks;
- (bool) PushSubscribeOne:(tagCodeWithNkey* _Nonnull)stock;
- (bool) PushUnSubscribe:(NSArray<tagCodeWithNkey*>* _Nonnull)stocks;
- (bool) PushUnSubscribeOne:(tagCodeWithNkey* _Nonnull)stock;
//请求接口
- (bool) SendRequest:(QuoteRequest* _Nullable) request;
- (bool) SendRequest2:(GPBMessage * _Nullable) request andReqNo:(int) reqno response:(void(^_Nullable)(QuoteRequest* _Nonnull)) rsp;
//数据获取接口
- (bool) IsMarketOpend:(short) setcode;
- (int) GetMarketOpenDate:(short) setcode;
- (short) GetMinuteByMarket:(tagCodeWithNkey* _Nonnull)code Period:(Period)period Index:(short) idx;
- (short) GetStandMinute:(tagCodeWithNkey* _Nonnull)code Time:(short) minute;
- (short) GetMinuteIdxByMarket:(tagCodeWithNkey* _Nonnull)code :(Period) period :(short) minute;
- (NSRange) GetMinuteSelection:(tagCodeWithNkey* _Nonnull)code Time:(short)minute;
- (short) GetMinuteCountByMarket:(tagCodeWithNkey* _Nonnull)code Period:(Period)period;
- (bool) GetMarketOpenClose:(short) setcode returned:(short* _Nonnull)fz;
- (bool) GetStockOpenClose:(tagCodeWithNkey* _Nonnull)code returned:(short* _Nonnull)fz;
- (int64_t) GetServerTime;
- (int) GetServerDate;
- (int) QuoteType;
- (int) GetStockNum:(short)setcode;
- (StkInfoNew* _Nullable) GetStockCode:(tagCodeWithNkey* _Nonnull)code;
- (short) GetPrecise:(tagCodeWithNkey* _Nonnull)code;
//- (StkInfoNew* _Nullable) GetStockInfoNkey:(uint64_t) nkey;
- (uint64_t) GetNKey:(short)setcode StockCode:(const char* _Nonnull)code;
- (tagCodeWithNkey* _Nullable) GetStock:(uint64_t)nkey;
- (StockCodeType) GetStockType:(uint64_t)nkey;
- (bool) testzs:(uint64_t) nkey;
- (tagCodeWithNkey* _Nullable) GetStock:(short)setcode Code:(const char* _Nonnull)code;
- (NSArray<tagCodeWithNkey*>* _Nonnull) GetAllStockCode;
- (NSArray<tagCodeWithNkey*>* _Nullable) FilterStockCode:(short)setcode;
- (NSArray<tagCodeWithNkey*>* _Nullable) FilterStockCodeByType:(const StockCodeType&)type;
- (NSArray<tagCodeWithNkey*>* _Nullable) FilterStockCodeByStock:(tagCodeWithNkey* _Nonnull)code;
- (NSArray<tagCodeWithNkey*>* _Nullable) FilterStockCodeByString:(NSString* _Nonnull)code;
- (NSArray<StkInfoNew*>* _Nullable) MatchStockCode:(NSString* _Nonnull)text Type:(const StockCodeType&)type;
- (tagCodeWithNkey* _Nullable) FilterOneStockCode:(NSString* _Nonnull)code;
- (BaseCWInfo* _Nullable) GetBaseInfo:(tagCodeWithNkey* _Nonnull)code;
- (NSArray<CqcxCWInfo*>* _Nullable) GetGpCwData:(tagCodeWithNkey* _Nonnull)code;
- (CurrStockDataBEx* _Nullable) GetCurrStockDataEx:(tagCodeWithNkey* _Nonnull)code;
- (void) SaveCurrStockDataEx:(CurrStockDataBEx* _Nonnull)data;
- (NSArray<MinuteInfo*>* _Nullable) GetMinuteData:(tagCodeWithNkey* _Nonnull)code;
- (CDPInfo* _Nullable) GetCDP:(tagCodeWithNkey* _Nonnull)code;
- (NSObject<ProtocolCommunication>* _Nullable) GetDefaultCommunication:(int)source_type;
- (void) PushHQ:(NSArray<CurrStockDataBEx*>* _Nonnull)vecHQ;
@end


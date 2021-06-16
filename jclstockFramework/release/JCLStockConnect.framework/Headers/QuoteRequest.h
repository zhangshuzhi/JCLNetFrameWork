#pragma once

#import <atomic>
#import <mutex>
#import <vector>

#import "QuoteStruct.h"
#import "Jclprotocol.pbobjc.h"

@class QuoteRequest;
@class QuoteComm;

@interface QuoteRequest : NSObject
@property (readonly) int source_type;
@property (readonly,atomic) int reqno;
@property (readonly,atomic) bool can_response;
@property (readwrite,atomic,nullable) void(^notify)(QuoteRequest* _Nonnull);
@property (readonly,nullable) NSMutableArray<NSData*>* requests;
@property (readonly,nullable) NSMutableArray<report_package*>* answers;

- (instancetype _Nullable) initWithType:(int) type;
- (void) dealloc;
- (void) addRequest: (report_package* _Nonnull)request;
- (report_package* _Nullable) request:(int)index;
- (void) setAnswer:(const tagAnsHeader* _Nonnull)head Package:(report_package* _Nonnull)package;
- (report_package* _Nullable) answer:(int)index;
- (bool) sendIt;
@end

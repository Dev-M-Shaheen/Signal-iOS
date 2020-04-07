//
//  Copyright (c) 2020 Open Whisper Systems. All rights reserved.
//

#import "BaseModel.h"

NS_ASSUME_NONNULL_BEGIN

@class OWSStorage;
@class SDSAnyReadTransaction;
@class SDSAnyWriteTransaction;
@class SSKProtoEnvelope;

extern NSNotificationName const kNSNotificationNameMessageDecryptionDidFlushQueue;

@interface OWSMessageDecryptJob : BaseModel

@property (nonatomic, readonly) NSDate *createdAt;
@property (nonatomic, readonly) NSData *envelopeData;
@property (nonatomic, readonly, nullable) SSKProtoEnvelope *envelopeProto;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithUniqueId:(NSString *)uniqueId NS_UNAVAILABLE;

- (instancetype)initWithEnvelopeData:(NSData *)envelopeData NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)coder NS_DESIGNATED_INITIALIZER;

// --- CODE GENERATION MARKER

// This snippet is generated by /Scripts/sds_codegen/sds_generate.py. Do not manually edit it, instead run `sds_codegen.sh`.

// clang-format off

- (instancetype)initWithGrdbId:(int64_t)grdbId
                      uniqueId:(NSString *)uniqueId
                       createdAt:(NSDate *)createdAt
                    envelopeData:(NSData *)envelopeData
NS_DESIGNATED_INITIALIZER NS_SWIFT_NAME(init(grdbId:uniqueId:createdAt:envelopeData:));

// clang-format on

// --- CODE GENERATION MARKER

@end

#pragma mark -

@interface OWSMessageDecryptJobFinder : NSObject

- (NSString *)databaseExtensionName;
- (NSString *)databaseExtensionGroup;

- (NSUInteger)queuedJobCountWithTransaction:(SDSAnyReadTransaction *)transaction;

#ifdef DEBUG
- (void)addJobForEnvelopeData:(NSData *)envelopeData transaction:(SDSAnyWriteTransaction *)transaction;
#endif

@end

#pragma mark -

// This class is used to write incoming (encrypted, unprocessed)
// messages to a durable queue and then decrypt them in the order
// in which they were received.  Successfully decrypted messages
// are forwarded to OWSBatchMessageProcessor.
@interface OWSMessageReceiver : NSObject

- (instancetype)init NS_DESIGNATED_INITIALIZER;

+ (NSString *)databaseExtensionName;
+ (void)asyncRegisterDatabaseExtension:(OWSStorage *)storage;

- (void)handleReceivedEnvelopeData:(NSData *)envelopeData;

- (BOOL)hasPendingJobsWithTransaction:(SDSAnyReadTransaction *)transaction;

@end

NS_ASSUME_NONNULL_END

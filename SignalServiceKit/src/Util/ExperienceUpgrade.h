//
//  Copyright (c) 2020 Open Whisper Systems. All rights reserved.
//

#import <SignalServiceKit/BaseModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface ExperienceUpgrade : BaseModel

@property (nonatomic) NSTimeInterval firstViewedTimestamp;
@property (nonatomic) NSTimeInterval lastSnoozedTimestamp;
@property (nonatomic) BOOL isComplete;

// --- CODE GENERATION MARKER

// This snippet is generated by /Scripts/sds_codegen/sds_generate.py. Do not manually edit it, instead run
// `sds_codegen.sh`.

// clang-format off

- (instancetype)initWithGrdbId:(int64_t)grdbId
                      uniqueId:(NSString *)uniqueId
            firstViewedTimestamp:(double)firstViewedTimestamp
                      isComplete:(BOOL)isComplete
            lastSnoozedTimestamp:(double)lastSnoozedTimestamp
NS_DESIGNATED_INITIALIZER NS_SWIFT_NAME(init(grdbId:uniqueId:firstViewedTimestamp:isComplete:lastSnoozedTimestamp:));

// clang-format on

// --- CODE GENERATION MARKER

@end

NS_ASSUME_NONNULL_END

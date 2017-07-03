// Copyright 2016 Google Inc.

#import <GoogleCast/GCKDefines.h>

#import <Foundation/Foundation.h>

GCK_ASSUME_NONNULL_BEGIN

/**
 * A class representing the ad break status.
 *
 * @since 3.3
 */
GCK_EXPORT
@interface GCKAdBreakStatus : NSObject <NSCopying>

/** The current time within the current ad break. */
@property(nonatomic, assign, readonly) NSTimeInterval currentAdBreakTime;

/** The current time within the current ad clip break. */
@property(nonatomic, assign, readonly) NSTimeInterval currentAdBreakClipTime;

/** The string identifier for the current ad break. */
@property(nonatomic, copy, readonly) NSString *adBreakID;

/** The string identifier for the current ad clip break. */
@property(nonatomic, copy, readonly) NSString *adBreakClipID;

@end

GCK_ASSUME_NONNULL_END

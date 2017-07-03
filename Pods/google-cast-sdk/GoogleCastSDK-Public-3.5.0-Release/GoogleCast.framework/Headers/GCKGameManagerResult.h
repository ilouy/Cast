// Copyright 2014 Google Inc.

/** @cond ENABLE_FEATURE_GAME_MANAGER */

#import <GoogleCast/GCKDefines.h>

#import <Foundation/Foundation.h>

#ifdef USE_CAST_DYNAMIC_FRAMEWORK
#define GCKGameManagerResultClass NSClassFromString(@"GCKGameManagerResult")
#endif

/**
 * @file GCKGameManagerResult.h
 * GCKGameManagerResult definition.
 */

GCK_ASSUME_NONNULL_BEGIN

/**
 * The result of a Game Manager request.
 *
 * @deprecated The Game Manager API is no longer supported and will be removed in a future release.
 */
GCK_EXPORT
GCK_DEPRECATED("This API is no longer supported and will be removed in a future release.")
@interface GCKGameManagerResult : NSObject

/**
 * The request ID associated with this response.
 */
@property(nonatomic, assign, readonly) NSInteger requestID;

/**
 * The player ID associated with this response.
 */
@property(nonatomic, copy, readonly) NSString *playerID;

/**
 * Extra message data stored as part of this response.
 */
@property(nonatomic, copy, readonly) id extraData;

/**
 * Default initializer is not available.
 */
- (instancetype)init NS_UNAVAILABLE;

@end

GCK_ASSUME_NONNULL_END

/** @endcond */

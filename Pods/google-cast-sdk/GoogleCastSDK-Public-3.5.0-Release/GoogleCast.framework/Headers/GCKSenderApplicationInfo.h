// Copyright 2013 Google Inc.

#import <GoogleCast/GCKDefines.h>

#import <Foundation/Foundation.h>

/**
 * @file GCKSenderApplicationInfo.h
 */

#ifdef USE_CAST_DYNAMIC_FRAMEWORK
#define GCKSenderApplicationInfoClass NSClassFromString(@"GCKSenderApplicationInfo")
#endif

GCK_ASSUME_NONNULL_BEGIN

/**
 * @enum GCKSenderApplicationInfoPlatform
 * Sender application platforms.
 */
typedef NS_ENUM(NSInteger, GCKSenderApplicationInfoPlatform) {
  /** Android. */
  GCKSenderApplicationInfoPlatformAndroid = 1,
  /** iOS. */
  GCKSenderApplicationInfoPlatformiOS = 2,
  /** Chrome. */
  GCKSenderApplicationInfoPlatformChrome = 3,
  /** Mac OS X. */
  GCKSenderApplicationInfoPlatformOSX = 4,
};

/**
 * Information about a sender application.
 */
GCK_EXPORT
@interface GCKSenderApplicationInfo : NSObject <NSCopying>

/** The sender application's platform. */
@property(nonatomic, assign, readonly) GCKSenderApplicationInfoPlatform platform;

/** The sender application's unique identifier (app ID). */
@property(nonatomic, copy, readonly, GCK_NULLABLE) NSString *appIdentifier;

/** The sender application's launch URL (URL scheme). */
@property(nonatomic, strong, readonly, GCK_NULLABLE) NSURL *launchURL;

@end

GCK_ASSUME_NONNULL_END

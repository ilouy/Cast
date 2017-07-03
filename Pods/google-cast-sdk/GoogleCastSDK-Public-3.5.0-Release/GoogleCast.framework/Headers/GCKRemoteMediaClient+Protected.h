// Copyright 2015 Google Inc.

#import <GoogleCast/GCKRemoteMediaClient.h>

#import <GoogleCast/GCKDefines.h>

#import <Foundation/Foundation.h>

GCK_ASSUME_NONNULL_BEGIN

/**
 * Methods to be called by GCKRemoteMediaClient subclasses only.
 *
 * @since 3.3
 */
@interface GCKRemoteMediaClient (Protected)

/**
 * To be called by subclasses whenever a media session begins, namely, right after new media has
 * been successfully loaded on the remote player.
 */
- (void)notifyDidStartMediaSession;

/**
 * To be called by subclasses any time that the mediaStatus object of the client changes.
 */
- (void)notifyDidUpdateMediaStatus;

/**
 * To be called by subclasses any time that the media queue managed by the client changes.
 */
- (void)notifyDidUpdateQueue;

/**
 * To be called by subclasses whenever the GCKMediaStatus::preloadedItemID for the client's
 * mediaStatus changes.
 */
- (void)notifyDidUpdatePreloadStatus;

/**
 * To be called by subclasses any time that the metadata changes.
 */
- (void)notifyDidUpdateMetadata;

@end

GCK_ASSUME_NONNULL_END

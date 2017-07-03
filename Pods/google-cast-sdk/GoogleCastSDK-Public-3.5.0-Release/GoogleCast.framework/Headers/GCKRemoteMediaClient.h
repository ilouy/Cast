// Copyright 2015 Google Inc.

#import <GoogleCast/GCKDefines.h>
#import <GoogleCast/GCKMediaCommon.h>
#import <GoogleCast/GCKMediaControlChannel.h>
#import <GoogleCast/GCKMediaInformation.h>
#import <GoogleCast/GCKMediaMetadata.h>
#import <GoogleCast/GCKMediaStatus.h>
#import <GoogleCast/GCKMediaQueueItem.h>
#import <GoogleCast/GCKRequest.h>

#import <Foundation/Foundation.h>

#ifdef USE_CAST_DYNAMIC_FRAMEWORK
#define GCKRemoteMediaClientClass NSClassFromString(@"GCKRemoteMediaClient")
#endif

typedef GCKMediaControlChannelResumeState GCKMediaResumeState;

@protocol GCKRemoteMediaClientListener;
@protocol GCKRemoteMediaClientAdInfoParserDelegate;

GCK_ASSUME_NONNULL_BEGIN


/**
 * A class for controlling media playback on a Cast receiver. This class provides the same
 * functionality as the deprecated GCKMediaControlChannel, which it wraps, but with a more
 * convenient API. The main differences are:
 * <ul>
 * <li>Each request is represented by a GCKRequest object which can be tracked with a dedicated
 * delegate.
 * <li>The GCKRemoteMediaClient supports multiple listeners rather than a single delegate.
 * </ul>
 *
 * @since 3.0
 */
GCK_EXPORT
@interface GCKRemoteMediaClient : NSObject

/** A flag that indicates whether this object is connected to a session. */
@property(nonatomic, assign, readonly) BOOL connected;

/** The current media status, as reported by the media control channel. */
@property(nonatomic, strong, readonly, GCK_NULLABLE) GCKMediaStatus *mediaStatus;

/**
 * The amount of time that has passed since the last media status update was received. If a
 * status request is currently in progress, this will be 0.
 */
@property(nonatomic, assign, readonly) NSTimeInterval timeSinceLastMediaStatusUpdate;

/**
 * Adds a listener to this object's list of listeners.
 *
 * @param listener The listener to add.
 */
- (void)addListener:(id<GCKRemoteMediaClientListener>)listener;

/**
 * Removes a listener from this object's list of listeners.
 *
 * @param listener The listener to remove.
 */
- (void)removeListener:(id<GCKRemoteMediaClientListener>)listener;

/**
 * A delegate capable of extracting ad break information from the custom data in a GCKMediaStatus
 * object.
 *
 * @deprecated Use GCKAdBreakStatus instead.
 */
@property(nonatomic, weak, readwrite) id<GCKRemoteMediaClientAdInfoParserDelegate>
    adInfoParserDelegate;

/**
 * Loads and starts playback of a new media item.
 *
 * @param mediaInfo An object describing the media item to load.
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)loadMedia:(GCKMediaInformation *)mediaInfo;

/**
 * Loads and optionally starts playback of a new media item.
 *
 * @param mediaInfo An object describing the media item to load.
 * @param autoplay Whether playback should start immediately.
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)loadMedia:(GCKMediaInformation *)mediaInfo autoplay:(BOOL)autoplay;

/**
 * Loads and optionally starts playback of a new media item.
 *
 * @param mediaInfo An object describing the media item to load.
 * @param autoplay Whether playback should start immediately.
 * @param playPosition The initial playback position.
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)loadMedia:(GCKMediaInformation *)mediaInfo
                 autoplay:(BOOL)autoplay
             playPosition:(NSTimeInterval)playPosition;

/**
 * Loads and optionally starts playback of a new media item.
 *
 * @param mediaInfo An object describing the media item to load.
 * @param autoplay Whether playback should start immediately.
 * @param playPosition The initial playback position.
 * @param customData Custom application-specific data to pass along with the request. Must either be
 * an object that can be serialized to JSON using
 * <a href="https://goo.gl/0vd4Q2"><b>NSJSONSerialization</b></a>, or <code>nil</code>.
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)loadMedia:(GCKMediaInformation *)mediaInfo
                 autoplay:(BOOL)autoplay
             playPosition:(NSTimeInterval)playPosition
               customData:(id GCK_NULLABLE_TYPE)customData;

/**
 * Loads and optionally starts playback of a new media item.
 *
 * @param mediaInfo An object describing the media item to load.
 * @param autoplay Whether playback should start immediately.
 * @param playPosition The initial playback position.
 * @param activeTrackIDs An array of integers specifying the active tracks.
 * May be <code>nil</code>.
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)loadMedia:(GCKMediaInformation *)mediaInfo
                 autoplay:(BOOL)autoplay
             playPosition:(NSTimeInterval)playPosition
           activeTrackIDs:(NSArray<NSNumber *> *GCK_NULLABLE_TYPE)activeTrackIDs;

/**
 * Loads and optionally starts playback of a new media item.
 *
 * @param mediaInfo An object describing the media item to load.
 * @param autoplay Whether playback should start immediately.
 * @param playPosition The initial playback position.
 * @param activeTrackIDs An array of integers specifying the active tracks.
 * May be <code>nil</code>.
 * @param customData Custom application-specific data to pass along with the request. Must either be
 * an object that can be serialized to JSON using
 * <a href="https://goo.gl/0vd4Q2"><b>NSJSONSerialization</b></a>, or <code>nil</code>.
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)loadMedia:(GCKMediaInformation *)mediaInfo
                 autoplay:(BOOL)autoplay
             playPosition:(NSTimeInterval)playPosition
           activeTrackIDs:(NSArray<NSNumber *> *GCK_NULLABLE_TYPE)activeTrackIDs
               customData:(id GCK_NULLABLE_TYPE)customData;

/**
 * Sets the active tracks. The request will fail if there is no current media status.
 *
 * @param activeTrackIDs An array of integers specifying the active tracks. May be empty or
 * <code>nil</code> to disable any currently active tracks.
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)setActiveTrackIDs:(NSArray<NSNumber *> *GCK_NULLABLE_TYPE)activeTrackIDs;

/**
 * Sets the text track style. The request will fail if there is no current media status.
 *
 * @param textTrackStyle The text track style. The style will not be changed if this is
 * <code>nil</code>.
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)setTextTrackStyle:(GCKMediaTextTrackStyle *GCK_NULLABLE_TYPE)textTrackStyle;

/**
 * Pauses playback of the current media item. The request will fail if there is no current media
 * status.
 *
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)pause;

/**
 * Pauses playback of the current media item. The request will fail if there is no current media
 * status.
 *
 * @param customData Custom application-specific data to pass along with the request. Must either be
 * an object that can be serialized to JSON using
 * <a href="https://goo.gl/0vd4Q2"><b>NSJSONSerialization</b></a>, or <code>nil</code>.
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)pauseWithCustomData:(id GCK_NULLABLE_TYPE)customData;

/**
 * Stops playback of the current media item. If a queue is currently loaded, it will be removed. The
 * request will fail if there is no current media status.
 *
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)stop;

/**
 * Stops playback of the current media item. If a queue is currently loaded, it will be removed. The
 * request will fail if there is no current media status.
 *
 *
 * @param customData Custom application-specific data to pass along with the request. Must either be
 * an object that can be serialized to JSON using
 * <a href="https://goo.gl/0vd4Q2"><b>NSJSONSerialization</b></a>, or <code>nil</code>.
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)stopWithCustomData:(id GCK_NULLABLE_TYPE)customData;

/**
 * Begins (or resumes) playback of the current media item. Playback always begins at the
 * beginning of the stream. The request will fail if there is no current media status.
 *
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)play;

/**
 * Begins (or resumes) playback of the current media item. Playback always begins at the
 * beginning of the stream. The request will fail if there is no current media status.
 *
 * @param customData Custom application-specific data to pass along with the request. Must either be
 * an object that can be serialized to JSON using
 * <a href="https://goo.gl/0vd4Q2"><b>NSJSONSerialization</b></a>, or <code>nil</code>.
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)playWithCustomData:(id GCK_NULLABLE_TYPE)customData;

/**
 * Seeks to a new position within the current media item. The request will fail if there is no
 * current media status.
 *
 * @param position The new position from the beginning of the stream.
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)seekToTimeInterval:(NSTimeInterval)position;

/**
 * Seeks to a new position within the current media item. The request will fail if there is no
 * current media status.
 *
 * @param position The new position interval from the beginning of the stream.
 * @param resumeState The action to take after the seek operation has finished.
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)seekToTimeInterval:(NSTimeInterval)position
                       resumeState:(GCKMediaResumeState)resumeState;

/**
 * Seeks to a new position within the current media item. The request will fail if there is no
 * current media status.
 *
 * @param position The new position from the beginning of the stream.
 * @param resumeState The action to take after the seek operation has finished.
 * @param customData Custom application-specific data to pass along with the request. Must either be
 * an object that can be serialized to JSON using
 * <a href="https://goo.gl/0vd4Q2"><b>NSJSONSerialization</b></a>, or <code>nil</code>.
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)seekToTimeInterval:(NSTimeInterval)position
                       resumeState:(GCKMediaResumeState)resumeState
                        customData:(id GCK_NULLABLE_TYPE)customData;

/**
 * Loads and optionally starts playback of a new queue of media items.
 *
 * @param queueItems An array of GCKMediaQueueItem instances to load. Must not be <code>nil</code>
 * or empty.
 * @param startIndex The index of the item in the items array that should be played first.
 * @param repeatMode The repeat mode for playing the queue.
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)queueLoadItems:(NSArray<GCKMediaQueueItem *> *)queueItems
                    startIndex:(NSUInteger)startIndex
                    repeatMode:(GCKMediaRepeatMode)repeatMode;

/**
 * Loads and optionally starts playback of a new queue of media items.
 *
 * @param queueItems An array of GCKMediaQueueItem instances to load. Must not be <code>nil</code>
 * or empty.
 * @param startIndex The index of the item in the items array that should be played first.
 * @param repeatMode The repeat mode for playing the queue.
 * @param customData Custom application-specific data to pass along with the request. Must either be
 * an object that can be serialized to JSON using
 * <a href="https://goo.gl/0vd4Q2"><b>NSJSONSerialization</b></a>, or <code>nil</code>.
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)queueLoadItems:(NSArray<GCKMediaQueueItem *> *)queueItems
                    startIndex:(NSUInteger)startIndex
                    repeatMode:(GCKMediaRepeatMode)repeatMode
                    customData:(id GCK_NULLABLE_TYPE)customData;

/**
 * Loads and optionally starts playback of a new queue of media items.
 *
 * @param queueItems An array of GCKMediaQueueItem instances to load. Must not be <code>nil</code>
 * or empty.
 * @param startIndex The index of the item in the items array that should be played first.
 * @param playPosition The initial playback position for the item when it is first played,
 * relative to the beginning of the stream. This value is ignored when the same item is played
 * again, for example when the queue repeats, or the item is later jumped to. In those cases the
 * item's startTime is used.
 * @param repeatMode The repeat mode for playing the queue.
 * @param customData Custom application-specific data to pass along with the request. Must either be
 * an object that can be serialized to JSON using
 * <a href="https://goo.gl/0vd4Q2"><b>NSJSONSerialization</b></a>, or <code>nil</code>.
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)queueLoadItems:(NSArray<GCKMediaQueueItem *> *)queueItems
                    startIndex:(NSUInteger)startIndex
                  playPosition:(NSTimeInterval)playPosition
                    repeatMode:(GCKMediaRepeatMode)repeatMode
                    customData:(id GCK_NULLABLE_TYPE)customData;

/**
 * Inserts a list of new media items into the queue.
 *
 * @param queueItems An array of GCKMediaQueueItem instances to insert. Must not be <code>nil</code>
 * or empty.
 * @param beforeItemID The ID of the item that will be located immediately after the inserted list.
 * If the value is @ref kGCKMediaQueueInvalidItemID, the inserted list will be appended to the end
 * of the queue.
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)queueInsertItems:(NSArray<GCKMediaQueueItem *> *)queueItems
                beforeItemWithID:(NSUInteger)beforeItemID;

/**
 * Inserts a list of new media items into the queue.
 *
 * @param queueItems An array of GCKMediaQueueItem instances to insert. Must not be <code>nil</code>
 * or empty.
 * @param beforeItemID ID of the item that will be located immediately after the inserted list. If
 * the value is @ref kGCKMediaQueueInvalidItemID, the inserted list will be appended to the end of
 * the queue.
 * @param customData Custom application-specific data to pass along with the request. Must either be
 * an object that can be serialized to JSON using
 * <a href="https://goo.gl/0vd4Q2"><b>NSJSONSerialization</b></a>, or <code>nil</code>.
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)queueInsertItems:(NSArray<GCKMediaQueueItem *> *)queueItems
                beforeItemWithID:(NSUInteger)beforeItemID
                      customData:(id GCK_NULLABLE_TYPE)customData;

/**
 * A convenience method that inserts a single item into the queue.
 *
 * @param item The item to insert.
 * @param beforeItemID The ID of the item that will be located immediately after the inserted item.
 * If the value is @ref kGCKMediaQueueInvalidItemID, or does not refer to any item currently in the
 * queue, the inserted item will be appended to the end of the queue.
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)queueInsertItem:(GCKMediaQueueItem *)item beforeItemWithID:(NSUInteger)beforeItemID;

/**
 * A convenience method that inserts a single item into the queue and makes it the current item.
 *
 * @param item The item to insert.
 * @param beforeItemID The ID of the item that will be located immediately after the inserted item.
 * If the value is @ref kGCKMediaQueueInvalidItemID, or does not refer to any item currently in the
 * queue, the inserted item will be appended to the end of the queue.
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)queueInsertAndPlayItem:(GCKMediaQueueItem *)item
                      beforeItemWithID:(NSUInteger)beforeItemID;

/**
 * A convenience method that inserts a single item into the queue and makes it the current item.
 *
 * @param item The item to insert.
 * @param beforeItemID The ID of the item that will be located immediately after the inserted item.
 * If the value is @ref kGCKMediaQueueInvalidItemID, or does not refer to any item currently in the
 * queue, the inserted item will be appended to the end of the queue.
 * @param playPosition The initial playback position for the item when it is first played,
 * relative to the beginning of the stream. This value is ignored when the same item is played
 * again, for example when the queue repeats, or the item is later jumped to. In those cases the
 * item's startTime is used.
 * @param customData Custom application-specific data to pass along with the request. Must either be
 * an object that can be serialized to JSON using
 * <a href="https://goo.gl/0vd4Q2"><b>NSJSONSerialization</b></a>, or <code>nil</code>.
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)queueInsertAndPlayItem:(GCKMediaQueueItem *)item
                      beforeItemWithID:(NSUInteger)beforeItemID
                          playPosition:(NSTimeInterval)playPosition
                            customData:(id GCK_NULLABLE_TYPE)customData;

/**
 * Updates the queue.
 *
 * @param queueItems The list of updated items.
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)queueUpdateItems:(NSArray<GCKMediaQueueItem *> *)queueItems;

/**
 * Updates the queue.
 *
 * @param queueItems The list of updated items.
 * @param customData Custom application-specific data to pass along with the request. Must either be
 * an object that can be serialized to JSON using
 * <a href="https://goo.gl/0vd4Q2"><b>NSJSONSerialization</b></a>, or <code>nil</code>.
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)queueUpdateItems:(NSArray<GCKMediaQueueItem *> *)queueItems
                      customData:(id GCK_NULLABLE_TYPE)customData;

/**
 * Removes a list of media items from the queue. If the queue becomes empty as a result, the current
 * media session will be terminated.
 *
 * @param itemIDs An array of media item IDs identifying the items to remove. Must not be
 * <code>nil</code> or empty.
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)queueRemoveItemsWithIDs:(NSArray<NSNumber *> *)itemIDs;

/**
 * Removes a list of media items from the queue. If the queue becomes empty as a result, the current
 * media session will be terminated.
 *
 * @param itemIDs An array of media item IDs identifying the items to remove. Must not be
 * <code>nil</code> or empty.
 * @param customData Custom application-specific data to pass along with the request. Must either be
 * an object that can be serialized to JSON using
 * <a href="https://goo.gl/0vd4Q2"><b>NSJSONSerialization</b></a>, or <code>nil</code>.
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)queueRemoveItemsWithIDs:(NSArray<NSNumber *> *)itemIDs
                             customData:(id GCK_NULLABLE_TYPE)customData;

/**
 * A convenience method that removes a single item from the queue.
 *
 * @param itemID The ID of the item to remove.
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)queueRemoveItemWithID:(NSUInteger)itemID;

/**
 * Reorders a list of media items in the queue.
 *
 * @param queueItemIDs An array of media item IDs identifying the items to reorder. Must not be
 * <code>nil</code> or empty.
 * @param beforeItemID ID of the item that will be located immediately after the reordered list. If
 * the value is @ref kGCKMediaQueueInvalidItemID, or does not refer to any item currently in the
 * queue, the reordered list will be appended at the end of the queue.
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)queueReorderItemsWithIDs:(NSArray<NSNumber *> *)queueItemIDs
                  insertBeforeItemWithID:(NSUInteger)beforeItemID;

/**
 * Reorder a list of media items in the queue.
 *
 * @param queueItemIDs An array of media item IDs identifying the items to reorder. Must not be
 * <code>nil</code> or empty.
 * @param beforeItemID The ID of the item that will be located immediately after the reordered list.
 * If the value is @ref kGCKMediaQueueInvalidItemID, or does not refer to any item currently in the
 * queue, the reordered list will be moved to the end of the queue.
 * @param customData Custom application-specific data to pass along with the request. Must either be
 * an object that can be serialized to JSON using
 * <a href="https://goo.gl/0vd4Q2"><b>NSJSONSerialization</b></a>, or <code>nil</code>.
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)queueReorderItemsWithIDs:(NSArray<NSNumber *> *)queueItemIDs
                  insertBeforeItemWithID:(NSUInteger)beforeItemID
                              customData:(id GCK_NULLABLE_TYPE)customData;

/**
 * A convenience method that moves a single item in the queue.
 *
 * @param itemID The ID of the item to move.
 * @param beforeItemID The ID of the item that will be located immediately after the reordered list.
 * If the value is @ref kGCKMediaQueueInvalidItemID, or does not refer to any item currently in the
 * queue, the item will be moved to the end of the queue.
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)queueMoveItemWithID:(NSUInteger)itemID beforeItemWithID:(NSUInteger)beforeItemID;

/**
 * Jumps to the item with the specified ID in the queue.
 *
 * @param itemID The ID of the item to jump to.
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)queueJumpToItemWithID:(NSUInteger)itemID;

/**
 * Jumps to the item with the specified ID in the queue.
 *
 * @param itemID The ID of the item to jump to.
 * @param customData Custom application-specific data to pass along with the request. Must either be
 * an object that can be serialized to JSON using
 * <a href="https://goo.gl/0vd4Q2"><b>NSJSONSerialization</b></a>, or <code>nil</code>.
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)queueJumpToItemWithID:(NSUInteger)itemID
                           customData:(id GCK_NULLABLE_TYPE)customData;

/**
 * Jumps to the item with the specified ID in the queue.
 *
 * @param itemID The ID of the item to jump to.
 * @param playPosition The initial playback position for the item when it is first played,
 * relative to the beginning of the stream. This value is ignored when the same item is played
 * again, for example when the queue repeats, or the item is later jumped to. In those cases the
 * item's startTime is used.
 * @param customData Custom application-specific data to pass along with the request. Must either be
 * an object that can be serialized to JSON using
 * <a href="https://goo.gl/0vd4Q2"><b>NSJSONSerialization</b></a>, or <code>nil</code>.
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)queueJumpToItemWithID:(NSUInteger)itemID
                         playPosition:(NSTimeInterval)playPosition
                           customData:(id GCK_NULLABLE_TYPE)customData;

/**
 * Moves to the next item in the queue.
 *
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)queueNextItem;

/**
 * Moves to the previous item in the queue.
 *
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)queuePreviousItem;

/**
 * Sets the queue repeat mode.
 *
 * @param repeatMode The new repeat mode.
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)queueSetRepeatMode:(GCKMediaRepeatMode)repeatMode;

/**
 * Sets the stream volume. The request will fail if there is no current media session.
 *
 * @param volume The new volume, in the range [0.0 - 1.0].
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)setStreamVolume:(float)volume;

/**
 * Sets the stream volume. The request will fail if there is no current media session.
 *
 * @param volume The new volume, in the range [0.0 - 1.0].
 * @param customData Custom application-specific data to pass along with the request. Must either be
 * an object that can be serialized to JSON using
 * <a href="https://goo.gl/0vd4Q2"><b>NSJSONSerialization</b></a>, or <code>nil</code>.
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)setStreamVolume:(float)volume customData:(id GCK_NULLABLE_TYPE)customData;

/**
 * Sets whether the stream is muted. The request will fail if there is no current media session.
 *
 * @param muted Whether the stream should be muted or unmuted.
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)setStreamMuted:(BOOL)muted;

/**
 * Sets whether the stream is muted. The request will fail if there is no current media session.
 *
 * @param muted Whether the stream should be muted or unmuted.
 * @param customData Custom application-specific data to pass along with the request. Must either be
 * an object that can be serialized to JSON using
 * <a href="https://goo.gl/0vd4Q2"><b>NSJSONSerialization</b></a>, or <code>nil</code>.
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)setStreamMuted:(BOOL)muted customData:(id GCK_NULLABLE_TYPE)customData;

/**
 * Requests updated media status information from the receiver.
 *
 * @return The GCKRequest object for tracking this request.
 */
- (GCKRequest *)requestStatus;

/**
 * Returns the approximate stream position as calculated from the last received stream information
 * and the elapsed wall-time since that update. Returns 0 if the channel is not connected or if no
 * media is currently loaded.
 */
- (NSTimeInterval)approximateStreamPosition;

@end

/**
 * The GCKRemoteMediaClient listener protocol.
 *
 * @since 3.0
 */
GCK_EXPORT
@protocol GCKRemoteMediaClientListener <NSObject>

@optional

/**
 * Called when a new media session has started on the receiver.
 *
 * @param client The client.
 * @param sessionID The ID of the new session.
 */
- (void)remoteMediaClient:(GCKRemoteMediaClient *)client
    didStartMediaSessionWithID:(NSInteger)sessionID;

/**
 * Called when updated media status has been received from the receiver.
 *
 * @param client The client.
 * @param mediaStatus The updated media status. The status can also be accessed as a property of
 * the player.
 */
- (void)remoteMediaClient:(GCKRemoteMediaClient *)client
     didUpdateMediaStatus:(GCKMediaStatus *GCK_NULLABLE_TYPE)mediaStatus;

/**
 * Called when updated media metadata has been received from the receiver.
 *
 * @param client The client.
 * @param mediaMetadata The updated media metadata. The metadata can also be accessed through the
 * GCKRemoteMediaClient::mediaStatus property.
 */
- (void)remoteMediaClient:(GCKRemoteMediaClient *)client
    didUpdateMediaMetadata:(GCKMediaMetadata *GCK_NULLABLE_TYPE)mediaMetadata;

/**
 * Called when the media playback queue has been updated on the receiver.
 *
 * @param client The client.
 */
- (void)remoteMediaClientDidUpdateQueue:(GCKRemoteMediaClient *)client;

/**
 * Called when the media preload status has been updated on the receiver.
 *
 * @param client The client.
 */
- (void)remoteMediaClientDidUpdatePreloadStatus:(GCKRemoteMediaClient *)client;

@end

/**
 * The delegate protocol for parsing ad break information from a media status.
 *
 * @deprecated A new API will be introduced in the future.
 * @since 3.0
 */
@protocol GCKRemoteMediaClientAdInfoParserDelegate <NSObject>
@optional

/**
 * Allows the delegate to determine whether the receiver is playing an ad or not, based on the
 * current media status.
 * @param client The client.
 * @param mediaStatus The current media status.
 * @return YES if the receiver is currently playing an ad, NO otherwise.
 */
- (BOOL)remoteMediaClient:(GCKRemoteMediaClient *)client
    shouldSetPlayingAdInMediaStatus:(GCKMediaStatus *)mediaStatus;

/**
 * Allows the delegate to determine the list of ad breaks in the current content.
 * @param client The client.
 * @param mediaStatus The current media status.
 * @return An array of GCKAdBreakInfo objects representing the ad breaks for this content, or nil
 * if there are no ad breaks.
 */
- (NSArray<GCKAdBreakInfo *> *GCK_NULLABLE_TYPE)remoteMediaClient:(GCKRemoteMediaClient *)client
                                   shouldSetAdBreaksInMediaStatus:(GCKMediaStatus *)mediaStatus;

@end

GCK_ASSUME_NONNULL_END

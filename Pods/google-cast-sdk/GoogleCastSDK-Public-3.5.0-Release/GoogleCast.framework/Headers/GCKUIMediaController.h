// Copyright 2015 Google Inc.

/** @cond ENABLE_FEATURE_GUI */

#import <GoogleCast/GCKDefines.h>
#import <GoogleCast/GCKMediaStatus.h>
#import <GoogleCast/GCKRemoteMediaClient.h>
#import <GoogleCast/GCKSession.h>
#import <GoogleCast/GCKUIButton.h>
#import <GoogleCast/GCKUIImageHints.h>

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 * @file GCKUIMediaController.h
 */

#ifdef USE_CAST_DYNAMIC_FRAMEWORK
#define GCKUIMediaControllerClass NSClassFromString(@"GCKUIMediaController")
#endif

GCK_ASSUME_NONNULL_BEGIN

/**
 * @var GCKUIControlStateRepeatOff
 * Custom <a href="https://goo.gl/tZWsqZ"><b>UIControlState</b></a> for the repeat mode button;
 * corresponds to @ref GCKMediaRepeatModeOff.
 *
 * @since 3.0
 */
#ifdef USE_CAST_DYNAMIC_FRAMEWORK
#define GCKUIControlStateRepeatOff GCK_EXTERN_UICONTROLSTATE(GCKUIControlStateRepeatOff)
#else
GCK_EXTERN
const UIControlState GCKUIControlStateRepeatOff;
#endif

/**
 * @var GCKUIControlStateRepeatAll
 * Custom <a href="https://goo.gl/tZWsqZ"><b>UIControlState</b></a> for the repeat mode button;
 * corresponds to @ref GCKMediaRepeatModeAll.
 *
 * @since 3.0
 */
#ifdef USE_CAST_DYNAMIC_FRAMEWORK
#define GCKUIControlStateRepeatAll GCK_EXTERN_UICONTROLSTATE(GCKUIControlStateRepeatAll)
#else
GCK_EXTERN
const UIControlState GCKUIControlStateRepeatAll;
#endif

/**
 * @var GCKUIControlStateRepeatSingle
 * Custom <a href="https://goo.gl/tZWsqZ"><b>UIControlState</b></a> for the repeat mode button;
 * corresponds to @ref GCKMediaRepeatModeSingle.
 *
 * @since 3.0
 */
#ifdef USE_CAST_DYNAMIC_FRAMEWORK
#define GCKUIControlStateRepeatSingle GCK_EXTERN_UICONTROLSTATE(GCKUIControlStateRepeatSingle)
#else
GCK_EXTERN
const UIControlState GCKUIControlStateRepeatSingle;
#endif

/**
 * @var GCKUIControlStatePlay
 * Custom <a href="https://goo.gl/tZWsqZ"><b>UIControlState</b></a> for the play/pause toggle
 * button; indicates media is playing.
 *
 * @since 3.0
 */
#ifdef USE_CAST_DYNAMIC_FRAMEWORK
#define GCKUIControlStatePlay GCK_EXTERN_UICONTROLSTATE(GCKUIControlStatePlay)
#else
GCK_EXTERN
const UIControlState GCKUIControlStatePlay;
#endif

/**
 * @var GCKUIControlStatePause
 * Custom <a href="https://goo.gl/tZWsqZ"><b>UIControlState</b></a> for the play/pause toggle
 * button; indicates media is paused.
 *
 * @since 3.0
 */
#ifdef USE_CAST_DYNAMIC_FRAMEWORK
#define GCKUIControlStatePause GCK_EXTERN_UICONTROLSTATE(GCKUIControlStatePause)
#else
GCK_EXTERN
const UIControlState GCKUIControlStatePause;
#endif

/**
 * @var GCKUIControlStateShuffle
 * Custom <a href="https://goo.gl/tZWsqZ"><b>UIControlState</b></a> for the repeat mode button;
 * corresponds to @ref GCKMediaRepeatModeAllAndShuffle.
 *
 * @since 3.0
 */
#ifdef USE_CAST_DYNAMIC_FRAMEWORK
#define GCKUIControlStateShuffle GCK_EXTERN_UICONTROLSTATE(GCKUIControlStateShuffle)
#else
GCK_EXTERN
const UIControlState GCKUIControlStateShuffle;
#endif


/**
 * A block for formatting an arbitrary object as an
 * <a href="https://goo.gl/5dXzU6"><b>NSString</b></a>.
 *
 * @since 3.0
 */
typedef NSString *GCK_NONNULL_TYPE (^GCKUIValueFormatter)(const id value);

@protocol GCKUIMediaControllerDelegate;
@class GCKUIPlayPauseToggleController;
@class GCKUIStreamPositionController;

/**
 * A controller for UI views that are used to control or display the status of media playback on
 * a Cast receiver. The calling application registers its media-related UI controls with the
 * controller by setting the appropriate properties. The controller then responds to touch events
 * on the controls by issuing the appropriate media commands to the receiver, and updates the
 * controls based on status information and media metadata received from the receiver. The
 * controller automatically enables and disables the UI controls as appropriate for the current
 * session and media player state. It additionally disables all of the controls while a request is
 * in progress.
 *
 * See GCKUIMediaControllerDelegate for the delegate protocol.
 *
 * @since 3.0
 */
GCK_EXPORT
@interface GCKUIMediaController : NSObject

/**
 * The delegate for receiving notificatiosn from the GCKUIMediaController.
 */
@property(nonatomic, weak, readwrite, GCK_NULLABLE) id<GCKUIMediaControllerDelegate> delegate;

/**
 * The session that is associated with this controller.
 */
@property(nonatomic, strong, readonly, GCK_NULLABLE) GCKSession *session;

/**
 * Whether there is media currently loaded (or loading) on the receiver. If no Cast session is
 * active, this will be <code>NO</code>.
 */
@property(nonatomic, assign, readonly) BOOL mediaLoaded;

/**
 * Whether there is a current item in the queue.
 */
@property(nonatomic, assign, readonly) BOOL hasCurrentQueueItem;

/**
 * Whether there is an item being preloaded in the queue.
 */
@property(nonatomic, assign, readonly) BOOL hasLoadingQueueItem;

/**
 * The latest known media player state. If no Cast session is active, this will be player state
 * just before the last session ended. If there was no prior session, this will be
 * @ref GCKMediaPlayerStateUnknown.
 */
@property(nonatomic, assign, readonly) GCKMediaPlayerState lastKnownPlayerState;

/**
 * The latest known media stream position. If no Cast session is active, this will be the stream
 * position of the media just before the last session ended. If there was no prior session, this
 * will be @ref kGCKInvalidTimeInterval.
 */
@property(nonatomic, assign, readonly) NSTimeInterval lastKnownStreamPosition;

/**
 * A "play" button. When the button is tapped, playback of the currently loaded media is started or
 * resumed on the receiver. The button will be disabled if playback is already in progress, or if
 * there is no media currently loaded, or if there is no Cast session currently active.
 */
@property(nonatomic, weak, readwrite, GCK_NULLABLE) UIButton *playButton;

/**
 * A "pause" button. When the button is tapped, playback of the currently loaded media is paused on
 * the receiver. The button will be disabled if the currently loaded media does not support pausing,
 * or if playback is not currently in progress, or if there is no media currently loaded, or if
 * there is no Cast session currently active.
 */
@property(nonatomic, weak, readwrite, GCK_NULLABLE) UIButton *pauseButton;

/**
 * A "play/pause" toggle button. The caller should set appropriate icons for the button's
 * @ref GCKUIControlStatePlay and @ref GCKUIControlStatePause states, namely, a "pause" icon for the
 * play state and a "play" icon for the pause state. The button's state is automatically updated to
 * reflect the current playback state on the receiver. When the button is tapped, playback of the
 * currently loaded media is paused or resumed on the receiver. The button will be disabled if the
 * currently loaded media does not support pausing, or if playback is not currently in progress or
 * paused, or if there is no media currently loaded, or if there is no Cast session currently
 * active.
 */
@property(nonatomic, weak, readwrite, GCK_NULLABLE) GCKUIButton *playPauseToggleButton;

/**
 * A "play/pause" toggle controller. Used as a stand-in for a custom, application-supplied
 * play/pause toggle UI. See GCKUIPlayPauseToggleController for details.
 *
 * @since 3.4
 */
@property(nonatomic, strong, readwrite, GCK_NULLABLE)
    GCKUIPlayPauseToggleController *playPauseToggleController;

/**
 * A "stop" button. When the button is tapped, playback of the currently loaded media is stopped on
 * the receiver. The button will be disabled if there is no media currently loaded, or if there is
 * no Cast session currently active.
 */
@property(nonatomic, weak, readwrite, GCK_NULLABLE) UIButton *stopButton;

/**
 * A button for seeking 30 seconds forward in the currently playing media item. The button will be
 * disabled if there is no media
 * currently loaded, or if there is no Cast session currently active.
 */
@property(nonatomic, weak, readwrite, GCK_NULLABLE) GCKUIButton *forward30SecondsButton;

/**
 * A button for seeking 30 seconds back in the currently playing media item. The button will be
 * disabled if there is no media currently loaded, or if there is no Cast session currently active.
 */
@property(nonatomic, weak, readwrite, GCK_NULLABLE) GCKUIButton *rewind30SecondsButton;

/**
 * A button for pausing queue playback once the current item finishes playing.
 */
@property(nonatomic, weak, readwrite, GCK_NULLABLE) UIButton *pauseQueueButton;

/**
 * A "next" button. When the button is tapped, playback moves to the next media item in the queue.
 * The button will be disabled if the operation is not supported, or if there is no media currently
 * loaded, or if there is no Cast session currently active.
 */
@property(nonatomic, weak, readwrite, GCK_NULLABLE) UIButton *nextButton;

/**
 * A "previous" button. When the button is tapped, playback moves to the previous media item in the
 * queue. The button will be disabled if the operation is not supported, or if there is no media
 * currently loaded, or if there is no Cast session currently active.
 */
@property(nonatomic, weak, readwrite, GCK_NULLABLE) UIButton *previousButton;

/**
 * A button for cycling through the available queue repeat modes. (See @ref GCKMediaRepeatMode.) The
 * caller should set appropriate icons for the button's
 * <a href="https://goo.gl/tZWsqZ"><b>UIControlStateNormal</b></a> (repeat off),
 * @ref GCKUIControlStateRepeatSingle, @ref GCKUIControlStateRepeatAll, and
 * @ref GCKUIControlStateShuffle states. The button's state is automatically updated to reflect the
 * current queue repeat mode on the receiver. Tapping on the button cycles to the next repeat mode,
 * in the order:
 *
 * @ref GCKMediaRepeatModeOff &rarr; @ref GCKMediaRepeatModeAll &rarr;
 * @ref GCKMediaRepeatModeSingle &rarr; @ref GCKMediaRepeatModeAllAndShuffle
 *
 * The button will be disabled if there is no Cast session currently active.
 */
@property(nonatomic, weak, readwrite, GCK_NULLABLE) GCKUIButton *repeatModeButton;

/**
 * A slider for displaying and changing the current stream position. When the slider's value is
 * changed by the user, the stream position of the currently loaded media is updated on the
 * receiver. While playback of media is in progress on the receiver, the slider's value is updated
 * in realtime to reflect the current stream position. The slider will be disabled if the currently
 * loaded media does not support seeking, or if there is no media currently loaded, or if there is
 * no Cast session currently active.
 */
@property(nonatomic, weak, readwrite, GCK_NULLABLE) UISlider *streamPositionSlider;

/**
 * A view for displaying the current stream progress. While playback of media is in progress on the
 * receiver, the views's value is updated in realtime to reflect the current stream position. The
 * view will be disabled if the currently loaded media is a live stream, or if there is no media
 * currently loaded, or if there is no Cast session currently active.
 */
@property(nonatomic, weak, readwrite, GCK_NULLABLE) UIProgressView *streamProgressView;

/**
 * A label for displaying the current stream position, in minutes and seconds. If there is no media
 * currently loaded, or if there is no Cast session currently active, the label displays a localized
 * form of "--:--".
 */
@property(nonatomic, weak, readwrite, GCK_NULLABLE) UILabel *streamPositionLabel;

/**
 * A label for displaying the current stream duration, in minutes and seconds. If the currently
 * loaded media does not have a duration (for example, if it is a live stream), or if there is no
 * media currently loaded, or if there is no Cast session currently active, the label displays a
 * localized form of "--:--".
 */
@property(nonatomic, weak, readwrite, GCK_NULLABLE) UILabel *streamDurationLabel;

/**
 * A label for displaying the remaining stream time (the duration minus the position), in minutes
 * and seconds. If the currently loaded media does not have a duration (for example, if it is a live
 * stream), or if there is no media currently loaded, or if there is no Cast session currently
 * active, the label displays a localized form of "--:--".
 */
@property(nonatomic, weak, readwrite, GCK_NULLABLE) UILabel *streamTimeRemainingLabel;

/**
 * A stream posdition controller. Used as a stand-in for a custom, application-supplied
 * stream position and/or seek UI. See GCKUIStreamPositionController for details.
 *
 * @since 3.4
 */
@property(nonatomic, strong, readwrite, GCK_NULLABLE)
    GCKUIStreamPositionController *streamPositionController;

/**
 * Whether remaining stream time will be displayed as a negative value, for example, "-1:23:45". By
 * default this property is set to <code>YES</code>.
 */
@property(nonatomic, assign, readwrite) BOOL displayTimeRemainingAsNegativeValue;

/**
 * A button for selecting audio tracks and/or closed captions or subtitles. When the button is
 * tapped, the media tracks selection UI is displayed to the user. The button will be disabled if
 * the currently loaded media does not have any selectable media tracks, or if there is no media
 * currently loaded, or if there is no Cast session currently active.
 */
@property(nonatomic, weak, readwrite, GCK_NULLABLE) UIButton *tracksButton;

/**
 * A label for displaying a subtitle for the currently loaded media. If there is no subtitle field
 * explicitly set in the metadata, the label will display the most appropriate metadata field based
 * on the media type, for example the studio name for a movie or the artist name for a music track.
 */
@property(nonatomic, weak, readwrite, GCK_NULLABLE) UILabel *smartSubtitleLabel;

/**
 * A activity indicator view for indicating media is in loading state.
 */
@property(nonatomic, weak, readwrite, GCK_NULLABLE) UIActivityIndicatorView *mediaLoadingIndicator;

/**
 * Initializes an instance.
 */
- (instancetype)init;

/**
 * Binds a <a href="https://goo.gl/POkr7n"><b>UILabel</b></a> to a metadata key. The view will
 * display the current value of the corresponding metadata field.
 *
 * See GCKMediaMetadata for a list of predefined metadata keys.
 *
 * @param label The <a href="https://goo.gl/POkr7n"><b>UILabel</b></a> that will display the value.
 * @param key The metadata key.
 */
- (void)bindLabel:(UILabel *)label toMetadataKey:(NSString *)key;

/**
 * Binds a <a href="https://goo.gl/POkr7n"><b>UILabel</b></a> to a metadata key. The view will
 * display the current value of the corresponding metadata field.
 *
 * See GCKMediaMetadata for a list of predefined metadata keys.
 *
 * @param label The <a href="https://goo.gl/POkr7n"><b>UILabel</b></a> that will display the value.
 * @param key The metadata key.
 * @param formatter A block that will produce the desired string representation of the value.
 */
- (void)bindLabel:(UILabel *)label
    toMetadataKey:(NSString *)key
    withFormatter:(GCKUIValueFormatter)formatter;

/**
 * Binds a <a href="https://goo.gl/ncWBFi"><b>UITextView</b></a> to a metadata key. The view will
 * display the current value of the corresponding metadata field.
 *
 * See GCKMediaMetadata for a list of predefined metadata keys.
 *
 * @param textView The <a href="https://goo.gl/ncWBFi"><b>UITextView</b></a> that will display the
 * value.
 * @param key The metadata key.
 */
- (void)bindTextView:(UITextView *)textView toMetadataKey:(NSString *)key;

/**
 * Binds a <a href="https://goo.gl/ncWBFi"><b>UITextView</b></a> to a metadata key. The view will
 * display the current value of the corresponding metadata field.
 *
 * See GCKMediaMetadata for a list of predefined metadata keys.
 *
 * @param textView The <a href="https://goo.gl/ncWBFi"><b>UITextView</b></a> that will display the
 * value.
 * @param key The metadata key.
 * @param formatter A block that will produce the desired string representation of the value.
 */
- (void)bindTextView:(UITextView *)textView
       toMetadataKey:(NSString *)key
       withFormatter:(GCKUIValueFormatter)formatter;

/**
 * Binds a <a href="https://goo.gl/8Eb8FS"><b>UIImageView</b></a> to a GCKUIImageHints instance.
 * The currently installed UIImagePicker will be used to select an image from the metadata for the
 * view.
 *
 * @param imageView The <a href="https://goo.gl/8Eb8FS"><b>UIImageView</b></a> that will display the
 * selected image.
 * @param imageHints The image hints.
 */
- (void)bindImageView:(UIImageView *)imageView toImageHints:(GCKUIImageHints *)imageHints;

/**
 * Unbinds the specified view.
 *
 * @param view The view to unbind.
 */
- (void)unbindView:(UIView *)view;

/**
 * Unbinds all bound views.
 */
- (void)unbindAllViews;

/**
 * Changes the repeat mode for the queue to the next mode in the cycle:
 *
 * @ref GCKMediaRepeatModeOff &rarr; @ref GCKMediaRepeatModeAll &rarr;
 * @ref GCKMediaRepeatModeSingle &rarr; @ref GCKMediaRepeatModeAllAndShuffle
 *
 * @return The new repeat mode.
 */
- (GCKMediaRepeatMode)cycleRepeatMode;

/**
 * A convenience method for displaying the media track selection UI.
 */
- (void)selectTracks;

@end

/**
 * The GCKUIMediaController delegate protocol.
 *
 * @since 3.0
 */
@protocol GCKUIMediaControllerDelegate <NSObject>

@optional

/**
 * Called when the remote media player state has changed.
 *
 * @param mediaController The GCKUIMediaController instance.
 * @param playerState The new player state.
 * @param streamPosition The last known stream position at the time of the player state change.
 */
- (void)mediaController:(GCKUIMediaController *)mediaController
    didUpdatePlayerState:(GCKMediaPlayerState)playerState
      lastStreamPosition:(NSTimeInterval)streamPosition;

/**
 * Called when preloading has started for an upcoming media queue item.
 *
 * @param mediaController The GCKUIMediaController instance.
 * @param itemID The ID of the item that is being preloaded, or @ref kGCKMediaQueueInvalidItemID
 * if none.
 */
- (void)mediaController:(GCKUIMediaController *)mediaController
    didBeginPreloadForItemID:(NSUInteger)itemID;

/**
 * Called when new media status has been received from the receiver, and after the
 * GCKUIMediaController has finished processing the updated status.
 *
 * @param mediaController The GCKUIMediaController instance.
 * @param mediaStatus The new media status.
 */
- (void)mediaController:(GCKUIMediaController *)mediaController
    didUpdateMediaStatus:(GCKMediaStatus *)mediaStatus;

@end

GCK_ASSUME_NONNULL_END

/** @endcond */

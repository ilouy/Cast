// Copyright 2016 Google Inc.

/** @cond ENABLE_FEATURE_GUI */

#import <GoogleCast/GCKDefines.h>

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

GCK_ASSUME_NONNULL_BEGIN

/**
 * A class for controlling the style (colors, fonts, icons) of the default views of the framework.
 *
 * @since 3.3
 */
GCK_EXPORT
@interface GCKUIStyleAttributes : NSObject

/**
 * An image that will be used in "closed captions" buttons in the framework's default views.
 */
@property(nonatomic, strong, readwrite) UIImage *closedCaptionsImage;
/**
 * An image that will be used in "forward 30 seconds" buttons in the frameworks default views.
 */
@property(nonatomic, strong, readwrite) UIImage *forward30SecondsImage;
/**
 * An image that will be used in "rewind 30 seconds" buttons in the framework's default views.
 */
@property(nonatomic, strong, readwrite) UIImage *rewind30SecondsImage;
/**
 * An image that will be used to indicate that a slider is a volume slider in the framework's
 * default views.
 */
@property(nonatomic, strong, readwrite) UIImage *volumeImage;
/**
 * An image that will be used in the "mute toggle" button in the framework's default views.
 * This is the image that will be displayed while the receiver is muted.
 */
@property(nonatomic, strong, readwrite) UIImage *muteOffImage;
/**
 * An image that will be used in the "mute toggle" button in the framework's default views. This is
 * the image that will be displayed while the receiver is not muted.
 */
@property(nonatomic, strong, readwrite) UIImage *muteOnImage;
/**
 * An image that will be used in the "play/pause toggle" button in the framework's default views.
 * This is the image that will be displayed while the receiver is playing.
 */
@property(nonatomic, strong, readwrite) UIImage *pauseImage;
/**
 * An image that will be used in the "play/pause toggle" button in the framework's default views.
 * This is the image that will be displayed while the receiver is paused.
 */
@property(nonatomic, strong, readwrite) UIImage *playImage;
/**
 * An image that will be used in "forward 30 seconds" buttons in the framework's default views.
 */
@property(nonatomic, strong, readwrite) UIImage *skipNextImage;
/**
 * An image that will be used in "forward 30 seconds" buttons in the framework's default views.
 */
@property(nonatomic, strong, readwrite) UIImage *skipPreviousImage;
/**
 * An image that will be used in the track selector, to select the audio track chooser view.
 */
@property(nonatomic, strong, readwrite) UIImage *audioTrackImage;
/**
 * An image that will be used in the track selector, to select the subtitle track chooser view.
 */
@property(nonatomic, strong, readwrite) UIImage *subtitlesTrackImage;
/**
 * An image that will be used in "stop" buttons in the framework's default views.
 */
@property(nonatomic, strong, readwrite) UIImage *stopImage;
/**
 * The UIFont to be used in labels of buttons in the framework's default views.
 */
@property(nonatomic, strong, readwrite) UIFont *buttonTextFont;
/**
 * The color to be used in labels of buttons in the framework's default views.
 */
@property(nonatomic, strong, readwrite) UIColor *buttonTextColor;
/**
 * The shadow color to be used in labels of buttons in the framework's default views.
 */
@property(nonatomic, strong, readwrite) UIColor *buttonTextShadowColor;
/**
 * The offset for the shadow for labels of buttons in the framework's default views.
 */
@property(nonatomic, assign, readwrite) CGSize buttonTextShadowOffset;
/**
 * The UIFont to be used in labels of type "body" in the framework's default views.
 */
@property(nonatomic, strong, readwrite) UIFont *bodyTextFont;
/**
 * The UIFont to be used in labels of type "heading" in the framework's default views.
 */
@property(nonatomic, strong, readwrite) UIFont *headingTextFont;
/**
 * The font to be used in labels of type "caption" in the framework's default views.
 */
@property(nonatomic, strong, readwrite) UIFont *captionTextFont;
/**
 * The color to be used in labels of type "body" in the framework's default views.
 */
@property(nonatomic, strong, readwrite) UIColor *bodyTextColor;
/**
 * The shadow color to be used in labels of type "body" in the framework's default views.
 */
@property(nonatomic, strong, readwrite) UIColor *bodyTextShadowColor;
/**
 * The color to be used in labels of type "heading" in the framework's default views.
 */
@property(nonatomic, strong, readwrite) UIColor *headingTextColor;
/**
 * The shadow color to be used in labels of type "heading" in the framework's default views.
 */
@property(nonatomic, strong, readwrite) UIColor *headingTextShadowColor;
/**
 * The color to be used in labels of type "caption" in the framework's default views.
 */
@property(nonatomic, strong, readwrite) UIColor *captionTextColor;
/**
 * The shadow color to be used in labels of type "caption" in the framework's default views.
 */
@property(nonatomic, strong, readwrite) UIColor *captionTextShadowColor;
/**
 * The background color to be used on the framework's default views.
 */
@property(nonatomic, strong, readwrite) UIColor *backgroundColor;
/**
 * The color to use as tint color on all buttons and icons on the framework's default views.
 */
@property(nonatomic, strong, readwrite) UIColor *iconTintColor;
/**
 * The offset for the shadow for labels of type "body" in the framework's default views.
 */
@property(nonatomic, assign, readwrite) CGSize bodyTextShadowOffset;
/**
 * The offset for the shadow for labels of type "caption" in the framework's default views.
 */
@property(nonatomic, assign, readwrite) CGSize captionTextShadowOffset;
/**
 * The offset for the shadow for labels of type "heading" in the framework's default views.
 */
@property(nonatomic, assign, readwrite) CGSize headingTextShadowOffset;

@end

/**
 * The style attributes for the view group representing the initial instructions overlay.
 * Can be accessed as castViews.instructions.
 */
@interface GCKUIStyleAttributesInstructions : GCKUIStyleAttributes
@end

/**
 * The style attributes for the view group representing the guest-mode pairing dialog.
 * Can be accessed as castViews.deviceControl.guestModePairingDialog
 */
@interface GCKUIStyleAttributesGuestModePairingDialog : GCKUIStyleAttributes
@end

/**
 * The style attributes for the view group representing the media track selector.
 * Can be accessed as castViews.mediaControl.trackSelector
 */
@interface GCKUIStyleAttributesTrackSelector : GCKUIStyleAttributes
@end

/**
 * The style attributes for the view group representing the mini controller.
 * Can be accessed as castViews.mediaControl.miniController
 */
@interface GCKUIStyleAttributesMiniController : GCKUIStyleAttributes
@end

/**
 * The style attributes for the view group representing the expanded controller.
 * Can be accessed as castViews.mediaControl.expandedController
 */
@interface GCKUIStyleAttributesExpandedController : GCKUIStyleAttributes
@end

/**
 * The style attributes for the view group representing the device chooser.
 * Can be accessed as castViews.deviceControl.deviceChooser
 */
@interface GCKUIStyleAttributesDeviceChooser : GCKUIStyleAttributes
@end

/**
 * The style attributes for the view group representing the connection controller.
 * Can be accessed as castViews.deviceControl.connectionController
 */
@interface GCKUIStyleAttributesConnectionController : GCKUIStyleAttributes
@end

/**
 * The style attributes for the view group representing all the media control views.
 * Can be accessed as castViews.mediaControl
 */
@interface GCKUIStyleAttributesMediaControl : GCKUIStyleAttributes
@property(readonly, nonatomic, strong) GCKUIStyleAttributesExpandedController *expandedController;
@property(readonly, nonatomic, strong) GCKUIStyleAttributesMiniController *miniController;
@property(readonly, nonatomic, strong) GCKUIStyleAttributesTrackSelector *trackSelector;
@end

/**
 * The style attributes for the view group representing all the device control views.
 * Can be accessed as castViews.deviceControl
 */
@interface GCKUIStyleAttributesDeviceControl : GCKUIStyleAttributes
@property(readonly, nonatomic, strong) GCKUIStyleAttributesDeviceChooser *deviceChooser;
@property(readonly, nonatomic, strong)
    GCKUIStyleAttributesConnectionController *connectionController;
@property(readonly, nonatomic, strong)
    GCKUIStyleAttributesGuestModePairingDialog *guestModePairingDialog;
@end

/**
 * The style attributes for the root view group.
 * Can be accessed as castViews
 */
@interface GCKUIStyleAttributesCastViews : GCKUIStyleAttributes
@property(readonly, nonatomic, strong) GCKUIStyleAttributesDeviceControl *deviceControl;
@property(readonly, nonatomic, strong) GCKUIStyleAttributesMediaControl *mediaControl;
@property(readonly, nonatomic, strong) GCKUIStyleAttributesInstructions *instructions;
@end

GCK_ASSUME_NONNULL_END

/** @endcond */

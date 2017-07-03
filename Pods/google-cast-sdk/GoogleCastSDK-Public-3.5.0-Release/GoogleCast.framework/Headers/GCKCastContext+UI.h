// Copyright 2016 Google Inc.

/** @cond ENABLE_FEATURE_GUI */

#import <GoogleCast/GCKCastContext.h>

#import <GoogleCast/GCKCommon.h>
#import <GoogleCast/GCKDefines.h>

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class GCKUICastContainerViewController;
@class GCKUIExpandedMediaControlsViewController;
@class GCKUIMiniMediaControlsViewController;
@protocol GCKUIImageCache;
@protocol GCKUIImagePicker;

GCK_ASSUME_NONNULL_BEGIN

/**
 * The name of the notification that will be published when the expanded media controls should be
 * presented to users.
 *
 * @memberof GCKUICastContainerViewController
 */
#ifdef USE_CAST_DYNAMIC_FRAMEWORK
#define kGCKExpandedMediaControlsTriggeredNotification \
  GCK_EXTERN_NSSTRING(kGCKExpandedMediaControlsTriggeredNotification)
#else
GCK_EXTERN NSString *const kGCKExpandedMediaControlsTriggeredNotification;
#endif

/**
 * The name of the notification that will be published when the Cast dialog is about to be shown.
 *
 * @memberof GCKCastContext
 * @since 3.4
 */
#ifdef USE_CAST_DYNAMIC_FRAMEWORK
#define kGCKUICastDialogWillShowNotification \
GCK_EXTERN_NSSTRING(kGCKUICastDialogWillShowNotification)
#else
GCK_EXTERN NSString *const kGCKUICastDialogWillShowNotification;
#endif

/**
 * The name of the notification that will be published when the Cast dialog has been dismissed.
 *
 * @memberof GCKCastContext
 * @since 3.4
 */
#ifdef USE_CAST_DYNAMIC_FRAMEWORK
#define kGCKUICastDialogDidHideNotification \
GCK_EXTERN_NSSTRING(kGCKUICastDialogDidHideNotification)
#else
GCK_EXTERN NSString *const kGCKUICastDialogDidHideNotification;
#endif

/**
 * A category on GCKCastContext containing UI-specific APIs.
 *
 * @since 3.0
 */
@interface GCKCastContext (UI)

/**
 * The image cache implementation that will be used by the framework to fetch images that are
 * referenced in media metadata. A default implementation will be used if one is not provided by the
 * application. May be set to <code>nil</code> to reinstate the default image cache.
 */
@property(nonatomic, strong, readwrite, GCK_NULLABLE) id<GCKUIImageCache> imageCache;

/**
 * The image picker implementation that will be used to select an image for a specific purpose.
 * A default implementation will be used if one is not provided by the application. May be set to
 * <code>nil</code> to reinstate the default image picker.
 */
@property(nonatomic, strong, readwrite, GCK_NULLABLE) id<GCKUIImagePicker> imagePicker;

/**
 * Displays the Cast dialog.
 */
- (void)presentCastDialog;

/**
 * Constructs a GCKUICastContainerViewController that embeds the given view controller.
 */
- (GCKUICastContainerViewController *)createCastContainerControllerForViewController:
    (UIViewController *)viewController;

/**
 * Constructs a GCKUIMiniMediaControlsViewController.
 */
- (GCKUIMiniMediaControlsViewController *)createMiniMediaControlsViewController;

/**
 * If it has not been shown before, presents a fullscreen modal view controller that calls attention
 * to the Cast button and displays some brief instructional text about its use.
 *
 * @return <code>YES</code> if the view controller was shown, <code>NO</code> if it was not shown
 * because it had already been shown before.
 */
- (BOOL)presentCastInstructionsViewControllerOnce;

/**
 * Clears the persistent flag that tracks whether the Cast instructions modal view controller has
 * been shown.
 */
- (void)clearCastInstructionsShownFlag;

/**
 * Displays the default Cast expanded media controls.
 */
- (void)presentDefaultExpandedMediaControls;

/**
 * Configures the behavior of the Framework when there's a user action that should result in the
 * presentation of the expanded controls. If <code>YES</code>, the Framework will present the
 * default expaned controls view. If <code>NO</code>, the Framework will just trigger a
 * @ref GCKUICastContainerViewController::kGCKExpandedMediaControlsTriggeredNotification.
 */
@property(nonatomic, assign, readwrite) BOOL useDefaultExpandedMediaControls;

/**
 * The instance of the default Cast expanded media controls view controller.
 */
@property(nonatomic, strong, readonly)
    GCKUIExpandedMediaControlsViewController *defaultExpandedMediaControlsViewController;

@end

GCK_ASSUME_NONNULL_END

/** @endcond */

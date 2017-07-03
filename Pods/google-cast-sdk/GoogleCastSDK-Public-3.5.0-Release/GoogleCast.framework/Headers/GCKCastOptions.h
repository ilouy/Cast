// Copyright 2015 Google Inc.

#import <GoogleCast/GCKDefines.h>

#import <Foundation/Foundation.h>

@class GCKLaunchOptions;

GCK_ASSUME_NONNULL_BEGIN

/**
 * Options that affect the discovery of Cast devices and the behavior of Cast sessions. Writable
 * properties must be set before passing this object to the GCKCastContext.
 *
 * @since 3.0
 */
GCK_EXPORT
@interface GCKCastOptions : NSObject <NSCopying>

/**
 * Constructs a new GCKCastOptions object with the specified receiver application ID.
 *
 * @param applicationID The ID of the receiver application which must be supported by discovered
 * Cast devices, and which will be launched when starting a new Cast session.
 */
- (instancetype)initWithReceiverApplicationID:(NSString *)applicationID;

/**
 * Constructs a new GCKCastOptions object with the specified list of namespaces.
 *
 * @param namespaces A list of namespaces which must be supported by the currently running receiver
 * application on each discovered Cast device.
 */
- (instancetype)initWithSupportedNamespaces:(NSArray<NSString *> *)namespaces;

/**
 * A flag indicating whether the sender device's physical volume buttons should control the
 * session's volume.
 */
@property(nonatomic, assign, readwrite) BOOL physicalVolumeButtonsWillControlDeviceVolume;

/**
 * A flag indicating whether the discovery of Cast devices should start automatically at
 * context initialization time. If set to <code>NO</code>, discovery can be started and stopped
 * on-demand by using the methods GCKDiscoveryManager::startDiscovery and
 * GCKDiscoveryManager::stopDiscovery.
 *
 * @since 3.4
 */
@property(nonatomic, assign, readwrite) BOOL disableDiscoveryAutostart;

/**
 * The receiver launch options to use when starting a Cast session.
 */
@property(nonatomic, copy, readwrite, GCK_NULLABLE) GCKLaunchOptions *launchOptions;

/**
 * The shared container identifier to use for background HTTP downloads that are performed by the
 * framework.
 *
 * @since 3.2
 */
@property(nonatomic, copy, readwrite, GCK_NULLABLE) NSString *sharedContainerIdentifier;

/**
 * Whether sessions should be suspended when the sender application goes into the background (and
 * resumed when it returns to the foreground). By default this option is set to <code>YES</code>.
 * It is appropriate to set this to <code>NO</code> in applications that are able to maintain
 * network connections indefinitely while in the background.
 *
 * @since 3.4
 */
@property(nonatomic, assign, readwrite) BOOL suspendSessionsWhenBackgrounded;

@end

GCK_ASSUME_NONNULL_END

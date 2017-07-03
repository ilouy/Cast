// Copyright 2013 Google Inc.

#import <GoogleCast/GCKDefines.h>

#import <Foundation/Foundation.h>

#ifdef USE_CAST_DYNAMIC_FRAMEWORK
#define GCKCastChannelClass NSClassFromString(@"GCKCastChannel")
#endif

@class GCKDeviceManager;
@class GCKError;

GCK_ASSUME_NONNULL_BEGIN

/**
 * A virtual communication channel for exchanging messages between a Cast sender and a Cast
 * receiver. Each channel is tagged with a unique namespace, so multiple channels may be multiplexed
 * over a single network connection between a sender and a receiver.
 *
 * A channel must be registered with a GCKCastSession before it can be used. When the associated
 * session is established, the channel will be connected automatically and can then send and receive
 * messages.
 *
 * Subclasses should implement the @ref didReceiveTextMessage: method to process incoming messages,
 * and will typically provide additional methods for sending messages that are specific to a given
 * namespace.
 */
GCK_EXPORT
@interface GCKCastChannel : NSObject

/** The channel's namespace. */
@property(nonatomic, copy, readonly) NSString *protocolNamespace;

/** A flag indicating whether this channel is currently connected. */
@property(nonatomic, assign, readonly) BOOL isConnected;

/**
 * The device manager with which this channel is registered, if any.
 *
 * @deprecated If this channel was not registered with the deprecated GCKDeviceManager class, this
 * will be <code>nil</code>.
 */
@property(nonatomic, weak, readonly) GCKDeviceManager *deviceManager;

/**
 * Designated initializer. Constructs a new GCKCastChannel with the given namespace.
 *
 * @param protocolNamespace The namespace.
 */
- (instancetype)initWithNamespace:(NSString *)protocolNamespace;

/**
 * Default initializer is not available.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 * Called when a text message has been received on this channel. The default implementation is a
 * no-op.
 *
 * @param message The message.
 */
- (void)didReceiveTextMessage:(NSString *)message;

/**
 * Sends a text message on this channel.
 *
 * @param message The message.
 * @return <code>YES</code> on success or <code>NO</code> if the message could not be sent (because
 * the channel is not connected, or because the send buffer is too full at the moment).
 *
 * @deprecated Use @ref sendTextMessage:error: which provides detailed error information.
 */
- (BOOL)sendTextMessage:(NSString *)message GCK_DEPRECATED("Use sendTextMessage:error:");

/**
 * Sends a text message on this channel.
 *
 * @param message The message.
 * @param error A pointer at which to store the error result. May be <code>nil</code>.
 * @return <code>YES</code> on success or <code>NO</code> if the message could not be sent.
 */
- (BOOL)sendTextMessage:(NSString *)message
                  error:(GCKError *GCK_NULLABLE_TYPE *GCK_NULLABLE_TYPE)error;

/**
 * Generates a request ID for a new message.
 *
 * @return The generated ID, or @ref kGCKInvalidRequestID if the channel is not currently connected.
 */
- (NSInteger)generateRequestID;

/**
 * A convenience method which wraps the result of @ref generateRequestID in an
 * <a href="https://goo.gl/gY6NGU"><b>NSNumber</b></a>.
 *
 * @return The generated ID, or <code>nil</code> if the channel is not currently connected.
 */
- (NSNumber * GCK_NULLABLE_TYPE)generateRequestNumber;

/**
 * Called when this channel has been connected, indicating that messages can now be exchanged with
 * the Cast device over this channel. The default implementation is a no-op.
 */
- (void)didConnect;

/**
 * Called when this channel has been disconnected, indicating that messages can no longer be
 * exchanged with the Cast device over this channel. The default implementation is a no-op.
 */
- (void)didDisconnect;

@end

GCK_ASSUME_NONNULL_END

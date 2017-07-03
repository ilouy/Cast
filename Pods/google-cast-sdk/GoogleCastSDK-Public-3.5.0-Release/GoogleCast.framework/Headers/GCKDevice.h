// Copyright 2012 Google Inc.

#import <GoogleCast/GCKDefines.h>

#import <Foundation/Foundation.h>

#ifdef USE_CAST_DYNAMIC_FRAMEWORK
#define GCKDeviceClass NSClassFromString(@"GCKDevice")
#endif

/**
 * @file GCKDevice.h
 * GCKDeviceStatus, GCKDeviceCapability, and GCKDeviceType enums.
 */

GCK_ASSUME_NONNULL_BEGIN

/**
 * @enum GCKDeviceStatus
 * Enum defining the device status at the time the device was scanned.
 */
typedef NS_ENUM(NSInteger, GCKDeviceStatus) {
  /** Unknown status. */
  GCKDeviceStatusUnknown = -1,
  /** Idle device status. */
  GCKDeviceStatusIdle = 0,
  /** Busy/join device status. */
  GCKDeviceStatusBusy = 1,
};

/**
 * @enum GCKDeviceCapability
 * Enum defining the capabilities of a receiver device.
 */
typedef NS_ENUM(NSInteger, GCKDeviceCapability) {
  /** The device has video-out capability. */
  GCKDeviceCapabilityVideoOut = 1 << 0,
  /** The device has video-in capability. */
  GCKDeviceCapabilityVideoIn = 1 << 1,
  /** The device has audio-out capability. */
  GCKDeviceCapabilityAudioOut = 1 << 2,
  /** The device has audio-in capability. */
  GCKDeviceCapabilityAudioIn = 1 << 3,
  /** The device has multizone group capability. */
  GCKDeviceCapabilityMultizoneGroup = 1 << 5,
  /** The device has master or fixed volume mode capability. */
  GCKDeviceCapabilityMasterOrFixedVolume = 1 << 11,
  /** The device has attenuation or fixed volume mode capability. */
  GCKDeviceCapabilityAttenuationOrFixedVolume = 1 << 12,
};

/**
 * @enum GCKDeviceType
 * Device types.
 * @since 3.3
 */
typedef NS_ENUM(NSInteger, GCKDeviceType) {
  /** Generic Cast device. */
  GCKDeviceTypeGeneric = 0,
  /** Cast-enabled TV. */
  GCKDeviceTypeTV,
  /** Cast-enabled speaker or other audio device. */
  GCKDeviceTypeSpeaker,
  /** Speaker group. */
  GCKDeviceTypeSpeakerGroup,
  /**
   * The "Nearby Devices" pseudo-device, which represents any nearby unpaired guest-mode devices.
   */
  GCKDeviceTypeNearbyUnpaired
};

/** @deprecated Use @ref GCKDeviceCapabilityVideoOut. */
GCK_EXTERN
const NSInteger kGCKDeviceCapabilityVideoOut GCK_DEPRECATED("Use GCKDeviceCapabilityVideoOut");
/** @deprecated Use @ref GCKDeviceCapabilityVideoIn. */
GCK_EXTERN
const NSInteger kGCKDeviceCapabilityVideoIn GCK_DEPRECATED("Use GCKDeviceCapabilityVideoIn");
/** @deprecated Use @ref GCKDeviceCapabilityAudioOut. */
GCK_EXTERN
const NSInteger kGCKDeviceCapabilityAudioOut GCK_DEPRECATED("Use GCKDeviceCapabilityAudioOut");
/** @deprecated Use @ref GCKDeviceCapabilityAudioIn. */
GCK_EXTERN
const NSInteger kGCKDeviceCapabilityAudioIn GCK_DEPRECATED("Use GCKDeviceCapabilityAudioIn");

/**
 * @var kGCKCastDeviceCategory
 * The device category that identifies Cast devices.
 */
#ifdef USE_CAST_DYNAMIC_FRAMEWORK
#define kGCKCastDeviceCategory GCK_EXTERN_NSSTRING(kGCKCastDeviceCategory)
#else
GCK_EXTERN NSString *const kGCKCastDeviceCategory;
#endif

@class GCKImage;

/**
 * An object representing a receiver device.
 */
GCK_EXPORT
@interface GCKDevice : NSObject <NSCopying, NSCoding>

/** The device's IPv4 address, in dot-notation. Used when making network requests. */
@property(nonatomic, copy, readonly) NSString *ipAddress;

/** The device's service port. */
@property(nonatomic, assign, readonly) uint16_t servicePort;

/** A unique identifier for the device. */
@property(nonatomic, copy, readonly) NSString *deviceID;

/** The device's friendly name. This is a user-assignable name such as "Living Room". */
@property(nonatomic, copy, readwrite, GCK_NULLABLE) NSString *friendlyName;

/**
 * The device's manufacturer name.
 * @deprecated Use the modelName or custom attributes instead.
 */
@property(nonatomic, copy, readwrite, GCK_NULLABLE) NSString *manufacturer;

/** The device's model name. */
@property(nonatomic, copy, readwrite, GCK_NULLABLE) NSString *modelName;

/** An array of GCKImage objects containing icons for the device. */
@property(nonatomic, copy, readwrite, GCK_NULLABLE) NSArray<GCKImage *> *icons;

/** The device's status at the time that it was most recently scanned. */
@property(nonatomic, assign, readwrite) GCKDeviceStatus status;

/** The status text reported by the currently running receiver application, if any. */
@property(nonatomic, copy, readwrite, GCK_NULLABLE) NSString *statusText;

/** The device's protocol version. */
@property(nonatomic, copy, readwrite, GCK_NULLABLE) NSString *deviceVersion;

/** YES if this device is on the local network. */
@property(nonatomic, assign, readonly) BOOL isOnLocalNetwork;

/**
 * The device type.
 *
 * @since 3.3
 */
@property(nonatomic, assign, readonly) GCKDeviceType type;

/**
 * The device category, a string that uniquely identifies the type of device. Cast devices have
 * a category of @ref kGCKCastDeviceCategory.
 */
@property(nonatomic, copy, readonly) NSString *category;

/**
 * A globally unique ID for this device. This is a concatenation of the @ref category and
 * @ref deviceID properties.
 */
@property(nonatomic, copy, readonly) NSString *uniqueID;

/**
 * Tests if this device refers to the same physical device as another. Returns <code>YES</code> if
 * both GCKDevice objects have the same category, device ID, IP address, service port, and protocol
 * version.
 */
- (BOOL)isSameDeviceAs:(const GCKDevice *)other;

/**
 * Returns <code>YES</code> if the device supports the given capabilities.
 *
 * @param deviceCapabilities A bitwise-OR of one or more of the @ref GCKDeviceCapability constants.
 */
- (BOOL)hasCapabilities:(NSInteger)deviceCapabilities;

/**
 * Sets an arbitrary attribute in the object. May be used by custom device providers to store
 * device-specific information for non-Cast devices.
 *
 * @param attribute The attribute value, which must be key-value coding compliant, and cannot be
 * <code>nil</code>.
 * @param key The key that identifies the attribute. The key is an arbitrary string. It cannot be
 * <code>nil</code>.
 */
- (void)setAttribute:(NSObject<NSCoding> *)attribute forKey:(NSString *)key;

/**
 * Looks up an attribute in the object.
 *
 * @param key The key that identifies the attribute. The key is an arbitrary string. It cannot be
 * <code>nil</code>.
 * @return The value of the attribute, or <code>nil</code> if no such attribute exists.
 */
- (NSObject<NSCoding> * GCK_NULLABLE_TYPE)attributeForKey:(NSString *)key;

/**
 * Removes an attribute from the object.
 *
 * @param key The key that identifies the attribute. The key is an arbitrary string. It cannot be
 * <code>nil</code>.
 */
- (void)removeAttributeForKey:(NSString *)key;

/**
 * Removes all attributes from the object.
 */
- (void)removeAllAttributes;

@end

GCK_ASSUME_NONNULL_END

// Copyright 2014 Google Inc.

#import <GoogleCast/GCKDefines.h>

#import <Foundation/Foundation.h>

#ifdef USE_CAST_DYNAMIC_FRAMEWORK
#define GCKMediaTrackClass NSClassFromString(@"GCKMediaTrack")
#endif

/**
 * @file GCKMediaTrack.h
 * GCKMediaTrackType and GCKMediaTextTrackSubtype enums.
 */

GCK_ASSUME_NONNULL_BEGIN

/**
 * @enum GCKMediaTrackType
 * Media track types.
 */
typedef NS_ENUM(NSInteger, GCKMediaTrackType) {
  /** Unknown track type. */
  GCKMediaTrackTypeUnknown = 0,
  /** Text. */
  GCKMediaTrackTypeText = 1,
  /** Audio. */
  GCKMediaTrackTypeAudio = 2,
  /** Video. */
  GCKMediaTrackTypeVideo = 3,
};

/**
 * @enum GCKMediaTextTrackSubtype
 * Media text track subtypes.
 */
typedef NS_ENUM(NSInteger, GCKMediaTextTrackSubtype) {
  /** Unknown text track subtype. */
  GCKMediaTextTrackSubtypeUnknown = 0,
  /** Subtitles. */
  GCKMediaTextTrackSubtypeSubtitles = 1,
  /** Captions. */
  GCKMediaTextTrackSubtypeCaptions = 3,
  /** Descriptions. */
  GCKMediaTextTrackSubtypeDescriptions = 4,
  /** Chapters. */
  GCKMediaTextTrackSubtypeChapters = 5,
  /** Metadata. */
  GCKMediaTextTrackSubtypeMetadata = 6,
};

/**
 * A class representing a media track. Instances of this object are immutable.
 */
GCK_EXPORT
@interface GCKMediaTrack : NSObject <NSCopying, NSCoding>

/**
 * Designated initializer. Constructs a new GCKMediaTrack with the given property values.
 */
- (instancetype)initWithIdentifier:(NSInteger)identifier
                 contentIdentifier:(NSString *GCK_NULLABLE_TYPE)contentIdentifier
                       contentType:(NSString *)contentType
                              type:(GCKMediaTrackType)type
                       textSubtype:(GCKMediaTextTrackSubtype)textSubtype
                              name:(NSString *GCK_NULLABLE_TYPE)name
                      languageCode:(NSString *GCK_NULLABLE_TYPE)languageCode
                        customData:(id GCK_NULLABLE_TYPE)customData;

/** The track's unique numeric identifier. */
@property(nonatomic, assign, readonly) NSInteger identifier;

/** The track's content identifier, which may be <code>nil</code>. */
@property(nonatomic, copy, readonly, GCK_NULLABLE) NSString *contentIdentifier;

/** The track's content (MIME) type. */
@property(nonatomic, copy, readonly) NSString *contentType;

/** The track's type. */
@property(nonatomic, assign, readonly) GCKMediaTrackType type;

/** The text track's subtype; applies only to text tracks. */
@property(nonatomic, assign, readonly) GCKMediaTextTrackSubtype textSubtype;

/** The track's name, which may be <code>nil</code>. */
@property(nonatomic, copy, readonly, GCK_NULLABLE) NSString *name;

/** The track's RFC 1766 language code, which may be <code>nil</code>. */
@property(nonatomic, copy, readonly, GCK_NULLABLE) NSString *languageCode;

/**
 * The custom data, if any. Must either be an object that can be serialized to JSON using
 * <a href="https://goo.gl/0vd4Q2"><b>NSJSONSerialization</b></a>, or <code>nil</code>.
 */
@property(nonatomic, strong, readonly, GCK_NULLABLE) id customData;

@end

GCK_ASSUME_NONNULL_END

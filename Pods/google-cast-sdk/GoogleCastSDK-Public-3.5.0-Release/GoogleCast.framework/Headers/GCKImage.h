// Copyright 2013 Google Inc.

#import <GoogleCast/GCKDefines.h>

#import <Foundation/Foundation.h>

#ifdef USE_CAST_DYNAMIC_FRAMEWORK
#define GCKImageClass NSClassFromString(@"GCKImage")
#endif

GCK_ASSUME_NONNULL_BEGIN

/**
 * A class that represents an image that is located on a web server. Used for such things as
 * GCKDevice icons and GCKMediaMetadata artwork.
 */
GCK_EXPORT
@interface GCKImage : NSObject <NSCopying, NSCoding>

/**
 * The image URL.
 */
@property(nonatomic, strong, readonly) NSURL *URL;

/**
 * The image width, in pixels.
 */
@property(nonatomic, assign, readonly) NSInteger width;

/**
 * The image height, in pixels.
 */
@property(nonatomic, assign, readonly) NSInteger height;

/**
 * Constructs a new GCKImage with the given URL and dimensions. Designated initializer.
 *
 * @param URL The URL of the image.
 * @param width The width of the image, in pixels.
 * @param height The height of the image, in pixels.
 * @throw NSInvalidArgumentException if the URL is <code>nil</code> or empty, or the dimensions are
 * invalid.
 */
- (instancetype)initWithURL:(NSURL *)URL width:(NSInteger)width height:(NSInteger)height;

/**
 * Default initializer is not available.
 */
- (instancetype)init NS_UNAVAILABLE;

@end

GCK_ASSUME_NONNULL_END

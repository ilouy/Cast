// Copyright 2012 Google Inc.

#import <GoogleCast/GCKDefines.h>

#import <Foundation/Foundation.h>

GCK_ASSUME_NONNULL_BEGIN

/**
 * A category that adds some convenience methods to
 * <a href="https://goo.gl/0kFoNp"><b>NSDictionary</b></a> for setting and safely looking up
 * values of various types. These methods are particularly useful for getting and setting fields of
 * JSON data objects.
 */
@interface NSDictionary (GCKAdditions)

/**
 * Looks up an <a href="https://goo.gl/5dXzU6"><b>NSString</b></a> value for a key, with a given
 * fallback value.
 *
 * @param key The key.
 * @param defaultValue The default value to return if the key is not found or if its value is not
 * an <a href="https://goo.gl/5dXzU6"><b>NSString</b></a>.
 * @return The value of the key, if it was found and was an
 * <a href="https://goo.gl/5dXzU6"><b>NSString</b></a>; otherwise the default value.
 */
- (NSString *GCK_NULLABLE_TYPE)gck_stringForKey:(NSString *)key
                               withDefaultValue:(NSString *GCK_NULLABLE_TYPE)defaultValue;

/**
 * Looks up an <a href="https://goo.gl/5dXzU6"><b>NSString</b></a> value for a key, with a fallback
 * value of <code>nil</code>.
 *
 * @param key The key.
 * @return The value of the key, if found it was found and was an
 * <a href="https://goo.gl/5dXzU6"><b>NSString</b></a>; otherwise <code>nil</code>.
 */
- (NSString *GCK_NULLABLE_TYPE)gck_stringForKey:(NSString *)key;

/**
 * Looks up an <a href="https://goo.gl/hQFeav"><b>NSInteger</b></a> value for a key, with a given
 * fallback value.
 *
 * @param key The key.
 * @param defaultValue The default value to return if the key is not found or if its value is not
 * an <a href="https://goo.gl/gY6NGU"><b>NSNumber</b></a>.
 * @return The value of the key, if it was found and was an
 * <a href="https://goo.gl/gY6NGU"><b>NSNumber</b></a>; otherwise the default value.
 */
- (NSInteger)gck_integerForKey:(NSString *)key withDefaultValue:(NSInteger)defaultValue;

/**
 * Looks up an <a href="https://goo.gl/hQFeav"><b>NSUInteger</b></a> value for a key, with a given
 * fallback value.
 *
 * @param key The key.
 * @param defaultValue The default value to return if the key is not found or if its value is not
 * an <a href="https://goo.gl/gY6NGU"><b>NSNumber</b></a>.
 * @return The value of the key, if it was found and was an
 * <a href="https://goo.gl/gY6NGU"><b>NSNumber</b></a>; otherwise the default value.
 */
- (NSUInteger)gck_uintegerForKey:(NSString *)key withDefaultValue:(NSUInteger)defaultValue;

/**
 * Looks up an <a href="https://goo.gl/hQFeav"><b>NSInteger</b></a> value for a key, with a fallback
 * value of <code>0</code>.
 *
 * @param key The key.
 * @return The value of the key, if it was found and was an
 * <a href="https://goo.gl/gY6NGU"><b>NSNumber</b></a>; otherwise <code>0</code>.
 */
- (NSInteger)gck_integerForKey:(NSString *)key;

/**
 * Looks up an <a href="https://goo.gl/hQFeav"><b>NSUInteger</b></a> value for a key, with a
 * fallback value of <code>0</code>.
 *
 * @param key The key.
 * @return The value of the key, if it was found and was an
 * <a href="https://goo.gl/gY6NGU"><b>NSNumber</b></a>; otherwise <code>0</code>.
 */
- (NSUInteger)gck_uintegerForKey:(NSString *)key;

/**
 * Looks up a <b>double</b> value for a key, with a given fallback value.
 *
 * @param key The key.
 * @param defaultValue The default value to return if the key is not found or if its value is not
 * an <a href="https://goo.gl/gY6NGU"><b>NSNumber</b></a>.
 * @return The value of the key, if it was found and was an
 * <a href="https://goo.gl/gY6NGU"><b>NSNumber</b></a>; otherwise the default value.
 */
- (double)gck_doubleForKey:(NSString *)key withDefaultValue:(double)defaultValue;

/**
 * Looks up a <b>double</b> value for a key, with a fallback value of <code>0.0</code>.
 *
 * @param key The key.
 * @return The value of the key, if it was found and was an
 * <a href="https://goo.gl/gY6NGU"><b>NSNumber</b></a>; otherwise <code>0.0</code>.
 */
- (double)gck_doubleForKey:(NSString *)key;

/**
 * Looks up a <b>BOOL</b> value for a key, with a given fallback value.
 *
 * @param key The key.
 * @param defaultValue The default value to return if the key is not found or if its value is not
 * an <a href="https://goo.gl/gY6NGU"><b>NSNumber</b></a>.
 * @return The value of the key, if it was found and was an
 * <a href="https://goo.gl/gY6NGU"><b>NSNumber</b></a>; otherwise the default value.
 */
- (BOOL)gck_boolForKey:(NSString *)key withDefaultValue:(BOOL)defaultValue;

/**
 * Looks up a <b>BOOL</b> value for a key, with a fallback value of <code>NO</code>.
 *
 * @param key The key.
 * @return The value of the key, if it was found and was an
 * <a href="https://goo.gl/gY6NGU"><b>NSNumber</b></a>; otherwise <code>NO</code>.
 */
- (BOOL)gck_boolForKey:(NSString *)key;

/**
 * Looks up an <a href="https://goo.gl/0kFoNp"><b>NSDictionary</b></a> value for a key, with a
 * fallback value of <code>nil</code>.
 *
 * @param key The key.
 * @return The value of the key, if it was found and was an
 * <a href="https://goo.gl/0kFoNp"><b>NSDictionary</b></a>; otherwise <code>nil</code>.
 */
- (NSDictionary *GCK_NULLABLE_TYPE)gck_dictionaryForKey:(NSString *)key;

/**
 * Looks up an <a href="https://goo.gl/q3tY5n"><b>NSArray</b></a> value for a key, with a fallback
 * value of <code>nil</code>.
 *
 * @param key The key.
 * @return The value of the key, if it was found and was an
 * <a href="https://goo.gl/q3tY5n"><b>NSArray</b></a>; otherwise <code>nil</code>.
 */
- (NSArray *GCK_NULLABLE_TYPE)gck_arrayForKey:(NSString *)key;

/**
 * Looks up an <a href="https://goo.gl/CGrMHD"><b>NSURL</b></a> value for a key, with a fallback
 * value of <code>nil</code>.
 *
 * @param key The key.
 * @return The value of the key as an <a href="https://goo.gl/CGrMHD"><b>NSURL</b></a>, if it was
 * found and was an <a href="https://goo.gl/5dXzU6"><b>NSString</b></a>; otherwise <code>nil</code>.
 */
- (NSURL *GCK_NULLABLE_TYPE)gck_urlForKey:(NSString *)key;

/**
 * Sets an <a href="https://goo.gl/5dXzU6"><b>NSString</b></a> value for a key.
 *
 * @param value The value.
 * @param key The key.
 */
- (void)gck_setStringValue:(NSString *)value forKey:(NSString *)key;

/**
 * Sets an <a href="https://goo.gl/hQFeav"><b>NSInteger</b></a> value for a key.
 *
 * @param value The value.
 * @param key The key.
 */
- (void)gck_setIntegerValue:(NSInteger)value forKey:(NSString *)key;

/**
 * Sets an <a href="https://goo.gl/hQFeav"><b>NSUInteger</b></a> value for a key.
 *
 * @param value The value.
 * @param key The key.
 */
- (void)gck_setUIntegerValue:(NSUInteger)value forKey:(NSString *)key;

/**
 * Sets a <b>double</b> value for a key.
 *
 * @param value The value.
 * @param key The key.
 */
- (void)gck_setDoubleValue:(double)value forKey:(NSString *)key;

/**
 * Sets a <b>BOOL</b> value for a key.
 *
 * @param value The value.
 * @param key The key.
 */
- (void)gck_setBoolValue:(BOOL)value forKey:(NSString *)key;

@end

GCK_ASSUME_NONNULL_END

// For backwards compatibility:
#ifndef GCKTypedValueLookup
#define GCKTypedValueLookup GCKAdditions
#endif

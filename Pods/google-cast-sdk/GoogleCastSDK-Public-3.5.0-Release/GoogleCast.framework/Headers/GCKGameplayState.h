// Copyright 2014 Google Inc.

/** @cond ENABLE_FEATURE_GAME_MANAGER */

#import <Foundation/Foundation.h>

/**
 * @file GCKGameplayState.h
 * GCKGameplayState enum
 */

/**
 * @enum GCKGameplayState
 * An enum describing gameplay states.
 *
 * @deprecated The Game Manager API is no longer supported and will be removed in a future release.
 */
typedef NS_ENUM(NSInteger, GCKGameplayState) {
  /**
   * Unknown gameplay state.
   */
  GCKGameplayStateUnknown = 0,
  /**
   * Game state for game is loading.
   */
  GCKGameplayStateLoading = 1,
  /**
   * Game state for game is running.
   */
  GCKGameplayStateRunning = 2,
  /**
   * Game state for game is paused.
   */
  GCKGameplayStatePaused = 3,
  /**
   * Game state for game is showing an information screen.
   */
  GCKGameplayStateShowingInfoScreen = 4
};

/** @endcond */

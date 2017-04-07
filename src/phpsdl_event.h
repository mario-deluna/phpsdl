//
//  phpsdl_event.hpp
//  phpsdl
//
//  Created by Mario Döring on 07.04.17.
//  Copyright © 2017 Mario Döring. All rights reserved.
//

#ifndef phpsdl_event_h
#define phpsdl_event_h

#include <phpcpp.h>
#include <SDL2/SDL.h>

const int PHPSDL_FIRSTEVENT     = SDL_FIRSTEVENT,     /**< Unused (do not remove) */

/* Application events */
const int PHPSDL_QUIT           = SDL_QUIT, /**< User-requested quit */

/* These application events have special meaning on iOS, see README-ios.md for details */
const int PHPSDL_APP_TERMINATING,        /**< The application is being terminated by the OS
                             Called on iOS in applicationWillTerminate()
                             Called on Android in onDestroy()
                             */
const int PHPSDL_APP_LOWMEMORY,          /**< The application is low on memory, free memory if possible.
                             Called on iOS in applicationDidReceiveMemoryWarning()
                             Called on Android in onLowMemory()
                             */
const int PHPSDL_APP_WILLENTERBACKGROUND, /**< The application is about to enter the background
                              Called on iOS in applicationWillResignActive()
                              Called on Android in onPause()
                              */
const int PHPSDL_APP_DIDENTERBACKGROUND, /**< The application did enter the background and may not get CPU for some time
                             Called on iOS in applicationDidEnterBackground()
                             Called on Android in onPause()
                             */
const int PHPSDL_APP_WILLENTERFOREGROUND, /**< The application is about to enter the foreground
                              Called on iOS in applicationWillEnterForeground()
                              Called on Android in onResume()
                              */
const int PHPSDL_APP_DIDENTERFOREGROUND, /**< The application is now interactive
                             Called on iOS in applicationDidBecomeActive()
                             Called on Android in onResume()
                             */

/* Window events */
const int PHPSDL_WINDOWEVENT    = SDL_WINDOWEVENT, /**< Window state change */
const int PHPSDL_SYSWMEVENT,             /**< System specific event */

/* Keyboard events */
const int PHPSDL_KEYDOWN        = SDL_KEYDOWN, /**< Key pressed */
const int PHPSDL_KEYUP,                  /**< Key released */
const int PHPSDL_TEXTEDITING,            /**< Keyboard text editing (composition) */
const int PHPSDL_TEXTINPUT,              /**< Keyboard text input */
const int PHPSDL_KEYMAPCHANGED,          /**< Keymap changed due to a system event such as an
                             input language or keyboard layout change.
                             */

/* Mouse events */
const int PHPSDL_MOUSEMOTION    = SDL_MOUSEMOTION, /**< Mouse moved */
const int PHPSDL_MOUSEBUTTONDOWN,        /**< Mouse button pressed */
const int PHPSDL_MOUSEBUTTONUP,          /**< Mouse button released */
const int PHPSDL_MOUSEWHEEL,             /**< Mouse wheel motion */

/* Joystick events */
const int PHPSDL_JOYAXISMOTION  = SDL_JOYAXISMOTION, /**< Joystick axis motion */
const int PHPSDL_JOYBALLMOTION,          /**< Joystick trackball motion */
const int PHPSDL_JOYHATMOTION,           /**< Joystick hat position change */
const int PHPSDL_JOYBUTTONDOWN,          /**< Joystick button pressed */
const int PHPSDL_JOYBUTTONUP,            /**< Joystick button released */
const int PHPSDL_JOYDEVICEADDED,         /**< A new joystick has been inserted into the system */
const int PHPSDL_JOYDEVICEREMOVED,       /**< An opened joystick has been removed */

/* Game controller events */
const int PHPSDL_CONTROLLERAXISMOTION  = SDL_CONTROLLERAXISMOTION, /**< Game controller axis motion */
const int PHPSDL_CONTROLLERBUTTONDOWN,          /**< Game controller button pressed */
const int PHPSDL_CONTROLLERBUTTONUP,            /**< Game controller button released */
const int PHPSDL_CONTROLLERDEVICEADDED,         /**< A new Game controller has been inserted into the system */
const int PHPSDL_CONTROLLERDEVICEREMOVED,       /**< An opened Game controller has been removed */
const int PHPSDL_CONTROLLERDEVICEREMAPPED,      /**< The controller mapping was updated */

/* Touch events */
const int PHPSDL_FINGERDOWN      = SDL_FINGERDOWN,
const int PHPSDL_FINGERUP,
const int PHPSDL_FINGERMOTION,

/* Gesture events */
const int PHPSDL_DOLLARGESTURE   = SDL_DOLLARGESTURE,
const int PHPSDL_DOLLARRECORD,
const int PHPSDL_MULTIGESTURE,

/* Clipboard events */
const int PHPSDL_CLIPBOARDUPDATE = SDL_CLIPBOARDUPDATE, /**< The clipboard changed */

/* Drag and drop events */
const int PHPSDL_DROPFILE        = SDL_DROPFILE, /**< The system requests a file open */
const int PHPSDL_DROPTEXT,                 /**< text/plain drag-and-drop event */
const int PHPSDL_DROPBEGIN,                /**< A new set of drops is beginning (NULL filename) */
const int PHPSDL_DROPCOMPLETE,             /**< Current set of drops is now complete (NULL filename) */

/* Audio hotplug events */
const int PHPSDL_AUDIODEVICEADDED = SDL_AUDIODEVICEADDED, /**< A new audio device is available */
const int PHPSDL_AUDIODEVICEREMOVED,        /**< An audio device has been removed. */

/* Render events */
const int PHPSDL_RENDER_TARGETS_RESET = SDL_RENDER_TARGETS_RESET, /**< The render targets have been reset and their contents need to be updated */
const int PHPSDL_RENDER_DEVICE_RESET, /**< The device has been reset and all textures need to be recreated */

/** Events ::SDL_USEREVENT through ::SDL_LASTEVENT are for your use,
 *  and should be allocated with SDL_RegisterEvents()
 */
const int PHPSDL_USEREVENT    = SDL_USEREVENT,

/**
 *  This last event is only for bounding internal arrays
 */
const int PHPSDL_LASTEVENT    = SDL_LASTEVENT

/**
 * END OF CONSTANTS 
 * ---------
 */

/**
 * Pump events
 */
void PHPSDL_PumpEvents();

/**
 * Poll events
 */
Php::Value PHPSDL_PollEvent();

#endif /* phpsdl_event_h */

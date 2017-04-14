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

const int PHPSDL_FIRSTEVENT     = SDL_FIRSTEVENT;

/* Application events */
const int PHPSDL_QUIT           = SDL_QUIT;

/* Key Events */
const int PHPSDL_KEYDOWN         = SDL_KEYDOWN;
const int PHPSDL_KEYUP           = SDL_KEYUP;


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

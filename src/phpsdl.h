/**
 * PHP Sdl main header
 */
#ifndef PHPSDL_H_
#define PHPSDL_H_

#include <iostream>
#include <phpcpp.h>
#include <SDL2/SDL.h>

/**
 * Init SDL 
 * ---
 */
const int PHPSDL_INIT_TIMER    			= SDL_INIT_TIMER;
const int PHPSDL_INIT_AUDIO    			= SDL_INIT_AUDIO;
const int PHPSDL_INIT_VIDEO    			= SDL_INIT_VIDEO;
const int PHPSDL_INIT_JOYSTICK    		= SDL_INIT_JOYSTICK;
const int PHPSDL_INIT_HAPTIC    		= SDL_INIT_HAPTIC;
const int PHPSDL_INIT_GAMECONTROLLER    = SDL_INIT_GAMECONTROLLER;
const int PHPSDL_INIT_EVENTS    		= SDL_INIT_EVENTS;
const int PHPSDL_INIT_NOPARACHUTE    	= SDL_INIT_NOPARACHUTE;
const int PHPSDL_INIT_EVERYTHING    	= SDL_INIT_EVERYTHING;

Php::Value PHPSDL_Init(Php::Parameters &params);

/**
 * Quit SDL
 * ---
 */
void PHPSDL_Quit();

#endif /* PHPSDL_H_ */

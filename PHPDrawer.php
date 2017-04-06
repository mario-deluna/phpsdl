<?php
/**
 * SDL init
 */

if (SDL_Init(PHPSDL_INIT_VIDEO) != 0)
{
	die("Could not initalize SDL.");
}

$window = new SDLWindow("Hallo Window");

var_dump($window); die;
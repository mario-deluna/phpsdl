<?php
/**
 * SDL init
 */

if (SDL_Init(PHPSDL_INIT_TIMER) != 0)
{
	die("Could not initalize SDL.");
}

$window = SDL_CreateWindow();


<?php
/**
 * SDL init
 */

if (SDL_Init(SDL_INIT_VIDEO) != 0)
{
	die("Could not initalize SDL.");
}

$window = SDL_CreateWindow();


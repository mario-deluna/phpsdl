<?php
define('SCREEN_WIDTH', 640);
define('SCREEN_HEIGHT', 480);
define('SCREEN_FPS', 60);
define('SCREEN_TICKS_PER_FRAME', 1000 / SCREEN_FPS);

/**
 * SDL init
 */
if (SDL_Init(SDL_INIT_VIDEO) != 0)
{
	die("Could not initalize SDL.");
}

$window = new SDLWindow("Hallo Window");
$renderer = new SDLRenderer($window);

$running = true;
$countedFrames = 0;

while($running)
{
	$startTick = SDL_GetTicks();

	while ($event = SDL_PollEvent()) 
	{
		switch ($event) {
			case SDL_QUIT:
				$running = false;
				break;
			
			default:
				# code...
				break;
		}
	}

	$renderer->setDrawColor(33, 33, 33, 255);
	$renderer->clear();


	$renderer->setDrawColor(255, 255, 0, 255);

	$x = sin($countedFrames / 10) * 150;
	$y = cos($countedFrames / 10) * 270;

	$x += 100;
	$y += 100;

	$renderer->drawRect($x, $y, 50, 50);

	$renderer->present();

	// capping
	$countedFrames++;

	$ticks = (SDL_GetTicks() - $startTick);
	
	if ($ticks < SCREEN_TICKS_PER_FRAME) {
		SDL_Delay((int) (SCREEN_TICKS_PER_FRAME - $ticks));
	}
}


unset($window);

SDL_Quit();

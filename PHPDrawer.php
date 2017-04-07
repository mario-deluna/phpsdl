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

$squares = [];

for($i=0; $i<8000; $i++)
{
	$squares[] = [
		mt_rand(0, SCREEN_WIDTH), 
		mt_rand(0, SCREEN_HEIGHT),
		mt_rand(0, 50), // r
		mt_rand(0, 255) // c
	];
}

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


	

	foreach($squares as $square)
	{
		list($sx, $sy, $r, $c) = $square;

		$x = sin($countedFrames / 10) * $r;
		$y = cos($countedFrames / 10) * $r;

		$x += $sx + 50;
		$y += $sy + 50;

		$renderer->setDrawColor($c, $c, $c, 255);
		$renderer->drawRect($x, $y, 1, 1);
	}

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

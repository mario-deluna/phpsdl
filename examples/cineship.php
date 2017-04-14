<?php
define('SCREEN_WIDTH', 1000);
define('SCREEN_HEIGHT', 800);
define('SCREEN_FPS', 60);
define('SCREEN_TICKS_PER_FRAME', 1000 / SCREEN_FPS);

/**
 * SDL init
 */
if (SDL_Init(SDL_INIT_VIDEO) != 0)
{
	die("Could not initalize SDL.");
}

$window = new SDLWindow(
	"CineShip Battle Teleroyal",
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
	SCREEN_WIDTH, SCREEN_HEIGHT
);
$renderer = new SDLRenderer($window);

/**
 * Textures
 */
$shipTexture = new SDLTexture($renderer, __DIR__ . '/assets/cineship.png');
$shipThrustTexture = new SDLTexture($renderer, __DIR__ . '/assets/cineship-thrusting.png');

$enemyTextures = [
	new SDLTexture($renderer, __DIR__ . '/assets/enemy-0.png'),
	new SDLTexture($renderer, __DIR__ . '/assets/enemy-1.png'),
	new SDLTexture($renderer, __DIR__ . '/assets/enemy-2.png'),
	new SDLTexture($renderer, __DIR__ . '/assets/enemy-3.png'),
];

$enemyExplTextrures = [];
for($i=0;$i<=24;$i++)
{
	$enemyExplTextrures[$i] = new SDLTexture($renderer, __DIR__ . '/assets/explosion/en' . $i . '.png');
}

// Background
$backgroundL1 = new SDLTexture($renderer, __DIR__ . '/assets/starbg.png');
$backgroundL2 = new SDLTexture($renderer, __DIR__ . '/assets/starbg2.png');
$backgroundL3 = new SDLTexture($renderer, __DIR__ . '/assets/starbg3.png');

/**
 * The ship
 */ 
class CineShip 
{
	protected $mvX = 0;
	protected $mvY = 0;

	public $x = 0;
	public $y = 0;

	public $width = 150;
	public $height = 32;

	protected $spX = 0;
	protected $spY = 0;

	protected $bullets = [];

	public function handleKeyEvent($e, $k)
	{
		switch ($k) {
			case SDLK_a:
				$this->mvX = $e === SDL_KEYDOWN ? -1 : 0;
				break;
			case SDLK_d:
				$this->mvX = $e === SDL_KEYDOWN ? 1 : 0;
				break;
			case SDLK_w:
				$this->mvY = $e === SDL_KEYDOWN ? -1 : 0;
				break;
			case SDLK_s:
				$this->mvY = $e === SDL_KEYDOWN ? 1 : 0;
				break;
			case SDLK_SPACE:

				if ($e === SDL_KEYDOWN) {
					$this->fire();
				}
				
				break;
		}
	}

	public function draw($renderer)
	{
		$this->spX += $this->mvX;
		$this->spY += $this->mvY;

		$this->spX *= 0.95;
		$this->spY *= 0.95;

		$this->x += $this->spX;
		$this->y += $this->spY;

		global $shipTexture, $shipThrustTexture;

		if ($this->mvX === 0 && $this->mvY === 0)
		{
			$renderer->copy($shipTexture, $this->x, $this->y, $this->width, $this->height);
		} else {
			$renderer->copy($shipThrustTexture, $this->x, $this->y, $this->width, $this->height);
		}
		// $renderer->setDrawColor(255, 255, 255, 255);
		// $renderer->drawRect($this->x, $this->y, $this->width, $this->height);

		foreach ($this->bullets as $k => $bullet) 
		{
			if ($bullet->gone())
			{
				unset($this->bullets[$k]);
			} else {
				$bullet->draw($renderer);
			}
		}
	}	

	public function fire()
	{
		$this->bullets[] = new Bullet($this->x + 100, $this->y + $this->height / 2);
	}
}

class Bullet 
{
	protected $x = 0;
	protected $y = 0;

	protected $width = 100;

	public function __construct($x, $y)
	{
		$this->x = $x;
		$this->y = $y;
	}

	public function gone()
	{
		return $this->x > SCREEN_WIDTH;
	}

	public function draw($renderer)
	{
		$this->x += 50;

		global $enemies, $enemyCount, $enemyKills;

		foreach($enemies as $ek => $enemy)
		{
			if ($this->y >= $enemy->y && $this->y <= $enemy->y + 20)
			{
				if ($this->x + $this->width >= $enemy->x && $this->x <= $enemy->x + 20)
				{
					$enemy->kill();
				}
			}
		}

		$renderer->setDrawColor(223, 49, 64, 255);
		$renderer->drawRect($this->x, $this->y, $this->width, 2);
	}
}

class Enemy 
{
	public $x = 0;
	public $y = 0;

	public $width = 100;
	public $height = 17;

	public $offX;
	public $offXi;
	public $offY;
	public $offYi;

	protected $speed;

	protected $bulletWait = 0;
	protected $bullets = [];

	protected $currTexture = 0;

	protected $killed = false;
	protected $killTexture = 0;

	public function __construct()
	{
		$this->x = SCREEN_WIDTH + 50;
		$this->y = mt_rand(20, SCREEN_HEIGHT - 20);
		$this->speed = mt_rand(1, 10) / 2;

		$this->offX = $this->width + 10;
		$this->offXi = $this->offX * -1;
		$this->offY = $this->height + 10;
		$this->offYi = $this->offY * -1;
	}

	public function kill()
	{
		$this->killed = true;
		// unset($enemies[$ek]);
		// $enemyCount--;
		// $enemyKills++;
	}

	public function draw($renderer)
	{
		if ($this->killed)
		{
			global $enemies, $enemyCount, $enemyKills, $enemyExplTextrures;

			$renderer->copy($enemyExplTextrures[$this->killTexture], $this->x -10, $this->y - 50, 125, 97);
			$this->killTexture++;

			if ($this->killTexture === 25)
			{
				foreach($enemies as $ek => $enemy)
				{
					if ($enemy === $this)
					{
						$enemyCount--;
						$enemyKills++;
						unset($enemies[$ek]);

						return;
					}
				}
			}

			return;
		}

		global $cineship, $countedFrames, $enemies;

		$speed = $this->speed;

		$acX = (($cineship->x + 200) - $this->x) / SCREEN_HEIGHT * $speed * 3;
		$acY = ($cineship->y - $this->y) / SCREEN_HEIGHT * $speed * 8;

		foreach ($enemies as $ek => $buddy) 
		{	
			if ($buddy === $this)
			{
				continue;
			}

			$dstY = $this->y - $buddy->y;
			$dstX = $this->x - $buddy->x;
			if ($dstY < $this->offY && $dstY > 0 && $dstX < $this->offX && $dstX > 0)
			{
				$this->x += 1;
				$this->y += 1;
				break;
			} elseif ($dstY > $this->offYi && $dstY < 0 && $dstX > $this->offXi && $dstX < 0)
			{
				$this->x -= 1;
				$this->y -= 1;
				break;
			}
		}

		$this->x += $acX;
		$this->y += $acY;

		// get the textures
		global $enemyTextures;
			
		$renderer->copy($enemyTextures[$this->currTexture], $this->x, $this->y, $this->width, $this->height);

		$this->currTexture++;
		if ($this->currTexture == 4) {
			$this->currTexture = 0;
		}
		
		// $renderer->setDrawColor(200, 200, 200, 255);
		// $renderer->drawRect($this->x, $this->y, 20, 20);

		if ($this->bulletWait <= 0 && $this->y >= ($cineship->y - 10) && $this->y <= ($cineship->y + $cineship->height + 10))
		{
			$this->bullets[] = new EnemyBullet($this->x, $this->y + 10);
			$this->bulletWait = 30;
		}

		$this->bulletWait--;

		foreach ($this->bullets as $bk => $bullet) 
		{
			if ($bullet->gone()) {
				unset($this->bullets[$bk]);
			} else {
				$bullet->draw($renderer);
			}
		}
	}
}

class EnemyBullet 
{
	protected $x = 0;
	protected $y = 0;

	protected $speed = 20;

	public function __construct($x, $y)
	{
		$this->x = $x;
		$this->y = $y;
	}

	public function gone()
	{
		return $this->x < 0;
	}

	public function draw($renderer)
	{
		$this->x -= $this->speed;

		//var_dump($enemies); die;

		$renderer->setDrawColor(0, 255, 0, 255);
		$renderer->drawRect($this->x, $this->y, 50, 1);
	}
}

$running = true;
$countedFrames = 0;

$cineship = new CineShip();
$enemies = [];
$enemyCount = 0;
$enemyKills = 0;

// background
$backgroundX = 0;

while($running)
{
	$startTick = SDL_GetTicks();

	while ($event = SDL_PollEvent()) 
	{
		switch ($event[0]) {
			case SDL_QUIT:
				$running = false;
				break;
			
			case SDL_KEYDOWN:
			case SDL_KEYUP:

				if ($event[1] === SDLK_ESCAPE) {
					$running = false; break;
				}

				// handle any key up / down events on the instance itself.
				$cineship->handleKeyEvent($event[0], $event[1]);

			break;

			default:
				# code...
				break;
		}
	}

	$renderer->setDrawColor(33, 33, 33, 255);
	$renderer->clear();

	// draw the background
	$renderer->copy($backgroundL1, $backgroundX, 0, 1000, 800);
	$renderer->copy($backgroundL1, $backgroundX + 1000, 0, 1000, 800);
	$renderer->copy($backgroundL2, $backgroundX * 0.6, 0, 1000, 800);
	$renderer->copy($backgroundL2, ($backgroundX + 1000) * 0.6, 0, 1000, 800);
	$renderer->copy($backgroundL3, $backgroundX * 0.3, 0, 1000, 800);
	$renderer->copy($backgroundL3, ($backgroundX + 1000) * 0.3, 0, 1000, 800);
	$backgroundX -= 0.5;

	if ($backgroundX < -1000) {
		$backgroundX = 0;
	}

	// draw the ship instance
	$cineship->draw($renderer);

	if ($enemyCount < 1 + (round($enemyKills / 5)))
	{
		$enemies[] = new Enemy();
		$enemyCount++;
	}

	foreach ($enemies as $enemy) 
	{
		$enemy->draw($renderer);
	}
	
	// present the frame
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

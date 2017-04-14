<?php 

$width = 1000;
$height = 800;

$stars = 1000;

$img = imagecreatetruecolor($width, $height); 

imagesavealpha($img, true);
imagefill($img, 0, 0, imagecolorallocatealpha($img, 0, 0, 0, 127));

for($i=0; $i<$stars; $i++)
{
	$light = mt_rand(125, 255);
	$color = imagecolorallocate($img, $light, $light, $light);

	imagesetpixel($img, mt_rand(0, $width), mt_rand(0, $height), $color);
}

imagepng($img, __DIR__ . '/assets/starbg3.png');
imagedestroy($img);


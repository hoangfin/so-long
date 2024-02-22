#include "MLX42/MLX42.h"

static int get_rgba(int r, int g, int b, int a) {
  return (r << 24 | g << 16 | b << 8 | a);
}

/**
 * In MLX42 Colors are as follows:
 * 0000 0000 A (1st byte) -> uint8_t because it's 8 bits
 * 0000 0000 R (2nd byte)
 * 0000 0000 G (3rd byte)
 * 0000 0000 B (4th byte)
 **/
int32_t mlx_get_pixel(mlx_texture_t* image, uint32_t x, uint32_t y) {
  if (x > image->width || y > image->height)
    return 0xFF000000;
  uint8_t* pixelstart = image->pixels + (y * image->width + x) * sizeof(int32_t);
  return get_rgba(*(pixelstart), *(pixelstart + 1),
    * (pixelstart + 2), *(pixelstart + 3));
}

int32_t	main(void)
{
	mlx_t			*mlx;
	mlx_texture_t	*texture;
	mlx_image_t		*image;
	uint32_t		w;
	uint32_t		h;

	mlx = mlx_init(500, 500, "Test", true);
	texture = mlx_load_png("assets/textures/bonus/collectible-sprite.png");
	image = mlx_new_image(mlx, 128, 128);
	for (h = 0; h < image->height; h++)
	{
		for (w = 0; w < image->width; w++)
		{
			mlx_put_pixel(image, w, h, mlx_get_pixel(texture, w + 128, h));
		}
	}
	mlx_resize_image(image, 64, 64);
	mlx_image_to_window(mlx, image, 50, 50);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
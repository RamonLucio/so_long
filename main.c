/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 22:55:54 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/12/16 19:56:35 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_no_event(t_ptr *ptr_to)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ptr_to->tile.img = mlx_xpm_file_to_image(ptr_to->mlx, "assets/tile.xpm",
			&ptr_to->tile.width, &ptr_to->tile.height);
	while (j < 512)
	{
		while (i < 512)
		{
			mlx_put_image_to_window(
				ptr_to->mlx, ptr_to->win, ptr_to->tile.img, i, j);
			i += 16;
		}
		i = 0;
		j += 16;
	}
	mlx_destroy_image(ptr_to->mlx, ptr_to->tile.img);
	return (0);
}

int	escape_window(int keycode, t_ptr *ptr_to)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(ptr_to->mlx, ptr_to->win);
		mlx_destroy_display(ptr_to->mlx);
		free(ptr_to->mlx);
		exit(0);
	}
	return (0);
}

int	close_window(t_ptr *ptr_to)
{
	mlx_destroy_window(ptr_to->mlx, ptr_to->win);
	mlx_destroy_display(ptr_to->mlx);
	free(ptr_to->mlx);
	exit(0);
	return (0);
}

int	main(void)
{
	t_ptr	ptr_to;

	ptr_to.mlx = mlx_init();
	if (ptr_to.mlx == NULL)
		return (1);
	ptr_to.win = mlx_new_window(ptr_to.mlx, 512, 512, "./so_long");
	if (ptr_to.win == NULL)
	{
		free(ptr_to.win);
		return (1);
	}
	mlx_loop_hook(ptr_to.mlx, handle_no_event, &ptr_to);
	mlx_hook(ptr_to.win, KeyRelease, KeyReleaseMask, &escape_window, &ptr_to);
	mlx_hook(ptr_to.win, DestroyNotify, StructureNotifyMask, &close_window,
		&ptr_to);
	mlx_loop(ptr_to.mlx);
	return (0);
}

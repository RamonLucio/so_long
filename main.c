/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 22:55:54 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/12/15 18:14:57 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <X11/keysym.h>
#include <stdlib.h>
#include <X11/X.h>

typedef struct s_ptr
{
	void	*mlx;
	void	*win;
}				t_ptr;

/*	mlx_loop_hook(ptr_to.mlx, &handle_no_event, &ptr_to) will be called when
	no event occurs. The only reason we've used it is because without it,
	the loop would have never ended. That's directly related to how the
	mlx_loop is implemented. */

int	handle_no_event(void)
{
	return (0);
}

/*	Pressing ESC must close the window and quit the program cleanly.*/

int	escape_window(int keycode, t_ptr *ptr_to)
{
	if (keycode == XK_Escape)
		mlx_destroy_window(ptr_to->mlx, ptr_to->win);
	return (0);
}

/*	Clicking on the red cross on the window’s frame must close the window and
	quit the program cleanly. */

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
	ptr_to.win = mlx_new_window(ptr_to.mlx, 500, 500, "Pressing esc");
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
	mlx_destroy_display(ptr_to.mlx);
	free(ptr_to.mlx);
	return (0);
}

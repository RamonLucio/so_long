/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:11:54 by rlucio-l          #+#    #+#             */
/*   Updated: 2022/01/06 12:13:57 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "./libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# define VALID_MAP 0
# define NOT_RECTANGULAR 1
# define INVALID_WALL 2
# define SPRITE_SIZE 16

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}				t_img;

typedef struct s_map
{
	void	*mlx;
	void	*window;
	char	*string;
	int		width;
	int		height;
	t_img	tile;
	t_img	wall;
	t_img	coin;
	t_img	exit;
	t_img	player;
	int		movements;
}				t_map;

#endif

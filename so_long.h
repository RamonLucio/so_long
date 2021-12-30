/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:11:54 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/12/30 19:49:34 by rlucio-l         ###   ########.fr       */
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
# define INVALID_WALL 1
# define VALID_WALL 0

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}				t_img;

typedef struct s_ptr
{
	void	*mlx;
	void	*win;
	t_img	tile;
}				t_ptr;

#endif

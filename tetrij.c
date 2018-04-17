/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrij.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groussel <groussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 22:25:40 by groussel          #+#    #+#             */
/*   Updated: 2018/04/15 19:28:54 by groussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** TODO:	[X] Check north
**			[X] Check east
**			[X] Check south
**			[X] Check west
**
** FIXME:	[X] Segv
*/

#include "fillit.h"
#include "libft.h"

int		checkJ(char **tab)
{
	if (checkJN(tab))
		return (0);
	if (checkJE(tab))
		return (1);
	if (checkJS(tab))
		return (2);
	if (checkJW(tab))
		return (3);
	return (-1);
}

/*  #
**  #
** ##
*/
int		checkJN(char **tab)
{
	int		x;
	int		y;

	y = -1;
	while (++y < 2)
	{
		x = 0;
		while (++x < 4)
		{
			if (tab[y][x] == '#' && tab[y + 1][x] == '#' &&
					tab[y + 2][x] == '#' && tab[y + 2][x - 1] == '#')
				return (1);
		}
	}
	return (0);
}

/* #
** ###
*/
int		checkJE(char **tab)
{
	int		x;
	int		y;

	y = -1;
	while (++y < 3)
	{
		x = -1;
		while (++x < 2)
		{
			if (tab[y][x] == '#' && tab[y + 1][x] == '#' &&
					tab[y + 1][x + 1] == '#' && tab[y + 1][x + 2] == '#')
				return (1);
		}
	}
	return (0);
}

/* ##
** #
** #
*/
int		checkJS(char **tab)
{
	int		x;
	int		y;

	y = -1;
	while (++y < 2)
	{
		x = -1;
		while (++x < 3)
		{
			if (tab[y][x] == '#' && tab[y][x + 1] == '#' &&
					tab[y + 1][x] == '#' && tab[y + 2][x] == '#')
				return (1);
		}
	}
	return (0);
}

/* ###
**   #
*/
int		checkJW(char **tab)
{
	int		x;
	int		y;

	y = -1;
	while (++y < 3)
	{
		x = -1;
		while (++x < 2)
		{
			if (tab[y][x] == '#' && tab[y][x + 1] == '#' &&
					tab[y][x + 2] == '#' && tab[y + 1][x + 2] == '#')
				return (1);
		}
	}
	return (0);
}
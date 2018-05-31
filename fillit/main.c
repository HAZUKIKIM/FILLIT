/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 16:39:49 by kykim             #+#    #+#             */
/*   Updated: 2018/05/31 11:18:08 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	char	**list;
	char	**board;
	int		x;

	if (argc != 2)
		ft_putstr("usage: ./fillit input_sample_file\n");
	else
	{
		if (validinput(argv[1], numoftet(argv[1])))
		{
			list = alphabet(splitandsave(list, convert(argv[1],
			numoftet(argv[1])), numoftet(argv[1])), numoftet(argv[1]));
			board = makeboard(boardsize(numoftet(argv[1])));
			while (!solve(list, board, 0, numoftet(argv[1])))
			{
				x = (int)ft_strlen(board[0]);
				freeboard(board);
				board = makeboard(x);
			}
			printboard(board);
		}
		else
			ft_putstr("error\n");
	}
	return (0);
}

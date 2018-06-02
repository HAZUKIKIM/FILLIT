/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 16:39:49 by kykim             #+#    #+#             */
/*   Updated: 2018/06/02 12:20:38 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	backtrack(char **av, char **list, char **board)
{
	int x;
	
	if (validinput(av[1], numoftet(av[1])))
	{
		list = alphabet(splitandsave(list, convert(av[1], numoftet(av[1])), numoftet(av[1])), numoftet(av[1]));
		board = makeboard(boardsize(numoftet(av[1])));
		while (!solve(list, board, 0, numoftet(av[1])))
		{
			x = (int)ft_strlen(board[0]) + 1;
			freeboard(board);
			board = makeboard(x);
		}
		printboard(board);
		freeboard(board);
	}
	else
		ft_putstr("error\n");
}

int	main(int argc, char **argv)
{
	char	**list;
	char	**board;
	int		i;

	i = 0;
	if (argc != 2)
		ft_putstr("usage: ./fillit input_sample_file\n");
	else
	{
		backtrack(argv, list, board);
		while (i < numoftet(argv[1]))
		{
			free(list[i]);
			i++;
		}
		free(list);	
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:58:23 by revieira          #+#    #+#             */
/*   Updated: 2023/02/28 19:49:14 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	validate_operation(char **operations, char *input)
{
	int	i;

	i = 0;
	while (operations[i])
	{
		if (!ft_strcmp(operations[i], input))
			return (1);
		i++;
	}
	return (0);
}

int	read_operations(t_data *data)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
		{
			free(line);
			break ;
		}
		if (!validate_operation(data->valided_operations, line))
		{
			free(line);
			return (0);
		}
		add_operation(&data->operations, line);
		free(line);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:58:23 by revieira          #+#    #+#             */
/*   Updated: 2023/02/27 18:06:28 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	validate_operation(char *operation)
{
	char	*operations;

	
	operations = ft_strdup(VALIDATED_OPERS);
	if (ft_strnstr(operations, operation, ft_strlen(operations)))
	{
		free (operations);
		return (1);
	}
	free(operations);
	return (0);
}

int	read_operations(t_data *data)
{
	char	*line;

	while (1)
	{
		line = get_next_line(1);
		if (!line)
		{
			free(line);
			break ;
		}
		if (!validate_operation(line))
		{
			free(line);
			return (0);
		}
		add_operation(&data->operations, line);
		free(line);
	}
	return(1);
}

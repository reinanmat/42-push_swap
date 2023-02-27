#include "push_swap_bonus.h"

void	init_operations(char **valided_operations)
{
	valided_operations[0] = ft_strdup("sa\n");
	valided_operations[1] = ft_strdup("sb\n");
	valided_operations[2] = ft_strdup("ss\n");
	valided_operations[3] = ft_strdup("pa\n");
	valided_operations[4] = ft_strdup("pb\n");
	valided_operations[5] = ft_strdup("ra\n");
	valided_operations[6] = ft_strdup("rb\n");
	valided_operations[7] = ft_strdup("rr\n");
	valided_operations[8] = ft_strdup("rra\n");
	valided_operations[9] = ft_strdup("rrb\n");
	valided_operations[10] = ft_strdup("rrr\n");
	valided_operations[11] = NULL;
}

void	init_data(t_data *data, int *int_array, int size)
{
	int	i;

	i = -1;
	data->size = size;
	data->s_a = NULL;
	data->s_b = NULL;
	data->operations= NULL;
	init_operations(data->valided_operations);
	while (++i < data->size)
		add_to_stack(&data->s_a, int_array[i]);
	free(int_array);
}

t_opers	*new_node_oper(char *operation)
{
	t_opers	*new;

	new = (t_opers *)malloc(sizeof(t_opers));
	new->operation = ft_strtrim(operation, "\n");
	new->next = NULL;
	return (new);
}

void	add_operation(t_opers **head_node, char *operation)
{
	t_opers	*new;
	t_opers	*aux;

	if (!*head_node)
		*head_node = new_node_oper(operation);
	else
	{
		new = new_node_oper(operation);
		aux = *head_node;
		while(aux->next)
			aux = aux->next;
		aux->next = new;
	}
}

void	print_opers(t_opers **operations)
{
	t_opers	*aux;

	aux = *operations;
	ft_printf("\n");
	while(aux)
	{
		ft_printf("%s", aux->operation);
		aux = aux->next;
	}
}

void	free_operation(t_opers **head_stack)
{
	t_opers	*current;
	t_opers	*next;

	if (!head_stack)
		return ;
	current = *head_stack;
	while (current)
	{
		next = current->next;
		free(current->operation);
		free(current);
		current = next;
	}
	*head_stack = NULL;
}

void	exec_opers(t_opers **opers, t_stack *s_a, t_stack *s_b)
{
	t_opers *tmp;

	tmp = *opers;
	while(tmp)
	{
		exec_operation(tmp->operation, &s_a, &s_b);
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		*int_array;
	int		i = -1;

	int_array = check_args(argc, argv);
	if (!int_array)
		ft_exit_program("Error", 1);
	init_data(&data, int_array, argc - 1);
	while(data.valided_operations[++i])
		ft_printf("%s\n", data.valided_operations[i]);
	exit(1);
	/*if (!read_operations(&data.operations))
		ft_exit_program("Error", 1);*/
	exec_opers(&data.operations, data.s_a, data.s_b);
	if (ft_issort(&data.s_a) && size_stack(&data.s_b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_operation(&data.operations);
	free_stack(&data.s_a);
	return (0);
}

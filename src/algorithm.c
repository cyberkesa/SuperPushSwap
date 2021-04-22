#include "push_swap.h"

int	maybe_sa(char **array)
{
	if (array[0] > array[1])
		return (1);
	return (0);
}

int	insert_sorts(t_general *g)
{
	if (check_sort(g->array) == 1
	&& get_len_array(g->stack_b) == 0)
		return (1);
	return (0);
}

int	get_min_way(char **array, size_t pos_elem)
{
	size_t	len;
	int	rotate;

	rotate = 0;
	len = get_len_array(array);
	if ((len / 2) < pos_elem)
		return (pos_elem);
	else if ((len / 2) >= pos_elem)
		return ((len - pos_elem) * -1);
	return (rotate);
}

int	check_sa(t_general *g, char **array)
{
	if (array[0] > array[1])
		return (1);
	return (0);
}

int	check_sb(t_general *g, char **array)
{
	if (array[0] < array[1])
		return (1);
	return (0);
}

int	push_b_with_rotate(t_general *g, char **array, int rotate)
{
	// printf("rotate: %d\n", rotate);
	if (rotate == 1 && maybe_sa(array) == 1)
	{
		sa_ins(g);
		pa_ins(g);
		return (0);
	}
	else if (rotate > 0)
	{
		while (rotate--)
			ra_ins(g);
	}
	else if (rotate < 0)
	{
		while (rotate++ != 0)
			rra_ins(g);
	}
	pa_ins(g);
	return (rotate);
}

int		just_rotate(t_general *g, char **array, int rotate)
{
	// printf("rotate: %d\n", rotate);
	if (rotate == 1 && maybe_sa(array) == 1)
	{
		sa_ins(g);
		return (0);
	}
	else if (rotate > 0)
	{
		while (rotate--)
			ra_ins(g);
	}
	else if (rotate < 0)
	{
		while (rotate++ != 0)
			rra_ins(g);
	}
	return (rotate);
}

void	super_algorithm(t_general *g)
{
	size_t	i;
	int	rotate;

	i = 0;
	printf("lol\n");
	if (check_polusort_stack_a(g->array) == 1 && get_len_array(g->stack_b) == 0)
	{
		rotate = rotate_master(g->array, 'a');
		just_rotate(g, g->array, rotate);
	}
	else if (check_polusort_stack_a(g->array) == 1 && check_polusort_stack_a(g->stack_b) == 1)
		insert_sorts(g);
	print_array(g->array);
	while (i != g->len_argc)
	{
		if (check_sort(g->array) == 0)
			break ;
		if (check_sa(g, g->array) == 1 && check_sb(g, g->stack_b) == 1)
			ss_ins(g);
		else if (check_sa(g, g->array) == 1 && check_sb(g, g->stack_b) == 0)
			sa_ins(g);
		rotate = get_pos_elem(g->array, g->sort_array[i]);
		push_b_with_rotate(g, g->array, rotate);
		i++;
	}
	while (get_len_array(g->stack_b) != 0)
		pb_ins(g);
}

// void	push_back_array(t_general *g)
// {
// 	while (get_len_array(g->stack_b) != 0)
// 		pb_ins(g);
// }

void	push_swap(t_general *g)
{
	if (check_sort(g->array) == 0)
		complete_sort(g);
	g->sort_array = quick_sort_arr(g->sort_array, 0, get_len_array(g->sort_array) - 1);
	g->middle = get_middle_values(g->sort_array, get_len_array(g->sort_array));
	if (g->len_argc == 3)
		alg_three(g);
	// else if (g->len_argc > 3 && g->len_argc <= 5)
	// 	alg_five(g);
	else if (g->len_argc > 5)
		super_algorithm(g);
	// if (check_sort(g->array) == 0 && get_len_array(g->stack_b) == 0)
	// 	complete_sort(g);
	// else
	// 	ft_error("Сортировка не завершена!\n");
}

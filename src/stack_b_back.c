#include "push_swap.h"

int	find_max_in_a(t_general *g)
{
	int	max;
	int	i;
	int	len;
	i = 1;
	len = get_len_array(g->array);
	max = ft_atoi(g->array[0]);
	while (i ^ len)
	{
		if (ft_atoi(g->array[i]) > max)
			max = ft_atoi(g->array[i]);
		i++;
	}
	return (max);
}

int	find_min_in_a(t_general *g)
{
	int	min;
	int	i;
	i = 1;
	min = ft_atoi(g->array[0]);
	while (i ^ get_len_array(g->array))
	{
		if (ft_atoi(g->array[i]) < min)
			min = ft_atoi(g->array[i]);
		i++;
	}
	return (min);
}

void	pushing_number(t_general *g, int number_id)
{
	if (g->num_ins[number_id].ra > 0)
		while (g->num_ins[number_id].ra--)
		{
			ra_ins(g);
			printf("ra\n");
		}
	if (g->num_ins[number_id].rra > 0)
		while (g->num_ins[number_id].rra--)
		{
			rra_ins(g);
			printf("rra\n");
		}
	if (g->num_ins[number_id].rb > 0)
		while (g->num_ins[number_id].rb--)
		{
			rb_ins(g);
			printf("rb\n");
		}
	if (g->num_ins[number_id].rrb > 0)
		while (g->num_ins[number_id].rrb--)
		{
			rrb_ins(g);
			printf("rrb\n");
		}
	if (g->num_ins[number_id].rr > 0)
		while (g->num_ins[number_id].rr--)
		{
			rr_ins(g);
			printf("rr\n");
		}
	if (g->num_ins[number_id].rrr > 0)
		while (g->num_ins[number_id].rrr--)
		{
			rrr_ins(g);
			printf("rrr\n");
		}
	pa_ins(g);
}

void	processing_ins(t_general *g, int i)
{
	if (g->num_ins[i].ra < 0)
		g->num_ins[i].ra = 0;
	if (g->num_ins[i].rb < 0)
		g->num_ins[i].rb = 0;
	if (g->num_ins[i].rr < 0)
		g->num_ins[i].rr = 0;
	if (g->num_ins[i].rrr < 0)
		g->num_ins[i].rrr = 0;
	if (g->num_ins[i].rrb < 0)
		g->num_ins[i].rrb = 0;
	if (g->num_ins[i].rra < 0)
		g->num_ins[i].rra = 0;
	if (g->num_ins[i].stack_a_rotate < 0)
		g->num_ins[i].rra = (abs)(g->num_ins[i].stack_a_rotate);
	if (g->num_ins[i].stack_b_rotate < 0)
		g->num_ins[i].rrb = (abs)(g->num_ins[i].stack_b_rotate);
	if (g->num_ins[i].stack_a_rotate > 0)
		g->num_ins[i].ra = g->num_ins[i].stack_a_rotate;
	if (g->num_ins[i].stack_b_rotate > 0)
		g->num_ins[i].rb = g->num_ins[i].stack_b_rotate;
	if (g->num_ins[i].ra > 0 && g->num_ins[i].rb > 0)
	{
		if (g->num_ins[i].ra < g->num_ins[i].rb)
		{
			g->num_ins[i].rr = g->num_ins[i].ra;
			g->num_ins[i].ra = 0;
			g->num_ins[i].rb -= g->num_ins[i].rr;
		}
		if (g->num_ins[i].ra > g->num_ins[i].rb)
		{
			g->num_ins[i].rr = g->num_ins[i].rb;
			g->num_ins[i].rb = 0;
			g->num_ins[i].ra -= g->num_ins[i].rr;
		}
		if (g->num_ins[i].ra == g->num_ins[i].rb)
		{
			g->num_ins[i].rr = g->num_ins[i].ra;
			g->num_ins[i].rb = 0;
			g->num_ins[i].ra = 0;
		}
	}
	if (g->num_ins[i].rra > 0 && g->num_ins[i].rrb > 0)
	{
		if (g->num_ins[i].rra < g->num_ins[i].rrb)
		{
			g->num_ins[i].rrr = g->num_ins[i].rra;
			g->num_ins[i].rra = 0;
			g->num_ins[i].rrb -= g->num_ins[i].rrr;
		}
		if (g->num_ins[i].rra > g->num_ins[i].rrb)
		{
			g->num_ins[i].rrr = g->num_ins[i].rrb;
			g->num_ins[i].rrb = 0;
			g->num_ins[i].rra -= g->num_ins[i].rrr;
		}
		if (g->num_ins[i].rra == g->num_ins[i].rrb)
		{
			g->num_ins[i].rrr = g->num_ins[i].rra;
			g->num_ins[i].rrb = 0;
			g->num_ins[i].rra = 0;
		}
	}
	g->num_ins[i].count = g->num_ins[i].rrr + g->num_ins[i].rra + g->num_ins[i].rrb +
	g->num_ins[i].rr + g->num_ins[i].ra + g->num_ins[i].rb;
}

void	get_best_alg(t_general *g, int i)
{
	int	a;
	int	res;
	int	current_number;
	int	max = find_max_in_a(g);
	int	min = find_min_in_a(g);

	current_number = ft_atoi(g->num_ins[i].number);
	if (current_number > max)
	{
		g->num_ins[i].stack_a_rotate = get_min_way(g->array, get_pos_elem(g->array, ft_itoa(min)));
		g->num_ins[i].stack_b_rotate = get_min_way(g->stack_b, get_pos_elem(g->stack_b, ft_itoa(current_number)));
		g->num_ins[i].count = (abs)(g->num_ins[i].stack_a_rotate) + (abs)(g->num_ins[i].stack_b_rotate);
	}
	else if (current_number < min)
	{
		g->num_ins[i].stack_a_rotate = get_min_way(g->array, get_pos_elem(g->array, ft_itoa(min)));
		g->num_ins[i].stack_b_rotate = get_min_way(g->stack_b, get_pos_elem(g->stack_b, ft_itoa(current_number)));
		g->num_ins[i].count = (abs)(g->num_ins[i].stack_a_rotate) + (abs)(g->num_ins[i].stack_b_rotate);
	}
	else
	{
		a = 0;
		res = -1;
		while (a + 1 ^ get_len_array(g->array))
		{
			if (ft_atoi(g->array[a]) < current_number && ft_atoi(g->array[a + 1]) > current_number)
				res = a;
			a++;
		}
		if (res == -1)
		{
			if (ft_atoi(g->array[a]) < current_number && ft_atoi(g->array[0]) > current_number)
				res = -1;
		}
		g->num_ins[i].stack_a_rotate = get_min_way(g->array, res) + 1;
		g->num_ins[i].stack_b_rotate = get_min_way(g->stack_b, get_pos_elem(g->stack_b, g->num_ins[i].number));
		g->num_ins[i].count = (abs)(g->num_ins[i].stack_a_rotate) + (abs)(g->num_ins[i].stack_b_rotate);
	}
	processing_ins(g, i);
}

void	init_numbers(t_general *g)
{
	int	i;
	int	len;
	len = get_len_array(g->stack_b);
	i = 0;
	while (i ^ len)
	{
		g->num_ins[i].number = g->stack_b[i];
		i++;
	}
	g->num_ins[i].number = NULL;
}

void	init_struct(t_general *g)
{
	init_numbers(g);
	int	len;
	len = 0;
	while (len ^ get_len_array(g->stack_b))
	{
		get_best_alg(g, len);
		len++;
	}
}

void	make_counts_struct(t_general *g)
{
	g->num_ins = NULL;
	g->num_ins = (t_num_ins *)malloc(sizeof(t_num_ins)
	* (get_len_array(g->stack_b) + 1));
	init_struct(g);
}

int	get_number(t_general *g)
{
	int	len;
	int	i;
	int	return_id;
	int	count_return_id;

	len = get_len_array(g->stack_b);
	count_return_id = g->num_ins[0].count;
	return_id = 0;
	if (len ^ 1)
	{
		i = 1;
		while (i ^ len)
		{
			if (g->num_ins[i].count < count_return_id)
			{
				return_id = i;
				count_return_id = g->num_ins[i].count;
			}
			i++;
		}
	}
	return (return_id);
}

void	back_push(t_general *g)
{
	while (get_len_array(g->stack_b) ^ 0)
	{
		make_counts_struct(g);
		pushing_number(g, get_number(g));
	}
}
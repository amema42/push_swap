/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:04:34 by jcardina          #+#    #+#             */
/*   Updated: 2023/10/04 14:31:31 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	algoritm(t_listx **stack_a, t_listx **stack_b, t_inst *inst, t_memo *m)
{
	while (ps_lstsize(*stack_b) != 0)
	{
		best_move(stack_a, stack_b, inst);
		inst_reader(stack_a, stack_b, inst);
	}
	final_rotate(stack_a, m);
}

void	best_move(t_listx **stack_a, t_listx **stack_b, t_inst	*inst)
{
	t_listx	*tmp;
	int		count;
	int		moves;
	int		moves_mem;

	tmp = *stack_b;
	moves_mem = 21474836;
	while (tmp)
	{
		count = spot_finder(stack_a, &tmp);
		moves = moves_counter(count, tmp ->index, stack_a, stack_b);
		if (moves <= moves_mem)
		{
			inst ->a_index = count;
			inst ->b_index = tmp ->index;
			inst ->cases = case_finder(count, tmp ->index, stack_a, stack_b);
			moves_mem = moves;
		}
		tmp = tmp ->next;
	}
}

int	moves_counter(int ia, int ib, t_listx **stack_a, t_listx **stack_b)
{
	int	ret;
	int	size_a;
	int	size_b;

	size_a = ps_lstsize(*stack_a);
	size_b = ps_lstsize(*stack_b);
	ret = 0;
	if ((ia <= (size_a / 2)) && (ib <= (size_b / 2)))
		ret = ia + ib;
	else if ((ia <= (size_a / 2)) && (ib > (size_b / 2)))
		ret = ia + (size_b - ib + 1);
	else if ((ia > (size_a / 2)) && (ib <= (size_b / 2)))
		ret = (size_a - ia) + ib;
	else if ((ia > (size_a / 2)) && (ib > (size_b / 2)))
		ret = (size_a - ia) + (size_b - ib + 1);
	return (ret);
}

int	case_finder(int ia, int ib, t_listx **stack_a, t_listx **stack_b)
{
	int	size_a;
	int	size_b;

	size_a = ps_lstsize(*stack_a);
	size_b = ps_lstsize(*stack_b);
	if ((ia <= (size_a / 2)) && (ib <= (size_b / 2)))
		return (1);
	else if ((ia <= (size_a / 2)) && (ib > (size_b / 2)))
		return (2);
	else if ((ia > (size_a / 2)) && (ib <= (size_b / 2)))
		return (3);
	else if ((ia > (size_a / 2)) && (ib > (size_b / 2)))
		return (4);
	return (-1);
}

int	spot_finder(t_listx **stack_a, t_listx **stack_b)
{
	t_listx	*tmp;
	t_listx	*tmp2;

	tmp = *stack_a;
	tmp2 = *stack_b;
	while (tmp)
	{
		if (tmp2 ->content < tmp ->content
			&& tmp2 ->content > ((ps_lstlast(*stack_a))->content))
			return (0);
		if (tmp2 ->content > tmp ->content
			&& tmp2 ->content < ((tmp ->next)->content))
			return (tmp ->index + 1);
		tmp = tmp ->next;
	}
	return (-1);
}

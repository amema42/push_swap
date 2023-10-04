/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_3n5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:37:57 by amema             #+#    #+#             */
/*   Updated: 2023/10/04 14:49:57 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_3(t_listx **s_a, t_memo *mem)
{
	t_listx	*tmp;

	tmp = *s_a;
	if (tmp ->content == mem->min && ps_lstlast(*s_a)-> content != mem ->max)
	{
		sa(s_a, 1);
		ra(s_a, 1);
	}
	else if (tmp ->content != mem->max && tmp ->content != mem->min)
	{
		if (ps_lstlast(*s_a)-> content == mem ->min)
			rra(s_a, 1);
		else
			sa(s_a, 1);
	}
	else if (tmp ->content == mem->max)
	{
		if (ps_lstlast(*s_a)-> content != mem ->min)
			ra(s_a, 1);
		else
		{
			sa(s_a, 1);
			rra(s_a, 1);
		}
	}
}

void	order_5(t_listx **stack_a, t_listx **stack_b, t_memo *mem)
{
	if (stack_sorted(*stack_a))
		return ;
	pb(stack_a, stack_b, 1);
	pb(stack_a, stack_b, 1);
	ft_mid(stack_a, mem);
	order_3(stack_a, mem);
	if (((*stack_b)->content < mem->max && (*stack_b)->content > mem->min)
		&& (((*stack_b)->next)->content < mem->max
			&& ((*stack_b)->next)->content > mem->min))
		return ;
	order_5_pt2(stack_a, stack_b, mem);
	ft_mid(stack_a, mem);
}

void	order_5_pt2(t_listx **stack_a, t_listx **stack_b, t_memo *mem)
{
	int	i;

	i = 0;
	while (i++ < 2)
	{
		if ((*stack_b)->content > mem ->max)
		{
			pa(stack_a, stack_b, 1);
			ra(stack_a, 1);
			ft_mid(stack_a, mem);
		}
		else if ((*stack_b)->content <= mem ->min)
		{
			pa(stack_a, stack_b, 1);
			ft_mid(stack_a, mem);
		}
		else if (ps_lstsize(*stack_b) == 2)
			rb(stack_b, 1);
	}
}

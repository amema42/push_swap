/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:39:12 by amema             #+#    #+#             */
/*   Updated: 2023/10/04 14:39:15 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_mid(t_listx **stack_a, t_memo *mem)
{
	int		cont;
	int		size;
	t_listx	*tmp;
	t_listx	*n;

	size = ps_lstsize(*stack_a);
	cont = 0;
	tmp = *stack_a;
	n = *stack_a;
	while (n)
	{
		while (tmp)
		{
			if (n ->content > tmp ->content)
				cont++;
			tmp = tmp -> next;
		}
		if (cont == size / 2)
			mem ->mid = n ->content;
		n = n->next;
		tmp = *stack_a;
		cont = 0;
	}
	ft_min_max(stack_a, mem);
}

void	ft_min_max(t_listx **stack_a, t_memo *mem)
{
	t_listx	*tmp;

	tmp = *stack_a;
	mem -> min = tmp ->content;
	mem ->max = tmp ->content;
	while (tmp)
	{
		if (tmp ->content < mem -> min)
			mem ->min = tmp ->content;
		if (tmp ->content > mem -> max)
			mem ->max = tmp ->content;
		tmp = tmp ->next;
	}
}

void	init_b(t_listx **stack_a, t_listx **stack_b, t_memo *mem)
{
	t_listx	*tmp;

	ft_mid(stack_a, mem);
	if (ps_lstsize(*stack_a) == 2 || ps_lstsize(*stack_a) == 5)
	{
		cases(stack_a, stack_b, mem);
		return ;
	}
	while (ps_lstsize(*stack_a) != 3)
	{
		tmp = *stack_a;
		if ((tmp->content < mem->mid) && (tmp->content != mem->min))
			pb(stack_a, stack_b, 1);
		else if ((tmp ->content > mem ->mid) && (tmp -> content != mem ->max))
		{
			pb(stack_a, stack_b, 1);
			rb(stack_b, 1);
		}
		else if ((tmp->content == mem->min || tmp->content == mem->mid
				|| tmp->content == mem-> max))
			ra(stack_a, 1);
	}
	cases(stack_a, stack_b, mem);
}

void	cases(t_listx **stack_a, t_listx **stack_b, t_memo *mem)
{
	if (ps_lstsize(*stack_a) == 2)
	{
		if ((*stack_a)->content == mem ->max)
			ra(stack_a, 1);
	}
	else if (ps_lstsize(*stack_a) == 5)
		order_5(stack_a, stack_b, mem);
	else if (ps_lstsize(*stack_a) == 3)
		order_3(stack_a, mem);
}

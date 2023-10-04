/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:39:50 by amema             #+#    #+#             */
/*   Updated: 2023/10/04 14:39:52 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb(t_listx **stack_a, t_listx **stack_b, int i)
{
	t_listx	*tmp;

	if (*stack_a == NULL)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	ps_lstadd_front(stack_b, tmp);
	index_init(stack_b);
	index_init(stack_a);
	if (i == 1)
		write(1, "pb\n", 3);
	return ;
}

void	pa(t_listx **stack_a, t_listx **stack_b, int i)
{
	t_listx	*tmp;

	if (*stack_b == NULL)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	ps_lstadd_front(stack_a, tmp);
	index_init(stack_a);
	index_init(stack_b);
	if (i == 1)
		write(1, "pa\n", 3);
	return ;
}

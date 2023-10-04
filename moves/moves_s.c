/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:39:32 by amema             #+#    #+#             */
/*   Updated: 2023/10/04 14:39:34 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_listx **stack_a, int i)
{
	t_listx	*tmp;

	if (ps_lstsize(*stack_a) == 1 || *stack_a == NULL)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = (*stack_a)->next;
	(*stack_a)->next = tmp;
	index_init(stack_a);
	if (i == 1)
		write(1, "sa\n", 3);
}

void	sb(t_listx **stack_b, int i)
{
	t_listx	*tmp;

	if (ps_lstsize(*stack_b) == 1 || *stack_b == NULL)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = (*stack_b)->next;
	(*stack_b)->next = tmp;
	index_init(stack_b);
	if (i == 1)
		write(1, "sb\n", 3);
}

void	ss(t_listx **stack_b, t_listx **stack_a, int i)
{
	t_listx	*tmp;

	if (ps_lstsize(*stack_a) <= 1 || ps_lstsize(*stack_b) <= 1)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = (*stack_a)->next;
	(*stack_a)->next = tmp;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = (*stack_b)->next;
	(*stack_b)->next = tmp;
	index_init(stack_b);
	index_init(stack_a);
	if (i == 1)
		write(1, "ss\n", 3);
}

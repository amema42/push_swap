/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:39:37 by amema             #+#    #+#             */
/*   Updated: 2023/10/04 14:39:40 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_listx **stack_a, int i)
{
	t_listx	*last;
	t_listx	*prev;

	if (ps_lstsize(*stack_a) == 1 || *stack_a == NULL)
		return ;
	last = *stack_a;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	ps_lstadd_front(stack_a, last);
	index_init(stack_a);
	if (i == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_listx **stack_b, int i)
{
	t_listx	*last;
	t_listx	*prev;

	if (ps_lstsize(*stack_b) == 1 || *stack_b == NULL)
		return ;
	last = *stack_b;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	ps_lstadd_front(stack_b, last);
	index_init(stack_b);
	if (i == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_listx **stack_a, t_listx **stack_b, int i)
{
	t_listx	*last;
	t_listx	*prev;

	if (ps_lstsize(*stack_a) <= 1 || ps_lstsize(*stack_b) <= 1)
		return ;
	last = *stack_a;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	ps_lstadd_front(stack_a, last);
	index_init(stack_a);
	last = *stack_b;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	ps_lstadd_front(stack_b, last);
	index_init(stack_b);
	if (i == 1)
		write(1, "rrr\n", 4);
}

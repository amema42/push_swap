/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:39:43 by amema             #+#    #+#             */
/*   Updated: 2023/10/04 14:39:45 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_listx **stack_a, int i)
{
	t_listx	*tmp;
	t_listx	*last;

	if (ps_lstsize(*stack_a) == 1 || *stack_a == NULL)
		return ;
	last = ps_lstlast(*stack_a);
	tmp = *stack_a;
	*stack_a = tmp->next;
	last->next = tmp;
	tmp->next = NULL;
	index_init(stack_a);
	if (i == 1)
		write(1, "ra\n", 3);
}

void	rb(t_listx **stack_b, int i)
{
	t_listx	*tmp;
	t_listx	*last;

	if (ps_lstsize(*stack_b) == 1 || *stack_b == NULL)
		return ;
	last = ps_lstlast(*stack_b);
	tmp = *stack_b;
	*stack_b = tmp->next;
	last->next = tmp;
	tmp->next = NULL;
	index_init(stack_b);
	if (i == 1)
		write(1, "rb\n", 3);
}

void	rr(t_listx **stack_a, t_listx **stack_b, int i)
{
	t_listx	*tmp;
	t_listx	*last;

	if (ps_lstsize(*stack_a) == 1 || ps_lstsize(*stack_b) == 1)
		return ;
	if (*stack_a == NULL || *stack_b == NULL)
		return ;
	last = ps_lstlast(*stack_a);
	tmp = *stack_a;
	*stack_a = tmp->next;
	last->next = tmp;
	tmp->next = NULL;
	index_init(stack_a);
	last = ps_lstlast(*stack_b);
	tmp = *stack_b;
	*stack_b = tmp->next;
	last->next = tmp;
	tmp->next = NULL;
	index_init(stack_b);
	if (i == 1)
		write(1, "rr\n", 3);
}

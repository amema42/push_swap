/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:37:25 by amema             #+#    #+#             */
/*   Updated: 2023/10/04 14:37:26 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_listx *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	ft_printlst(t_listx **stack_a)
{
	t_listx	*tmp;
	t_listx	*save;
	int		i;

	save = *stack_a;
	while (save)
	{
		tmp = save->next;
		i = save->content;
		ft_printf("%d ", i);
		save = tmp;
	}
	ft_printf(" / ");
}

void	index_init(t_listx **stack_a)
{
	t_listx	*tmp;
	t_listx	*save;
	int		i;

	i = 0;
	save = *stack_a;
	while (save)
	{
		tmp = save->next;
		save->index = i;
		i++;
		save = tmp;
	}
}

void	ft_printindex(t_listx **stack_a)
{
	t_listx	*tmp;
	t_listx	*save;
	int		i;

	save = *stack_a;
	while (save)
	{
		tmp = save->next;
		i = save->index;
		ft_printf("%d ", i);
		save = tmp;
	}
}

void	final_rotate(t_listx **stack_a, t_memo *m)
{
	t_listx	*tmp;
	int		i;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp ->content == m ->min)
		{
			if (tmp ->index > (ps_lstsize(*stack_a) / 2))
			{
				i = tmp ->index;
				while (i++ < ps_lstsize(*stack_a))
					rra(stack_a, 1);
			}
			if (tmp ->index <= (ps_lstsize(*stack_a) / 2))
			{
				i = tmp ->index;
				while (i-- > 0)
					ra(stack_a, 1);
			}
		}
		tmp = tmp ->next;
	}
}

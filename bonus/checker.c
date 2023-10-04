/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:31:46 by jcardina          #+#    #+#             */
/*   Updated: 2023/10/04 14:31:50 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_moves2(t_listx **stack_a, t_listx **stack_b, char *str)
{
	if (ft_strncmp(str, "ra\n", 3) == 0)
		ra(stack_a, 0);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		rb(stack_b, 0);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		rr(stack_a, stack_b, 0);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		rra(stack_a, 0);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		rrb(stack_b, 0);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		rrr(stack_a, stack_b, 0);
	else
	{
		write(2, "Error\n", 6);
		free(str);
		return ;
	}
	return ;
}

void	do_moves(t_listx **stack_a, t_listx **stack_b, char *str)
{
	while (str != NULL)
	{
		if (ft_strncmp(str, "sa\n", 3) == 0)
			sa(stack_a, 0);
		else if (ft_strncmp(str, "sb\n", 3) == 0)
			sb(stack_a, 0);
		else if (ft_strncmp(str, "ss\n", 3) == 0)
			ss(stack_a, stack_b, 0);
		else if (ft_strncmp(str, "pa\n", 3) == 0)
			pa(stack_a, stack_b, 0);
		else if (ft_strncmp(str, "pb\n", 3) == 0)
			pb(stack_a, stack_b, 0);
		else
			do_moves2(stack_a, stack_b, str);
		free(str);
		str = get_next_line(0);
	}
}

int	okorko(t_listx **stack_a)
{
	t_listx	*tmp;
	t_listx	*succ;

	tmp = *stack_a;
	succ = (*stack_a)->next;
	while (succ)
	{
		if (tmp->content < succ->content)
		{
			tmp = tmp->next;
			succ = succ->next;
		}
		else
			return (-1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_listx	*stack_a;
	t_listx	*stack_b;

	if (ac < 2)
		return (0);
	if (list_init(ac, av, &stack_a) == -1)
		return (EXIT_FAILURE);
	do_moves(&stack_a, &stack_b, get_next_line(0));
	if (okorko(&stack_a) == -1)
	{
		write(1, "KO\n", 3);
		free_all(&stack_a);
		free_all(&stack_b);
		return (0);
	}
	write(1, "OK\n", 3);
	free_all(&stack_a);
	return (0);
}

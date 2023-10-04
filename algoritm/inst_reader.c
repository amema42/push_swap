/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:59:32 by jcardina          #+#    #+#             */
/*   Updated: 2023/10/04 14:31:43 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//da fare il lettore delle istruzioni

void	inst_reader(t_listx **stack_a, t_listx **stack_b, t_inst *inst)
{
	if (inst ->cases == 1)
		tiger(stack_a, stack_b, inst);
	else if (inst ->cases == 2)
		cobra(stack_a, stack_b, inst);
	else if (inst ->cases == 3)
		labrador(stack_a, stack_b, inst);
	else if (inst ->cases == 4)
		kyte(stack_a, stack_b, inst);
	return ;
}

void	tiger(t_listx **stack_a, t_listx **stack_b, t_inst *inst)
{
	while (inst ->a_index > 0 && inst ->b_index > 0)
	{
		rr(stack_a, stack_b, 1);
		inst ->a_index--;
		inst ->b_index--;
	}
	while (inst ->a_index > 0)
	{
		ra(stack_a, 1);
		inst ->a_index--;
	}
	while (inst ->b_index > 0)
	{
		rb(stack_b, 1);
		inst ->b_index--;
	}
	pa(stack_a, stack_b, 1);
	inst_init(inst);
	return ;
}

void	cobra(t_listx **stack_a, t_listx **stack_b, t_inst *inst)
{
	while (inst ->a_index > 0)
	{
		ra(stack_a, 1);
		inst ->a_index--;
	}
	while (inst ->b_index < ps_lstsize(*stack_b))
	{
		rrb(stack_b, 1);
		inst ->b_index++;
	}
	pa(stack_a, stack_b, 1);
	inst_init(inst);
	return ;
}

void	labrador(t_listx **stack_a, t_listx **stack_b, t_inst *inst)
{
	while (inst ->a_index < ps_lstsize(*stack_a))
	{
		rra(stack_a, 1);
		inst ->a_index++;
	}
	while (inst ->b_index > 0)
	{
		rb(stack_b, 1);
		inst ->b_index--;
	}
	pa(stack_a, stack_b, 1);
	inst_init(inst);
	return ;
}

void	kyte(t_listx **stack_a, t_listx **stack_b, t_inst *inst)
{
	while (inst ->a_index < ps_lstsize(*stack_a)
		&& inst ->b_index < ps_lstsize(*stack_b))
	{
		rrr(stack_a, stack_b, 1);
		inst ->a_index++;
		inst ->b_index++;
	}
	while (inst ->a_index < ps_lstsize(*stack_a))
	{
		rra(stack_a, 1);
		inst ->a_index++;
	}
	while (inst ->b_index < ps_lstsize(*stack_b))
	{
		rrb(stack_b, 1);
		inst ->b_index++;
	}
	pa(stack_a, stack_b, 1);
	inst_init(inst);
	return ;
}

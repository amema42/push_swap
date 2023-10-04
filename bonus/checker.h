/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:45:46 by jcardina          #+#    #+#             */
/*   Updated: 2023/10/04 14:32:07 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "../push_swap.h"
# include "../gnl/get_next_line.h"

void	do_moves(t_listx **stack_a, t_listx **stack_b, char *str);
void	do_moves2(t_listx **stack_a, t_listx **stack_b, char *str);
int		okorko(t_listx **stack_a);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:37:44 by amema             #+#    #+#             */
/*   Updated: 2023/10/04 14:50:12 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

typedef struct s_listx
{
	int				index;
	int				content;
	struct s_listx	*next;
}	t_listx;

typedef struct s_memo
{
	int	mid;
	int	min;
	int	max;
}	t_memo;

typedef struct s_inst
{
	int	a_index;
	int	b_index;
	int	cases;
}	t_inst;

//free
int		free_all(t_listx **stack_a);
void	free_matrix(char **matrix);
//le funzione prese da libft
t_listx	*ps_lstnew(int content);
int		ps_lstsize(t_listx *lst);
void	ps_lstadd_front(t_listx **lst, t_listx *new);
void	ps_lstadd_back(t_listx **lst, t_listx *new);
t_listx	*ps_lstlast(t_listx *lst);
//inizializzare la lista
int		list_init(int ac, char **av, t_listx **stack_a);
int		fill_stack(char **av, t_listx **stack_a, int row_nb, int i);
void	index_init(t_listx **stack_a);
void	inst_init(t_inst *inst);
//pushare in b
void	ft_mid(t_listx **stack_a, t_memo *mem);
void	ft_min_max(t_listx **stack_a, t_memo *mem);
void	init_b(t_listx **stack_a, t_listx **stack_b, t_memo *mem);
void	order_3(t_listx **stack_a, t_memo *mem);
void	order_5(t_listx **stack_a, t_listx **satck_b, t_memo *mem);
void	order_5_pt2(t_listx **stack_a, t_listx **stack_b, t_memo *mem);
int		stack_sorted(t_listx *stack);
void	cases(t_listx **stack_a, t_listx **stack_b, t_memo *mem);
// ok input
int		ok_input(char **matrix, int i);
int		double_n(char **matrix, int i);
int		min_max(char **matrix, int i);
int		check_one(char **matrix, int i);
int		check_av(char *str);
int		okorko2(t_listx **stack_a);
// algoritmo
void	best_move(t_listx **stack_a, t_listx **stack_b, t_inst *inst);
int		spot_finder(t_listx **stack_a, t_listx **stack_b);
void	algoritm(t_listx **stack_a, t_listx **stack_b, t_inst *inst, t_memo *m);
int		moves_counter(int ia, int ib, t_listx **stack_a, t_listx **stack_b);
int		case_finder(int ia, int ib, t_listx **stack_a, t_listx **stack_b);
void	final_rotate(t_listx **stack_a, t_memo *m);
// inst reader
void	inst_reader(t_listx **stack_a, t_listx **stack_b, t_inst *inst);
void	tiger(t_listx **stack_a, t_listx **stack_b, t_inst *inst);
void	cobra(t_listx **stack_a, t_listx **stack_b, t_inst *inst);
void	labrador(t_listx **stack_a, t_listx **stack_b, t_inst *inst);
void	kyte(t_listx **stack_a, t_listx **stack_b, t_inst *inst);
//stampa valori di controllo (non servono per la versione finale)
void	ft_printindex(t_listx **stack_a);
void	ft_printlst(t_listx **stack_a);
//mosse
void	ra(t_listx **stack_a, int i);
void	rb(t_listx **stack_b, int i);
void	rr(t_listx **stack_a, t_listx **stack_b, int i);
void	rra(t_listx **stack_a, int i);
void	rrb(t_listx **stack_b, int i);
void	rrr(t_listx **stack_a, t_listx **stack_b, int i);
void	pb(t_listx **stack_a, t_listx **stack_b, int i);
void	pa(t_listx **stack_a, t_listx **stack_b, int i);
void	sa(t_listx **stack_a, int i);
void	sb(t_listx **stack_b, int i);
void	ss(t_listx **stack_b, t_listx **stack_a, int i);

#endif

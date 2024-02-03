/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:06:08 by descamil          #+#    #+#             */
/*   Updated: 2024/02/03 17:15:31 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write (1, "Error\n", 7);
	exit(1);
}

void	ft_lstprinter(t_list *stack)
{
	if (stack != NULL)
	{
		while (stack != NULL)
		{
			printf("	%d\n", stack->content);
			stack = stack->next;
		}
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_num	num;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		ft_error();
	num.first = 0;
	num.second = 0;
	num.third = 0;
	ft_take_numbers(argc, argv, &stack_a);
	if (ft_lstordered(&stack_a) == 1)
		return (0);
	size = ft_lstsize(stack_a);
	if (size >= 2 && size <= 5)
		ft_force(&stack_a, &stack_b, &num, size);
	ft_lstprinter(stack_a);
	ft_lstprinter(stack_b);
	ft_clear_stack(&stack_a);
	ft_clear_stack(&stack_b);
	return (0);
}

	// else
	// 	ft_radix(&stack_a);
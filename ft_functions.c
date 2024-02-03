/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:32:11 by descamil          #+#    #+#             */
/*   Updated: 2024/02/03 14:36:43 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

t_list	*ft_lstnew(int content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

long	ft_atol(const char *str)
{
	int		i;
	long	m;
	long	number;

	m = 1;
	i = 0;
	number = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-')
	{
		m = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i++] - '0');
		if ((number * m) < INT_MIN || (number * m) > INT_MAX)
			return ((long) INT_MAX + 1);
	}
	return (number * m);
}

int	ft_lstordered(t_list **stack)
{
	t_list	*current;
	
	current = *stack;
	while (current->next != NULL)
	{
		if (current->content > current->next->content)
			return (0);	
		current = current->next;
	}
	ft_clear_stack(stack);
	return (1);
}
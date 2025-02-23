/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdoun <shamdoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:27:55 by shamdoun          #+#    #+#             */
/*   Updated: 2024/10/13 17:52:52 by shamdoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_lstadd_back(t_ray **lst, t_ray *new)
{
	t_ray	*head;

	if (!lst || !new)
		return ;
	head = *lst;
	if (!head)
	{
		*lst = new;
		(*lst)->previous = NULL;
	}
	else
	{
		while (head -> next)
			head = head -> next;
		head -> next = new;
		head->next->previous = head;
	}
}

void	ft_lstadd_a_back(t_data **lst, t_data *new)
{
	t_data	*head;

	if (!lst || !new)
		return ;
	head = *lst;
	if (!head)
		*lst = new;
	else
	{
		while (head -> next)
			head = head -> next;
		head -> next = new;
	}
}

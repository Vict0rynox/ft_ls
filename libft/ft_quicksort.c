/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 16:42:59 by vvasilie          #+#    #+#             */
/*   Updated: 2017/06/01 16:43:00 by vvasilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void		ft_quicksort(int *arr, int arr_size)
{
	int start;
	int end;
	int average;

	start = 0;
	end = arr_size - 1;
	average = arr[arr_size / 2];
	while (start <= end)
	{
		while (arr[start] < average)
			start++;
		while (arr[end] > average)
			end--;
		if (start <= end)
		{
			ft_swap(&arr[start], &arr[end]);
			start++;
			end--;
		}
	}
	if (end > 0)
		ft_quicksort(arr, end);
	if (arr_size > start)
		ft_quicksort(arr + start, arr_size - start);
}

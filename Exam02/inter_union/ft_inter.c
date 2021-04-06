/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 11:49:10 by najlee            #+#    #+#             */
/*   Updated: 2021/04/06 11:51:02 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char *argv[])
{
	int i;
	int j;
	int temp;

	if (argc != 3)
		return (0);
	i = 0;
	while (argv[1][i])
	{
		j = 0;
		while (argv[2][j])
		{
			if (argv[1][i] == argv[2][j])
			{	
				temp = i;
				while (argv[1][--temp] && temp >= 0)
				{	
					if (argv[1][temp] == argv[1][i])
						break;
				}
				if (temp < 0)
					write(1, &argv[1][i], 1);
				break;
			}
			j++;
		}
		i++;
	}
}

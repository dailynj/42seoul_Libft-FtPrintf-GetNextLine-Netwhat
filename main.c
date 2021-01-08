/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:56:58 by najlee            #+#    #+#             */
/*   Updated: 2021/01/08 23:13:04 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

int main()
{
	int a = 0;
	ft_printf("%0*.d", 5,  123);
	ft_printf("%0*.i", 5,  234);
	ft_printf("%0*.u", 5,  345);
	ft_printf("%0*.p", 5,  &a);
	ft_printf("%0*.c", 5,  'a');
	ft_printf("%0*.s", 5,  "abc");
	//ft_printf("%0*.x", 5,  456);
	//ft_printf("%0*.X", 5,  567);

	ft_printf("%-*.d", 5,  123);
	ft_printf("%-*.i", 5,  234);
	ft_printf("%-*.u", 5,  345);
	ft_printf("%-*.p", 5,  &a);
	ft_printf("%-*.c", 5,  'a');
	ft_printf("%-*.s", 5,  "abc");
	ft_printf("%-*.x", 5,  456);
	ft_printf("%-*.X", 5,  567);

	ft_printf("%*.d", 5,  123);
	ft_printf("%*.i", 5,  234);
	ft_printf("%*.u", 5,  345);
	ft_printf("%*.p", 5,  &a);
	ft_printf("%*.c", 5,  'a');
	ft_printf("%*.s", 5,  "abc");
	ft_printf("%*.x", 5,  456);
	ft_printf("%*.X", 5,  567);

	while(1)
	{

	}
}

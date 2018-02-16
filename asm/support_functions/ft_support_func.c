/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_support_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 14:57:16 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/04 14:57:19 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

void	ft_put_error(char *str)
{
	ft_printf("%s", str);
	exit(0);
}

void	error_name(char **av, int count_arg)
{
	ft_printf("Can't read source file %s\n", av[count_arg - 1]);
	exit(0);
}

void	error_usage(void)
{
	ft_printf("Usage: ./asm <sourcefile.s>\n");
	ft_printf("Bonuses :\n");
	ft_printf("-a for detailed print\n");
	exit(0);
}

void	free_str(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

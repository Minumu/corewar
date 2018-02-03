/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_binary.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:30:28 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/03 18:30:31 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cor.h"

char			*generate_binary(unsigned char c, t_cor *cor, int curr_i, int z)
{
	char *s;

	s = malloc(sizeof(char) * curr_i + 1);
	while (cor->lev <= curr_i)
	{
		if (c & (1 << curr_i))
			s[z] = 49;
		else
			s[z] = 48;
		--curr_i;
		z++;
	}
	return (s);
}

int				convert_uns_int(unsigned n)
{
	return ((int16_t)n);
}

unsigned char	*convert_int_to_str(int nbr)
{
	unsigned char	*s;
	int				i;
	int				byte;

	i = -1;
	byte = 24;
	s = (unsigned char *)malloc(sizeof(char) * 4);
	while (++i < 4)
	{
		s[i] = (unsigned char)((nbr >> byte) & 0xFF);
		byte -= 8;
	}
	return (s);
}

int				convert_chr_to_int(const unsigned char *s)
{
	int nbr;
	int i;
	int byte;

	i = 0;
	byte = 24;
	nbr = s[i++] << byte;
	byte -= 8;
	while (i < 4)
	{
		nbr += s[i] << byte;
		byte -= 8;
		i++;
	}
	return (nbr);
}

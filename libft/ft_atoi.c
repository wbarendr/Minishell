/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 18:34:00 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/11/15 11:19:20 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	iswhitespace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
	{
		return (1);
	}
	return (0);
}

int			ft_atoi(const char *str)
{
	int					sign;
	unsigned long int	result;

	result = 0;
	sign = 1;
	while (iswhitespace(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = (10 * result) + (*str - '0');
		str++;
	}
	if (result > 9223372036854775807 && sign == -1)
		return (0);
	else if (result >= 9223372036854775807)
		return (-1);
	return (sign * result);
}

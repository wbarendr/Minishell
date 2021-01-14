/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memsetfunctions.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: Peer <pde-bakk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 18:30:59 by pde-bakk      #+#    #+#                 */
/*   Updated: 2020/06/10 18:10:24 by Peer          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset_p(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		ptr[i] = c;
		i++;
	}
	return (b);
}

void	ft_bzero_p(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

void	*ft_calloc_p(size_t count, size_t size)
{
	void *ptr;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	ptr = malloc(count * size);
	if (ptr)
		ft_bzero_p(ptr, count * size);
	return (ptr);
}

char	*ft_strchr_p(const char *s, int c)
{
	int i;
	int len;

	len = ft_strlen_peer(s) + 1;
	i = 0;
	while (i < len)
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}

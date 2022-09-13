/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:05:09 by wrosendo          #+#    #+#             */
/*   Updated: 2022/09/12 11:05:47 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*p;

	p = ((char *)s);
	while (n--)
		*p++ = (unsigned char)c;
	return (s);
}

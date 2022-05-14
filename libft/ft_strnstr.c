/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:59:08 by aseptimu          #+#    #+#             */
/*   Updated: 2021/11/02 20:59:08 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hi;
	size_t	nj;
	char	*ret;

	ret = (char *)haystack;
	hi = 0;
	if (needle[0] == '\0')
		return (ret);
	while (ret[hi])
	{
		if (ret[hi] == needle[0])
		{
			nj = 0;
			while (needle[nj] == ret[hi + nj] && hi + nj < len \
					&& needle[nj] != '\0' && ret[hi + nj] != '\0')
			{
				nj++;
				if (needle[nj] == '\0')
					return (&ret[hi]);
			}
		}
		hi++;
	}
	return ((void *)0);
}

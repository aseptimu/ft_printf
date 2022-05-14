/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:59:08 by aseptimu          #+#    #+#             */
/*   Updated: 2021/11/02 20:59:08 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	srcl;
	size_t	dstl;

	dstl = 0;
	srcl = 0;
	dstl = ft_strlen(dst);
	srcl = ft_strlen(src);
	if (dstl > dstsize || dstsize == 0)
		return (dstsize + srcl);
	j = dstl;
	i = 0;
	while (dstsize - dstl > 1 && src[i])
	{
		dst[j++] = src[i++];
		dstsize--;
	}
	dst[j] = '\0';
	return (dstl + srcl);
}

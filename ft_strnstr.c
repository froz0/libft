/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 22:53:10 by tmatis            #+#    #+#             */
/*   Updated: 2020/10/13 17:31:05 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const	size_t	nlen = ft_strlen(needle);

	if (nlen == 0)
		return ((char *)haystack);
	while (*haystack && strncmp(haystack, needle, nlen) != 0 && len >= nlen)
	{
		haystack++;
		len--;
	}
	if (strncmp(haystack, needle, nlen) == 0)
		return ((char *)haystack);
	return (NULL);
}

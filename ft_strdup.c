/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 20:49:38 by tmatis            #+#    #+#             */
/*   Updated: 2020/10/09 12:59:53 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	len;

	len = 0;
	while (s1[len])
		len++;
	dest = (char *)malloc((len + 1) * sizeof(char));
	dest[len] = '\0';
	while (len--)
		dest[len] = s1[len];
	return (dest);
}

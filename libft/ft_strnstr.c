/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odursun <odursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:54:36 by odursun           #+#    #+#             */
/*   Updated: 2022/01/09 18:15:40 by odursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int	i;

	if (!*s2)
		return ((char *)s1);
	while (*s1 && n-- >= ft_strlen(s2))
	{
		i = 0;
		while (s2[i] == s1[i])
		{
			i++;
			if (!s2[i])
				return ((char *)(s1));
		}
		s1++;
	}
	return (NULL);
}

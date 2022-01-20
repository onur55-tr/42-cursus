/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odursun <odursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:39:47 by odursun           #+#    #+#             */
/*   Updated: 2022/01/10 10:58:56 by odursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str1;
	size_t	i;

	i = ft_strlen(s1);
	str1 = (char *)malloc(sizeof(char) * i + 1);
	if (!str1)
		return (str1);
	str1[i] = 0;
	while (i--)
		str1[i] = s1[i];
	return (str1);
}

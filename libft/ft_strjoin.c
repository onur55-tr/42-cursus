/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odursun <odursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:32:50 by odursun           #+#    #+#             */
/*   Updated: 2022/01/09 18:15:40 by odursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1l;
	size_t	s2l;
	char	*str;

	if (!s1)
		return ((char *)s1);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)));
	if (!str)
		return (str);
	s1l = 0;
	s2l = 0;
	while (s1[s1l])
		str[s2l++] = s1[s1l++];
	s1l = 0;
	while (s2[s1l])
		str[s2l++] = s2[s1l++];
	str[s2l] = '\0';
	return (str);
}

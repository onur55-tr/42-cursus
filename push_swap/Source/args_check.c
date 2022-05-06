/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odursun <odursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:29:29 by odursun           #+#    #+#             */
/*   Updated: 2022/04/14 14:00:01 by odursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

//kaç tane argüman varsa onu sayma
int	number_count(char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == ' ' || *s == '\t')
			s++;
		if ((*s >= 48 && *s <= 57) || *s == '-' || *s == '+')
			count++;
		else
			return (0);
		while ((*s >= 48 && *s <= 57) || *s == '-' || *s == '+')
			s++;
	}
	return (count);
}

/* 2 tane argüman gelme durumu ex:a.out "..." */
void	two_args(char *s, t_swap *a, t_swap *b)
{
	int	i;
	int	i_number;

	i_number = 0;
	i = 0;
	a->size = number_count(s);
	b->size = 0;
	a->array = malloc(sizeof(int) * a->size);
	b->array = malloc(sizeof(int) * a->size);
	while (*s)
	{
		while (*s == ' ' || *s == '\t')
			s++;
		if ((*s >= 48 && *s <= 57) || *s == '-' || *s == '+')
			a->array[a->size - 1 - i_number++] = ft_atoim(s, a, b);
		while ((*s >= 48 && *s <= 57) || *s == '-' || *s == '+')
			s++;
	}
}

<<<<<<< HEAD
=======
//argümanın 2 den fazla gelme durumu
void	more_args(int argc, char **argv, t_swap *a, t_swap *b)
{
	char	**new_string;
	char	*string;
	char	*tmp;
	int		i;

	i = 0;
	string = ft_strdup("");
	while (++i < argc)
	{
		tmp = ft_strjoin(string, argv[i]);
		free(string);
		string = ft_strjoin(tmp, " ");
		free(tmp);
	}
	new_string = ft_split(string, ' ');
	for (int f = 0; new_string[f]; f++)
		ft_printf("string->%s<-\n", new_string[f]);
	free(string);
	i = -1;
	while (new_string[++i])
		if (!number_count(new_string[i]))
			exit(1);
	for (int c = 0; new_string[c]; c++)
		printf("new_String: ->%s<-\ni: ->%d<-\n", new_string[c], i);
	a->size = i;
	b->size = 0;
	a->array = malloc(sizeof(int) * a->size);
	b->array = malloc(sizeof(int) * a->size);
	i = -1;
	while (new_string[++i])
	a->array[a->size - i - 1] = ft_atoim(new_string[i], a, b);
}

>>>>>>> 93a9c08c324acc54e8d16ede06f0b58fa5f58599
//çift sayı kontrolü
void	check_double(t_swap *a, t_swap *b)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->size)
	{
		j = i;
		while (j < a->size - 1)
		{
			if (a->array[i] == a->array[j++ + 1])
				error_message(a, b);
		}
		i++;
	}
}

//sıralı mı değil mi
void	check_list(t_swap *a, t_swap *b)
{
	int	i;
	int	counter;

	i = 0;
	counter = 1;
	while (i < a->size - 1)
	{
		if (a->array[i] < a->array[i + 1])
		{
			counter = 0;
			break ;
		}
		i++;
	}
	if (counter == 1)
		free_func(a, b);
}

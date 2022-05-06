#include "../Include/push_swap.h"

int	*sort_before(t_swap *a)
{
	int	i;
	int	j;
	int	*tmp;
	int	tmp_alone;

	i = -1;
	tmp = malloc(sizeof(int) * a->size);
	while (++i < a->size)
		tmp[i] = a->array[i];
	i = -1;
	while (++i < a->size)
	{
		j = i - 1;
		while (++j < a->size)
		{
			if (tmp[i] > tmp[j])
			{
				tmp_alone = tmp[i];
				tmp[i] = tmp[j];
				tmp[j] = tmp_alone;
			}
		}
	}
	return (tmp);
}

void	indexing(t_swap *a)
{
	int	*sort;
	int	i;
	int	j;

	i = 0;
	sort = sort_before(a);
	while (i < a->size)
	{
		j = 0;
		while (j < a->size)
		{
			if (a->array[i] == sort[j])
			{
				a->array[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free (sort);
}

//gelen arraylari yeni bir string içerisinde boşluk oluşturarak sayıları
// kontrol ediyoruz
char	**__arg_array(int argc, char **argv, char **new_string)
{
	char	*tmp;
	char	*string;
	int		index;

	index = 0;
	string = ft_strdup("");
	while (++index < argc)
	{
		tmp = ft_strjoin(string, argv[index]);
		free(string);
		string = ft_strjoin(tmp, " ");
		free(tmp);
	}
	new_string = ft_split(string, ' ');
	for (int f = 0; new_string[f]; f++)		ft_printf("string->%s<-\n", new_string[f]);
	free(string);
	index = -1;
	return (new_string);
}

//argümanın 2 den fazla gelme durumu
void	more_args(int argc, char **argv, t_swap *a, t_swap *b)
{
	int		i;
	char	**new_string;

	new_string = NULL;
	i = 0;
	new_string = __arg_array(argc, argv, new_string);
	while (new_string[++i])
		if (!number_count(new_string[i]))
			exit(1);
	a->size = i;
	b->size = 0;
	a->array = malloc(sizeof(int) * a->size);
	b->array = malloc(sizeof(int) * a->size);
	i = -1;
	while (new_string[++i])
		a->array[a->size - i - 1] = ft_atoim(new_string[i], a, b);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odursun <odursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:10:46 by odursun           #+#    #+#             */
/*   Updated: 2022/02/11 13:10:47 by odursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_read(char *buff, int fd, char **str)
{
	int		i;
	char	*tmp;

	if (!str[fd] || !ft_strchr(str[fd], '\n'))
	{
		i = read(fd, buff, BUFFER_SIZE);
		while (i > 0)
		{
			buff[i] = 0;
			if (!str[fd])
				str[fd] = ft_substr(buff, 0, i);
			else
			{
				tmp = str[fd];
				str[fd] = ft_strjoin(str[fd], buff);
				free(tmp);
			}
			if (ft_strchr(buff, '\n'))
				break ;
			i = read(fd, buff, BUFFER_SIZE);
		}
	}
	free (buff);
}

char	*ft_process(char **str, int fd)
{
	char	*line;
	char	*tmp;

	if (!str[fd])
		return (NULL);
	if (!ft_strchr(str[fd], '\n'))
	{
		if (!ft_strlen(str[fd]))
		{
			free(str[fd]);
			str[fd] = 0;
			return (NULL);
		}
		line = ft_substr(str[fd], 0, ft_strlen(str[fd]));
		free(str[fd]);
		str[fd] = 0;
		return (line);
	}
	line = ft_substr(str[fd], 0, ft_strlen(str[fd]) - \
			ft_strlen(ft_strchr(str[fd], '\n')) + 1);
	tmp = str[fd];
	str[fd] = ft_substr(ft_strchr(str[fd], '\n'), 1, \
			ft_strlen(ft_strchr(str[fd], '\n')) - 1);
	free(tmp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		*buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	if (fd == -1 || BUFFER_SIZE < 1 || read(fd, buff, 0) == -1)
	{
		free(buff);
		return (NULL);
	}
	ft_read(buff, fd, str);
	return (ft_process(str, fd));
}
/*
#include <stdio.h>
#include <fcntl.h>
int	main()
{
	int	fd1 = open("test1.txt", O_CREAT | O_RDWR, 0777);
    int fd2 = open("test2.txt", O_CREAT | O_RDWR, 0777);
    int fd3 = open("test3.txt", O_CREAT | O_RDWR, 0777);
    
    write(fd1, "11111\naaaaaa\n\n\ndddddd\n", 22);
    write(fd2, "222222\nbbbbbb\neeeeee\n\nttttttt\n", 28);
    write(fd3, "333333\ncccccc\n", 14);
    
    close(fd1);
    close(fd2);
    close(fd3);
    
    fd1 = open("test1.txt", O_CREAT | O_RDWR, 0777);
    fd2 = open("test2.txt", O_CREAT | O_RDWR, 0777);
    fd3 = open("test3.txt", O_CREAT | O_RDWR, 0777);

	printf("Birinci dosyanın numarası : %d\n", fd1);
	printf("İkinci dosyanın numarası : %d\n", fd2);
    printf("Ucuncu dosyanın numarası : %d\n", fd3);
    
    printf("Birinci dosyanın 1. satiri : %s",get_next_line(fd1));
	printf("ikinci dosyanın 1.satiri : %s",get_next_line(fd2));
    printf("ucuncu dosyanın 1.satiri : %s",get_next_line(fd3));
	
    printf("Birinci dosyanın 2. satiri : %s",get_next_line(fd1));
    printf("İkinci dosyanın 2. satiri : %s",get_next_line(fd2));
    printf("ucuncu dosyanın 2.satiri : %s",get_next_line(fd3));
    
    printf("Birinci dosyanın 3. satiri : %s",get_next_line(fd1));
    printf("İkinci dosyanın 3. satiri : %s",get_next_line(fd2));
    printf("ucuncu dosyanın 3.satiri : %s",get_next_line(fd3));
    
    close(fd1);
    close(fd2);
    close(fd3);
	
}*/

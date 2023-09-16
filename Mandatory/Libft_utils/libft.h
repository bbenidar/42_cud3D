/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:55:15 by moudrib           #+#    #+#             */
/*   Updated: 2023/08/22 11:48:02 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_infos
{
	int				*rgb;
	char			*value;
	char			*element;
	struct s_infos	*link;
}	t_infos;

void		ft_putnbr(int nbr);
void		ft_putstr(char *str);
ssize_t		ft_atoi(const char *str);
char		**ft_free_arr(char **arr);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *s1);
t_infos		*ft_lstlast(t_infos *head);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strtrim(char *s1, char *set);
void		*ft_destroy_list(t_infos **head);
char		**ft_split(char const *s, char c);
t_infos		*ft_lstnew(char *element, char *value);
void		ft_lstadd_back(t_infos **head, t_infos *new);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_strnstr(const char *str, const char *to_find, size_t len);

#endif

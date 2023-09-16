/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:01:17 by moudrib           #+#    #+#             */
/*   Updated: 2023/08/03 11:29:43 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include "../Libft_utils/libft.h"

char		*ft_save_rest(char *buf);
char		*ft_get_next_line(int fd);
int			ft_search_newline(char *s);
char		*ft_read_line(int fd, char *buf);

#endif
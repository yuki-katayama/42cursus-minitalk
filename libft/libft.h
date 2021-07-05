/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:42:30 by kyuki             #+#    #+#             */
/*   Updated: 2021/07/05 12:42:31 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "unistd.h"

void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
size_t			ft_strlen(const char *s);
#endif

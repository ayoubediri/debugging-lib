/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiri <adiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:12:04 by adiri             #+#    #+#             */
/*   Updated: 2025/03/31 17:34:08 by adiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_debugging.h"


/*
** @file ft_display_fd.c
** @brief Displays the status of file descriptors from 0 to number_of_fds.
** @details This function uses fstat to check if the file descriptor is open or closed.
** @param number_of_fds The number of file descriptors to check.
** @return void
*/
void ft_display_fd(int number_of_fds)
{
    struct stat statbuf;

    for (int fd = 0; fd < number_of_fds; fd++)
        {
        if (fstat(fd, &statbuf) == 0)
                {
            fprintf(stderr, "FD %d is OPEN\n", fd);
        } else 
                {
            fprintf(stderr, "FD %d is CLOSED\n", fd);
        }
    }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd_file_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiri <adiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:28:11 by adiri             #+#    #+#             */
/*   Updated: 2025/03/31 17:40:43 by adiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_debugging.h"


/*
** @file ft_fd_file_path.c
** @brief Displays the file name associated with a file descriptor.
** @details This function uses the /proc/self/fd directory to get the file name
** @param fd The file descriptor to check.
** @param commant A string to display before the file name.
** @return 0 on success, -1 on error.
*/
int ft_debug_fd(int fd, const char *commant)
{
    char path[256];
    char buf[512];
    ssize_t len;

    snprintf(path, sizeof(path), "/proc/self/fd/%d", fd);
    len = readlink(path, buf, sizeof(buf) - 1);
    if (len != -1)
    {
        buf[len] = '\0';
        fprintf(stderr,"%s (fd %d) -> %s\n", commant ? commant : "", fd, buf);
    } 
    else 
    {
        perror("readlink");
        return (-1);
    }
    return (0);
}

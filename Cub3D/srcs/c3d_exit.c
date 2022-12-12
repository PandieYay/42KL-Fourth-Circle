/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:16:44 by schuah            #+#    #+#             */
/*   Updated: 2022/12/07 17:57:14 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

int	c3d_fail_exit(char *msg, char *details)
{
	ft_dprintf(2, "Error\n%s", msg);
	if (details != NULL)
		ft_dprintf(2, ": |%s|", details);
	ft_dprintf(2, "\n");
	exit(1);
	return (1);
}

int	c3d_success_exit(void)
{
	printf("Thanks for playing!\n");
	exit(0);
	return (0);
}

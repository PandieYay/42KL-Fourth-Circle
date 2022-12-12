/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:57:41 by schuah            #+#    #+#             */
/*   Updated: 2022/11/21 12:55:57 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

int	main(int ac, char **av)
{
	t_gm	gm;

	c3d_init_gm(&gm);
	c3d_check_file(&gm, ac, av);
	c3d_hooks(&gm);
	return (c3d_success_exit());
}

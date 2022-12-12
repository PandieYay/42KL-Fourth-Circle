/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:27:11 by schuah            #+#    #+#             */
/*   Updated: 2022/11/04 12:35:12 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

void	c3d_all_elements_present(t_gm *gm)
{
	if (!gm->map.n_img.ref || !gm->map.e_img.ref
		|| !gm->map.s_img.ref || !gm->map.w_img.ref
		|| gm->map.c_rgb.hex < 0 || gm->map.f_rgb.hex < 0)
		c3d_fail_exit("Missing element", NULL);
}

int	c3d_map_contents_only(char *str)
{
	int	i;

	i = -1;
	if (str == NULL)
		return (0);
	while (str[++i] != '\0')
	{
		if ((str[i] != '1' && str[i] != '0' && str[i] != 'N' && str[i] != 'E'
				&& str[i] != 'S' && str[i] != 'W' && str[i] != ' '
				&& str[i] != 'D' && str[i] != '\t'
				&& (str[i] != '\n' || i == 0))
			|| str[ft_strlen(str) - 1] != '\n')
			return (0);
	}
	return (1);
}

int	c3d_is_all_num(char *str1, char *str2, char *str3)
{
	while (*str1 != '\0')
	{
		if (*str1 < '0' || *str1 > '9')
			return (0);
		str1++;
	}
	while (*str2 != '\0')
	{
		if (*str2 < '0' || *str2 > '9')
			return (0);
		str2++;
	}
	while (*str3 != '\0')
	{
		if (*str3 < '0' || *str3 > '9')
			return (0);
		str3++;
	}
	return (1);
}

void	c3d_trim_spaces(char *str, int len)
{
	if (len == 0 || str[len] != ' ')
		return ;
	if (str[len] == ' ')
		str[len] = '\0';
	c3d_trim_spaces(str, len - 1);
}

char	*c3d_pad_spaces(t_gm *gm, char *str)
{
	if (ft_strlen(str) < (size_t)gm->map.size.x)
	{
		str = ft_append_char(str, ' ');
		return (c3d_pad_spaces(gm, str));
	}
	return (str);
}

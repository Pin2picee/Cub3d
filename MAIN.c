/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MAIN.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:52:42 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/28 17:52:11 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/LIB.h"

int	check_extension(char *file, const char *extension)
{
	char	*after_last_point;

	after_last_point = ft_strrchr(file, '.');
	if (!after_last_point || !extension
		|| ft_strcmp(after_last_point, extension))
	{
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	data;

	ft_init_data(&data);
	(void)argc;
	data.flags = 0;
	if (main_parsing(argv[1], &data))
		printf("Error\n");
	else
	{
		init_my_mlx(&data);
		mlx_loop(data.mlx_ptr);
	}
	free_data(&data);
	return (0);
}

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 10:52:13 by schuah            #+#    #+#              #
#    Updated: 2022/12/07 17:25:15 by schuah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D
LIBFT		=	libft/libft.a
MLX			=	mlx/libmlx.a
CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -Imlx
# CFLAGS		=	-fsanitize=address -g3
MLXFLAGS	=	-L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
SRCS_FILES	=	c3d_main \
				c3d_hook \
				c3d_exit \
				c3d_init \
				c3d_door \
				c3d_draw \
				c3d_mouse \
				c3d_render \
				c3d_get_map \
				c3d_minimap \
				c3d_display \
				c3d_check_map \
				c3d_check_file \
				c3d_renderdoor \
				c3d_image_utils \
				c3d_check_utils \
				c3d_render_utils \
				c3d_player_control
SRCS		= 	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS		= 	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))
SRCS_DIR	=	srcs/
LIBFT_DIR	=	libft/
OBJS_DIR	=	objs/

all:			
				mkdir -p $(OBJS_DIR)
				make libft
				make $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(LIBFT) $(MLX) $(OBJS) $(MLXFLAGS) -o $(NAME)

libft:
				make -C $(LIBFT_DIR)

clean:
				rm -rf $(OBJS_DIR)
				make clean -C $(LIBFT_DIR)

fclean:			clean
				make fclean -C $(LIBFT_DIR)
				rm -rf $(NAME)

re:				fclean all

.PHONY:			all bonus libft clean fclean re
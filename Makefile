# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/14 09:05:11 by moudrib           #+#    #+#              #
#    Updated: 2023/09/14 17:01:07 by moudrib          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = cub3D
BONUS    = cub3D_bonus
CC      = cc
CFLAGS	= -Wall -Wextra -Werror
M_OBJDIR	= Mandatory_Object_files/
B_OBJDIR	= Bonus_Object_files/
R		= \x1B[91m
G		= \x1B[32m
W		= \x1B[0m
B		= \033[1m
MANDATORY_SRCS		= \
			Mandatory/Libft_utils/libft_utils1.c \
			Mandatory/Libft_utils/libft_utils2.c \
			Mandatory/Libft_utils/libft_utils3.c \
			Mandatory/Libft_utils/libft_utils4.c \
			Mandatory/Libft_utils/libft_utils5.c \
			Mandatory/Get_next_line/get_next_line.c \
			Mandatory/Parsing/cub3d.c \
			Mandatory/Parsing/parsing.c \
			Mandatory/Parsing/map_pars.c \
			Mandatory/Parsing/parsing_utils.c \
			Mandatory/Parsing/check_elemnts.c \
			Mandatory/Parsing/parsing_elements.c \
			Mandatory/Execution/colors.c \
			Mandatory/Execution/texture.c \
			Mandatory/Execution/raycasting.c \
			Mandatory/Execution/player_movements.c \
			Mandatory/Execution/drawing_functions.c \
			Mandatory/Execution/window_management.c \
			Mandatory/Execution/events_management.c \
			Mandatory/Execution/wall_intersections.c  \
			Mandatory/Execution/rendering_walls.c 

BONUS_SRCS		= \
			Bonus/Libft_utils/libft_utils1.c \
			Bonus/Libft_utils/libft_utils2.c \
			Bonus/Libft_utils/libft_utils3.c \
			Bonus/Libft_utils/libft_utils4.c \
			Bonus/Libft_utils/libft_utils5.c \
			Bonus/Libft_utils/libft_utils6.c \
			Bonus/Get_next_line/get_next_line.c \
			Bonus/Parsing/b_cub3d.c \
			Bonus/Parsing/b_parsing.c \
			Bonus/Parsing/b_map_pars.c \
			Bonus/Parsing/b_parsing_utils.c \
			Bonus/Parsing/b_check_elemnts.c \
			Bonus/Parsing/b_parsing_elements.c \
			Bonus/Execution/b_colors.c \
			Bonus/Execution/b_texture.c \
			Bonus/Execution/b_raycasting.c \
			Bonus/Execution/b_player_movements.c \
			Bonus/Execution/b_drawing_functions.c \
			Bonus/Execution/b_window_management.c \
			Bonus/Execution/b_events_management.c \
			Bonus/Execution/b_wall_intersections.c \
			Bonus/Execution/b_mous.c  \
			Bonus/Execution/b_rendring_wall.c \
			Bonus/Execution/b_apload_file.c \
			Bonus/Execution/b_animation.c \
			Bonus/Execution/b_draw_pixels_on_image.c 


			
MANDATORY_OBJ = $(addprefix $(M_OBJDIR), $(MANDATORY_SRCS:.c=.o))

BONUS_OBJ = $(addprefix $(B_OBJDIR), $(BONUS_SRCS:.c=.o))

all: $(NAME)

$(NAME): $(MANDATORY_OBJ)
	@$(CC) $(CFLAGS) mlx/libmlx.a -framework OpenGL -framework AppKit $(MANDATORY_OBJ) -o $(NAME)
	@clear
	@echo
	@echo "$(G)Cub3d compilation done ✔️"
	@echo
	@echo "                            $(R)██████$(W)╗ $(R)██$(W)╗   $(R)██$(W)╗ $(R)██████$(W)╗  $(R)██████$(W)╗  $(R)██████$(W)╗ "
	@echo "                           $(R)██$(W)╔════╝ $(R)██$(W)║   $(R)██$(W)║ $(R)██$(W)╔══$(R)██$(W)╗ ╚════$(R)██$(W)╗ $(R)██$(W)╔══$(R)██$(W)╗"
	@echo "                           $(W)█$(R)█$(W)║      $(W)█$(R)█$(W)║   $(R)█$(W)█$(W)║ $(W)█$(R)█████$(W)╔╝  $(R)█████$(W)╔╝ $(W)█$(R)█$(W)║  $(R)██$(W)║"
	@echo "                           $(W)██$(R)║      $(W)██$(R)║   $(W)██$(R)║ $(W)██$(R)╔══$(W)██$(R)╗  ╚═══$(W)██$(R)╗ $(W)██$(R)║  $(W)██$(R)║"
	@echo "                           ╚$(W)██████$(R)╗ ╚$(W)██████$(R)╔╝ $(W)██████$(R)╔╝ $(W)██████$(R)╔╝ $(W)██████$(R)╔╝"
	@echo "                            ╚═════╝  ╚═════╝  ╚═════╝  ╚═════╝  ╚═════╝ "
	@echo "                                                  $(B)$(R)Made by $(W)$(B)Arobase $(R)&& $(W)$(B)Don Juan"
	@echo
	@echo

$(M_OBJDIR)%.o: %.c Mandatory/cub3d.h Mandatory/Libft_utils/libft.h Mandatory/Get_next_line/get_next_line.h
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(G)Compiling: $(W)$<"

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJ)
	@$(CC) $(CFLAGS) mlx/libmlx.a -framework OpenGL -framework AppKit $(BONUS_OBJ) -o $(BONUS)

$(B_OBJDIR)%.o: %.c Bonus/cub3d_bonus.h Bonus/Libft_utils/libft.h Bonus/Get_next_line/get_next_line.h
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(G)Compiling: $(W)$<"

clean:
	@rm -rf $(M_OBJDIR) $(B_OBJDIR)

fclean:	clean
	@rm -rf $(NAME) $(BONUS)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus
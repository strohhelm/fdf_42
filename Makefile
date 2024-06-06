NAME	:= fdf
NAME_B	:= fdf_bonus
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
CC = gcc
FT_LIBS :=	libft/libft.a\
			ftprintf/libftprintf.a\
			get_next_line/get_next_line.a\
			MLX42/build/libmlx42.a

CFILES	:=	src/array_utils.c\
			src/calc_utils.c\
			src/coordinate_utils.c\
			src/atol.c\
			src/draw_grid.c\
			src/draw_line.c\
			src/hook.c\
			src/init_grid_and_window.c\
			src/main.c\
			src/matrix_calculations.c\
			src/matrix_functions.c\
			src/put_new_img_to_screen.c

BONUS := 	bonus/array_utils_bonus.c\
			bonus/calc_utils_bonus.c\
			bonus/coordinate_utils_bonus.c\
			bonus/atol_bonus.c\
			bonus/draw_grid_bonus.c\
			bonus/draw_line_bonus.c\
			bonus/hooks_bonus.c\
			bonus/hooks_utils_bonus.c\
			bonus/init_grid_and_window_bonus.c\
			bonus/main_bonus.c\
			bonus/matrix_calculations_bonus.c\
			bonus/matrix_functions_bonus.c\
			bonus/put_new_img_to_screen_bonus.c

OBJS	:= $(patsubst src/%.c, obj/%.o,$(CFILES))
BONUS_OBJS := $(patsubst bonus/%.c, bonus_obj/%.o,$(BONUS))

all:  $(NAME)
	
$(NAME): $(FT_LIBS) $(OBJS) 
	@$(CC) $(CFLAGS) $(OBJS) $(FT_LIBS) -o $(NAME) -ldl -lglfw -pthread -lm -g
	@echo MAKING fdf...

bonus: $(NAME_B)
	
$(NAME_B): $(FT_LIBS) $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(FT_LIBS) -o $(NAME_B) -ldl -lglfw -pthread -lm -g
	@echo MAKING bonus fdf...

bonus_obj/%.o: bonus/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $^ -g

obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $^ -g

$(FT_LIBS): 
	
	@make -C libft
	@make -C ftprintf
	@make -C get_next_line
	git clone https://github.com/codam-coding-college/MLX42.git
	cd MLX42 && cmake -B build && cmake --build build -j4

clean:
	@rm -rf obj
	@rm -rf bonus_obj
	@rm -rf MLX42
	@echo MAKING clean...

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(NAME_B)
	@make fclean -C libft
	@make fclean -C ftprintf
	@make fclean -C get_next_line
	@echo MAKING fclean...


re: fclean all

.PHONY: all, clean, fclean, re, bonus
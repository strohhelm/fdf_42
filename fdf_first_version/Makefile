NAME	:= fdf
CFLAGS	:= -Wextra -Wall -Wunreachable-code -Ofast
cc = cc
FT_LIBS :=	libft/libft.a\
			ftprintf/libftprintf.a\
			get_next_line/get_next_line.a\
			MLX42/build/libmlx42.a

CFILES	:=	src/1_utils.c\
			src/2_utils.c\
			src/connect_grid_with_lies.c\
			src/draw_line.c\
			src/ft_atol.c\
			src/get_grid_from_map.c\
			src/hooks.c\
			src/main.c

OBJS	:= $(patsubst 4_src/%.c, obj/%.o,$(CFILES))

all:  $(NAME)
	
$(NAME): $(FT_LIBS) $(OBJS) 
	@$(CC) $(CFLAGS) $(OBJS) $(FT_LIBS) -o $(NAME) -Iinclude -lglfw -g
	@echo MAKING fdf...


obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $^ -0O -g

$(FT_LIBS): 
	git submodule update --init
	@make -C libft
	@make -C ftprintf
	@make -C get_next_line
	@cmake MLX42 -B MLX42/build && make -C MLX42/build -j4

clean:
	@rm -rf obj
	@rm -rf MLX42/build

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft
	@make fclean -C ftprintf
	@make fclean -C get_next_line


re: fclean all

.PHONY: all, clean, fclean, re,
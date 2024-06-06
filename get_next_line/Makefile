NAME := get_next_line.a
CC := cc
CFLAGS ?= -Wall -Wextra -Werror

CFILES := 	get_next_line.c\
			get_next_line_utils.c

OBJFILES := obj/get_next_line.o\
			obj/get_next_line_utils.o

$(NAME): $(OBJFILES)
	@echo MAKING $(NAME)...
	@ar -rcs $@ $^


obj/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) -c $(CFLAGS) $^ -o $@ -g

all: $(NAME)
	
clean:
	@echo CLEAN $(NAME)...
	@rm -rf obj

fclean:
	@echo FCLEAN $(NAME)...
	@rm -rf $(NAME) obj


re: fclean all

.PHONY: all clean fclean re t 

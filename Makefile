NAME = scop
CC = gcc

SRC_PATH = ./srcs/
OBJ_PATH = ./obj/
LIB_PATH = ./lib/
INC_PATH = ./includes/ $(LIB_PATH)libft/includes/ $(LIB_PATH)glfw/include/ \
			$(LIB_PATH)libmatrices/includes/

GCC_FLGS = -Werror -Wextra -Wall -pedantic -g3
GCC_LIBS = -lglfw3 -lGLEW -framework AppKit -framework OpenGL -framework IOKit -framework CoreVideo

SRC_NAME =	main.c\
			init.c\
			parse_object.c\
			utilitaries.c\
			key_controls.c\
			shaders.c\
			test_render.c\
			set_buffers.c\

OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = libft libmatrices glfw/src

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(addprefix -L$(LIB_PATH),$(LIB_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_PATH)libft -j
	make -C $(LIB_PATH)libmatrices -j
	$(CC) $(GCC_FLGS) $(INC) $(OBJ) $(GCC_LIBS) $(LIB) -lft -lmatrices -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(GCC_FLGS) $(INC) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	rm -rf $(OBJ_PATH)

fclean: clean
	make -C $(LIB_PATH)libft fclean
	make -C $(LIB_PATH)libmatrices fclean
	rm -fv $(NAME)

re: fclean all
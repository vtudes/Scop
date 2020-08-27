SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./includes/

NAME = libmatrices.a
CC = gcc
CFGLAGS = -Werror -Wextra -Wall

SRC_NAME  = matrices_add.c\
			matrices_copy.c\
			matrices_transpose.c\
			matrices_sub.c\
			matrices_multiplication.c\
			matrices_rotation.c\
			matrices_scale.c\
			matrices_set.c\
			init_vecteurs.c\
			addition_vecteurs.c\
			copy_vecteurs.c\
			cross_vecteurs.c\
			dot_vecteurs.c\
			fmulti_vecteurs.c\
			amplitude_vecteurs.c\
			multiplication_vecteurs.c\
			normalize_vecteurs.c\
			rotation_vecteurs.c\
			scale_vecteurs.c\
			set_vecteurs.c\
			substraction_vecteurs.c\

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	rm -f $(OBJ)
	@rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all
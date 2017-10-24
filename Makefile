# Compilation
NAME = RTv1
CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

LIB_FT = ./lib/libft/libft.a

INCLUDES = -I./includes -I./lib/libft

# Sources

SRC_FILE = src/file/file_get_acr.c \
	src/file/file_get_basename.c \
	src/file/file_get_filename.c \
	src/file/file_get_group.c \
	src/file/file_get_lcount.c \
	src/file/file_get_mimedate.c \
	src/file/file_get_owner.c \
	src/file/file_get_path.c \
	src/file/file_get_pathname.c \
	src/file/file_get_size.c \
	src/file/file_get_type.c \
	src/file/file_is_dir.c \
	src/file/file_new.c \
	src/file/file_remove.c

SRC_OPTIONS = src/options/dirdata/behavior.c \
	src/options/dirdata/decorated.c \
	src/options/dirdata/decorated_columns.c \
	src/options/dirdata/decorated_default.c \
	src/options/dirdata/filter.c \
	src/options/new_args.c \
	src/options/options_by_string.c

SOURCE_FILES = $(SRC_FILE) \
	$(SRC_OPTIONS) \
	src/ft_ls.c \
	src/main.c \
	src/read_info.c

OBJ_FILES =	$(SOURCE_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@make -C ./lib/libft
	@$(CC) $(OBJ_FILES) $(INCLUDES) $(LIB_FT) $(FLAGS) $(CFLAGS) -o $(NAME)

%.o: %.c
	@$(CC) -c $(INCLUDES) $(CFLAGS) $(FLAGS) -o $@ $<

clean:
	@make clean -C ./lib/libft
	@rm -f $(OBJ_FILES)

fclean: clean
	@rm -rf $(NAME) $(LIB_FT) $(LIB_MLX)

re: fclean all
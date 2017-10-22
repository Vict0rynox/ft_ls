# Compilation
CC =	gcc
CFLAGS =	-std=c11 #-Wall -Wextra -Werror
ADDFLAGS =

# Default rule
DEFRULE =   all

# Binary
NAME =		ft_ls
DST =

# Directories
SRCDIR =	src
OBJDIR =	objs
INCDIR =	includes \
	lib/libft

# Sources

SRC_FILE = file/file_get_acr.c \
	file/file_get_basename.c \
	file/file_get_filename.c \
	file/file_get_group.c \
	file/file_get_lcount.c \
	file/file_get_mimedate.c \
	file/file_get_owner.c \
	file/file_get_path.c \
	file/file_get_pathname.c \
	file/file_get_size.c \
	file/file_get_type.c \
	file/file_is_dir.c \
	file/file_new.c \
	file/file_remove.c

SRC_OPTIONS = options/dirdata/behavior.c \
	options/dirdata/decorated.c \
	options/dirdata/decorated_columns.c \
	options/dirdata/decorated_default.c \
	options/dirdata/filter.c \
	options/new_args.c \
	options/new_options_by_string.c

SRC = $(SRC_FILE) \
	$(SRC_OPTIONS) \
	ft_ls.c \
	main.c \
	read_info.c

LIB =		ft
OBJ =		$(SRC:.c=.o)

# Prefixes
LLIBP =		$(addprefix -l, $(LIB))
LIBNAME =	$(addprefix lib/lib, $(LIB))

# Paths foreach
LIBP =		$(addprefix -L, $(LIBNAME)/)
OBJP =		$(addprefix $(OBJDIR)/, $(SRC:.c=.o))
INCP =		$(foreach dir, $(INCDIR), -I$(dir))

# **************************************************************************** #
# SPECIAL CHARS

LOG_CLEAR		= \033[2K
LOG_UP			= \033[A
LOG_NOCOLOR		= \033[0m
LOG_BOLD		= \033[1m
LOG_UNDERLINE	= \033[4m
LOG_BLINKING	= \033[5m
LOG_BLACK		= \033[1;30m
LOG_RED			= \033[1;31m
LOG_GREEN		= \033[1;32m
LOG_YELLOW		= \033[1;33m
LOG_BLUE		= \033[1;34m
LOG_VIOLET		= \033[1;35m
LOG_CYAN		= \033[1;36m
LOG_WHITE		= \033[1;37m

# **************************************************************************** #
# RULES

.PHONY: glu

# Main rules
default:
	@echo -e "$(LOG_BOLD)Default execution: rule $(DEFRULE)$(LOG_NOCOLOR)"
	@make $(DEFRULE)
	@echo -e "$(LOG_BOLD)Execution finished     $(LOG_NOCOLOR)ヽ(ヅ)ノ"


glu: re
	@make clean

all: libcomp $(OBJDIR) $(NAME)

re: fclean all

# Compilation rules
pathcat:
	echo $(INCP)
	echo $(LIBP)
	echo $(LLIBP) 
libcomp:
	@make all -C $(LIBNAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo -e "--$(LOG_CLEAR)$(LOG_VIOLET)$(NAME)$(LOG_NOCOLOR)........................ $(LOG_YELLOW)$<$(LOG_NOCOLOR)$(LOG_UP)"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(ADDFLAGS) -c -o $@ $^ $(INCP)

$(OBJDIR):
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)build $(NAME)$(LOG_NOCOLOR)"
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJP)
	@echo -e "--$(LOG_CLEAR)$(LOG_VIOLET)$(NAME)$(LOG_NOCOLOR)....................... $(LOG_YELLOW)assembling$(LOG_NOCOLOR)$(LOG_UP)"
	$(CC) $(CFLAGS) $(ADDFLAGS) -o $@ $^ $(INCP) $(LIBP) $(LLIBP)
	@echo -e "--$(LOG_CLEAR)$(LOG_VIOLET)$(NAME)$(LOG_NOCOLOR) compiled............... $(LOG_GREEN)✓$(LOG_NOCOLOR)"

# MrProper's legacy
clean:
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)clean $(NAME)$(LOG_NOCOLOR)"
	@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW)Objects$(LOG_NOCOLOR) deletion............. $(LOG_RED)×$(LOG_NOCOLOR)"
	@rm -rf $(OBJDIR)
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)clean $(LIBNAME)$(LOG_NOCOLOR)"
	@make clean -C lib/libft/

fclean:
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)clean $(LIBNAME)$(LOG_NOCOLOR)"
	@make fclean -C lib/libft/
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)clean $(NAME)$(LOG_NOCOLOR)"
	@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW)Objects$(LOG_NOCOLOR) deletion............. $(LOG_RED)×$(LOG_NOCOLOR)"
	@rm -rf $(OBJDIR)
	@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW)Binary$(LOG_NOCOLOR) deletion.............. $(LOG_RED)×$(LOG_NOCOLOR)"
	@rm -f $(NAME)

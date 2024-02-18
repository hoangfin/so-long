# Output filename NAME
NAME := libft.a

COMMON_DIR := ./common
ARRAY_DIR := ./array
LIST_DIR := ./linkedlist
STRING_DIR := ./string
GNL_DIR := ./gnl

# Compiler & flags
CC := cc
CFLAGS := -g -Wall -Wextra -Werror

# Source files
SOURCES := $(COMMON_DIR)/ft_atoi.c \
		$(COMMON_DIR)/ft_atol.c \
		$(COMMON_DIR)/ft_bzero.c \
		$(COMMON_DIR)/ft_calloc.c \
		$(COMMON_DIR)/ft_isalnum.c \
		$(COMMON_DIR)/ft_isalpha.c \
		$(COMMON_DIR)/ft_isspace.c \
		$(COMMON_DIR)/ft_isascii.c \
		$(COMMON_DIR)/ft_isdigit.c \
		$(COMMON_DIR)/ft_isprint.c \
		$(COMMON_DIR)/ft_itoa.c \
		$(COMMON_DIR)/ft_utoa.c \
		$(COMMON_DIR)/ft_ultoa.c \
		$(COMMON_DIR)/ft_memchr.c \
		$(COMMON_DIR)/ft_memcmp.c \
		$(COMMON_DIR)/ft_memcpy.c \
		$(COMMON_DIR)/ft_memmove.c \
		$(COMMON_DIR)/ft_memset.c \
		$(COMMON_DIR)/ft_putchar_fd.c \
		$(COMMON_DIR)/ft_putendl_fd.c \
		$(COMMON_DIR)/ft_putnbr_fd.c \
		$(COMMON_DIR)/ft_putstr_fd.c \
		$(COMMON_DIR)/ft_putstrchr_fd.c \
		$(COMMON_DIR)/ft_split.c \
		$(COMMON_DIR)/ft_count_digits.c \
		$(COMMON_DIR)/ft_strchr.c \
		$(COMMON_DIR)/ft_strdup.c \
		$(COMMON_DIR)/ft_striteri.c \
		$(COMMON_DIR)/ft_strjoin.c \
		$(COMMON_DIR)/ft_join_string.c \
		$(COMMON_DIR)/ft_strlcat.c \
		$(COMMON_DIR)/ft_strlcpy.c \
		$(COMMON_DIR)/ft_strlen.c \
		$(COMMON_DIR)/ft_strmapi.c \
		$(COMMON_DIR)/ft_strcmp.c \
		$(COMMON_DIR)/ft_strncmp.c \
		$(COMMON_DIR)/ft_strnstr.c \
		$(COMMON_DIR)/ft_strrchr.c \
		$(COMMON_DIR)/ft_strtrim.c \
		$(COMMON_DIR)/ft_substr.c \
		$(COMMON_DIR)/ft_tolower.c \
		$(COMMON_DIR)/ft_toupper.c \
		$(COMMON_DIR)/ft_tolower_str.c \
		$(COMMON_DIR)/ft_toupper_str.c \
		$(STRING_DIR)/ft_string.c \
		$(STRING_DIR)/ft_strdup_chr.c \
		$(STRING_DIR)/ft_grid.c \
		$(STRING_DIR)/ft_grid_delete.c \
		$(ARRAY_DIR)/ft_array.c \
		$(ARRAY_DIR)/ft_array_from.c \
		$(ARRAY_DIR)/ft_foreach.c \
		$(ARRAY_DIR)/ft_every.c \
		$(ARRAY_DIR)/ft_some.c \
		$(LIST_DIR)/ft_list.c \
		$(LIST_DIR)/ft_list_node.c \
		$(LIST_DIR)/ft_list_push.c \
		$(LIST_DIR)/ft_list_reduce.c \
		$(LIST_DIR)/ft_list_shift.c \
		$(LIST_DIR)/ft_list_unshift.c \
		$(LIST_DIR)/ft_list_foreach.c \
		$(LIST_DIR)/ft_list_every.c \
		$(LIST_DIR)/ft_list_some.c \
		$(LIST_DIR)/ft_list_map.c \
		$(LIST_DIR)/ft_list_clear.c \
		$(GNL_DIR)/get_next_line.c

# Object files
OBJECTS := $(SOURCES:.c=.o)

.PHONY = all clean fclean re

# Link object files to create an archive file for library with
# Linux command: ar crs
# where c = create, r = replace, s = index (as ranlib)
$(NAME): $(OBJECTS)
	ar crs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(COMMON_DIR)/*.o \
			$(ARRAY_DIR)/*.o \
			$(LIST_DIR)/*.o \
			$(STRING_DIR)/*.o

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

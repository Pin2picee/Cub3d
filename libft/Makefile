NAME = libft.a

CC = gcc

CFLAGS =  -W -Wall -Wextra -Werror

SRC_FILES = ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
ft_isdigit.c ft_isprint.c ft_strchr.c ft_strdup.c ft_strlcat.c \
ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strrchr.c ft_tolower.c \
ft_toupper.c ft_bzero.c ft_memset.c ft_memcpy.c ft_memmove.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c \
ft_memchr.c ft_calloc.c ft_memcmp.c ft_substr.c ft_strjoin.c \
ft_itoa.c ft_strnstr.c ft_split.c ft_striteri.c ft_strmapi.c \
ft_strtrim.c ft_printf/ft_printf.c ft_printf/number.c ft_printf/alpha.c
ft_strldup.c ft_strcmp.c

OBJ_FILES = $(SRC_FILES:.c=.o)

SRC_FILES_BONUS = ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstmap_bonus.c ft_lstlast_bonus.c \
ft_lstiter_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstadd_front_bonus.c ft_lstadd_back_bonus.c

OBJ_FILES_BONUS = $(SRC_FILES_BONUS:.c=.o)

AR = ar
ARFLAGS = rc

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ_FILES)

clean:
	rm -rf $(OBJ_FILES)


fclean: clean
	rm -f $(NAME)

bonus: $(OBJ_FILES) $(OBJ_FILES_BONUS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ_FILES) $(OBJ_FILES_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
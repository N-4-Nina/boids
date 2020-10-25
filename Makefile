NAME = boids
OS	= $(shell uname)
DIR_S = srcs
INCLUDES = -I include/
CC = clang
CFLAGS	= -O3 -Wall -Wextra -Werror
DEFINE = -D SCREEN_WIDTH=1920 -D SCREEN_HEIGHT=1080
SOURCES =  srcs/alignment.c \
srcs/cohesion.c \
srcs/draw_boids.c \
srcs/generate_boids.c \
srcs/intersection.c \
srcs/main.c \
srcs/move_boids.c \
srcs/separation.c \
srcs/utils.c \

OBJS	= ${SOURCES:.c=.o}

ifeq ($(OS), Linux)
	LIBS = `sdl2-config --cflags --libs` -lm
else
	LIBS = -l SDL2-2.0.0
endif

.c.o:
	${CC} ${CFLAGS} ${DEFINE} -c $< -o ${<:.c=.o} ${INCLUDES}

all : $(NAME)

${NAME}: ${OBJS}
		${CC} ${CFLAGS} ${INCLUDES} ${OBJS} ${LIBS} -o ${NAME}

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)/*.h
	@mkdir -p objs
	@$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

clean :
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

test : all
		./boids 20

re: fclean all

.PHONY:	clean fclean all re mlx ft

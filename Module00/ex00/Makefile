SRCS = megaphone.cpp
SRCS_PATH = ./
OBJS = ${patsubst %.cpp, ${OBJS_PATH}/%.o, ${SRCS}}
OBJS_PATH = ./objs/

CC = c++
# CFLAGS = -Wall -Wextra -Werror

vpath %.cpp ${SRCS_PATH}

NAME = megaphone

all: ${NAME}

${OBJS}: ${OBJS_PATH}/%.o: %.cpp Makefile
		mkdir -p ${OBJS_PATH}
		${CC} ${CFLAGS} -c $< -o $@ ${INC}

${NAME}:  ${OBJS}
		${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS} ${INC}	

clean:	
		rm -rf ${OBJS_PATH}


fclean:	clean;
		rm -f ${NAME}

re:	fclean ${NAME}

.PHONY: all clean fclean re

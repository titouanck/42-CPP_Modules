SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
SRCS_PATH = srcs/
INC = -I inc/

OBJS = ${patsubst %.cpp, ${OBJS_PATH}/%.o, ${SRCS}}
OBJS_PATH = ./objs/

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

vpath %.cpp ${SRCS_PATH}

NAME = unnecessaryViolence

all: ${NAME}

${OBJS}: ${OBJS_PATH}/%.o: %.cpp Makefile inc/HumanA.hpp inc/HumanB.hpp inc/Weapon.hpp
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

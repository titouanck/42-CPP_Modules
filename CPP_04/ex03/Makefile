SRCS = main.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp
SRCS_PATH = srcs/
INC = -I inc/

OBJS = ${patsubst %.cpp, ${OBJS_PATH}/%.o, ${SRCS}}
OBJS_PATH = ./objs/

CC = c++
# CFLAGS = -std=c++98 -g
CFLAGS = -g -Wall -Wextra -Werror -std=c++98

vpath %.cpp ${SRCS_PATH}

NAME = Interfaces

all: ${NAME}

${OBJS}: ${OBJS_PATH}/%.o: %.cpp Makefile inc/AMateria.hpp inc/Ice.hpp inc/Cure.hpp inc/ICharacter.hpp inc/IMateriaSource.hpp inc/Character.hpp inc/MateriaSource.hpp
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

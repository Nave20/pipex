SOURCES =	pipex.c						\
			pipex_cmd.c					\
			pipex_utils.c				\
			pipex_exec.c				\
			pipex_dev.c					\

OBJS	=	${SOURCES:%.c=${OBJDIR}%.o}

HEADER	=	pipex.h

LIB = libft/libft.a

NAME	=	pipex

CC	=	cc

FLAGS	=	-Wall -Wextra -Werror

OBJDIR	= OBJS/

all	:	${NAME}

${OBJDIR}%.o	:	%.c ${HEADER}
	mkdir -p ${OBJDIR}
	${CC} ${FLAGS} -c $< -o $@

${NAME}	:	${OBJS} ${LIB}  Makefile
	${CC} ${FLAGS}  -o $@ ${OBJS} ${LIB}

${LIB} : FORCE
	make bonus -C libft/

FORCE:

clean	:
	rm -rf ${OBJDIR}
	make fclean -C libft/

fclean	:	clean
	rm -f ${NAME}
	make fclean -C libft/

re	:	fclean all

.PHONY	:	all clean fclean re bonus FORCE
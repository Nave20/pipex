SOURCES =	pipex.c					\
			pipex_cmd.c				\
			pipex_utils.c			\
			pipex_exec.c			\
			pipex_fd.c				\
			pipex_dev.c				\
			get_next_line_bonus.c			\
			get_next_line_utils_bonus.c	\


OBJS	=	${SOURCES:%.c=${OBJDIR}%.o}

HEADER	=	pipex.h

LIB = libft/libft.a

NAME	=	pipex

CC	=	cc

FLAGS	=	#-Wall -Wextra -Werror

OBJDIR	= OBJS/

all	:	${NAME}

${OBJDIR}%.o	:	%.c ${HEADER}
	mkdir -p ${OBJDIR}
	${CC} ${FLAGS} -c $< -o $@

${NAME}	:	${OBJS} ${LIB}  Makefile
	cp libft/libft.a libft.a
	${CC} ${FLAGS}  -o $@ ${OBJS} ${LIB}

${LIB} : FORCE
	make bonus -C libft/

FORCE:

clean	:
	rm -rf ${OBJDIR}
	make fclean -C libft/

fclean	:	clean
	rm -f ${NAME}
	rm libft.a
	make fclean -C libft/

re	:	fclean all

.PHONY	:	all clean fclean re bonus FORCE
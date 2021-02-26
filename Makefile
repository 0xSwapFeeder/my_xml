##
## EPITECH PROJECT, 2020
## MakeFile
## File description:
## CompilControl
##

CC = 	gcc

SRC	=	src/xml_node.c\
		src/xml_list.c\
		src/parse_xml_node.c\
		src/parse_xml_node2.c\
		src/my_xmlwriter.c\
		src/my_xmlloader.c\
		src/my_strndup.c\
		src/my_strncpy.c\
		src/my_strcpy.c\
		src/my_strcmp.c\
		src/my_putstr_err.c\
		src/my_mem.c\
		src/load_file.c

NAME = libmy_xml.a
CFLAGS= -I ./include
DEPS = my_xml.h

OBJ	=	$(SRC:.c=.o)

%.o: %.c $(DEPS)
	gcc -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm  -f $(NAME)


re: fclean all
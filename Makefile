NAME = pathfinder

LIBAR = ./Libmx/libmx.a

DIROBJ = obj

DIRSRC = src

DIRINC = inc

LIB = ./Libmx

SRC = src/main.c \
		src/mx_printerr.c \
		src/mx_isalpha.c \
		src/mx_errors.c \
		src/mx_errors_functions.c \
		src/mx_file_to_lines.c \
		src/get_multi_len.c \
		src/mx_create_mass.c \
		src/mx_init.c

OUT = main.o \
		mx_printerr.o \
		mx_isalpha.o \
		mx_errors.o \
		mx_errors_functions.o \
		mx_file_to_lines.o \
		get_multi_len.o \
		mx_create_mass.o \
		mx_init.o

INC = inc/pathfinder.h

CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -Werror -g -fsanitize=address

all: install clean

install: 
	@cd $(LIB) && make install
	@mkdir $(DIROBJ)
	@clang $(CFLAGS) $(SRC) -c $(SRC) -I $(INC)
	@mv $(OUT) $(DIROBJ)
	@clang $(CFLAGS) $(SRC) $(LIBAR) -o $(NAME) -I $(INC)
	@make clean


uninstall: clean
	@rm -rf $(NAME)
	@cd $(LIB) && make uninstall

clean: 
	@rm -rf $(DIROBJ)
	@cd $(LIB) && make clean

reinstall: uninstall all

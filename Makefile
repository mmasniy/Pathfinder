NAME = pathfinder

INC = ./inc/pathfinder.h

HEADTMP = ./pathfinder.h

SRC = ./*.c \

SRCS = ./src/*.c \

OBJ = ./*.o \

OBJO = ./obj./*.o \

CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -Werror -g -fsanitize=address

all: install uninstall

install:
	@cd Libmx && make -f Makefile install
	@cp $(INC) $(SRCS) .
	@clang $(CFLAGS) -c $(SRC)
	@mkdir obj
	@mv $(OBJ) ./obj
	@clang $(CFLAGS) $(OBJO) libmx/libmx.a -o $(NAME)

uninstall:
	@cd libmx && make -f Makefile uninstall
	@rm -rf $(OBJO) $(SRC) $(HEADTMP)
	@rm -rf ./obj

clean : unistall
	@cd libmx && make -f Makefile clean
	@rm -rf $(NAME)

reinstall : clean all
##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Arcade Makefile
##

#Program Name
NAME 		 	= raytracer

#Sources
SRC_CORE      	= Sdl2.cpp \
								main.cpp \
								Vector3D.cpp \
								Ray3D.cpp \
								Sphere.cpp \
								ShapeList.cpp \
								Camera.cpp \
								Material.cpp \


#Objects
OBJ_CORE		= $(SRC_CORE:.cpp=.o)

#GCDA & GCNO
GCDA_CORE		= $(SRC_CORE:.cpp=.gcda)

#flags
CXXFLAGS		= -g -fno-gnu-unique -Wall -Wextra -Werror -std=c++20
CXXFLAGS 		+= -fprofile-arcs
SFML_FLAGS		= -lsfml-graphics -lsfml-window -lsfml-system
SDL_FLAGS		= -lSDL2 -lSDL2_image -lSDL2_ttf
NCURSES_FLAGS	= -lncurses
INC				= -I.

#Compiler
CC				= g++
LINKER			= g++

#Colors
GREEN 			= /bin/echo -e "\x1b[32m $1\x1b[0m"
YELLOW 			= /bin/echo -e "\x1b[33m $1\x1b[0m"

#Rules
all: core

#-----------------Games Rules--------------------

core: $(NAME)

%.o: 	%.cpp
	@$(CC) $(INC) $(CXXFLAGS) $(SDL_FLAGS) -c -o $@ $< && \
	$(call YELLOW,"🆗 $<") || \
	$(call YELLOW,"❌ $<")

$(NAME) : $(OBJ_CORE)
	@$(LINKER) -o $(NAME) $(OBJ_CORE) $(CXXFLAGS) $(SDL_FLAGS) && \
	$(call YELLOW,"✅ $@") || \
	$(call YELLOW,"❌ $@")


clean:
	@rm -f $(OBJ_CORE)
	@$(call GREEN,"✅ [$@] done !")

fclean: clean
	@rm -f $(NAME)
	@$(call GREEN,"✅ [$@] done !")

tests_fclean:
	rm -f $(OBJ_TEST)
	rm -f $(NAME)
	rm -f unit_tests
	rm -f $(GCDA_FILES)
	rm -f $(GCNO_FILES)

re: fclean all

obj: $(OBJ_CORE) $(OBJ_PACMAN) $(OBJ_SNAKE) $(OBJ_NCURSES) $(OBJ_SFML) $(OBJ_SDL)

test_obj: $(OBJ_TEST)

tests_run: fclean
	$(MAKE) obj CXXFLAGS+=--coverage -lcriterion
	$(MAKE) test_obj CXXFLAGS+=-lcriterion
	g++ -o unit_tests $(OBJ_TEST) $(CXXFLAGS) -lcriterion --coverage
	./unit_tests
	gcovr --exclude tests/
	gcovr -b --exclude tests/

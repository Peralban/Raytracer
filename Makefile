##
## EPITECH PROJECT, 2024
## Raytracer
## File description:
## Makefile
##

#-------------- Main Variables --------------#

SRC		= 		main.cpp								\
				Graphical/Sdl2.cpp						\
				DataRetriever/Parsing.cpp				\
				Math/Ray3D.cpp							\
				Math/Vector3D.cpp						\
				Math/Point3D.cpp						\
				Raytracer/Camera.cpp					\
				Raytracer/Background.cpp				\
				Raytracer/Light.cpp						\
				Shapes/ShapeList.cpp					\
				Core/Core.cpp							\
				Core/ClusterManagement.cpp				\
				Factory/Factory.cpp						\
				Shapes/TransformedShape.cpp				\

TRUE_SRC 	= 	$(patsubst %,src/%, $(SRC))

OBJ			=	$(TRUE_SRC:.cpp=.o)

NAME		=	raytracer

WARNINGS	=	-Wall -Wextra -Wshadow

INCLUDE		=	-I./src -I.

VALGRIND	=	-g3

LIBS		=	-lconfig++ -lSDL2 -lSDL2_image -lSDL2_ttf

CXXFLAGS	=	$(INCLUDE) $(WARNINGS) $(LIBS) #$(VALGRIND)

#-------------- Libs --------------#

SHAPES_LIBS_SRC		=	Shapes/Sphere.cpp					\
						Shapes/Plane.cpp					\
						Shapes/Parallelepiped.cpp			\
						Shapes/Torus.cpp					\
						Shapes/Cone.cpp						\
						Shapes/CylinderInfinite.cpp			\
						Shapes/CylinderLimited.cpp			\

SHAPE_LIBS_TRUE_SRC	=	$(patsubst %,src/%, $(SHAPES_LIBS_SRC))

SHAPES_LIBS_OBJ		=	$(SHAPE_LIBS_TRUE_SRC:.cpp=.o)

MATERIALS_LIBS_SRC	=	Materials/Glass.cpp					\
						Materials/Metal.cpp					\
						Materials/Matte.cpp					\

MATERIALS_LIBS_TRUE_SRC	=	$(patsubst %,src/%, $(MATERIALS_LIBS_SRC))

TRANSFORMATIONS_LIBS_SRC	=	Transformations/Translation.cpp		\
								Transformations/Rotation.cpp		\
								Transformations/Scale.cpp			\
								Transformations/Shear.cpp			\

TRANSFORMATIONS_LIBS_TRUE_SRC	=	$(patsubst %,src/%, $(TRANSFORMATIONS_LIBS_SRC))

TRANSFORMATIONS_LIBS_OBJ		=	$(TRANSFORMATIONS_LIBS_TRUE_SRC:.cpp=.o)

LIBS_FLAGS	=	-shared -fPIC

#-------------- Tests Variables --------------#

TEST_SRC		=	MainTests.cpp							\
					DataRetriever/ParsingTests.cpp			\

TESTS_LIBS		=	-lcriterion -lconfig++ -lSDL2 -lSDL2_image -lSDL2_ttf

TESTS_INCLUDE 		= -I./Tests/Include -I./src -I. -I./Interfaces

TESTS_COMPILATION_FLAGS	=	--coverage

TEST_TRUE_SRC	=	$(patsubst %,Tests/src/%, $(TEST_SRC))	\
					$(filter-out src/main.cpp, $(TRUE_SRC))

TESTS_FLAGS		=	$(TESTS_INCLUDE) $(WARNINGS) $(TESTS_LIBS) $(TESTS_COMPILATION_FLAGS)

#-------------- Bonus --------------#

BONUS_SRC	=	CFGGenerator/main.cpp						\
				CFGGenerator/CFGGenerator.cpp				\

BONUS_TRUE_SRC	=	$(patsubst %,Bonus/src/%, $(BONUS_SRC))

BONUS_OBJ	=	$(BONUS_TRUE_SRC:.cpp=.o)

BONUS_NAME	=	CFG_Generator

BONUS_LIBS	=	-lconfig++

#-------------- Phony & Silent Rules --------------#

.PHONY: all clean fclean re tests_run tests_compile tests_launch tests_launch tests_run shape_libs material_libs transformation_libs libs bonus_compile bonus_run bonus_clean bonus_fclean bonus_re all_clean

.SILENT: clean fclean re tests_launch tests_run shape_libs material_libs transformation_libs libs all $(NAME)

#-------------- Rules --------------#

all:	$(NAME)
	printf "\033[1;35mAll compiled ✅\033[0m\n"

$(NAME): libs
	@g++ -o $(NAME) $(TRUE_SRC) $(CXXFLAGS)
	@if [ -f $(NAME) ]; then \
		printf "\033[1;32mCompilation completed ✅\033[0m\n"; \
	else \
		printf "\033[1;31mCompilation failed ❌\033[0m\n"; \
	fi

libs: shape_libs material_libs transformation_libs


# Règle pour compiler toutes les bibliothèques de formes
shape_libs:
	for file in $(SHAPE_LIBS_TRUE_SRC); do \
  		lib_name=$${file%.cpp}.so; \
  		g++ -shared -fPIC -o $${lib_name} $${file} $(CXXFLAGS); \
  		if [ -f $${lib_name} ]; then \
  			printf "\033[1;32m$${file%.cpp}.so compiled ✅\033[0m\n"; \
  		else \
  			printf "\033[1;31m$${file%.cpp}.so compilation failed ❌\033[0m\n"; \
  		fi; \
  		mv $${lib_name} ./libs/Shapes; \
	done; \
	for file in ./libs/Shapes/*; do \
	    filename=$$(basename $$file); \
	    lower_filename=$$(echo "$$filename" | tr '[:upper:]' '[:lower:]'); \
	    mv $$file ./libs/Shapes/lib$$lower_filename; \
	    if [ -f ./libs/Shapes/lib$$lower_filename ]; then \
			printf "\033[1;32mLib $$lower_filename renamed ✅\033[0m\n"; \
		else \
			printf "\033[1;31mLib $$lower_filename renaming failed ❌\033[0m\n"; \
		fi; \
	done; \

material_libs:
	for file in $(MATERIALS_LIBS_TRUE_SRC); do \
  		lib_name=$${file%.cpp}.so; \
  		g++ -shared -fPIC -o $${lib_name} $${file} $(CXXFLAGS); \
  		if [ -f $${lib_name} ]; then \
  			printf "\033[1;32m$${file%.cpp}.so compiled ✅\033[0m\n"; \
  		else \
  			printf "\033[1;31m$${file%.cpp}.so compilation failed ❌\033[0m\n"; \
  		fi; \
  		mv $${lib_name} ./libs/Materials; \
	done; \
	for file in ./libs/Materials/*; do \
	    filename=$$(basename $$file); \
	    lower_filename=$$(echo "$$filename" | tr '[:upper:]' '[:lower:]'); \
	    mv $$file ./libs/Materials/lib$$lower_filename; \
	    if [ -f ./libs/Materials/lib$$lower_filename ]; then \
			printf "\033[1;32mLib $$lower_filename renamed ✅\033[0m\n"; \
		else \
			printf "\033[1;31mLib $$lower_filename renaming failed ❌\033[0m\n"; \
		fi; \
	done; \

transformation_libs:
	for file in $(TRANSFORMATIONS_LIBS_TRUE_SRC); do \
  		lib_name=$${file%.cpp}.so; \
  		g++ -shared -fPIC -o $${lib_name} $${file} $(CXXFLAGS); \
  		if [ -f $${lib_name} ]; then \
  			printf "\033[1;32m$${file%.cpp}.so compiled ✅\033[0m\n"; \
  		else \
  			printf "\033[1;31m$${file%.cpp}.so compilation failed ❌\033[0m\n"; \
  		fi; \
  		mv $${lib_name} ./libs/Transformations; \
	done; \
	for file in ./libs/Transformations/*; do \
	    filename=$$(basename $$file); \
	    lower_filename=$$(echo "$$filename" | tr '[:upper:]' '[:lower:]'); \
	    mv $$file ./libs/Transformations/lib$$lower_filename; \
	    if [ -f ./libs/Transformations/lib$$lower_filename ]; then \
			printf "\033[1;32mLib $$lower_filename renamed ✅\033[0m\n"; \
		else \
			printf "\033[1;31mLib $$lower_filename renaming failed ❌\033[0m\n"; \
		fi; \
	done; \

clean:
	rm -f $(OBJ)
	printf "\033[1;35mObject files removed ✅\033[0m\n"

fclean:	clean
	rm -f $(NAME)
	rm -f unit_tests*
	rm -f *.gc*
	rm -f vgcore*
	rm -f *.so
	rm -f ./libs/Shapes/*.so
	rm -f ./libs/Materials/*.so
	rm -f ./libs/Transformations/*.so
	printf "\033[1;35mFiles removed ✅\033[0m\n"

re:	fclean all
	printf "\033[1;35mRecompiled ✅\033[0m\n"

#-------------- Tests --------------#

tests_compile: fclean
	g++ -o unit_tests $(TEST_TRUE_SRC) $(TESTS_FLAGS)
	@if [ -f unit_tests ]; then \
		printf "\033[1;32mTests compiled ✅\033[0m\n"; \
	else \
		printf "\033[1;31mTests compilation failed ❌\033[0m\n"; \
	fi

tests_launch:
	./unit_tests
	printf "\033[1;35mTests launched ✅\033[0m\n"
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches
	printf "\033[1;35mCoverage generated ✅\033[0m\n"

tests_run: tests_compile tests_launch
	printf "\033[1;32mTests runned ✅\033[0m\n"

#-------------- Bonus --------------#

bonus_compile:
	g++ -o $(BONUS_NAME) $(BONUS_TRUE_SRC) $(CXXFLAGS)
	@if [ -f $(BONUS_NAME) ]; then \
		printf "\033[1;32mBonus compiled ✅\033[0m\n"; \
	else \
		printf "\033[1;31mBonus compilation failed ❌\033[0m\n"; \
	fi

bonus_run: bonus_compile
	./$(BONUS_NAME)
	printf "\033[1;35mBonus runned ✅\033[0m\n"

bonus_clean:
	rm -f $(BONUS_OBJ)
	printf "\033[1;35mBonus object files removed ✅\033[0m\n"

bonus_fclean: bonus_clean
	rm -f $(BONUS_NAME)
	printf "\033[1;35mBonus files removed ✅\033[0m\n"

bonus_re: bonus_fclean bonus_compile

#-------------- All Project --------------#

all_clean: fclean bonus_fclean
	printf "\033[1;35mAll object files removed ✅\033[0m\n"

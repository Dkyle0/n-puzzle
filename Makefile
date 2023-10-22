OS = $(shell uname -s)

NAME := n-puzzle
CC := gcc -g -Wall -Wextra -Werror
SRC := src/

FP :=	a_star_algorithm\
		branching\
		check_solv\
		closer\
		def_map\
		def_window\
		draw_boxes\
		draw_decor\
		draw_question2\
		draw_question\
		draw_text_line\
		draw_texture_from_render\
		error\
		event_proc\
		find_list_a\
		grafic_close\
		grafic_init\
		greedy_hopping_algorithm\
		get_next_line_n\
		list_a_sort\
		list_a\
		list\
		m_generator\
		map\
		move\
		n-puzzle\
		print_solve\
		queue\
		read_input\
		read_file\
		read_is\
		read_check\
		read_utils\
		rf_help\
		subsidiary_func\
		subsidiary_func2\
		strsplit\
		h_function\
		h_help\
		vertex\
		vertex_a\
		visual\
		weight\
		window
		

SRCO := srco/

ifeq ($(OS), Linux)

        SDL_INCS :=
        FRAMEWORKS := \
                -lSDL2 \
                -lSDL2_image \
                -lSDL2_ttf
        FRAMEWORKSO :=

else ifeq ($(OS), Darwin)

        SDL_INCS := \
                -I./frameworks/SDL2.framework/Versions/A/Headers \
                -I./frameworks/SDL2_image.framework/Versions/A/Headers \
                -I./frameworks/SDL2_ttf.framework/Versions/A/Headers \
                -I./frameworks/SDL2_mixer.framework/Versions/A/Headers
        FRAMEWORKS := \
                -F./frameworks \
                -rpath ./frameworks \
                -framework SDL2 \
                -framework SDL2_ttf \
                -framework SDL2_image \
                -framework SDL2_mixer
        FRAMEWORKSO := \
                -F./frameworks

endif


INC :=	-I includes/

FPO :=	$(addprefix $(SRCO), $(addsuffix .o, $(FP)))\

all:	$(SRCO) $(NAME)

$(NAME):	$(FPO)
	@$(CC) $^ $(INC) $(SDL_INCS) $(FRAMEWORKS) -o $(NAME)
	@echo $(NAME) "completed"

$(SRCO)%.o:	$(SRC)%.c
	@$(CC) -MD -c $< $(INC) $(FRAMEWORKSO) $(SDL_INCS) -o $@

$(SRCO):
	@mkdir $@

clean:
	@rm -rf $(SRCO)
	@echo $(NAME)" directory cleaning completed"

fclean:
	@rm -f $(NAME)
	@echo $(NAME)" deleted"
	@rm -rf $(SRCO)
	@echo $(NAME)" directory cleaning completed"

re:			fclean all

include $(wildcard $(SRCO)*.d)\

.PHONY:		all clean fclean re

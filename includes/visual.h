/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <ghusk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 06:27:05 by val               #+#    #+#             */
/*   Updated: 2021/05/30 19:12:55 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H
/*
**	Debian, Ubuntu, Gentoo, Fedora, openSUSE, RedHat, Centos and other
*/

# if defined(__linux__)
#  include <SDL2/SDL.h>
#  include <SDL2/SDL_image.h>
#  include <SDL2/SDL_ttf.h>
#  include <SDL2/SDL_render.h>

/*
**	Apple OSX and iOS (Darwin)
*/

# elif defined(__APPLE__)
#  include "../frameworks/SDL2.framework/Headers/SDL.h"
#  include "../frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h"
#  include "../frameworks/SDL2_image.framework/Headers/SDL_image.h"
#  include "../frameworks/SDL2_mixer.framework/Headers/SDL_mixer.h"
#  include "../frameworks/SDL2.framework/Headers/SDL_render.h"

# endif

# define SC_W_MIN 1344
# define SC_H_MIN 756

# define BOX_FILE "media/box.png"

# define FONT_BOX1 "media/arial.ttf"
# define FONT_BOX2 "media/ariblk.ttf"
# define FONT_BOX3 "media/BERNHC.TTF"
# define FONT_BOX4 "media/CASTELAR.TTF"
# define FONT_BOX5 "media/HARLOWSI.TTF"
# define FONT_BOX6 "media/LHANDW.TTF"
# define FONT_BOX7 "media/MiriamCLM-Bold.ttf"
# define FONT_BOX8 "media/swissbo.ttf"

# define DELAY_STATES 400
# define MOTION_DELEY 2

# define NO_MOVEMENT -1
# define UP_MOVEMENT 0
# define RIGHT_MOVEMENT 1
# define DOWN_MOVEMENT 2
# define LEFT_MOVEMENT 3

# include <fcntl.h>
# include <math.h>

typedef struct s_list
{
	int				i_zero;
	int				i_b;
	int				ii_min_weight;
	struct s_list	*next;
	struct s_list	*prev;
	int				i_move[4];
	int				move_weight[4];
}				t_list;

typedef struct s_list_a
{
	int				i_zero;
	int				f;
	int				h;
	int				g;
	int				*map;
	struct s_list_a	*next;
	struct s_list_a	*prev;
	struct s_list_a	*left;
	struct s_list_a	*right;
	int				i_move[4];
}				t_list_a;

typedef struct s_all
{
	char			**s_all;
	int				*i_all;
	int				*max_int;
	int				max_str;
	int				all_n;
	int				n;
	int				row;

	int				i_zero;
	int				i_b;
	t_list			*head;
	t_list			*present_move;
	t_list			*free_list;
	unsigned long	moves_num;
	Uint64			moves_step;
	unsigned long	compl_time;
	unsigned long	compl_size;

	int				h_min;
	int				h_max;
	int				h_count;
	int				skip;
	t_list_a		*present_move_a;
	t_list_a		*open_list;
	t_list_a		*close_list;
	t_list_a		*free_list_a;

	int				type_alg;
	int				type_heuristic;
	int				type_puzzle;
	Uint32			start_time;
	Uint32			end_time;
	Uint32			pr_time;
	Uint32			screen_delay;

	int				sc_width;
	int				sc_heigth;
	int				len;
	int				side_cube;
	int				xmid;
	int				ymid;
	int				*map;
	int				*def_map;
	int				*tmp_map;
	int				succ_init;
	int				user_exit;
	int				finish;
	int				key_f;

	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Surface		*screen_surface;

	SDL_Texture		*box;
	TTF_Font		*font_box;
	SDL_Texture		**numbering;
	SDL_Color		text_color;

	TTF_Font		*field_font;
	TTF_Font		*field_fmini;
	SDL_Color		field_tc;
	SDL_Color		field_tc2;
	SDL_Color		field_c;
	SDL_Color		field_c2;
}				t_all;

t_list			*create_list(int i_zero, t_list *prev, t_all *all);
t_list			*create_next_list(t_list *list, t_all *all);
void			free_list(t_list *head);

t_list_a		*create_list_a(int i_zero, int i_b, t_list_a *prev, t_all *all);
t_list_a		*find_list_a(t_list_a *head, t_list_a *list, t_all *all);
t_list_a		*extract_list_a(t_list_a *head, t_list_a *list, t_all *all);
t_list_a		*extract_top_a(t_all *all);
void			free_list_a(t_list_a *head);

void			move_next(int *map, t_list *list);
void			move_prev(int *map, t_list *list);

int				error_create_surfase(void);
int				fill_numbering(t_all *all);
void			init_var(t_all *all);
void			initial_size_data(t_all *all);
int				grafic_init(t_all *all);
void			grafic_close(t_all *all);

SDL_Surface		*loadSurface(char *name_file);
SDL_Texture		*load_texture(char *name_file, t_all *all);
SDL_Texture		*load_from_rendered_text(char *str, TTF_Font *font,
					SDL_Color color, t_all *all);
int				draw_texture_from_render(SDL_Texture *texture,
					SDL_Rect *field, t_all *all);

int				window(t_all *all);
void			event_proc(int *quit, int *pause, time_t *t, t_all *all);
int				def_window(t_all *all);

int				draw_text_line(char *str, SDL_Rect line_field,
					SDL_Color color, t_all *all);
int				draw_text_line_mini(char *str, SDL_Rect line_field,
					SDL_Color color, t_all *all);

int				draw_box(int i, float k, int direction, t_all *all);
int				draw_boxes(time_t t, int i_zero, int i_moved, t_all *all);
int				draw_decor(t_all *all);
int				draw_question(int step_y, t_all *all);
int				draw_question2(SDL_Rect line_field, int step_x,
					int step_y, t_all *all);

int				get_direction(int i_dif, int n);
void			add_el_to_queue(t_list_a *new, t_all *all);

#endif

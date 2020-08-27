#ifndef SCOP_H
# define SCOP_H

# include "libft.h"
# include "libmatrices.h"
# include <math.h>
# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <OpenGL/gl3.h>
# include <GLFW/glfw3.h>

# define OPENGL_VERSION "4.0"
# define GLFW_VERSION 4.0

# define WINDOW_W 780
# define WINDOW_H 720

# define BUFFER_SIZE 128

GLuint vertexbuffer;

typedef struct  s_movipr
{
    t_mat4	model;
	t_mat4	view;
	t_mat4	projection;
	t_mat4	mvp;
}               t_movipr;

typedef struct	s_text
{
	int				size;
	int				w;
	int				h;
}				t_text;

typedef struct	s_win
{
	GLFWwindow	*ptr;
	int			width;
	int			height;
	float       ratio;
}				t_win;

typedef struct 	s_shaders
{
	GLuint		program;
	GLint		mvp_loc;
	GLint		vpos_loc;
	GLint		vcol_loc;
}				t_shaders;

typedef struct	s_obj
{
	char			*filename;
	GLfloat			*vertex;
	GLuint			*indices;
	unsigned int	vertex_size;
	unsigned int	indices_size;
	unsigned int	indices_num;
	t_mat4			translation;
	t_mat4			rotation;
	t_vec3			axis_center;
    t_vec3			inertia;
	float			velocity;
}				t_obj;

typedef struct	s_buffer
{
	GLuint	vao;
	GLuint	vbo;
	GLuint	ebo;
	GLuint	texture;
}				t_buffer;

typedef struct	s_env
{
	t_win		win;
	t_obj		obj;
	t_shaders	shaders;
	t_buffer    buf;
    t_movipr    movipr;
	
}               t_env;

/*
** init
*/
void		init(t_env *env, int ac, char **argv);
void		vertex_buffers(t_env *env);

/*
** Parsing
*/
void        load_object(t_env *env, char *filename);

/*
** Fonctions utilitaires
*/
int		array_len(void **tab);
GLuint	*gluint_array_copy(GLuint *array, int length, int m);
void	error(char *info);

/*
** key controls
*/
void       key_controls(t_env *env);

/*
** Shaders
*/
void            create_shader_program(t_env *env);
void        	attrib(void);
void     		run_render(t_env *env);


#endif

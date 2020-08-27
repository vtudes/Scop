#ifndef LIBMATRICES_H
# define LIBMATRICES_H

# include <math.h>

# define MATRICES_ADDITION_ERR 0
# define MATRICES_SUBSTRACTION_ERR 1
# define MATRICES_MULTIPLICATION_ERR 2
# define MATRICES_TRANSPOSE_ERR 3
# define MATRICES_COPY_DATA_ERR 4

# define STAY 0
# define EXIT 1

# define AXIS_X 0
# define AXIS_Y 1
# define AXIS_Z 2

# define IDENTITY 0x7FFFFFFF

typedef struct	s_mat4
{
	float	m[16];
}				t_mat4;

typedef struct	s_vec4
{
	float	v[4];
}				t_vec4;

typedef struct	s_vec3
{
	float	v[3];
}		        t_vec3;

/*
** Operations sur matrices
*/
t_mat4	matrices_add(t_mat4 a, t_mat4 b);
t_mat4	matrices_copy(t_mat4 *a, t_mat4 b);
t_mat4	matrices_transpose(t_mat4 m);
t_mat4	matrices_sub(t_mat4 a, t_mat4 b);
t_mat4	matrices_multiplicate(t_mat4 a, t_mat4 b);
t_mat4	matrices_rotate_axis(t_mat4 m, int axis, float angle);
t_mat4	matrices_scale(t_mat4 m, float f);
void	matrices_set(t_mat4 *m, float f);

/*
** Operations sur vecteurs
*/
t_vec3	vec3(float x, float y, float z);
t_vec3	addition_vecteurs(t_vec3 a, t_vec3 b);
t_vec3	copy_vecteurs(t_vec3 *a, t_vec3 *b);
t_vec3	cross_vecteurs(t_vec3 a, t_vec3 b);
float	dot_vecteurs(t_vec3 a, t_vec3 b);
t_vec3	fmulti_vecteurs(t_vec3 v, float f);
float	amplitude_vecteurs(t_vec3 v);
t_vec3	multiplication_vecteurs(t_vec3 a, t_vec3 b);
t_vec3	normalize_vecteurs(t_vec3 v);
t_vec3	rotation_vecteurs(t_vec3 v, t_vec3 axis);
t_vec3	scale_vecteurs(t_vec3 v, float f);
void	set_vecteurs(t_vec3 *v, float f);
t_vec3	substraction_vecteurs(t_vec3 a, t_vec3 b);

#endif

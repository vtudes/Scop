#include "libmatrices.h"

t_mat4	matrices_scale(t_mat4 m, float f)
{
	int	i;

	i = -1;
	while (++i < 16)
		m.m[i] *= f;
	return (m);
}
#include "libmatrices.h"

float	dot_vecteurs(t_vec3 a, t_vec3 b)
{
	return (a.v[0] * b.v[0] + a.v[1] * b.v[1] + a.v[2] * b.v[2]);
}
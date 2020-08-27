#include "libmatrices.h"

float	amplitude_vecteurs(t_vec3 v)
{
	return (sqrt(v.v[0] * v.v[0] + v.v[1] * v.v[1] + v.v[2] * v.v[2]));
}
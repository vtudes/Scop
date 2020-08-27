#include "libmatrices.h"

t_vec3	normalize_vecteurs(t_vec3 v)
{
	float	magnitude;

	magnitude = amplitude_vecteurs(v);
	v.v[0] /= magnitude;
	v.v[1] /= magnitude;
	v.v[2] /= magnitude;
	return (v);
}
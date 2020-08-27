#include "libmatrices.h"

t_vec3	scale_vecteurs(t_vec3 v, float f)
{
	int	i;

	normalize_vecteurs(v);
	i = -1;
	while (++i < 3)
		v.v[i] *= f;
	return (v);
}
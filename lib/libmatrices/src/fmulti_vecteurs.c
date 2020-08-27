#include "libmatrices.h"

t_vec3	fmulti_vecteurs(t_vec3 v, float f)
{
	int	i;

	i = -1;
	while (++i < 3)
		v.v[i] *= f;
	return (v);
}
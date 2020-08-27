#include "libmatrices.h"

t_vec3	cross_vecteurs(t_vec3 a, t_vec3 b)
{
	t_vec3	tmp;

	tmp.v[0] = a.v[1] * b.v[2] - a.v[2] * b.v[1];
	tmp.v[1] = a.v[2] * b.v[0] - a.v[0] * b.v[2];
	tmp.v[2] = a.v[0] * b.v[1] - a.v[1] * b.v[0];
	copy_vecteurs(&a, &tmp);
	return (a);
}
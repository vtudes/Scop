#include "libmatrices.h"

t_vec3	rotation_vecteurs(t_vec3 v, t_vec3 axis)
{
	t_vec3	tmp;

	copy_vecteurs(&tmp, &v);
	if (axis.v[2] != 0.0)
	{
		axis.v[2] *= (M_PI / 180);
		tmp.v[0] = v.v[0] * cos(axis.v[2]) - v.v[1] * sin(axis.v[2]);
		tmp.v[1] = v.v[0] * sin(axis.v[2]) + v.v[1] * cos(axis.v[2]);
	}
	if (axis.v[1] != 0.0)
	{
		axis.v[1] *= (M_PI / 180);
		tmp.v[0] = v.v[0] * cos(axis.v[1]) - v.v[2] * sin(axis.v[1]);
		tmp.v[2] = v.v[0] * sin(axis.v[1]) + v.v[2] * cos(axis.v[1]);
	}
	if (axis.v[0] != 0.0)
	{
		axis.v[0] *= (M_PI / 180);
		tmp.v[1] = v.v[1] * cos(axis.v[0]) - v.v[2] * sin(axis.v[0]);
		tmp.v[2] = v.v[1] * sin(axis.v[0]) + v.v[2] * cos(axis.v[0]);
	}
	copy_vecteurs(&v, &tmp);
	return (v);
}
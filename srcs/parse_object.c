#include "scop.h"

static GLfloat     *fill_vertex(GLfloat *array, char *line, int *length)
{
    int		i;
	int		j;
	char	**tab;
    //int     count;
    //int     count2;
	GLfloat	*new;

    //count = 0;
	tab = ft_strsplit(&line[1], ' ');
	*length += 6;
	new = (GLfloat*)malloc(sizeof(GLfloat) * *length);
	i = -1;
	while (++i < *length - 6)
		new[i] = array[i];
	free(array);
	array = new;
	j = -1;
	while (tab[++j] != NULL)
	{
		array[*length - 6 + j] = (GLfloat)ft_atof(tab[j]);
		array[*length - 3 + j] = j * 0.66f;
		ft_strdel(&tab[j]);
        //count++;
	}
	ft_strdel(&tab[j]);
	free(tab);
	tab = NULL;
    //for (count2 = 0; count2 < count; count2++)
    //    printf("%f\n", array[count2]);
	return (array);
}


/*
** Si j'ai 3 indices je malloc de 3 et wi j'en ait 4 je mallox de
** 2x3, c'est un peu moche, mais ca marche, donc nik
*/
static GLuint          *fill_indices(GLuint *array, char *line, int *length)
{
    int		j;
	int		m;
	char	**tab;

	tab = ft_strsplit(&line[1], ' ');
	m = array_len((void**)tab) == 4 ? 6 : 3;
	*length += m;
	array = gluint_array_copy(array, *length, m);
	j = -1;
	while (++j < 3)
	{
		array[*length - m + j] = (GLuint)ft_atoi(tab[j]) - 1;
		if (m == 6)
			array[*length - m + 3 + j] =
			(GLuint)ft_atoi(tab[j > 0 ? j + 1 : 0]) - 1;
		ft_strdel(&tab[j]);
	}
	ft_strdel(&tab[j]);
	free(tab);
	tab = NULL;
	return (array);
}

void        load_object(t_env *env, char *filename)
{
    int		fd;
	int		v;
	int		f;
	char	*line;

	v = 0;
	f = 0;
	env->obj.vertex = (GLfloat*)malloc(sizeof(GLfloat) * 3);
	env->obj.indices = (GLuint*)malloc(sizeof(GLuint) * 3);
    if ((fd = open(filename, O_RDWR)) == -1)
		error("Object file failed to open.");
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == 'v' && line[1] == ' ')
			env->obj.vertex = fill_vertex(env->obj.vertex, line, &v);
        else if (line[0] == 'f' && line[1] == ' ')
			env->obj.indices = fill_indices(env->obj.indices, line, &f);   
        ft_strdel(&line);
    }
    ft_strdel(&line);
    env->obj.vertex_size = v * sizeof(GLfloat);
    env->obj.indices_size = f * sizeof(GLuint);
    env->obj.indices_num = f;
}

#include "scop.h"

void		vertex_buffers(t_env *env)
{
	glGenBuffers(1, &env->buf.vbo);
	glGenBuffers(1, &env->buf.ebo);
	glGenVertexArrays(1, &env->buf.vao);
	glBindVertexArray(env->buf.vao);
}

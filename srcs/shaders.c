#include "scop.h"

static GLuint   create_program(GLuint shader_vert, GLuint shader_frag)
{
    GLint       success;
    GLuint      program;

    program = glCreateProgram();
    glAttachShader(program, shader_vert);
    glAttachShader(program, shader_frag);
    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success)
        error("Creation de shader program a po marché");
    glDeleteShader(shader_vert);
    glDeleteShader(shader_frag);
    return(program);
}

static GLchar   *fetch_shaders(char *filename)
{
    int     fd;
    int     ret;
    char	buffer[BUFFER_SIZE];
	char	*source;
	char	*del;

	source = ft_strnew(BUFFER_SIZE);
	if ((fd = open(filename, O_RDONLY)) == -1)
		error("shader source file opening failed.");
	while ((ret = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[ret] = '\0';
		del = source;
		source = ft_strjoin(source, buffer);
		ft_strdel(&del);
	}
	close(fd);
	return (source);

}

static GLuint   create_shader(char *filename, int type)
{
	GLint			success;
	GLuint			shader;
	const GLchar	*shader_source;

	shader_source = fetch_shaders(filename);
	shader = glCreateShader(type);
	glShaderSource(shader, 1, &shader_source, NULL);
	glCompileShader(shader);
	free((void*)shader_source);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
		error("shader compilation failed.");
	return (shader);
}

void            create_shader_program(t_env *env)
{
    GLuint  shader_vert;
    GLuint  shader_frag;

    ft_putendl("Grosse teuch");
    shader_vert = create_shader("./shader/vertex_shaders", GL_VERTEX_SHADER);
	shader_frag = create_shader("./shader/fragment_shaders", GL_FRAGMENT_SHADER);
    env->shaders.program =  create_program(shader_vert, shader_frag);
    //env->shaders.mvp_loc = glGetUniformLocation(env->shaders.program, "MVP");
    //env->shaders.vpos_loc = glGetUniformLocation(env->shaders.program, "vPos");
    //env->shaders.vcol_loc = glGetUniformLocation(env->shaders.program, "vCol");
}

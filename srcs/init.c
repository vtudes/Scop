#include "scop.h"

static void init_window(t_env *env)
{
	int	width;
	int	height;

	env->win.ptr = glfwCreateWindow(env->win.width, env->win.height, "Scop", NULL, NULL);
    if (env->win.ptr == NULL)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
	glfwMakeContextCurrent(env->win.ptr);
	glfwGetFramebufferSize(env->win.ptr, &width, &height);
	glViewport(0, 0, width, height);
    glfwSetInputMode(env->win.ptr, GLFW_STICKY_KEYS, 1);
}

static void init_glfw(void)
{
    if (!glfwInit())
    {
		ft_putstr("ERROR: glfw initialization failed.");
        exit(EXIT_FAILURE);
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_SAMPLES, 4); //antialiasing x4
}

void		init(t_env *env, int ac, char **av)
{
	if (ac == 2 && ft_strcmp(&av[1][ft_strlen(av[1]) - 4], ".obj") == 0)
		env->obj.filename = av[1];
    env->win.width = WINDOW_W;
	env->win.height = WINDOW_H;
    env->win.ratio = env->win.width / (float)env->win.height;
    init_glfw();
    init_window(env);
}

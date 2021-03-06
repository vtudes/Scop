//#include "scop.h"
//
//static const GLfloat g_vertex_buffer_data[] = {
//   -1.0f, -1.0f, 0.0f,
//   1.0f, -1.0f, 0.0f,
//   0.0f,  1.0f, 0.0f,
//};
//
//static void init_window(t_env *env)
//{
//	env->win.ptr = glfwCreateWindow(env->win.width, env->win.height, "Scop", NULL, NULL);
//    if (env->win.ptr == NULL)
//    {
//        glfwTerminate();
//        exit(EXIT_FAILURE);
//    }
//    glfwMakeContextCurrent(env->win.ptr);
//    //glfwSwapInterval(1);
//    GLuint vertexbuffer;
//    glGenBuffers(1, &vertexbuffer);
//    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
//    create_shader_program(env);
//    while (!glfwWindowShouldClose(env->win.ptr))
//    {
//        //glfwGetFramebufferSize(env->win.ptr, &env->win.width, &env->win.height);
//        key_controls(env);
//
//        glEnableVertexAttribArray(0);
//        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
//        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
//        glDrawArrays(GL_TRIANGLES, 0, 3);
//        glDisableVertexAttribArray(0);
//
//        glfwPollEvents();
//        continue ;
//    }
//}
//
//static void init_glfw(void)
//{
//    if (!glfwInit())
//    {
//		ft_putstr("ERROR: glfw initialization failed.");
//        exit(EXIT_FAILURE);
//    }
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//    glfwWindowHint(GLFW_SAMPLES, 4); //antialiasing x4
//}
//
//void		init(t_env *env, int ac, char **av)
//{
//	if (ac == 2 && ft_strcmp(&av[1][ft_strlen(av[1]) - 4], ".obj") == 0)
//		env->obj.filename = av[1];
//    //printf("%s", env->obj.filename);
//    env->win.width = WINDOW_W;
//	env->win.height = WINDOW_H;
//    env->win.ratio = env->win.width / (float)env->win.height;
//    init_glfw();
//    init_window(env);
//}
//
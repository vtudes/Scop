#include "scop.h"


void     run_render(t_env *env)
{
    (void)env;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glUseProgram(env->shaders.program);

    glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
    glDisableVertexAttribArray(0);

    glfwPollEvents();
}

int		        main(int ac, char **av)
{
	t_env env;

    init(&env, ac, av);
    load_object(&env, env.obj.filename);
    printf("%s\n", glfwGetVersionString());
    create_shader_program(&env);
    attrib();
    while (!glfwWindowShouldClose((&env)->win.ptr))
    {
        key_controls(&env);
        run_render(&env);

    }
    glfwTerminate();
    //create_shader_program(&env);
	return (0);
}

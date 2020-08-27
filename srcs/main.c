#include "scop.h"

static const GLfloat g_vertex_buffer_data[] = {
   -1.0f, -1.0f, 0.0f,
   1.0f, -1.0f, 0.0f,
   0.0f,  1.0f, 0.0f,
};

int		        main(int ac, char **av)
{
	t_env env;

    init(&env, ac, av);
    load_object(&env, env.obj.filename);
    create_shader_program(&env);

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
	

    while (!glfwWindowShouldClose((&env)->win.ptr))
    {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        key_controls(&env);

    	glUseProgram(env.shaders.program);
		
		// BEGIN DRAWING

    	glEnableVertexAttribArray(0);

	    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

		glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle

    	glDisableVertexAttribArray(0);

		// END DRAWING
    	
		glfwSwapBuffers(env.win.ptr);
    	glfwPollEvents();
    }
    glfwTerminate();
	return (0);
}

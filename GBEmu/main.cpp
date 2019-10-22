#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

int GB_WIDTH = 160;
int GB_HEIGHT = 144;
int gb_mult = 5;

int main()
{
	if (!glfwInit())
	{
		fprintf(stderr, "Error: Failed to initialize GLFW\n");
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);									//AA x4
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);						//OpenGL ver 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);		//Current OpenGL

	GLFWwindow* window;
	window = glfwCreateWindow(gb_mult * GB_WIDTH, gb_mult * GB_HEIGHT, "GB Emu", NULL, NULL);
	if (window == NULL)
	{
		fprintf(stderr, "Error: Failed to create window.\n");
		return -1;
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);  //Init GLEW
	if (glewInit() != GLEW_OK)
	{
		fprintf(stderr, "Error: Failed to initialize GLEW.\n");
		return -1;
	}


	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	do 
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	} while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
}
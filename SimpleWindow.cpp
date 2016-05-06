// first OpenGL program

#include <iostream>

// include GLEW header
#define GLEW_STATIC
#include <GL/glew.h>

// include GLFW
#include <GLFW/glfw3.h>

int main()
{
	int iErrorCode;

	// init GLFW
	iErrorCode = glfwInit();
	if (iErrorCode != GL_TRUE)
	{
		std::cout<< "Error while initialising GLFW.";
		return 0;
	}

	// set window hints
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE); // comment this to enable resizable property

	// create window object
	GLFWwindow* window = glfwCreateWindow(800, 600, "Simple Window", nullptr, nullptr);
	if ( window == nullptr )
	{
		std::cout<< "Error while creating window";
		glfwTerminate();
		return 0;
	}

	// make window current context
	glfwMakeContextCurrent(window);

	// init GLEW
	// this will init all the function pointers to all GL calls.
	glewExperimental = GL_TRUE;
	iErrorCode = glewInit();
	if (iErrorCode != GLEW_OK)
	{
		std::cout<< "Error while initialising GLEW";
		glfwTerminate();
		return 0;
	}

	// setting up viewport
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);

	// gameloop i.e. continious polling
	// check for window closure
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	// cleaning up
	glfwTerminate();
	
	return 0;
}
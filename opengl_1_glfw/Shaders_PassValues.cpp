//#include <iostream>
//
//// GLEW
//#define GLEW_STATIC
//#include <GL/glew.h>
//
//// GLFW
//#include <GLFW/glfw3.h>
//
//
//// Function prototypes
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
//
//// Window dimensions
//const GLuint WIDTH = 1600, HEIGHT = 1200;
//
//// Shaders
//const GLchar* vertexShaderSource = "#version 330 core\n"
//"layout (location = 0) in vec3 position;\n"
//"out vec4 colorVertex;\n"
//"void main()\n"
//"{\n"
//"gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
//"colorVertex = vec4(0.0f, 1.0f, 1.0f, 1.0f);\n"
//"}\0";
//
//const GLchar* fragmentShaderSource = "#version 330 core\n"
//"in vec4 colorVertex;\n"
//"out vec4 color;\n"
//"void main()\n"
//"{\n"
//"color = colorVertex;\n"
//"}\n\0";
//
//
//// The MAIN function, from here we start the application and run the game loop
//int main()
//{
//	std::cout << "Starting GLFW context, OpenGL 3.3" << std::endl;
//
//	// Init GLFW
//	glfwInit();
//
//	// Set all the required options for GLFW
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
//
//	// Create a GLFWwindow object that we can use for GLFW's functions
//	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGL Tutorial 1 - GLFW", nullptr, nullptr);
//	glfwMakeContextCurrent(window);
//
//	glfwSetKeyCallback(window, key_callback);
//
//	glewExperimental = GL_TRUE;
//	glewInit();
//
//	int width, height;
//	glfwGetFramebufferSize(window, &width, &height);
//	glViewport(0, 0, width, height);
//	
//	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//	GLuint shaderProgram = glCreateProgram();
//	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//	glCompileShader(vertexShader);
//	glCompileShader(fragmentShader);
//	glAttachShader(shaderProgram, vertexShader);
//	glAttachShader(shaderProgram, fragmentShader);
//	glLinkProgram(shaderProgram);
//	glDeleteShader(vertexShader);
//	glDeleteShader(fragmentShader);
//
//	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	GLfloat vertices[] = {
//		-0.5f, -0.5f, 0.0f, // left
//		0.5f, -0.5f, 0.0f,	// right
//		0.0f, 0.5f, 0.0f,	// top
//	};
//
//	GLuint VAO, VBO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	glBindVertexArray(VAO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindVertexArray(0);
//
//	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	// Game loop
//	while (!glfwWindowShouldClose(window))
//	{
//		glfwPollEvents();
//
//		// ============================================
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		glUseProgram(shaderProgram);
//		glBindVertexArray(VAO);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//		glBindVertexArray(0);
//
//		// ===========================================
//
//		glfwSwapBuffers(window);
//	}
//
//	// Terminate GLFW, clearing any resources allocated by GLFW.
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//	glfwTerminate();
//	return 0;
//}
//
//// Is called whenever a key is pressed/released via GLFW
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
//{
//	std::cout << key << std::endl;
//	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, GL_TRUE);
//	else
//		std::cout << "You pressed key: " << key << std::endl;
//}
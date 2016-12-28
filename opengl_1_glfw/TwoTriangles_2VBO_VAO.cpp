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
//"void main()\n"
//"{\n"
//"gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
//"}\0";
//
//const GLchar* fragmentShaderOrangeSource = "#version 330 core\n"
//"out vec4 color;\n"
//"void main()\n"
//"{\n"
//"color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//"}\n\0";
//
//const GLchar* fragmentShaderYellowSource = "#version 330 core\n"
//"out vec4 color;\n"
//"void main()\n"
//"{\n"
//"color = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
//"}\n\0";
//
//
//// The MAIN function, from here we start the application and run the game loop
//int main()
//{
//	std::cout << "Starting GLFW context, OpenGL 3.3" << std::endl;
//
//	//////////////////	INIT GLFW & GLEW	////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
//	if (window == nullptr)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//
//	// Set the required callback functions
//	glfwSetKeyCallback(window, key_callback);
//
//	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
//	glewExperimental = GL_TRUE;
//
//	// Initialize GLEW to setup the OpenGL Function pointers
//	if (glewInit() != GLEW_OK)
//	{
//		std::cout << "Failed to initialize GLEW" << std::endl;
//		return -1;
//	}
//
//	// Define the viewport dimensions
//	int width, height;
//	glfwGetFramebufferSize(window, &width, &height);
//	glViewport(0, 0, width, height);
//
//	//////////////////	END INIT GLFW & GLEW	////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	//////////////////	START SHADERS	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	GLuint fragmentShaderOrange = glCreateShader(GL_FRAGMENT_SHADER); // The first fragment shader that outputs the color orange
//	GLuint fragmentShaderYellow = glCreateShader(GL_FRAGMENT_SHADER); // The second fragment shader that outputs the color yellow
//	GLuint shaderProgramOrange = glCreateProgram();
//	GLuint shaderProgramYellow = glCreateProgram(); // The second shader program
//
//	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//	glCompileShader(vertexShader);
//	glShaderSource(fragmentShaderOrange, 1, &fragmentShaderOrangeSource, NULL);
//	glCompileShader(fragmentShaderOrange);
//	glShaderSource(fragmentShaderYellow, 1, &fragmentShaderYellowSource, NULL);
//	glCompileShader(fragmentShaderYellow);
//	// Link the first program object
//	glAttachShader(shaderProgramOrange, vertexShader);
//	glAttachShader(shaderProgramOrange, fragmentShaderOrange);
//	glLinkProgram(shaderProgramOrange);
//	// Then link the second program object using a different fragment shader (but same vertex shader) this time.
//	// This is perfectly allowed since the inputs and outputs of both the vertex and fragment shaders are equally matched.
//	glAttachShader(shaderProgramYellow, vertexShader);
//	glAttachShader(shaderProgramYellow, fragmentShaderYellow);
//	glLinkProgram(shaderProgramYellow);
//
//	// delete shader objects, we no longer need them since they have been linked to program object
//	glDeleteShader(vertexShader);
//	glDeleteShader(fragmentShaderOrange);
//	glDeleteShader(fragmentShaderYellow);
//	//////////////////	END SHADERS	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//	////////////////////	CREATE VERTEX OBJECTS AND ATTRIBUTES	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	GLfloat vertices[] = {
//		-0.5f, -0.6, 0.0f,	// Triangle 1
//		-0.5f, 0.4f, 0.0f,
//		0.5f, -0.6f, 0.0f
//	};
//
//	GLfloat vertices2[] = {
//		-0.5f, 0.6f, 0.0f,	// Triangle 2
//		0.5f, 0.6f, 0.0f,
//		0.5f, -0.4f, 0.0f
//	};
//
//	// Create Vertex Array Object, Vertex Buffer Object, Element Buffer Object
//	GLuint VBOs[2], VAOs[2];
//	glGenVertexArrays(2, VAOs);
//	glGenBuffers(2, VBOs);
//
//	// ==============================
//	// Triangle 1 setup
//	// ==============================
//	glBindVertexArray(VAOs[0]);
//	glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//	glBindVertexArray(0);
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//
//	// ==============================
//	// Triangle 2 setup
//	// ==============================
//	glBindVertexArray(VAOs[1]);
//	glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//	glBindVertexArray(0);
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//	////////////////////	END CREATE VERTEX OBJECTS AND ATTRIBUTES	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//	// Game loop
//	while (!glfwWindowShouldClose(window))
//	{
//		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
//		glfwPollEvents();
//
//		// Render
//		// Clear the colorbuffer
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//
//		// draw triangle 1
//		glUseProgram(shaderProgramOrange);
//		glBindVertexArray(VAOs[0]);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//
//		// draw triangle 2
//		glUseProgram(shaderProgramYellow);
//		glBindVertexArray(VAOs[1]);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//		glBindVertexArray(0);
//
//		
//		// Swap the screen buffers
//		glfwSwapBuffers(window);
//	}
//
//
//
//	//////////	CLEAN UP	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	// Terminate GLFW, clearing any resources allocated by GLFW.
//	glDeleteVertexArrays(1, VAOs);
//	glDeleteBuffers(1, VBOs);
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
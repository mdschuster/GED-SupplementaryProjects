//must include glad before glfw
#include "../external/GLAD/include/glad.h"
#include "../external/GLFW/include/glfw3.h"

#include <iostream>

void processInput(GLFWwindow *window);
unsigned int createShaderProgram();
void setupArrayObjects(unsigned int& VAO, unsigned int& VBO, float vertices[], int arraySize);
GLFWwindow* createWindow();

int main(int argc, char** argv) {
    //!Initialization
    //setup the OpenGL window
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); //needed for mac

  
    //create the window and opengl context using glfw
    GLFWwindow* window=createWindow();
    if(window==nullptr){
        return -1;
    }

    //create the shader program for coloring our triangle
    unsigned int shaderProgram = createShaderProgram();
 

    //setting up a triangle vertices in an array (p1, p2, p3)
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };  

    //create the vertex array and vertex buffer objects
    unsigned int VBO, VAO;
    //setup vertex array and buffer objects with our vertices
    setupArrayObjects(VAO, VBO, vertices, sizeof(vertices));


    //!Main drawing loop
    
    //show window until it should close
    while(!glfwWindowShouldClose(window))
    {
        //clearing the window to the clear color
        glClear(GL_COLOR_BUFFER_BIT);
        processInput(window);

        //do any rendering here...
        //now, use this shader program
        glUseProgram(shaderProgram);
        //use VAO objects
        glBindVertexArray(VAO);
        //draw what is in VAO as triangles
        glDrawArrays(GL_TRIANGLES, 0, 3);

        //swap the buffer using glfw
        glfwSwapBuffers(window);
        //get any key,mouse,etc events
        glfwPollEvents();    
    }

    //!Clean Up shader, buffers, and arrays
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);


    glfwTerminate();
    return 0;
  
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

GLFWwindow* createWindow(){
    //!Window Creation
    //create the window using glfw
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Window", NULL, NULL);
    //for mac (and retina display), need to get the frame buffer size and width from glfw
    int frameBufferHeight, frameBufferWidth;
    glfwGetFramebufferSize(window, &frameBufferWidth, &frameBufferHeight);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return nullptr;
    }

    glfwMakeContextCurrent(window);

	//initalize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return nullptr;
    }  

    //set actual opengl viewport (use the fbheight and fbwidth from above here, needed for mac because of retina display)
    glViewport(0, 0, frameBufferWidth, frameBufferHeight);

    //setting the window clear color
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    return window;
}

unsigned int createShaderProgram(){
    //!Shader creation and compliation

    //vertex shader stored as a c-style string:
    const char *vertexShaderSource = "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";

    //we must compile the shader at run time!
    //create a vertex shader ID
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    //save the c-string vertex shader into the id and compile
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    //you may waht to check if the compilation was successful:
    int  success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    //fragment shader (similar to vertex shader)
    const char *fragmentShaderSource="#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0);\n"
        "}\0";
    //same as vertex shader: create and ID, set to the string and compile
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    //check that it compiled correctly
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    //with both shaders compiled, let's create the program (link, just like a regular program)
    //this is just combining the shaders into one program
    //create the progrm by first creating and ID and then glCreateProgram()
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    //then, attach the shaders to the program and link
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    //we can, and probably should, check if the shader program failed to link:
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::LINKING_FAILED\n" << infoLog << std::endl;
    }

    //we no longer need the individual shader objects
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);  
    return shaderProgram;
}


void setupArrayObjects(unsigned int& VAO, unsigned int& VBO, float vertices[], int arraySize){

    //essentially, we are determining how opengl will interpret our vertex data
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first.
    glBindVertexArray(VAO);
    //bind and set vertex buffer(s) (anything i do with buffer affects VBO, because it is bound right now)
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, arraySize*sizeof(float), vertices, GL_STATIC_DRAW); //for the VBO
    //configure vertex attributes(s) (anything I do with vertex array affects VAO, because it is bound right now)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0); //for the VAO
    glEnableVertexAttribArray(0);

    //unbinding buffer and vertex arrays
    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0); 
}
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <GL/glew.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>

#include "VertexBuffer.h"
void GLAPIENTRY
MessageCallback( GLenum source,
                 GLenum type,
                 GLuint id,
                 GLenum severity,
                 GLsizei length,
                 const GLchar* message,
                 const void* userParam )
{
  fprintf( stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
           ( type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "" ),
            type, severity, message );
}


std::stringstream get_file(std::string path){
    std::stringstream result;
    std::ifstream stream(path);
    std::string line;
    while(getline(stream,line))
        result << line << "\n";
    return result;
}

GLuint createShader(std::string& shader,GLenum type){
    GLuint id = glCreateShader(type);
    const char* shader_c_string = shader.c_str();
    glShaderSource(id,1,&shader_c_string,nullptr);
    glCompileShader(id);

    GLint result;
    glGetShaderiv(id,GL_COMPILE_STATUS,&result);
    if(result == GL_FALSE){
        GLint length;
        glGetShaderiv(id,GL_INFO_LOG_LENGTH,&length);
        char *message = (char*)alloca(sizeof(char)*length);
        glGetShaderInfoLog(id,length,&length,message);
        std::cout << "Failed to compile "<<(type == GL_VERTEX_SHADER ? "vertex" : "fragment") << "shader"<<std::endl;
        std::cout << message << std::endl;
    }

    return id;
}

int main(void)
{
    GLFWwindow* window;

    
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);


    GLenum err = glewInit();
    if(err != GLEW_OK){
        std::cout <<"error :"<< glewGetErrorString(err);
        return 0;
    }


    glEnable              ( GL_DEBUG_OUTPUT );
    glDebugMessageCallback( MessageCallback, 0 );

    // Create a buffer
    unsigned int no_of_vertices = 8;
    int no_of_indices = 6;
    float vertices[] = {
        -1,-1,
        1,1,
        -1,1,
        1,-1
    };
    float vertices2[] = {
        -1,-1,
        1,1,
        -1,1,
        1,-0.8
    };
    unsigned int indices[] = {
        0,1,2,
        0,1,3
    };


    VertexBuffer vb;
    vb.addData(vertices,no_of_vertices,2);
    vb.bind();
    unsigned int ibo;
    glGenBuffers(1,&ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices),indices,GL_DYNAMIC_DRAW);
    vb.unbind();



    //create and attach shaders

    std::string vs_source = get_file("./res/shaders/basic.vert").str(),
    fs_source = get_file("./res/shaders/basic.frag").str();

    GLuint program = glCreateProgram();
    GLuint vs = createShader(vs_source,GL_VERTEX_SHADER);
    GLuint fs = createShader(fs_source,GL_FRAGMENT_SHADER);

    glAttachShader(program,vs);
    glAttachShader(program,fs);
    glLinkProgram(program);
    glUseProgram(program);
    
    unsigned int time_location = glGetUniformLocation(program,"u_Time");
    float time = 0;

    // glUseProgram(0);
    // glBindVertexArray(0);
    // glBindBuffer(GL_ARRAY_BUFFER,0);
    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
    vb.bind();
    while (!glfwWindowShouldClose(window))
    {
        glUniform1f(time_location,time);
        time += 0.001;

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        // glBindVertexArray(vertex_arr);
        glDrawElements(GL_TRIANGLES,no_of_indices,GL_UNSIGNED_INT,nullptr);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
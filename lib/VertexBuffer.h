#include <GL/glew.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>

#ifndef VertexBuffer_h
#define VertexBuffer_h


class VertexBuffer{
    private:
        GLuint m_vertex_array_id;
        GLuint m_buffer_id;
    public:
        VertexBuffer();
        ~VertexBuffer();
        void bind();
        void unbind();
        void addData(float*, unsigned int,unsigned int);
};


#endif
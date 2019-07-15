#include "VertexBuffer.h"
#include <iostream>
VertexBuffer::VertexBuffer(){
    glGenVertexArrays(1,&m_vertex_array_id);
    glGenBuffers(1,&m_buffer_id);
}
void VertexBuffer::bind(){
    glBindVertexArray(m_vertex_array_id);
}
void VertexBuffer::unbind(){
    glBindVertexArray(0);
}
void VertexBuffer::addData(float vertices[],unsigned int total_vertices,unsigned int components_per_vertex){
    this->bind();
    glBindBuffer(GL_ARRAY_BUFFER,m_buffer_id);
    glBufferData(GL_ARRAY_BUFFER,sizeof(float)*total_vertices,vertices,GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(0);
    GLuint index = 0,
        type = GL_FLOAT,
        normalised = GL_FALSE,
        stride = components_per_vertex * sizeof(float); 
    glVertexAttribPointer(index,components_per_vertex,type,normalised,stride,0);
    this->unbind();
    // glBindBuffer(GL_ARRAY_BUFFER,0);
}
VertexBuffer::~VertexBuffer(){
    std::cout << "destructor"<<std::endl;
    glDeleteBuffers(1,&m_buffer_id);
}
#include "processFloatVertexData.hpp"



Mesh processFloatVertexData(VertexData vertex_data){
    Mesh mesh;
    unsigned int VAO,EBO,VBO;

    glGenVertexArrays(1,&VAO);
    glBindVertexArray(VAO);

    //create VBO
    glGenBuffers(1,&VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertex_data.vertices.size()*sizeof(float), &vertex_data.vertices[0], GL_STATIC_DRAW);

    //create EBO
    glGenBuffers(1,&EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,vertex_data.indices.size()*sizeof(unsigned ),&vertex_data.indices[0],GL_STATIC_DRAW);

    

    //create attribute pointers

    //positin data
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,5*sizeof(float),(void*) 0);
    glEnableVertexAttribArray(0);

    //uv data
    glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,5*sizeof(float),(void*) (3*sizeof(float)) );
    glEnableVertexAttribArray(1);
    
    //unbing buffer
    glBindBuffer(GL_ARRAY_BUFFER,0);
    //unbind Vertex Array
    glBindVertexArray(0);

    mesh.VAO = VAO;
    mesh.indices_size = vertex_data.indices.size();

    return mesh;
}
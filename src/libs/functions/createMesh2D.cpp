#include "createMesh2D.hpp"

Mesh2D createMesh2D(Mesh2DData vertex_data)
{
    Mesh2D mesh;
    unsigned int VAO,EBO,VBO;

    glGenVertexArrays(1,&VAO);
    glBindVertexArray(VAO);

    //create VBO
    glGenBuffers(1,&VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertex_data.vertices.size()*sizeof(Vertex2D), &vertex_data.vertices[0], GL_STATIC_DRAW);

    //create EBO
    glGenBuffers(1,&EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,vertex_data.indices.size()*sizeof(unsigned int),&vertex_data.indices[0],GL_STATIC_DRAW);

    

    //create attribute pointers

  

    glEnableVertexAttribArray(0);	
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex2D), (void*)0);
    
    // vertex normals
    glEnableVertexAttribArray(1);	
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2D), (void*)offsetof(Vertex2D,TexCoords));

    
    
    //unbing buffer
    glBindBuffer(GL_ARRAY_BUFFER,0);
    //unbind Vertex Array
    glBindVertexArray(0);

    mesh.VAO = VAO;
    mesh.indices_size = vertex_data.indices.size();

    return mesh;
}
#include "batch.hpp"
#include "../functions/loadShader.hpp"
#include "../functions/loadTexture.hpp"
Batch::Batch()
{
    //set max no of quads   
    
    //create a single texture atlas and add different 
    
    
    
    Quad* quad_obj1 = new Quad(0.0,0.0,0.0);
    quad_obj1->rot = 30.0f;
    quad_obj1->updateTransform();

    addQuad(quad_obj1);

    Quad* quad_obj2 = new Quad(0.0,0.0,1.0);
    quad_obj1->rot = 30.0f;
    quad_obj1->updateTransform();

    addQuad(quad_obj2);
    
    
}




void Batch::loadBatch()
{
    //load all the textures and texture atlas into the memory
    
    
    //create indices
    //update indices
    for (unsigned int i = 0 ;i<maxQuad;i++)
    {
        unsigned int offset = 4;

        indices[0+i*6] =  0+offset*i;
        indices[1+i*6] =  1+offset*i;
        indices[2+i*6] =  2+offset*i;
        indices[3+i*6] =  2+offset*i;
        indices[4+i*6] =  3+offset*i;
        indices[5+i*6] =  0+offset*i;
    }


    // create buffers/arrays
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    // load data into vertex buffers
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, maxVertices * sizeof(Vertex),nullptr, GL_DYNAMIC_DRAW); 

    //transfer the indice data 
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, maxIndices*sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

    // set the vertex attribute pointers
    // vertex Positions
    glEnableVertexAttribArray(0);	
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex2D), (void*)offsetof(Vertex2D, Position));
    // vertex normals
    glEnableVertexAttribArray(1);	
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2D), (void*)offsetof(Vertex2D, TexCoords));
    // vertex texture coords
    glEnableVertexAttribArray(2);	
    glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, sizeof(Vertex2D), (void*)offsetof(Vertex2D, TextureID));
    // vertex tangent
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex2D), (void*)offsetof(Vertex2D, Color));
    glBindVertexArray(0);

    
    
    
    
    //create a shader

    shaderProgram = loadShader("shaders/sprite.vs","shaders/sprite.fs");

    //load a textures
    
    unsigned int texture1 = loadTexture("textures/wood.jpg");   
    unsigned int texture2 = loadTexture("textures/mouse.jpg");
    textures.push_back(texture1);
    textures.push_back(texture2);

    
    
    //bind textures to shader
    glUseProgram(shaderProgram);
    int samplers[]={0,1};
    unsigned int loc =glGetUniformLocation(shaderProgram,"texture1");
    glUniform1iv(loc,2,samplers);

    //glDeleteTextures(1,&textures[0]);
    
}

void Batch::renderBatch()
{   

    updateQuads();
    //glClearColor(0.0,0.0,0.0,1.0);
    //glClear(GL_COLOR_BUFFER_BIT);
    //use the shader
    glUseProgram(shaderProgram);
    //loadtexture 
    
    //render container
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D,textures[0]);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D,textures[1]);
    //transfer dynamic vertex data
    glBindVertexArray(VAO);
    glBufferSubData(GL_ARRAY_BUFFER,0,maxVertices*sizeof(Vertex),vertices);
    glDrawElements(GL_TRIANGLES,6*quad_array.size(),GL_UNSIGNED_INT,0);
    glBindVertexArray(0);
    //(unsigned int)(sizeof(indices)/sizeof(unsigned int))
}

void Batch::unloadBatch()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);
    glDeleteTextures(1,&textures[0]);
    glDeleteTextures(1,&textures[1]);
}
Batch::~Batch()
{
    

    
    cout<<"Batch is dead" << endl;
}

void Batch::addQuad(Quad* q)
{
    quad_array.push_back(q);
    //quad_count +=1;
    //cout<<quad_count;
}

// update the geometry every frame
void Batch::updateQuads()
{
    
    
    //  CREATE THE FINAL COMBINED GEOMETRY AFTER UPADTING ALL VERTICES
   

    //combine vertices of all quads and crate one geometry with all the vertices
    for (unsigned int i=0;i<quad_array.size();i++)
    {
        
        //update all quad data
        quad_array[i]->update();
        //update all quad transforms
        quad_array[i]->updateTransform();
        //copy all quad vertices to batch_vertices;
        memcpy(vertices+i*quad_array[i]->vertices.size(),quad_array[i]->vertices.data(),quad_array[i]->vertices.size()*sizeof(Vertex));
        //memcpy(vertices,quad1.data(),quad1.size()*sizeof(Vertex));
        //memcpy(vertices+quad1.size(),quad2.data(),quad2.size()*sizeof(Vertex));
    }
    
}
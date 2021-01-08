#include "batch.hpp"
#include "../functions/loadShader.hpp"
#include "../functions/loadTexture.hpp"
#include "sprite.hpp"
Batch::Batch()
{
    camera = new Camera();
    
}




void Batch::loadBatch()
{
    pause = false;
    
    //load all the textures and texture atlas into the memory
    

    //vertices will be loaded in run time
    
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

    //load all textures from textures and upload it to texture map
    for (unsigned int i=0;i<textures.size();i++)
    {
        auto it = texture_map.find(textures[i]);
        if (it == texture_map.end())
        {
            texture_map[textures[i]] = loadTexture(textures[i].c_str());
            cout << textures[i] << ":loaded into the memoty" <<endl ;
        }
    }
    //load all the textures from the texture_map of the batch
    
    cout<<texture_map["textures/spritesheet.jpeg"]<<endl;
    cout<<texture_map["textures/mouse.jpg"]<<endl;
    //texture1 = loadTexture("textures/wood.jpg");   
    //unsigned int texture2 = loadTexture("textures/mouse.jpg");
    //textures.push_back(texture1);
    //textures.push_back(texture2);

    
    
    //bind textures to shader
    glUseProgram(shaderProgram);
    int samplers[]={0,1,2};
    unsigned int loc =glGetUniformLocation(shaderProgram,"texture1");
    glUniform1iv(loc,3,samplers);

    mat4 model = translate(mat4(1.0),vec3(0.0,0.0,0.0));
    //set the initial camera view to shader for background layer parallax layer
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram,"model0"),1,GL_FALSE,&model[0][0]);
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram,"view0"),1,GL_FALSE,&camera->view[0][0]);
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram,"projection0"),1,GL_FALSE,&camera->projection[0][0]);

    //glDeleteTextures(1,&textures[0]);
    
}

void Batch::renderBatch()
{   
    if (!pause)
    {
        //update camera
    camera->updateCamera();
    update(); // update other things later added to it such as physics world
    updateQuads();
    //glClearColor(0.0,0.0,0.0,1.0);
    //glClear(GL_COLOR_BUFFER_BIT);
    //use the shader
    glUseProgram(shaderProgram);

    mat4 model = translate(mat4(1.0),vec3(0.0,0.0,0.0));
    //update camera view and projection
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram,"model"),1,GL_FALSE,&model[0][0]);
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram,"view"),1,GL_FALSE,&camera->view[0][0]);
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram,"projection"),1,GL_FALSE,&camera->projection[0][0]);
    //loadtexture 
    
    //bind each texture in the batch texture map to corresponding texture unit
    for(auto tex:texture_map)
    {
        glActiveTexture(GL_TEXTURE0+tex.second-1);
        glBindTexture(GL_TEXTURE_2D,tex.second);
    }
    glActiveTexture(GL_TEXTURE0);
    //glBindTexture(GL_TEXTURE_2D,texture1);
    //glActiveTexture(GL_TEXTURE1);
    //glBindTexture(GL_TEXTURE_2D,textures[1]);
    //transfer dynamic vertex data
    glBindVertexArray(VAO);
    glBufferSubData(GL_ARRAY_BUFFER,0,maxVertices*sizeof(Vertex),vertices);
    glDrawElements(GL_TRIANGLES,6*quad_array.size(),GL_UNSIGNED_INT,0);
    glBindVertexArray(0);
    //(unsigned int)(sizeof(indices)/sizeof(unsigned int))
    }
    
}

void Batch::unloadBatch()
{
    pause = true;
    
    
    
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);
    //glDeleteTextures(1,&textures[0]);
    //glDeleteTextures(1,&textures[1]);
    //delete all the textures loaded in the map
    for (auto tex:texture_map)
    {
        glDeleteTextures(1,&tex.second);
        cout << tex.first <<": unloaded from memory" << endl;
    }
    
    

}
Batch::~Batch()
{
    delete camera;
    //delete each quad from the heap
    for(auto item:quad_array)
    {
        cout<<"quad"<< item->ID<<" deleted"<<endl;
        delete item;
        
    }
    
    this->unloadBatch();

    
    
    
    

    //delete input;
    
    
    
    cout<<"Batch is unloaded" << endl;
}

//add quads to the batch
void Batch::addQuad(Quad* q)
{
    //add quad to batch
    q->ID = quad_array.size();
    cout<<q->ID<<endl;
    quad_array.push_back(q); 
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


//load texture paths to texture vector
void Batch::addtexture(string path)
{
    if (path !="")
    {
        
        //update texture path if texture is not acailable
        textures.push_back(path);
        
    }
    
    
}

/*
void Batch::update()
{

}
*/
//current_scene = scene_array[ID];
            cam = new Camera();
            //create a quad
            Quad quad = Quad();

            quad.mesh_data.vertices;
            quad.mesh_data.indices;
            vector<Vertex> quad_vertices = quad.mesh_data.vertices;

            mat4  transform = mat4(1.0);
            transform = translate(transform,vec3(2.2,0.0,0.0));
            
            for (Vertex v:quad_vertices)
            {
                vec4 v_pos = transform*vec4(v.Position,1.0);
                v.Position = vec3(v_pos.x/v_pos.w,v_pos.y/v_pos.w,v_pos.z/v_pos.w);
                
                quad.mesh_data.vertices.push_back(v);
            } 

            vector<unsigned int> quad_indices = quad.mesh_data.indices;
            for (unsigned int  i = 0 ;i<quad_indices.size();i++)
            {
               
                
                quad.mesh_data.indices.push_back(quad_indices[i]+4);
                  
            }   

            
             
            //create a mesh
            Mesh mesh = createMesh(quad.mesh_data);
            //load data from models and create a batch

            //create a sshader
            shader = new Shader("shaders/model.vs","shaders/model.fs");
            shader->setModelViewProjectionMatrix(mat4(1.0),cam->view,cam->projection);
            shader->loadTextureData({25,"textures/wood.jpg","texture1"});
            
            
            shader->loadVertexData(mesh);
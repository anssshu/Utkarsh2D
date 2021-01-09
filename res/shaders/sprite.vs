#version 300 es



layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoords;
layout (location = 2) in float aTexID;
layout (location = 3) in vec4 aColor;


out vec2 TexCoords;
out vec4 Color;
out float TexID;


uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

//for parallax layer
uniform mat4 model0;
uniform mat4 view0;
uniform mat4 projection0;


void main()
{
    TexCoords = aTexCoords;
    Color = aColor;
    TexID = aTexID;  

    //for background textures -----slot0
    if (aTexID == 0.0){
        gl_Position =  projection0*view0*model0*vec4(aPos, 1.0);//set at initial view of camera
    }
    else
    {
        gl_Position = projection * view * model * vec4(aPos, 1.0);
        //gl_Position = vec4(aPos, 1.0);
    }
  
    
}
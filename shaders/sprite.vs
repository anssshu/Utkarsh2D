#version 300 es



layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoords;
layout (location = 2) in float aTexID;
layout (location = 3) in vec4 aColor;


out vec2 TexCoords;
out vec4 Color;
out float TexID;


//uniform mat4 model;
//uniform mat4 view;
//uniform mat4 projection;

void main()
{
    TexCoords = aTexCoords;
    Color = aColor;
    TexID = aTexID;    
    //gl_Position = projection * view * model * vec4(aPos, 1.0);
    gl_Position = vec4(aPos, 1.0);
}
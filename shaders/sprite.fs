#version 300  es

#ifdef GL_ES
precision highp float;
#endif

out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D texture1;

void main()
{    
    FragColor = texture(texture1, TexCoords);
}
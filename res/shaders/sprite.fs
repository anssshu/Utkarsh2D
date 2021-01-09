#version 300  es

#ifdef GL_ES
precision highp float;
#endif

out vec4 FragColor;

in vec2 TexCoords;
in vec4 Color;
in float TexID;

uniform sampler2D texture1[3];



void main()
{    
    if (TexID == 0.0){
        FragColor = texture(texture1[0], TexCoords);
    }

    if (TexID == 1.0){
        FragColor = texture(texture1[1], TexCoords);
    }

    if (TexID == 2.0){
        FragColor = texture(texture1[2], TexCoords);
    }
    
}
#include "loadShader.hpp"

unsigned int loadShader(string vertex_shader_path,string fragment_shader_path){
        string _vs_code = readFile(vertex_shader_path.c_str());
        string _fs_code = readFile(fragment_shader_path.c_str());

        const char* vscode = _vs_code.c_str();
        const char* fscode = _fs_code.c_str();

        //create vertex shader
        GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader,1,&vscode,NULL);
        glCompileShader(vertexShader);//compile shader code

        //check for error
        int success;
        char infolog[512];
        glGetShaderiv(vertexShader,GL_COMPILE_STATUS,&success);
        cout<<_vs_code<<endl;
        if (!success)
        {
            glGetShaderInfoLog(vertexShader,512,NULL,infolog);
            cout<<"vertex shader compilation failed:"<<infolog<<endl;
        }

        //create fragmentShader
        GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        //copy shader code
        glShaderSource(fragmentShader,1,&fscode,NULL);
        //compile shader
        glCompileShader(fragmentShader);

        //check for errors
       

        glGetShaderiv(fragmentShader,GL_COMPILE_STATUS,&success);
        if (!success)
        {
            glGetShaderInfoLog(fragmentShader,512,NULL,infolog);
            cout<<"fragment shader compilation failed:"<<infolog<<endl;
        }



        //link all the shaders
        unsigned int shaderProgram = glCreateProgram();
        //attach vertext shaed
        glAttachShader(shaderProgram,vertexShader);
        //attach fragment shader
        glAttachShader(shaderProgram,fragmentShader);
        //link shader program
        glLinkProgram(shaderProgram);

        //check for error
        glGetProgramiv(shaderProgram,GL_LINK_STATUS,&success);
        if (!success)
        {
            glGetProgramInfoLog(shaderProgram,512,NULL,infolog);
            cout<<" shaderProgram linking  failed:"<<infolog<<endl;
        }


        //delete shaders
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        return shaderProgram;

};
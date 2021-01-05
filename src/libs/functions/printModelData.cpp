#include "printModelData.hpp"

void printModelData(ModelData data){
    for (unsigned int i = 0;i<data.mesh_data_array.size();i++)
    {
        MeshData  mesh_data = data.mesh_data_array[i];

        cout << "Mesh No-" << i <<":"<<endl;
        cout<<"indices={";
        for(unsigned int k=0;k<mesh_data.indices.size();k++)
        {
            cout<<mesh_data.indices[k]<<",";
        }
        cout<<"};";
        for(unsigned int j =0 ;j<mesh_data.vertices.size();j++)
        {   cout<<endl;
            cout << "//Vertex" << j <<":" << endl;
            Vertex v = mesh_data.vertices[j];

            cout<<"v"<<j<<"."<<"Position="<<"vec3("<<v.Position.x<<","<<v.Position.y<<","<<v.Position.z<<");"<<endl;
            cout<<"v"<<j<<"."<<"Normal="<<"vec3("<<v.Normal.x<<","<<v.Normal.y<<","<<v.Normal.z<<");"<<endl;
            cout<<"v"<<j<<"."<<"TexCoords="<<"vec2("<<v.TexCoords.x<<","<<v.TexCoords.y<<");"<<endl;
            cout<<"v"<<j<<"."<<"Tangent="<<"vec3("<<v.Tangent.x<<","<<v.Tangent.y<<","<<v.Tangent.z<<");"<<endl;
            cout<<"v"<<j<<"."<<"Bitangent="<<"vec3("<<v.Bitangent.x<<","<<v.Bitangent.y<<","<<v.Bitangent.z<<");"<<endl;

            cout<<"//----------------------------------------------------------"<<endl;
        }
        cout<<"//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    }
}
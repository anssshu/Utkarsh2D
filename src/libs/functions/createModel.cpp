#include "createModel.hpp"

vector<Mesh> createModel(ModelData model_data)
{   
    //create meshse from the model data and connect it to the model
    vector<Mesh> dummy_mesh_array;
    //get each meshData from model data and store it in the my_meshes
    for (unsigned int i=0;i<model_data.mesh_data_array.size();i++)
    {
        dummy_mesh_array.push_back(createMesh(model_data.mesh_data_array[i]));
    }
    //my_meshes = dummy_mesh_array;
    return dummy_mesh_array;
}
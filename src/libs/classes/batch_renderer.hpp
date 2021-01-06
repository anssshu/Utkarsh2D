//combines all geometries into a single geometry and then renderes;
#include "scene.hpp"
#include "batch.hpp"

class BatchRenderer
{
    public:
        vector<Scene*> scene_array;
        Scene*  current_scene;
        Shader* shader;
        Camera* cam;
        Batch* batch;
        BatchRenderer()
        {
            batch = new Batch();
        }
        ~BatchRenderer()
        {
            delete batch;
        }
        
        void loadScene(unsigned int ID)
        {
           
            batch->loadBatch();

        }
        void renderScene()
        {
            batch->renderBatch();
        }
};
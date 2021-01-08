//combines all geometries into a single geometry and then renderes;
#pragma once
#include "scene.hpp"
#include "batch.hpp"
#include "input.hpp"
class BatchRenderer
{
    public:
        vector<Batch*> batch_array;
        Batch*  current_batch;     
        Input* input;
        BatchRenderer();
        ~BatchRenderer();

        void addBatch(Batch* batch);
        void loadBatch(unsigned int ID);
        void renderBatch();
              
};
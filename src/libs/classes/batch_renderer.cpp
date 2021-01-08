 #include "batch_renderer.hpp"

BatchRenderer::BatchRenderer()
{
    //current_batch = new Batch();
    //input = inp;
}
BatchRenderer:: ~BatchRenderer()
{
    delete current_batch;
}

void BatchRenderer::loadBatch(unsigned int ID)
{
    
    current_batch = batch_array[ID];
    current_batch->loadBatch();

}
void BatchRenderer::renderBatch()
{
    current_batch->renderBatch();
}
void BatchRenderer::addBatch(Batch* batch)
{
    batch_array.push_back(batch);
}
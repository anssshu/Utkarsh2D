#include "mainBatch.hpp"

//every batch has a camera
MainBatch::MainBatch(Input* inp):Batch()
{
    // PHYSICS
    
float H = 5;
float jump_time=0.5;
float g = 2*H/jump_time;
float v = g*jump_time;

float timeStep = 1.0f / 60.0f;
int iterations = 10;





//ADD ALL TEXTURES TO CONTAINER 

addtexture("textures/mouse.jpg");//0 //parallax background layer-------texture1[0] at vetex shader //back ground sprite will not be effected by the model view and projection matrix
addtexture("textures/wood.jpg");//1  //add a map texture
addtexture("textures/spritesheet.jpeg");//2   //sprite sheet  //single texture atlas


// TEXTURE ATLAS QUAD

Rect player_char_uv = {0.05,0.05,0.128,0.256}; //define all the uv maps from the sprite_sheet
Rect char2_uv = {0.05+0.128,0.05,0.128,0.256};

        
// PLAYER CAMERA
 //create a camera and connect to input object
camera->input = inp;




// PARALLAX BACKGROUND
Sprite* bg = new Sprite(0.0f); //create a parallaax background //create a single texture atlas and add different 
bg->setScale(5,5);
bg->setRot(0.0f);

// MAP
Sprite* map = new Sprite(1.0f);//create a map to navigate
map->setScale(15,3);
map->setPos(0.0,5.0);
map->setRot(0.0f);




// PLAYER
//create a main character
player = new Player(2.0f);
player->input = inp;//for input processing
camera->player = player;//for camera tracking


//CHAR

joe = new Sprite(2.0,char2_uv);
joe->pos.y = 3;
addQuad(joe);




// POPULATE QUAD CONTAINER OF THE BATCH

addQuad(player);

addQuad(map);
addQuad(bg);


  
    
    



   
}

void MainBatch::update()
{
    //COLLISION WITH BOTTOM WALL
    
    
    
   
    
    bool col = checkCollision(player,joe);
    if (col){
        cout << "player collided with joe" << endl;
    }
    
    
    // COLLISION WITH BULLET
    
    
}

MainBatch::~MainBatch()
{
    
    pause = true;
    
    

    //delete camera;
    //delete each quad from the heap
   
    
    //this->unloadBatch();

    
    
    
    

    //delete input;
    
    
    
    cout<<"MainBatch is unloaded" << endl;
}
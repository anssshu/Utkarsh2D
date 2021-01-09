#include "mainBatch.hpp"

//every batch has a camera
MainBatch::MainBatch(Input* inp):Batch()
{
    // PHYSICS
    


//Audio
//Mix_Music *gMusic = NULL;
Mix_Music* gMusic = Mix_LoadMUS( "res/audio/back.mp3" );

 
cout << "music not playing" ;
    //Play the music
Mix_PlayMusic( gMusic, 0 );


//ADD ALL TEXTURES TO CONTAINER 

addtexture("res/textures/mouse.jpg");//0 //parallax background layer-------texture1[0] at vetex shader //back ground sprite will not be effected by the model view and projection matrix
addtexture("res/textures/wood.jpg");//1  //add a map texture
addtexture("res/textures/spritesheet.jpeg");//2   //sprite sheet  //single texture atlas


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
hero= new Player(2.0f);
hero->input = inp;//for input processing
camera->player = hero;//for camera tracking


//CHAR

joe = new Sprite(2.0,char2_uv);
joe->pos.y = 3;
addQuad(joe);

//ENEMY

miku = new Enemy(2.0f);



// POPULATE QUAD CONTAINER OF THE BATCH

addQuad(hero);
addQuad(miku);
addQuad(map);
addQuad(bg);


  
    
    



   
}

void MainBatch::update()
{
    //COLLISION WITH BOTTOM WALL
    
    
    
   
    
    bool col = checkCollision(hero,joe);
    if (col){
        hero->hit_by_enemy = true;
        //cout << "player collided with joe" << endl;
    }
    hero->hit_by_enemy = false;
    
    
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
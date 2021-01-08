#include "mainBatch.hpp"





//every batch has a camera
MainBatch::MainBatch(Input* inp)
{
    float H = 5;
    float jump_time=0.5;
    float g = 2*H/jump_time;
    float v = g*jump_time;
    
    float timeStep = 1.0f / 60.0f;
	int iterations = 10;

    b2_world = new World(Vec2(0.0f,g),iterations);

    base = new Body();
    base->Set(Vec2(100.0f,5.0f),FLT_MAX);
    base->position.Set(0.0f,3.0f);
    b2_world->Add(base);
    
    
    box = new Body();
    box->Set(Vec2(1.0f,1.0f),100.0f);
    box->position.Set(-2.5f,-2.0f);
    b2_world->Add(box);

    //c = new Contact();

    
    //DEFINE ALL TEXTURES TO BE LOADED
    //add Textures to textures vector

    //parallax background layer-------texture1[0] at vetex shader
    addtexture("textures/mouse.jpg");//0  //back ground sprite will not be effected by the model view and projection matrix
    
    //add a map texture
    addtexture("textures/wood.jpg");//1
    //sprite sheet 
    addtexture("textures/spritesheet.jpeg");//2  //single texture atlas
    
   


    //define all the uv maps from the sprite_sheet
    Rect player_char_uv = {0.05,0.05,0.128,0.256};
    Rect char2_uv = {0.05+0.128,0.05,0.128,0.256};
    
    
    //create a camera and connect to input object
    camera = new Camera();
    
    
    //create a single texture atlas and add different 
   
   
    
    //create a parallaax background
    Sprite* bg = new Sprite(0.0f);
    bg->setScale(5,5);
    bg->setRot(0.0f);

    //create a map to navigate
    Sprite* map = new Sprite(1.0f);
    map->setScale(15,2.5);
    map->setPos(0.0,2.0);
    map->setRot(0.0f);
    //add other characters

    //create a main character
    player = new Player(2.0f);
    player->body->position.Set(0.0,-3);
    player->input = inp;//for input processing
    camera->player = player;//for camera tracking
    b2_world->Add(player->body);
   

    enemy = new Enemy(2.0f);
    enemy->body->position.Set(3.0,-3.0);
    b2_world->Add(enemy->body);
    //add a UI Layer
    
    //add all the quads to the batch for rendering
    addQuad(player);
    addQuad(enemy);
    addQuad(map);
    addQuad(bg);


    //add all the colliders to the world
    
    



   
}

void MainBatch::update()
{
    //check collision between base and the player
    int foo = Collide(player->contact,base,player->body);
    if (foo > 0)
    {
        player->on_ground = true;
    }
    else
    {
        player->on_ground = false;
    }
    
    
    //update the world
    b2_world->Step(1/60.0f);
}

MainBatch::~MainBatch()
{
    
}
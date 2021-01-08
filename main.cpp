
#include "app/app.hpp"


int main()
{
  //first create window and opengl context
  Application app;// = Display(800,600,"SDL GLES3");

  app.run();

  app.cleanup();

  //delete display;
  
  
  return 0;
}
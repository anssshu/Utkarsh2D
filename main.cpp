
#include "libs/classes/display.hpp"


int main()
{
  //first create window and opengl context
  Display* display = new Display(800,600,"SDL GLES3");

  display->run();

  display->cleanup();

  delete display;
  
  
  return 0;
}
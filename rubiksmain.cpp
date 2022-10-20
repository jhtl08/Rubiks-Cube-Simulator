//rubiksmain.cpp
//Kyle Coloma, Jason Lorenzo, Paolo Ong
//ENGG 31-N
//October 13, 2022

#include "rubikscube.h"

using namespace std;

int main()
{
  Face display = Face('w', 'y', 'o', 'r', 'g', 'b');
  display.printFace();

  system("pause");
}
//rubiksmain.cpp
//Kyle Coloma, Jason Lorenzo, Paolo Ong
//ENGG 31-N
//October 20, 2022

#include "rubikscube.h"

using namespace std;

int main()
{
  RubiksCube rCube=RubiksCube();
  rCube.upplus();
  rCube.leftplus();
  rCube.frontplus();
  rCube.rightplus();
  rCube.backplus();
  rCube.downplus();
  /*Configuration of these 6 turns in this specific order has been
  /confirmed correct using an online rubiks cube simulator*/
  rCube.printCube();
  system("pause");
}
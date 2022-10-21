//rubiksmain.cpp
//Kyle Coloma, Jason Lorenzo, Paolo Ong
//ENGG 31-N
//October 20, 2022

#include "rubikscube.h"

using namespace std;

int main()
{
  RubiksCube rCube=RubiksCube();

  rCube.printCube();

while(true)
{
  string rotation;
  cout << "> ";
  cin >> rotation;
  
  if (rotation == "u-")
  {
    rCube.upminus(); // with simplification
  }
  if (rotation == "u+")
  {
    rCube.upplus();
  }
  if (rotation == "l+")
  {
    rCube.leftplus();
  }
  if (rotation == "f+")
  {
    rCube.frontplus();
  }
  if (rotation == "r+")
  {
    rCube.rightplus();
  }
  if (rotation == "b+")
  {
    rCube.backplus();
  }
  if (rotation == "d+")
  {
    rCube.downplus(); // with simplification
  }
  

  /*Configuration of these 6 turns in this specific order has been
  /confirmed correct using an online rubiks cube simulator*/
  rCube.printCube();
  cin.clear();
}

  system("pause");
}
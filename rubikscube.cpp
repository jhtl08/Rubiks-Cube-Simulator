//rubikscube.cpp
//Kyle Coloma, Jason Lorenzo, Paolo Ong
//ENGG 31-N
//October 13, 2022

#include "rubikscube.h"

//class Face members

//default constructor
Face::Face()
{
  sideFace[0] = "-------------";
  sideFace[1] = "|   |   |   |";
  sideFace[2] = "| x | x | x |";
  sideFace[3] = "|   |   |   |";
  sideFace[4] = "-------------";
  sideFace[5] = "|   |   |   |";
  sideFace[6] = "| x | x | x |";
  sideFace[7] = "|   |   |   |";
  sideFace[8] = "-------------";
  sideFace[9] = "|   |   |   |";
  sideFace[10] = "| x | x | x |";
  sideFace[11] = "|   |   |   |";
  sideFace[12] = "-------------";
}

//non-empty constructor
Face::Face(char color)
{
  sideFace[0] = "-------------";
  sideFace[1] = "|   |   |   |";
  sideFace[2] = "| x | x | x |";
  sideFace[3] = "|   |   |   |";
  sideFace[4] = "-------------";
  sideFace[5] = "|   |   |   |";
  sideFace[6] = "| x | x | x |";
  sideFace[7] = "|   |   |   |";
  sideFace[8] = "-------------";
  sideFace[9] = "|   |   |   |";
  sideFace[10] = "| x | x | x |";
  sideFace[11] = "|   |   |   |";
  sideFace[12] = "-------------";
  for(int i=2; i<11; i+=4)
  {
    for(int j=2; j<11; j+=4)
    {
      sideFace[i][j]=color;
    }
  }
}

//single-face display function
void Face::printFace()
{
  for (int i=0; i<13; i++){
    std::cout<<sideFace[i]<<std::endl;
  }
}



//class RubiksCube members

RubiksCube::RubiksCube()
{
  up=Face('w');
  down=Face('y');
  left=Face('o');
  right=Face('r');
  front=Face('g');
  back=Face('b');
}

void RubiksCube::printCube()
{
  up.printFace();
  left.printFace();
  front.printFace();
  right.printFace();
  back.printFace();
  down.printFace();
}
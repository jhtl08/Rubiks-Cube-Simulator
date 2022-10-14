//rubikscube.cpp
//Kyle Coloma, Jason Lorenzo, Paolo Ong
//ENGG 31-N
//October 13, 2022

#include "rubikscube.h"

//class Face members

RubiksCube::RubiksCube()
{
  //allocate memory for the arrays pointed at (rows)
  for(int i = 0; i < 3; i++)
  {
    up[i] = new char[3];
    left[i] = new char[3];
    front[i] = new char[3];
    right[i] = new char[3];
    back[i] = new char[3];
    down[i] = new char[3];
  }

  //set initial colors of the faces (2d arrays)
  for (int i=0; i<3; i++)
  {
    for(int j=0; j<3; j++)
    {
      up[i][j]='w';
      left[i][j]='o';
      front[i][j]='g';
      right[i][j]='r';
      back[i][j]='b';
      down[i][j]='y';
    }
  }
}

void RubiksCube::printCube()
{
  //change template colors to up face's colors
  for (int i=0; i<3; i++)
  {
    for (int j=0; j<3; j++)
    {
      single_face_template[69+(j*4)+(i*108)]=up[i][j];
    }
  }
  std::cout<<single_face_template;

  //change template colors to left, front, right, back colors
  for (int i=0; i<3; i++)
  {
    for (int j=0; j<3; j++)
    {
      four_face_template[108+(j*4)+(i*212)]=left[i][j];
    }
  }

  for (int i=0; i<3; i++)
  {
    for (int j=0; j<3; j++)
    {
      four_face_template[121+(j*4)+(i*212)]=front[i][j];
    }
  }

  for (int i=0; i<3; i++)
  {
    for (int j=0; j<3; j++)
    {
      four_face_template[134+(j*4)+(i*212)]=right[i][j];
    }
  }

  for (int i=0; i<3; i++)
  {
    for (int j=0; j<3; j++)
    {
      four_face_template[147+(j*4)+(i*212)]=back[i][j];
    }
  }  

  std::cout<<four_face_template;

  //change template colors to down face's colors
  for (int i=0; i<3; i++)
  {
    for (int j=0; j<3; j++)
    {
      single_face_template[69+(j*4)+(i*108)]=down[i][j];
    }
  }
  std::cout<<single_face_template;
}
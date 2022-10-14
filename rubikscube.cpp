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
  single_face_template[69]=up[0][0];
  single_face_template[73]=up[0][1];
  single_face_template[77]=up[0][2];
  single_face_template[177]=up[1][0];
  single_face_template[181]=up[1][1];
  single_face_template[185]=up[1][2];
  single_face_template[285]=up[2][0];
  single_face_template[289]=up[2][1];
  single_face_template[293]=up[2][2];
  std::cout<<single_face_template;

  //change template colors to left, front, right, back colors
  four_face_template[108]=left[0][0];
  four_face_template[112]=left[0][1];
  four_face_template[116]=left[0][2];
  four_face_template[320]=left[1][0];
  four_face_template[324]=left[1][1];
  four_face_template[328]=left[1][2];
  four_face_template[532]=left[2][0];
  four_face_template[536]=left[2][1];
  four_face_template[540]=left[2][2];

  four_face_template[121]=front[0][0];
  four_face_template[125]=front[0][1];
  four_face_template[129]=front[0][2];
  four_face_template[333]=front[1][0];
  four_face_template[337]=front[1][1];
  four_face_template[341]=front[1][2];
  four_face_template[545]=front[2][0];
  four_face_template[549]=front[2][1];
  four_face_template[553]=front[2][2];

  four_face_template[134]=right[0][0];
  four_face_template[138]=right[0][1];
  four_face_template[142]=right[0][2];
  four_face_template[346]=right[1][0];
  four_face_template[350]=right[1][1];
  four_face_template[354]=right[1][2];
  four_face_template[558]=right[2][0];
  four_face_template[562]=right[2][1];
  four_face_template[566]=right[2][2];

  four_face_template[147]=down[0][0];
  four_face_template[151]=down[0][1];
  four_face_template[155]=down[0][2];
  four_face_template[359]=down[1][0];
  four_face_template[363]=down[1][1];
  four_face_template[367]=down[1][2];
  four_face_template[571]=down[2][0];
  four_face_template[575]=down[2][1];
  four_face_template[579]=down[2][2];
  std::cout<<four_face_template;

  //change template colors to down face's colors
  single_face_template[69]=down[0][0];
  single_face_template[73]=down[0][1];
  single_face_template[77]=down[0][2];
  single_face_template[177]=down[1][0];
  single_face_template[181]=down[1][1];
  single_face_template[185]=down[1][2];
  single_face_template[285]=down[2][0];
  single_face_template[289]=down[2][1];
  single_face_template[293]=down[2][2];
  std::cout<<single_face_template;

}
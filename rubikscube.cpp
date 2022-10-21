//rubikscube.cpp
//Kyle Coloma, Jason Lorenzo, Paolo Ong
//ENGG 31-N
//October 20, 2022

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
      left[i][j]='b';
      front[i][j]='o';
      right[i][j]='g';
      back[i][j]='r';
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
      full_face_template[121+(j*4)+(i*212)]=up[i][j];
    }
  }


  //change template colors to left, front, right, back colors
  for (int i=0; i<3; i++)
  {
    for (int j=0; j<3; j++)
    {
      full_face_template[797+(j*4)+(i*212)]=left[i][j];
    }
  }


  for (int i=0; i<3; i++)
  {
    for (int j=0; j<3; j++)
    {
      full_face_template[810+(j*4)+(i*212)]=front[i][j];
    }
  }

  
  for (int i=0; i<3; i++)
  {
    for (int j=0; j<3; j++)
    {
      full_face_template[823+(j*4)+(i*212)]=right[i][j];
    }
  }

  for (int i=0; i<3; i++)
  {
    for (int j=0; j<3; j++)
    {
      full_face_template[836+(j*4)+(i*212)]=back[i][j];
    }
  }  

  //change template colors to down face's colors
  for (int i=0; i<3; i++)
  {
    for (int j=0; j<3; j++)
    {
      full_face_template[1499+(j*4)+(i*212)]=down[i][j];
    }
  }  
 std::cout<<full_face_template;
}

void RubiksCube::upplus()
{//oh dear...
  //Turning the corner pieces of the main face
  swap = up[2][0];
  up[2][0] = up[0][0];
  up[0][0] = up[0][2];
  swap2 = up[2][2];
  up[2][2] = swap;
  up[0][2] = swap2;

  //Turning the outer-middle pieces of the main face
  swap = up[1][0];
  up[1][0] = up[0][1];
  up[0][1] = up[1][2];
  swap2 = up[2][1];
  up[2][1] = swap;
  up[1][2] = swap2;

  //Turning the affected faces (NOTE: I change each affected piece individually so that I don't have to initialize more than 2 swap values.
  //Feel free to change if you want.
  
  swap = front[0][2];
  front[0][2] = left[0][2];
  left[0][2] = back[0][2];
  swap2 = right[0][2];
  right[0][2] = swap;
  back[0][2] = swap2;

  swap = front[0][1];
  front[0][1] = left[0][1];
  left[0][1] = back[0][1];
  swap2 = right[0][1];
  right[0][1] = swap;
  back[0][1] = swap2;

  swap = front[0][0];
  front[0][0] = left[0][0];
  left[0][0] = back[0][0];
  swap2 = right[0][0];
  right[0][0] = swap;
  back[0][0] = swap2;
  

}

void RubiksCube::frontplus()
{
  //Turning the corner pieces of the main face
  swap = front[2][0];
  front[2][0] = front[0][0];
  front[0][0] = front[0][2];
  swap2 = front[2][2];
  front[2][2] = swap;
  front[0][2] = swap2;

  //Turning the outer-middle pieces of the main face
  swap = front[1][0];
  front[1][0] = front[0][1];
  front[0][1] = front[1][2];
  swap2 = front[2][1];
  front[2][1] = swap;
  front[1][2] = swap2;

  //Turning the affected faces 
  swap = left[0][2];
  left[0][2] = up[2][2];
  up[2][2] = right[2][0];
  swap2 = down[0][0];
  down[0][0] = swap;
  right[2][0] = swap2;

  swap = left[1][2];
  left[1][2] = up[2][1];
  up[2][1] = right[1][0];
  swap2 = down[0][1];
  down[0][1] = swap;
  right[1][0] = swap2;

  swap = left[2][2];
  left[2][2] = up[2][0];
  up[2][0] = right[0][0];
  swap2 = down[0][2];
  down[0][2] = swap;
  right[0][0] = swap2;
}

void RubiksCube::leftplus()
{

  //Turning the corner pieces of the main face
  swap = left[2][0];
  left[2][0] = left[0][0];
  left[0][0] = left[0][2];
  swap2 = left[2][2];
  left[2][2] = swap;
  left[0][2] = swap2;

  //Turning the outer-middle pieces of the main face
  swap = left[1][0];
  left[1][0] = left[0][1];
  left[0][1] = left[1][2];
  swap2 = left[2][1];
  left[2][1] = swap;
  left[1][2] = swap2;

  //Turning the affected faces 
  swap = back[2][2];
  back[2][2] = up[0][0];
  up[0][0] = front[0][0];
  swap2 = down[0][0];
  down[0][0] = swap;
  front[0][0] = swap2;

  swap = back[1][2];
  back[1][2] = up[1][0];
  up[1][0] = front[1][0];
  swap2 = down[1][0];
  down[1][0] = swap;
  front[1][0] = swap2;

  swap = back[0][2];
  back[0][2] = up[2][0];
  up[2][0] = front[2][0];
  swap2 = down[2][0];
  down[2][0] = swap;
  front[2][0] = swap2;
}

void RubiksCube::rightplus()
{
  //Turning the corner pieces of the main face
  swap = right[2][0];
  right[2][0] = right[0][0];
  right[0][0] = right[0][2];
  swap2 = right[2][2];
  right[2][2] = swap;
  right[0][2] = swap2;

  //Turning the outer-middle pieces of the main face
  swap = right[1][0];
  right[1][0] = right[0][1];
  right[0][1] = right[1][2];
  swap2 = right[2][1];
  right[2][1] = swap;
  right[1][2] = swap2;

  //Turning the affected faces 
  swap = front[2][2];
  front[2][2] = up[2][2];
  up[2][2] = back[0][0];
  swap2 = down[2][2];
  down[2][2] = swap;
  back[0][0] = swap2;

  swap = front[1][2];
  front[1][2] = up[1][2];
  up[1][2] = back[1][0];
  swap2 = down[1][2];
  down[1][2] = swap;
  back[1][0] = swap2;

  swap = front[0][2];
  front[0][2] = up[0][2];
  up[0][2] = back[2][0];
  swap2 = down[0][2];
  down[0][2] = swap;
  back[2][0] = swap2;
}

void RubiksCube::backplus()
{
  //Turning the corner pieces of the main face
  swap = back[2][0];
  back[2][0] = back[0][0];
  back[0][0] = back[0][2];
  swap2 = back[2][2];
  back[2][2] = swap;
  back[0][2] = swap2;

  //Turning the outer-middle pieces of the main face
  swap = back[1][0];
  back[1][0] = back[0][1];
  back[0][1] = back[1][2];
  swap2 = back[2][1];
  back[2][1] = swap;
  back[1][2] = swap2;

  //Turning the affected faces 
  swap = right[2][2];
  right[2][2] = up[0][2];
  up[0][2] = left[0][0];
  swap2 = down[2][0];
  down[2][0] = swap;
  left[0][0] = swap2;

  swap = right[1][2];
  right[1][2] = up[0][1];
  up[0][1] = left[1][0];
  swap2 = down[2][1];
  down[2][1] = swap;
  left[1][0] = swap2;

  swap = right[0][2];
  right[0][2] = up[0][0];
  up[0][0] = left[2][0];
  swap2 = down[2][2];
  down[2][2] = swap;
  left[2][0] = swap2;
}

void RubiksCube::downplus()
{
  //Turning the corner pieces of the main face
  swap = down[2][0];
  down[2][0] = down[0][0];
  down[0][0] = down[0][2];
  swap2 = down[2][2];
  down[2][2] = swap;
  down[0][2] = swap2;

  //Turning the outer-middle pieces of the main face
  swap = down[1][0];
  down[1][0] = down[0][1];
  down[0][1] = down[1][2];
  swap2 = down[2][1];
  down[2][1] = swap;
  down[1][2] = swap2;

  //Turning the affected faces
  /*
  swap = left[2][0];
  left[2][0] = front[2][0];
  front[2][0] = right[2][0];
  swap2 = back[2][0];
  back[2][0] = swap;
  right[2][0] = swap2;

  swap = left[2][1];
  left[2][1] = front[2][1];
  front[2][1] = right[2][1];
  swap2 = back[2][1];
  back[2][1] = swap;
  right[2][1] = swap2;

  swap = left[2][2];
  left[2][2] = front[2][2];
  front[2][2] = right[2][2];
  swap2 = back[2][2];
  back[2][2] = swap;
  right[2][2] = swap2;
  */

 //Rotation of affected areas from face-to-face
 for (int x = 0; x < 3; x++)
  {
    char PlaceHolder [2][2];
    PlaceHolder [0][x] = back[2][x]; // PlaceHolder for Back
    back[2][x] = left[2][x]; // Left to Back
    left[2][x] = front[2][x]; // Front to Left
    front[2][x] = right[2][x]; // Right to Front
    right[2][x] = PlaceHolder[0][x]; // Back to Right
  }

}

void RubiksCube::upminus()
{

  //Rotation of affected areas from face-to-face
  for (int x = 0; x < 3; x++)
  {
    char PlaceHolder [2][2];
    PlaceHolder [0][x] = back[0][x]; // Place Holder for Back
    back[0][x] = left[0][x]; // Left to Back
    left[0][x] = front[0][x]; // Front to Left
    front[0][x] = right[0][x]; // Right to Front
    right[0][x] = PlaceHolder[0][x]; // Back to Right
  }

}

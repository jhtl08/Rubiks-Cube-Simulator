//rubikscube.cpp
//Kyle Coloma, Jason Lorenzo, Paolo Ong
//ENGG 31-N
//October 13, 2022

#include "rubikscube.h"
using namespace std;

//class Face members

//default constructor
Face::Face()
{
  sideFace[0]  = "             -------------                          ";
  sideFace[1]  = "             |   |   |   |                          ";
  sideFace[2]  = "             | x | x | x |                          ";
  sideFace[3]  = "             |   |   |   |                          ";
  sideFace[4]  = "             -------------                          ";
  sideFace[5]  = "             |   |   |   |                          ";
  sideFace[6]  = "             | x | x | x |                          ";
  sideFace[7]  = "             |   |   |   |                          ";
  sideFace[8]  = "             -------------                          ";
  sideFace[9]  = "             |   |   |   |                          ";
  sideFace[10] = "             | x | x | x |                          ";
  sideFace[11] = "             |   |   |   |                          ";
  sideFace[12] = "             -------------                          ";
  sideFace[13] = "----------------------------------------------------";
  sideFace[14] = "|   |   |   ||   |   |   ||   |   |   ||   |   |   |";
  sideFace[15] = "| x | x | x || x | x | x || x | x | x || x | x | x |";
  sideFace[16] = "|   |   |   ||   |   |   ||   |   |   ||   |   |   |";
  sideFace[17] = "----------------------------------------------------";
  sideFace[18] = "|   |   |   ||   |   |   ||   |   |   ||   |   |   |";
  sideFace[19] = "| x | x | x || x | x | x || x | x | x || x | x | x |";
  sideFace[20] = "|   |   |   ||   |   |   ||   |   |   ||   |   |   |";
  sideFace[21] = "----------------------------------------------------";
  sideFace[22] = "|   |   |   ||   |   |   ||   |   |   ||   |   |   |";
  sideFace[23] = "| x | x | x || x | x | x || x | x | x || x | x | x |";
  sideFace[24] = "|   |   |   ||   |   |   ||   |   |   ||   |   |   |";
  sideFace[25] = "----------------------------------------------------";
  sideFace[26] = "             -------------                          ";
  sideFace[27] = "             |   |   |   |                          ";
  sideFace[28] = "             | x | x | x |                          ";
  sideFace[29] = "             |   |   |   |                          ";
  sideFace[30] = "             -------------                          ";
  sideFace[31] = "             |   |   |   |                          ";
  sideFace[32] = "             | x | x | x |                          ";
  sideFace[33] = "             |   |   |   |                          ";
  sideFace[34] = "             -------------                          ";
  sideFace[35] = "             |   |   |   |                          ";
  sideFace[36] = "             | x | x | x |                          ";
  sideFace[37] = "             |   |   |   |                          ";
  sideFace[38] = "             -------------                          ";
}

//non-empty constructor
Face::Face(char color, char color1, char color2, char color3, char color4, char color5)
{
  sideFace[0]  = "             -------------                          ";
  sideFace[1]  = "             |   |   |   |                          ";
  sideFace[2]  = "             | x | x | x |                          ";
  sideFace[3]  = "             |   |   |   |                          ";
  sideFace[4]  = "             -------------                          ";
  sideFace[5]  = "             |   |   |   |                          ";
  sideFace[6]  = "        up   | x | x | x |                          ";
  sideFace[7]  = "             |   |   |   |                          ";
  sideFace[8]  = "             -------------                          ";
  sideFace[9]  = "             |   |   |   |   front                  ";
  sideFace[10] = "             | x | x | x |   /                      ";
  sideFace[11] = "             |   |   |   |  /                       ";
  sideFace[12] = "  left       ------------- /   right       back     ";
  sideFace[13] = "----------------------------------------------------";
  sideFace[14] = "|   |   |   ||   |   |   ||   |   |   ||   |   |   |";
  sideFace[15] = "| x | x | x || x | x | x || x | x | x || x | x | x |";
  sideFace[16] = "|   |   |   ||   |   |   ||   |   |   ||   |   |   |";
  sideFace[17] = "----------------------------------------------------";
  sideFace[18] = "|   |   |   ||   |   |   ||   |   |   ||   |   |   |";
  sideFace[19] = "| x | x | x || x | x | x || x | x | x || x | x | x |";
  sideFace[20] = "|   |   |   ||   |   |   ||   |   |   ||   |   |   |";
  sideFace[21] = "----------------------------------------------------";
  sideFace[22] = "|   |   |   ||   |   |   ||   |   |   ||   |   |   |";
  sideFace[23] = "| x | x | x || x | x | x || x | x | x || x | x | x |";
  sideFace[24] = "|   |   |   ||   |   |   ||   |   |   ||   |   |   |";
  sideFace[25] = "----------------------------------------------------";
  sideFace[26] = "             -------------                          ";
  sideFace[27] = "             |   |   |   |                          ";
  sideFace[28] = "             | x | x | x |                          ";
  sideFace[29] = "             |   |   |   |                          ";
  sideFace[30] = "             -------------                          ";
  sideFace[31] = "             |   |   |   |                          ";
  sideFace[32] = "             | x | x | x |    down                  ";
  sideFace[33] = "             |   |   |   |                          ";
  sideFace[34] = "             -------------                          ";
  sideFace[35] = "             |   |   |   |                          ";
  sideFace[36] = "             | x | x | x |                          ";
  sideFace[37] = "             |   |   |   |                          ";
  sideFace[38] = "             -------------                          ";

  // Assigning Up Face Colors
  for(int i=2; i<13; i+=4)
  {
    for(int j=15; j<26; j+=4)
    {
      sideFace[i][j]=color;
    }
  }

  // Assigning Left Face Colors
  for(int i=15; i<25; i+=4)
  {
    for(int j=2; j<11; j+=4)
    {
      sideFace[i][j]=color1;
    }
  }

  // Assigning Front Face Colors
  for(int i=15; i<25; i+=4)
  {
    for(int j=15; j<26; j+=4)
    {
      sideFace[i][j]=color2;
    }
  }

  // Assigning Right Face Colors
  for(int i=15; i<25; i+=4)
  {
    for(int j=28; j<39; j+=4)
    {
      sideFace[i][j]=color3;
    }
  }

  // Assigning Back Face Colors
  for(int i=15; i<25; i+=4)
  {
    for(int j=41; j<53; j+=4)
    {
      sideFace[i][j]=color4;
    }
  }

  // Assigning Down Face Colors
  for(int i=28; i<39; i+=4)
  {
    for(int j=15; j<26; j+=4)
    {
      sideFace[i][j]=color5;
    }
  }
}


//single-face display function
void Face::printFace()
{
  for (int i=0; i<39; i++){
    cout<<sideFace[i]<<endl;
  }
}

void Face::upplus()
{//oh dear...

  //Turning the corner pieces of the main face
  swap = sideFace[10][15];
  sideFace[10][15] = sideFace[2][15];
  sideFace[2][15] = sideFace[2][23];
  swap2 = sideFace[10][23];
  sideFace[10][23] = swap;
  sideFace[2][23] = swap2;

  //Turning the outer-middle pieces of the main face
  swap = sideFace[6][15];
  sideFace[6][15] = sideFace[2][19];
  sideFace[2][19] = sideFace[6][23];
  swap2 = sideFace[10][19];
  sideFace[10][19] = swap;
  sideFace[6][23] = swap2;

  //Turning the affected faces (NOTE: I change each affected piece individually so that I don't have to initialize than 2 swap values.
  //Feel free to change if you want.
  swap = sideFace[15][23];
  sideFace[15][23] = sideFace[15][10];
  sideFace[15][10] = sideFace[15][49];
  swap2 = sideFace[15][36];
  sideFace[15][36] = swap;
  sideFace[15][49] = swap2;

  swap = sideFace[15][19];
  sideFace[15][19] = sideFace[15][6];
  sideFace[15][6] = sideFace[15][45];
  swap2 = sideFace[15][32];
  sideFace[15][32] = swap;
  sideFace[15][45] = swap2;

  swap = sideFace[15][15];
  sideFace[15][15] = sideFace[15][2];
  sideFace[15][2] = sideFace[15][41];
  swap2 = sideFace[15][28];
  sideFace[15][28] = swap;
  sideFace[15][41] = swap2;
}

void Face::frontplus()
{

  //Turning the corner pieces of the main face
  swap = sideFace[23][15];
  sideFace[23][15] = sideFace[15][15];
  sideFace[15][15] = sideFace[15][23];
  swap2 = sideFace[23][23];
  sideFace[23][23] = swap;
  sideFace[15][23] = swap2;

  //Turning the outer-middle pieces of the main face
  swap = sideFace[19][15];
  sideFace[19][15] = sideFace[15][19];
  sideFace[15][19] = sideFace[19][23];
  swap2 = sideFace[23][19];
  sideFace[23][19] = swap;
  sideFace[19][23] = swap2;

  //Turning the affected faces (NOTE: I change each affected piece individually so that I don't have to initialize than 2 swap values.
  //Feel free to change if you want.
  swap = sideFace[23][10];
  sideFace[23][10] = sideFace[10][15];
  sideFace[10][15] = sideFace[15][28];
  swap2 = sideFace[28][23];
  sideFace[28][23] = swap;
  sideFace[15][28] = swap2;

  swap = sideFace[19][10];
  sideFace[19][10] = sideFace[10][19];
  sideFace[10][19] = sideFace[19][28];
  swap2 = sideFace[28][19];
  sideFace[28][19] = swap;
  sideFace[19][28] = swap2;

  swap = sideFace[15][10];
  sideFace[15][10] = sideFace[10][23];
  sideFace[10][23] = sideFace[23][28];
  swap2 = sideFace[28][15];
  sideFace[28][15] = swap;
  sideFace[23][28] = swap2;
}

void Face::leftplus()
{

  //Turning the corner pieces of the main face
  swap = sideFace[23][2];
  sideFace[23][2] = sideFace[15][2];
  sideFace[15][2] = sideFace[15][10];
  swap2 = sideFace[23][10];
  sideFace[23][10] = swap;
  sideFace[15][10] = swap2;

  //Turning the outer-middle pieces of the main face
  swap = sideFace[19][2];
  sideFace[19][2] = sideFace[15][6];
  sideFace[15][6] = sideFace[19][10];
  swap2 = sideFace[23][6];
  sideFace[23][6] = swap;
  sideFace[19][10] = swap2;

  //Turning the affected faces (NOTE: I change each affected piece individually so that I don't have to initialize than 2 swap values.
  //Feel free to change if you want.
  swap = sideFace[23][49];
  sideFace[23][49] = sideFace[2][15];
  sideFace[2][15] = sideFace[15][15];
  swap2 = sideFace[28][15];
  sideFace[28][15] = swap;
  sideFace[15][15] = swap2;

  swap = sideFace[19][49];
  sideFace[19][49] = sideFace[6][15];
  sideFace[6][15] = sideFace[19][15];
  swap2 = sideFace[32][15];
  sideFace[32][15] = swap;
  sideFace[19][15] = swap2;

  swap = sideFace[15][49];
  sideFace[15][49] = sideFace[10][15];
  sideFace[10][15] = sideFace[23][15];
  swap2 = sideFace[36][15];
  sideFace[36][15] = swap;
  sideFace[23][15] = swap2;
}

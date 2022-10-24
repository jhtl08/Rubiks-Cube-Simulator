//rubikscube.cpp
//Kyle Coloma, Jason Lorenzo, Paolo Ong
//ENGG 31-N
//October 20, 2022

#include "rubikscube.h"

//class Face members

//default constructor
RubiksCube::RubiksCube()
{
  //allocate memory for array of pointers to arrays (rows)
    up = new char*[3];
    left = new char*[3];
    front = new char*[3];
    right = new char*[3];
    back = new char*[3];
    down = new char*[3];

  //allocate memory for the arrays pointed at (columns)
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

//display function
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

//Functions to perform single face rotation and swapping
//to be used for the actual rotation functions
void RubiksCube::faceRotate(char** face, bool clockwise)
{
  char temp;
  if (clockwise)
  {
    //rotate corner pieces clockwise
    temp = face[2][0];
    face[2][0] = face[2][2];
    face[2][2] = face[0][2];
    face[0][2] = face[0][0];
    face[0][0] = temp;

    //rotate middle pieces clockwise
    temp = face[1][0];
    face[1][0] = face[2][1];
    face[2][1] = face[1][2];
    face[1][2] = face[0][1];
    face[0][1] = temp;  
  }
  else
  {
    //rotate corner pieces counterclockwise
    temp = face[2][0];
    face[2][0] = face[0][0];
    face[0][0] = face[0][2];
    face[0][2] = face[2][2];
    face[2][2] = temp;

    //rotate middle pieces counterclockwise
    temp = face[1][0];
    face[1][0] = face[0][1];
    face[0][1] = face[1][2];
    face[1][2] = face[2][1];
    face[2][1] = temp;
  }
}

void RubiksCube::rowSwap(char** face1, char** face2, 
char** face3, char** face4, int rowIndex)
{
  char* temp= new char[3];
  temp = face1[rowIndex];
  face1[rowIndex] = face2[rowIndex];
  face2[rowIndex] = face3[rowIndex];
  face3[rowIndex] = face4[rowIndex];
  face4[rowIndex] = temp;
}

void RubiksCube::columnSwap(char** face1, char** face2, 
char** face3, char** face4, int columnIndex, bool toUp)
{
  char temp;
  int oppositeIndex=1;
  if (columnIndex==2)
  {
    oppositeIndex=0;
  }
  else if (columnIndex==0)
  {
    oppositeIndex=2;
  }

  if (toUp)
  {
    for(int i=0; i<3; i++)
    {
      temp = face1[0+i][columnIndex];
      face1[0+i][columnIndex] = face4[0+i][columnIndex];
      face4[0+i][columnIndex] = face3[2-i][oppositeIndex];
      face3[2-i][oppositeIndex] = face2[0+i][columnIndex];
      face2[0+i][columnIndex] = temp;
    }
  }
  else
  {
    for(int i=0; i<3; i++)
    {
      temp = face1[0+i][columnIndex];
      face1[0+i][columnIndex] = face2[0+i][columnIndex];
      face2[0+i][columnIndex] = face3[2-i][oppositeIndex];
      face3[2-i][oppositeIndex] = face4[0+i][columnIndex];
      face4[0+i][columnIndex] = temp;
    }
  }
}

void RubiksCube::rowcolumnSwap(char** face1, char** face2, char** 
face3, char** face4, int columnIndex, int rowIndex, bool toRight)
{
  char* temp = new char[3];
  char* face2asRow = new char[3];
  char* face4asRow = new char[3];
  int oppCol=1;
  int oppRow=1;
  if (columnIndex==0)
  {
    oppCol=2;
  }
  else if (columnIndex==2)
  {
    oppCol=0;
  }
  if (rowIndex==0)
  {
    oppRow=2;
  }
  else if (rowIndex==2)
  {
    oppRow=0;
  }

  if (toRight)
  {
    //convert the columns to lists like face1 and face4's rows
    for (int i=0; i<3; i++)
    {
      face2asRow[i] = face2[2-i][columnIndex];
    }
    for (int i=0; i<3; i++)
    {
      face4asRow[i] = face4[2-i][oppCol];
    }

    //swapping the rows
    temp = face1[rowIndex];
    face1[rowIndex] = face4asRow;
    face4asRow = face3[oppRow];
    face3[oppRow] = face2asRow;
    face2asRow = temp;

    //transfer back to column
    for (int i=0; i<3; i++)
    {
      face2[i][columnIndex] = face2asRow[i];
    }
    for (int i=0; i<3; i++)
    {
      face4[i][oppCol] = face4asRow[i];
    }
  }
  else
  {
    //convert the columns to lists like face1 and face4's rows
    for (int i=0; i<3; i++)
    {
      face2asRow[i] = face2[i][columnIndex];
    }
    for (int i=0; i<3; i++)
    {
      face4asRow[i] = face4[i][oppCol];
    }

    temp = face1[rowIndex];
    face1[rowIndex] = face2asRow;
    face2asRow = face3[oppRow];
    face3[oppRow] = face4asRow;
    face4asRow = temp;

    //transfer back to column
    for (int i=0; i<3; i++)
    {
      face2[i][columnIndex] = face2asRow[2-i];
    }
    for (int i=0; i<3; i++)
    {
      face4[i][oppCol] = face4asRow[2-i];
    }
  }
}

void RubiksCube::doublefaceRotate(char** face)
{
  char* listTemp = new char[3];
  char charTemp;

  //rotate first and last row
  for (int i=0; i<3; i++)
  {
    listTemp[2-i]=face[0][i];
    face[0][i]=face[2][2-i];
  }
  face[2]=listTemp;

  //swap remaining middle pieces
  charTemp = face[1][0];
  face[1][0]=face[1][2];
  face[1][2]=charTemp;
}

void RubiksCube::tworowSwap(char** face1, char** face2, 
int rowIndex, int oppositeIndex, bool flip)
{
  if (flip)
  {
    char temp;
    temp = face1[oppositeIndex][0];
    face1[oppositeIndex][0] = face2[rowIndex][2];
    face2[rowIndex][2] = temp;
    temp = face1[oppositeIndex][2];
    face1[oppositeIndex][2] = face2[rowIndex][0];
    face2[rowIndex][0] = temp;
    temp = face1[oppositeIndex][1];
    face1[oppositeIndex][1] = face2[rowIndex][1];
    face2[rowIndex][1] = temp;
  }
  else
  {
    char* temp = new char[3];
    temp = face1[rowIndex];
    face1[rowIndex] = face2[oppositeIndex];
    face2[oppositeIndex] = temp;
  }
}

void RubiksCube::twocolumnSwap(char** face1, char** face2, 
int columnIndex, int oppositeIndex, bool flip)
{
  char temp;
  
  if (flip)
  {
    temp = face1[0][oppositeIndex];
    face1[0][oppositeIndex] = face2[2][columnIndex];
    face2[2][columnIndex] = temp;
    temp = face1[2][oppositeIndex];
    face1[2][oppositeIndex] = face2[0][columnIndex];
    face2[0][columnIndex] = temp;
  }
  else
  {
    temp = face1[0][columnIndex];
    face1[0][columnIndex] = face2[0][oppositeIndex];
    face2[0][oppositeIndex] = temp;
    temp = face1[2][columnIndex];
    face1[2][columnIndex] = face2[2][oppositeIndex];
    face2[2][oppositeIndex] = temp;
  }
  temp = face1[1][oppositeIndex];
  face1[1][oppositeIndex] = face2[1][columnIndex];
  face2[1][columnIndex] = temp;
}

//Rotation Functions
void RubiksCube::upplus()
{
  faceRotate(up, false);
  rowSwap(left, back, right, front, 0);
}

void RubiksCube::upminus()
{
  faceRotate(up, true);
  rowSwap(front, right, back, left, 0);
}

void RubiksCube::downplus()
{
  faceRotate(down, false);
  rowSwap(front, right, back, left, 2);
}

void RubiksCube::downminus()
{
  faceRotate(down, true);
  rowSwap(left, back, right, front, 2);
}

void RubiksCube::leftplus()
{
  faceRotate(left, false);
  columnSwap(front, up, back, down, 0, true);
}

void RubiksCube::leftminus()
{
  faceRotate(left, true);
  columnSwap(front, up, back, down, 0, false);
}

void RubiksCube::rightplus()
{
  faceRotate(right, false);
  columnSwap(front, up, back, down, 2, false);
}

void RubiksCube::rightminus()
{
  faceRotate(right, true);
  columnSwap(front, up, back, down, 2, true);
}

void RubiksCube::frontminus()
{
  faceRotate(front, true);
  rowcolumnSwap(up, right, down, left, 0, 2, true);
}

void RubiksCube::frontplus()
{
  faceRotate(front, false);
  rowcolumnSwap(up, right, down, left, 0, 2, false);
}

void RubiksCube::backplus()
{
  faceRotate(back, false);
  rowcolumnSwap(down, left, up, right, 0, 2, true);
}

void RubiksCube::backminus()
{
  faceRotate(back, true);
  rowcolumnSwap(down, left, up, right, 0, 2, false);
}

void RubiksCube::uptwo()
{
  doublefaceRotate(up);
  tworowSwap(left, right, 0, 0, false);
  tworowSwap(front, back, 0, 0, false);
}

void RubiksCube::downtwo()
{
  doublefaceRotate(down);
  tworowSwap(left, right, 2, 2, false);
  tworowSwap(front, back, 2, 2, false);
}

void RubiksCube::lefttwo()
{
  doublefaceRotate(left);
  twocolumnSwap(back, front, 0, 2, true);
  twocolumnSwap(up, down, 0, 0, false);
}

void RubiksCube::righttwo()
{
  doublefaceRotate(right);
  twocolumnSwap(back, front, 2, 0, true);
  twocolumnSwap(up, down, 2, 2, false);
}

void RubiksCube::fronttwo()
{
  doublefaceRotate(front);
  tworowSwap(up, down, 0, 2, true);
  twocolumnSwap(left, right, 0, 2, true);
}

void RubiksCube::backtwo()
{
  doublefaceRotate(back);
  tworowSwap(up, down, 2, 0, true);
  twocolumnSwap(left, right, 2, 0, true);
}
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

//Swaps affected rows of each faces to 
//other affected row of each faces
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

//Swaps affected column of each faces to 
//other affected column of each faces
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

//rotates the face 180 degrees
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

//rotates the affected rows of each faces in 180 degrees rotation
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

//rotates the affected column of each faces in 180 degrees rotation
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
  //up - up face rotation
  //false - 90 degrees counterclockwise rotation

  rowSwap(left, back, right, front, 0);
  //left, back, right, front - affected faces when up face is rotated
  //rowswap function - only the rows of affected faces are rotated
  //0 - only the 1st row of the affected faces are rotated
}

void RubiksCube::upminus()
{
  faceRotate(up, true);
  //up - up face rotation
  //true - 90 degrees clockwise rotation

  rowSwap(front, right, back, left, 0);
  //front, right, back, left - affected faces when up face is rotated
  //rowswap function - only the rows of affected faces are rotated
  //0 - only the 1st row of the affected faces are rotated
}

void RubiksCube::downplus()
{
  faceRotate(down, false);
  //down - down face rotation
  //false - 90 degrees counterclockwise rotation

  rowSwap(front, right, back, left, 2);
  //front, right, back, left - affected faces when down face is 
  // rotated
  //rowSwap function - only the rows of affected faces are rotated
  //2 - only the 3rd row of the affected faces are rotated
}

void RubiksCube::downminus()
{
  faceRotate(down, true);
  //down - down face rotation
  //true - 90 degrees clockwise rotation

  rowSwap(left, back, right, front, 2);
  //left, back, right, front - affected faces when down face is 
  // rotated
  //rowSwap function - only the rows of affected faces are rotated
  //2 - only the 3rd row of the affected faces are rotated
}

void RubiksCube::leftplus()
{
  faceRotate(left, false);
  //left - left face rotation
  //false - 90 degrees counterclockwise rotation

  columnSwap(front, up, back, down, 0, true);
  //front, up, back, down - affected faces when left face is rotated
  //columnSwap function - only the column of affected faces are 
  // rotated
  //0 - most of the affected areas lies on the 1st column
  //3rd affected face (back) has its affected column at its 
  // 3rd column
  //true - affected parts of the faces rotates counterclockwise with
  // left face

}

void RubiksCube::leftminus()
{
  faceRotate(left, true);
  //left - left face rotation
  //true - 90 degrees clockwise rotation

  columnSwap(front, up, back, down, 0, false);
  //front, up, back, down - affected faces when left face is rotated
  //columnSwap function - only the column of affected faces are 
  // rotated
  //0 - most of the affected areas lies on the 1st column
  //3rd affected face (back) has its affected column at its 
  // 3rd column
  //false - affected parts of the faces rotates clockwise with 
  // left face
}

void RubiksCube::rightplus()
{
  faceRotate(right, false);
  //right - right face rotation
  //false - 90 degrees counterclockwise rotation

  columnSwap(front, up, back, down, 2, false);
  //front, up, back, down - affected faces when right face is rotated
  //columnSwap function - only the column of affected faces are 
  // rotated
  //2 - most of the affected areas lies on the 3rd column
  //3rd affected face (back) has its affected column at its 
  // 1st column
  //false - affected parts of the faces rotates counterclockwise with
  // right face

}

void RubiksCube::rightminus()
{
  faceRotate(right, true);
  //right - right face rotation
  //true - 90 degrees clockwise rotation

  columnSwap(front, up, back, down, 2, true);
  //front, up, back, down - affected faces when right face is rotated
  //columnSwap function - only the column of affected faces are 
  //rotated
  //2 - most of the affected areas lies on the 3rd column
  //3rd affected face (back) has its affected column at its 
  // 1st column
  //true - affected parts of the faces rotates clockwise with 
  // right face
}

void RubiksCube::frontminus()
{
  faceRotate(front, true);
  //front - front face rotation
  //true - 90 degrees clockwise rotation

  rowcolumnSwap(up, right, down, left, 0, 2, true);
  //up, right, down, left - affected faces when front face is rotated
  //rowcolumnSwap function - both row and column of the affected 
  // faces are rotated. Up & Down - Rows; Left & Right - Column
  //0 - 1st Column of the Left & Right face are affected
  //2 - 3rd Row of the Up & Down face are affected
  //true - affected parts of the faces rotates clockwise with 
  // front face
}

void RubiksCube::frontplus()
{
  faceRotate(front, false);
  //front - front face rotation
  //false - 90 degrees counterclockwise rotation

  rowcolumnSwap(up, right, down, left, 0, 2, false);
  //up, right, down, left - affected faces when front face is rotated
  //rowcolumnSwap function - both row and column of the affected 
  // faces are rotated. Up & Down - Rows; Left & Right - Column
  //0 - 1st Column of the Left & Right face are affected
  //2 - 3rd Row of the Up & Down face are affected
  //false - affected parts of the faces rotates counterclockwise with
  // front face
}

void RubiksCube::backplus()
{
  faceRotate(back, false);
  //back - back face rotation
  //false - 90 degrees counterclockwise rotation

  rowcolumnSwap(down, left, up, right, 0, 2, true);
  //down, left, up, right - affected faces when back face is rotated
  //rowcolumnSwap function - both row and column of the affected 
  // faces are rotated. Up & Down - Rows; Left & Right - Column
  //0 - 1st Column of the Left face is affected 
  // while 3rd column of right face is affected
  //2 - 3rd Row of the Down face is affected
  // while 1st Row of the Up face is affected
  //true - affected parts of the faces rotates counterclockwise with
  // back face
}

void RubiksCube::backminus()
{
  faceRotate(back, true);
  //back - back face rotation
  //true - 90 degrees clockwise rotation

  rowcolumnSwap(down, left, up, right, 0, 2, false);
  //down, left, up, right - affected faces when back face is rotated
  //rowcolumnSwap function - both row and column of the affected 
  // faces are rotated. Up & Down - Rows; Left & Right - Column
  //0 - 1st Column of the Left face is affected 
  // while 3rd column of right face is affected
  //2 - 3rd Row of the Down face is affected
  // while 1st Row of the Up face is affected
  //false - affected parts of the faces rotates clockwise with
  // back face
}

void RubiksCube::uptwo()
{
  doublefaceRotate(up);
  //up - up face 180 degree rotation

  tworowSwap(left, right, 0, 0, false);
  //affected parts of left & right faces are swapped

  tworowSwap(front, back, 0, 0, false);
  //affected parts of front & back faces are swapped
}

void RubiksCube::downtwo()
{
  doublefaceRotate(down);
  //down - down face 180 degree rotation

  tworowSwap(left, right, 2, 2, false);
  //affected parts of left & right faces are swapped

  tworowSwap(front, back, 2, 2, false);
  //affected parts of front & back faces are swapped
}

void RubiksCube::lefttwo()
{
  doublefaceRotate(left);
  //left - left face 180 degree rotation

  twocolumnSwap(back, front, 0, 2, true);
  //affected parts of back & front faces are swapped

  twocolumnSwap(up, down, 0, 0, false);
  //affected parts of up & down faces are swapped
}

void RubiksCube::righttwo()
{
  doublefaceRotate(right);
  //right - right face 180 degree rotation

  twocolumnSwap(back, front, 2, 0, true);
  //affected parts of back & front faces are swapped
  
  twocolumnSwap(up, down, 2, 2, false);
  //affected parts of up & down faces are swapped
}

void RubiksCube::fronttwo()
{
  doublefaceRotate(front);
  //front - front face 180 degree rotation

  tworowSwap(up, down, 0, 2, true);
  //affected parts of up & down faces are swapped

  twocolumnSwap(left, right, 0, 2, true);
  //affected parts of left & right faces are swapped
}

void RubiksCube::backtwo()
{
  doublefaceRotate(back);
  //back - back face 180 degree rotation

  tworowSwap(up, down, 2, 0, true);
  //affected parts of up & down faces are swapped

  twocolumnSwap(left, right, 2, 0, true);
  //affected parts of left & right faces are swapped
}

std::string RubiksCube::get_template()
{
  return full_face_template;
}


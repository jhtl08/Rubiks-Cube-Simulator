//rubiksmain.cpp
//Kyle Coloma, Jason Lorenzo, Paolo Ong
//ENGG 31-N
//October 20, 2022

#include "rubikscube.h"

using namespace std;

int main()
{
  RubiksCube rCube;

  rCube.printCube();

while(true)
{
  string user_command;
  cout << "> ";
  cin >> user_command;
  
  if (user_command == "u-")
  {
    rCube.upminus();
  }
  else if (user_command == "u+")
  {
    rCube.upplus();
  }
  else if (user_command == "u2")
  {
    rCube.uptwo();
  }
  else if (user_command == "d+")
  {
    rCube.downplus();
  }
  else if (user_command == "d-")
  {
    rCube.downminus();
  }  
  else if (user_command == "d2")
  {
    rCube.downtwo();
  }
  else if (user_command == "l+")
  {
    rCube.leftplus();
  }
  else if (user_command == "l-")
  {
    rCube.leftminus();
  }
  else if (user_command == "l2")
  {
    rCube.lefttwo();
  }
  else if (user_command == "r+")
  {
    rCube.rightplus();
  }
  else if (user_command == "r-")
  {
    rCube.rightminus();
  }
  else if (user_command == "r2")
  {
    rCube.righttwo();
  }
  else if (user_command == "f+")
  {
    rCube.frontplus();
  }
  else if (user_command == "f-")
  {
    rCube.frontminus();
  }
  else if (user_command == "f2")
  {
    rCube.fronttwo();
  }
  else if (user_command == "b+")
  {
    rCube.backplus();
  }
  else if (user_command == "b-")
  {
    rCube.backminus();
  }
  else if (user_command == "b2")
  {
    rCube.backtwo();
  }
  else if (user_command=="help")
  {
    cout << "InstructionsInstructionsInstructionsInstructions"<<endl; //put instructions here
    continue;
  }
  else if (user_command == "exit")
  {
    cout << "Thanks for playing with our Rubik's Cube!"<<endl;
    break;
  }
  else
  {
    cout<< "Invalid input. Enter help for the list of valid inputs."<<endl;
    continue;
  }

  rCube.printCube();
  cin.clear();
}

  return 0;
}
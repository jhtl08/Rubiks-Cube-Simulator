//rubiksmain.cpp
//Kyle Coloma, Jason Lorenzo, Paolo Ong
//ENGG 31-N
//October 25, 2022

#include "rubikscube.h"
#include <fstream>

using namespace std;

int main()
{
  RubiksCube rCube;

  rCube.printCube();
  
  ofstream myFile;

  myFile.open("cubelog.txt");

  string instructions = 
  "----------------------------------------------------"
  "\nInput Notation: \n"
  "[lowercase first letter of face (f, l, b, r, u)][direction]\n"
  "\nAvailable directions: \n"
  "2: 180 degrees\n"
  "+: 90 degrees counter-clockwise\n"
  "-: 90 degrees clockwise\n"
  "\nNote that final command should not include brackets.\n"
  "ex. f+ means to turn the front face 90 degrees CCW.\n" 
  "\nTo exit the program, type 'exit' without single\n"
  "quotation marks. \n"
  "To reset the cube, type 'reset' without single\n"
  "quotation marks.\n"
  "----------------------------------------------------\n";

while(true)
{
  string user_command;
  cout << "> ";
  cin >> user_command;
  myFile << "> " << user_command << endl;
  
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
    cout << instructions;
    myFile << instructions;
    continue;
  }
  else if (user_command == "exit")
  {
    cout<< "Thanks for playing with our Rubik's Cube!"<<endl;
    myFile<< "Thanks for playing with our Rubik's Cube!"<<endl;
    break;
  }
  else if (user_command == "reset")
  {
    rCube = RubiksCube();
  }
  else
  {
    cout<< "Invalid input. Enter help for the list of valid inputs."
    <<endl;
    myFile<<"Invalid input. Enter help for the list of valid inputs."
    <<endl;
    continue;
  }

  rCube.printCube();
  cin.clear();

  myFile<<rCube.get_template();
}
  myFile.close();

  return 0;
}
//rubikscube.h
//Kyle Coloma, Jason Lorenzo, Paolo Ong
//ENGG 31-N
//October 13, 2022

#ifndef RUBIKSCUBE_H
#define RUBIKSCUBE_H

#include <iostream>

class RubiksCube
{
  private:
    //allocate memory for array of pointers to arrays (columns)
    char** up = new char*[3];
    char** left = new char*[3];
    char** front = new char*[3];
    char** right = new char*[3];
    char** back = new char*[3];
    char** down = new char*[3];

    //template for faces left, front, right, back
    std::string full_face_template = 
  "             -------------                          \n"
  "             |   |   |   |                          \n"
  "             | x | x | x |                          \n"
  "             |   |   |   |                          \n"
  "             -------------                          \n"
  "             |   |   |   |                          \n"
  "        up   | x | x | x |                          \n"
  "             |   |   |   |                          \n"
  "             -------------                          \n"
  "             |   |   |   |   front                  \n"
  "             | x | x | x |   /                      \n"
  "             |   |   |   |  /                       \n"
  "  left       ------------- /   right       back     \n"
  "----------------------------------------------------\n"
  "|   |   |   ||   |   |   ||   |   |   ||   |   |   |\n"
  "| x | x | x || x | x | x || x | x | x || x | x | x |\n"
  "|   |   |   ||   |   |   ||   |   |   ||   |   |   |\n"
  "----------------------------------------------------\n"
  "|   |   |   ||   |   |   ||   |   |   ||   |   |   |\n"
  "| x | x | x || x | x | x || x | x | x || x | x | x |\n"
  "|   |   |   ||   |   |   ||   |   |   ||   |   |   |\n"
  "----------------------------------------------------\n"
  "|   |   |   ||   |   |   ||   |   |   ||   |   |   |\n"
  "| x | x | x || x | x | x || x | x | x || x | x | x |\n"
  "|   |   |   ||   |   |   ||   |   |   ||   |   |   |\n"
  "----------------------------------------------------\n"
  "             -------------                          \n"
  "             |   |   |   |                          \n"
  "             | x | x | x |                          \n"
  "             |   |   |   |                          \n"
  "             -------------                          \n"
  "             |   |   |   |                          \n"
  "             | x | x | x |    down                  \n"
  "             |   |   |   |                          \n"
  "             -------------                          \n"
  "             |   |   |   |                          \n"
  "             | x | x | x |                          \n"
  "             |   |   |   |                          \n"
  "             -------------                          \n";

  public:
    //default constructor
    RubiksCube();

    void printCube();
};






#endif

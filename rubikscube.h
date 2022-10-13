//rubikscube.h
//Kyle Coloma, Jason Lorenzo, Paolo Ong
//ENGG 31-N
//October 13, 2022

#ifndef RUBIKSCUBE_H
#define RUBIKSCUBE_H

#include <iostream>

class Face
{
  private:
    std::string* sideFace = new std::string[13];
  
  public:
    //default constructor
    Face();

    //constructor with parameter
    Face(char color);

    void printFace();
};

class RubiksCube
{
  private:
    Face up, down, left, right, front, back;

  public:
    //default constructor
    RubiksCube();

    void printCube();
};






#endif

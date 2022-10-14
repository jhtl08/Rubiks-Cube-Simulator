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
    std::string* sideFace = new std::string[39];
  
  public:
    //default constructor
    Face();

    //constructor with parameter
    Face(char color, char color1, char color2, char color3, char color4, char color5);

    void printFace();
};


#endif

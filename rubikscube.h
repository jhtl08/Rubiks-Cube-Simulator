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

    //template for the single faces (up and down)
    std::string single_face_template = 
    "             -------------\n"
    "             |   |   |   |\n"
    "             | a | b | c |\n"
    "             |   |   |   |\n"
    "             -------------\n"
    "             |   |   |   |\n"
    "             | d | e | f |\n"
    "             |   |   |   |\n"
    "             -------------\n"
    "             |   |   |   |\n"
    "             | g | h | i |\n"
    "             |   |   |   |\n"
    "             -------------\n";
  
    //template for faces left, front, right, back
    std::string four_face_template = 
    "----------------------------------------------------\n"
    "|   |   |   ||   |   |   ||   |   |   ||   |   |   |\n"
    "| a | b | c || j | k | l || s | t | u || B | C | D |\n"
    "|   |   |   ||   |   |   ||   |   |   ||   |   |   |\n"
    "----------------------------------------------------\n"
    "|   |   |   ||   |   |   ||   |   |   ||   |   |   |\n"
    "| d | e | f || m | n | o || v | w | x || E | F | G |\n"
    "|   |   |   ||   |   |   ||   |   |   ||   |   |   |\n"
    "----------------------------------------------------\n"
    "|   |   |   ||   |   |   ||   |   |   ||   |   |   |\n"
    "| g | h | i || p | q | r || y | z | A || H | I | J |\n"
    "|   |   |   ||   |   |   ||   |   |   ||   |   |   |\n"
    "----------------------------------------------------\n";

  public:
    //default constructor
    RubiksCube();

    void printCube();
};






#endif

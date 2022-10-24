//rubikscube.h
//Kyle Coloma, Jason Lorenzo, Paolo Ong
//ENGG 31-N
//October 20, 2022

#ifndef RUBIKSCUBE_H
#define RUBIKSCUBE_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class RubiksCube
{
  private:
    //declare 2D arrays for faces
    char** up;
    char** left;
    char** front;
    char** right;
    char** back;
    char** down;

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
  "  left       ------------- /   right        back    \n"
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
  "             | x | x | x | down                     \n"
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

    void faceRotate(char** face, bool clockwise);
    void rowSwap(char** face1, char** face2, char** face3, 
    char** face4, int rowIndex);
    void columnSwap(char** face1, char** face2, char** face3, 
    char** face4, int columnIndex, bool toUp);
    void rowcolumnSwap(char** face1, char** face2, char** face3, 
    char** face4, int columnIndex, int rowIndex, bool toRight);
    void doublefaceRotate(char** face);
    void tworowSwap(char** face1, char** face2, int rowIndex, 
    int oppositeIndex, bool flip);
    void twocolumnSwap(char** face1, char** face2, int columnIndex,
    int oppositeIndex, bool flip);

    void upplus();
    void upminus();
    void downplus();
    void downminus();
    void leftplus();
    void leftminus();
    void rightplus();
    void rightminus();
    void frontplus();
    void frontminus();
    void backplus();
    void backminus();
    void uptwo();
    void downtwo();
    void lefttwo();
    void righttwo();
    void fronttwo();
    void backtwo();

    std::string get_template();
};

#endif

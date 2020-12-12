//
//  Sodoku.cpp
//  SODOKU
//
//  Created by Yehia Darweesh on 2020-12-12.
//  Copyright © 2020 Yaya Creations. All rights reserved.
//



#include "Sodoku.hpp"
#include <fstream>
#include <iostream>
using namespace std;

//Read Sodoku grid from a text file and save it in a 2-D Array
void Board::Read_Grid_From_File(string File_Name)
{
    ifstream file;
    file.open(File_Name);

    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            file>>(Grid[row][col]);
        }
    }
    file.close();
}

//Print sodoku grid with a "|" symbol separating adjacent characters
void Board::Print_Grid()
{
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            (col == 8)? cout << Grid[row][col] <<endl : cout << Grid[row][col] <<" | ";
        }
    }
}



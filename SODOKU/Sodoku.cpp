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
    char input_char;

    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            file>>input_char;
            if(input_char == '.')
                input_char = '0';               //Change all the '.' to be zeroes
            Grid[row][col] = input_char - '0';  //change chars to ints
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

bool Board::Grid_Complete()
{
    int row;
    int col;
    if (Check_For_Zeros(row, col))
        return true; // No more zeros
    for(int val = 1; val <= 9; val++)
    {
        if(Valid_Entry(val,row,col))
        {
            Grid[row][col] = val;
            if (Grid_Complete())
                return true;
            Grid[row][col] = 0;
            m_Correction++;
        }
    }
    return false;
}

void Board::Print_Correction()
{
    cout<<"Corrected "<<m_Correction<<" Times"<<endl;
}

bool Board::Check_For_Zeros(int &row, int &col)
{
    
    for ( row = 0; row < 9; row++) {
        for ( col = 0; col < 9; col++) {
            if(Grid[row][col] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

bool Board::Valid_Entry(int val, int row, int col)
{
    bool Found_In_Row = false;
    bool Found_In_col = false;
    bool Found_In_Box = false;
    
    // check if val is present in the row
    for(int colcheck = 0; colcheck < 9; colcheck++)
    {
        if(Grid[row][colcheck] == val)
        {
            Found_In_Row = true;
            break;
        }
    }
    
    // check if i is present in the col
    for(int rowcheck = 0; rowcheck < 9; rowcheck++)
    {
        if(Grid[rowcheck][col] == val)
        {
            Found_In_col = true;
            break;
        }
    }
    
    //check if number in the 3x3 box
    if(row>=0 && row<=2 && col>=0 && col<=2)
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if (Grid[i][j] == val)
                {
                    Found_In_Box = true;
                    break;
                }
            }
        }
    }
    if(row>=0 && row<=2 && col>=3 && col<=5)
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 3; j < 6; j++)
            {
                if (Grid[i][j] == val)
                {
                    Found_In_Box = true;
                    break;
                }
            }
        }
    }
    if(row>=0 && row<=2 && col>=6 && col<=8)
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 6; j < 9; j++)
            {
                if (Grid[i][j] == val)
                {
                    Found_In_Box = true;
                    break;
                }
            }
        }
    }
    if(row>=3 && row<=5 && col>=0 && col<=2)
    {
        for(int i = 3; i < 6; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if (Grid[i][j] == val)
                {
                    Found_In_Box = true;
                    break;
                }
            }
        }
    }
    if(row>=3 && row<=5 && col>=3 && col<=5)
    {
        for(int i = 3; i < 6; i++)
        {
            for(int j = 3; j < 5; j++)
            {
                if (Grid[i][j] == val)
                {
                    Found_In_Box = true;
                    break;
                }
            }
        }
    }
    if(row>=3 && row<=5 && col>=6 && col<=8)
    {
        for(int i = 3; i < 6; i++)
        {
            for(int j = 6; j < 9; j++)
            {
                if (Grid[i][j] == val)
                {
                    Found_In_Box = true;
                    break;
                }
            }
        }
    }
    if(row>=6 && row<=8 && col>=0 && col<=2)
    {
        for(int i = 6; i < 9; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if (Grid[i][j] == val)
                {
                    Found_In_Box = true;
                    break;
                }
            }
        }
    }
    if(row>=6 && row<=8 && col>=3 && col<=5)
    {
        for(int i = 6; i < 9; i++)
        {
            for(int j = 3; j < 6; j++)
            {
                if (Grid[i][j] == val)
                {
                    Found_In_Box = true;
                    break;
                }
            }
        }
    }
    if(row>=6 && row<=8 && col>=6 && col<=8)
    {
        for(int i = 6; i < 9; i++)
        {
            for(int j = 6; j < 9; j++)
            {
                if (Grid[i][j] == val)
                {
                    Found_In_Box = true;
                    break;
                }
            }
        }
    }
    return !Found_In_Row && !Found_In_col && !Found_In_Box && Grid[row][col] == 0;
}


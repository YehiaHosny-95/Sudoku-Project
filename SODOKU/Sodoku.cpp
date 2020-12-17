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
#include <stdlib.h>
#include <vector>
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

//Check if the Sodoku is solved, if not, grab an empty spot and assign it with a suitable value
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
            Grid[row][col] = val; //Assign possible value
            if (Grid_Complete())
                return true;
            Grid[row][col] = 0;
            m_Correction++; //Increment the number a box had to be reset
        }
    }
    return false;
}

//Determine the Difficulty of the grid
void Board::Determine_Difficulty()
{
    //Given the Examples in the project description, the number of times the code had to reset (backtrack) a number was calculated. I took the average numbers (to the nearest 10th) between difficulties and set them as constrains to determine the grid's difficulty
    if(m_Correction < 2945)
        m_Difficulty = "Easy";
    else if(m_Correction >= 2945 && m_Correction < 25960)
        m_Difficulty = "Miduim";
    else if(m_Correction >= 25960 && m_Correction < 90900)
        m_Difficulty = "Hard";
    else
        m_Difficulty = "Samurai";
    cout<<"Corrected "<<m_Correction<<" Times."<<" Difficulty: "<<m_Difficulty<< endl;
}

//Grab an empty box (i.e. a box with 0 inside it), if non found return false
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

//Check if a number can be stored inside the empty box
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
    //Left top box
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
    //Middle top box
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
    //Right top box
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
    //Left middle Box
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
    //Middle middle Box
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
    //Middle right box
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
    //Buttom left box
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
    //Buttom Middle Box
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
    //Buttom right box
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

//The Following function will fill the top left 3x3 box and will call other functions to fill the middle top 3x3, top right 3x3 box and col 0. All of these functions are used to generate a Sudodku puzzle
void Board::Fill_Empty_Left_Box()
{
    srand((unsigned) time(0));
    vector<int> Valid_numbers_Box_1 = {1,2,3,4,5,6,7,8,9};
    vector<int> Used_numbers_row_0 = {};
    vector<int> Used_numbers_row_1 = {};
    vector<int> Used_numbers_row_2 = {};
    vector<int> Used_numbers_col_0 = {};
    vector<int> temp_Used_numbers_row_0 = {};
    vector<int> temp_Used_numbers_row_1 = {};
    vector<int> temp_Used_numbers_row_2 = {};
    int randomIndex;
    for(int row = 0; row < 3; row++){
        for(int col = 0; col < 3; col++)
        {
            randomIndex = rand() % Valid_numbers_Box_1.size(); //Random index from the vector
            Grid[row][col] = Valid_numbers_Box_1[randomIndex]; //Random number from 1-9
            switch (row)
            {
                case 0:
                    Used_numbers_row_0.push_back(Valid_numbers_Box_1[randomIndex]);
                    temp_Used_numbers_row_0.push_back(Valid_numbers_Box_1[randomIndex]);
                    break;
                case 1:
                    Used_numbers_row_1.push_back(Valid_numbers_Box_1[randomIndex]);
                    temp_Used_numbers_row_1.push_back(Valid_numbers_Box_1[randomIndex]);
                    break;
                case 2:
                    Used_numbers_row_2.push_back(Valid_numbers_Box_1[randomIndex]);
                    temp_Used_numbers_row_2.push_back(Valid_numbers_Box_1[randomIndex]);
                    break;
                default:
                    break;
            }
            
            Valid_numbers_Box_1.erase(Valid_numbers_Box_1.begin() + randomIndex);
            if(col == 0)
            {
                Used_numbers_col_0.push_back(Grid[row][col]);
            }
        }
    }
    
    Fill_Middle_Box(Used_numbers_row_0, Used_numbers_row_1, Used_numbers_row_2);
   
    Fill_Right_Box(temp_Used_numbers_row_0, temp_Used_numbers_row_1, temp_Used_numbers_row_2);
    
    Fill_Col_0(Used_numbers_col_0);
    
    Grid_Complete();

}

//This function will fill the middle top box
void Board::Fill_Middle_Box(vector<int> Used_numbers_row_0, vector<int> Used_numbers_row_1, vector<int> Used_numbers_row_2)
{
    srand((unsigned) time(0));
    int randomIndex;
    for(int row = 0; row < 3; row++){
        for(int col = 3; col < 6; col++)
        {
            switch (row)
            {
                case 0:
                    randomIndex = rand() % Used_numbers_row_2.size();
                    Grid[row][col] = Used_numbers_row_2[randomIndex];
                    Used_numbers_row_2.erase(Used_numbers_row_2.begin() + randomIndex);
                    break;
                case 1:
                    randomIndex = rand() % Used_numbers_row_0.size();
                    Grid[row][col] = Used_numbers_row_0[randomIndex];
                    Used_numbers_row_0.erase(Used_numbers_row_0.begin() + randomIndex);
                    break;
                case 2:
                    randomIndex = rand() % Used_numbers_row_1.size();
                    Grid[row][col] = Used_numbers_row_1[randomIndex];
                    Used_numbers_row_1.erase(Used_numbers_row_1.begin() + randomIndex);
                    break;
                default:
                    break;
            }
        }
    }
}

//This function will fill the top right box
void Board::Fill_Right_Box(vector<int> temp_Used_numbers_row_0, vector<int> temp_Used_numbers_row_1, vector<int> temp_Used_numbers_row_2)
{
    srand((unsigned) time(0));
    int randomIndex;
    for(int row = 0; row < 3; row++){
        for(int col = 6; col < 9; col++)
        {
            switch (row)
            {
                case 0:
                    randomIndex = rand() % temp_Used_numbers_row_1.size();
                    Grid[row][col] = temp_Used_numbers_row_1[randomIndex];
                    temp_Used_numbers_row_1.erase(temp_Used_numbers_row_1.begin() + randomIndex);
                    break;
                case 1:
                    randomIndex = rand() % temp_Used_numbers_row_2.size();
                    Grid[row][col] = temp_Used_numbers_row_2[randomIndex];
                    temp_Used_numbers_row_2.erase(temp_Used_numbers_row_2.begin() + randomIndex);
                    break;
                case 2:
                    randomIndex = rand() % temp_Used_numbers_row_0.size();
                    Grid[row][col] = temp_Used_numbers_row_0[randomIndex];
                    temp_Used_numbers_row_0.erase(temp_Used_numbers_row_0.begin() + randomIndex);
                    break;
                default:
                    break;
            }
        }
    }
}

//This function will fill the first column of the grid
void Board::Fill_Col_0(vector<int> Used_numbers_col_0)
{
    srand((unsigned) time(0));
    int randomIndex;
    vector<int> valid_numbers_col_0 = {};
    for(int i = 1; i<10; i++)
    {
        bool found_a_matching_number = false;
        for(int j = 0; j < Used_numbers_col_0.size(); j++)
        {
            if(i == Used_numbers_col_0[j])
            {
                found_a_matching_number = true;
                break;
            }
        }
        if (!found_a_matching_number)
            valid_numbers_col_0.push_back(i);
    }
    
    for(int row = 3; row<9; row++)
    {
        randomIndex = rand() % valid_numbers_col_0.size();
        Grid[row][0] = valid_numbers_col_0[randomIndex];
        valid_numbers_col_0.erase(valid_numbers_col_0.begin() + randomIndex);
    }
}

//This function will make sure the generated Puzzle has only one solution
void Board::Unique_Solution(int &No_of_Solutions)
{
    int row, col;

    if (Check_For_Zeros(row, col))
    {
        No_of_Solutions++;
        return; // No more zeros
    }


    for(int val = 1;val <= 9 && No_of_Solutions < 2; val++)
    {
        if(Valid_Entry(val,row,col))
        {
            Grid[row][col] = val;
            Unique_Solution(No_of_Solutions);
        }
        Grid[row][col] = 0;
        m_Correction++;
    }
}

void Board::Hide_Numbers(char Difficulty)
{
    vector<int> Number_to_Hide = {1,2,3,4,5,6,7,8,9};
    srand((unsigned) time(0));
    int random_Num;
    int Level;
    int No_of_Solutions = 0;
    int temp_num;
    m_Correction = 0;
    switch (Difficulty)
    {
        case 'E':
            Level = 2945;
            break;
        case 'M':
            Level = 25960;
            break;
        case 'H':
            Level = 90900;
            break;
        case 'S':
            Level = 500000;
            break;
        default:
            Level = 25960;
            break;
    }
    while(Number_to_Hide.size() != 0)
    {
        int randomIndex = rand() % Number_to_Hide.size();
        random_Num = Number_to_Hide[randomIndex];
        Number_to_Hide.erase(Number_to_Hide.begin() + randomIndex);
        if(m_Correction < Level)
        {
            for(int row = 0; row < 9; row++)
            {
                for(int col = 0; col < 9; col++)
                {
                    if(Grid[row][col] == random_Num)
                    {
                        temp_num = Grid[row][col];
                        Grid[row][col] = 0;
                        No_of_Solutions = 0;
                        Unique_Solution(No_of_Solutions);
                        if(No_of_Solutions != 1)
                        {
                            Grid[row][col] = temp_num;
                        }
                    }
                }
            }
        }
    }
}


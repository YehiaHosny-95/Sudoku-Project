//
//  Sodoku.hpp
//  SODOKU
//
//  Created by Yehia Darweesh on 2020-12-12.
//  Copyright © 2020 Yaya Creations. All rights reserved.
//


#ifndef Sodoku_hpp
#define Sodoku_hpp

#include <stdio.h>
#include <string>
using namespace std;

class Board
{
public:

    void Read_Grid_From_File(string File_Name);
    void Print_Grid();
    bool Check_For_Zeros(int &row, int& col);
    bool Grid_Complete();
    bool Valid_Entry(int val, int row, int col);
    void Determine_Difficulty();
    void Fill_Middle_Box(vector<int> Used_numbers_row_0, vector<int> Used_numbers_row_1, vector<int> Used_numbers_row_2);
    void Fill_Right_Box(vector<int> Temp_Used_numbers_row_0, vector<int> Temp_Used_numbers_row_1, vector<int> Temp_Used_numbers_row_2);
    void Fill_Col_0(vector<int> Used_numbers_col_0);
    void Fill_Empty_Left_Box();
    void Unique_Solution(int &No_of_Solutions);
    void Hide_Numbers(char Difficulty);
private:
    
    int Grid[9][9]{0};
    int m_Correction;
    int m_number_of_Solutions = 0;
    string m_Difficulty;
    
};


#endif /* Sodoku_hpp */


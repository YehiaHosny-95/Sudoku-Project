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
    void Print_Correction();
private:
    
    int Grid[9][9]{};
    int m_Correction;
    
};

#endif /* Sodoku_hpp */


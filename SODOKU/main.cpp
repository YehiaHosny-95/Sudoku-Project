//
//  main.cpp
//  SODOKU
//
//  Created by Yehia Darweesh on 2020-12-12.
//  Copyright © 2020 Yaya Creations. All rights reserved.
//

#include <iostream>
#include "Sodoku.hpp"
#include <iostream>


int main(int argc, const char * argv[]) {
    Board My_Board;
    My_Board.Read_Grid_From_File("Sodoku.txt");
    My_Board.Print_Grid();
    cout<<endl<<endl;
    My_Board.Grid_Complete();
    My_Board.Print_Grid();
    My_Board.Print_Correction();

    return 0;
}

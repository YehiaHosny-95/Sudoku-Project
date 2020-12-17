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

//This function will ask the user to select an operation and will check the validity of the selection
int Choose_Operation(char &Difficulty)
{
    int operation;
    bool Valid_choice;
    bool Valid_Diff;
    do
    {
        cout<<"Choose operation:"<<endl;
        cout<<"Type 1 to load unsolved sudoku from text file"<<endl;
        cout<<"Type 2 to solve loaded sudoku"<<endl;
        cout<<"Type 3 to Generate a sudoku puzzle"<<endl;
        cout<<"Type 0 to end the program"<<endl;
        cin>>operation;
        Valid_choice = (cin.good() && (operation == 1 || operation == 2 || operation == 3 || operation == 0));
        
        if (!Valid_choice)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Invalid Choice of operation. Please choose one of the following options."<<endl;
        }
        
    }while(!Valid_choice);
    
    if(operation == 3)
    {
        do
        {
            cout<<"Choose Difficulty, E for easy, M for Medium, H for Hard or S for Samurai:"<<endl;
            cin>>Difficulty;
            Valid_Diff = (cin.good() && (Difficulty == 'E' || Difficulty == 'M' || Difficulty == 'H' || Difficulty == 'S'));
            if(!Valid_Diff)
                cout<<"Invalid choice of difficulty. Please choose one of the following options."<<endl;
        }while(!Valid_Diff);
    }
    return operation;
}

//This Function will Load and print the sudoku puzzle save in Sodoku.txt file (Part 1)
void Load_Unsolved_Puzzle(Board &My_Board)
{
    My_Board.Read_Grid_From_File("Sodoku.txt");
    My_Board.Print_Grid();
    cout<<endl<<endl;
}

//This function will solve and print loaded puzzle from part. If no puzzle was loaded it will just generate a dummy puzzle. (Part 2)
void Solve_Loaded_Puzzle(Board &My_Board)
{
    My_Board.Grid_Complete();
    My_Board.Print_Grid();
    My_Board.Determine_Difficulty();
}

//This function will generate and print a sudoku puzzle based on the difficulty input of the user
void Genrate_Puzzle(char &Difficulty)
{
    Board Created_Grid;
    Created_Grid.Fill_Empty_Left_Box();
    //Created_Grid.Print_Grid();
    cout<<endl<<endl;
    Created_Grid.Hide_Numbers(Difficulty);
    Created_Grid.Print_Grid();
}

int main(int argc, const char * argv[]) {
    Board My_Board;
    char Difficulty;
    int Operation = 0;
    do
    {
        Operation = Choose_Operation(Difficulty);
        switch (Operation)
        {
            case 1:
                Load_Unsolved_Puzzle(My_Board);
                break;
            case 2:
                Solve_Loaded_Puzzle(My_Board);
                break;
            case 3:
                Genrate_Puzzle(Difficulty);
                break;
            default:
                break;
        }
    }while (Operation != 0);

    return 0;
}

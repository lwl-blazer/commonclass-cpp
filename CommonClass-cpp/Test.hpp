//
//  Test.hpp
//  CommonClass-cpp
//
//  Created by blazer on 2020/3/19.
//  Copyright © 2020 luowailin. All rights reserved.
//

#ifndef Test_hpp
#define Test_hpp

#include <stdio.h>
#include <iostream>
#include "AstarSearch.hpp"

using std::cout;

class Test{
public:
    Test(){
        
    }
    
    ~Test(){
        
    }
    
    void TestHeuristic(AStartSearch star){
        cout << "----------------------" << "\n";
        cout << "Heuristic Function Test:";
        if (star.Heuristic(1, 2, 3, 4) != 4) {
            cout << "failed" << "\n";
            cout << "\n" << "Heuristic(1, 2, 3, 4) = " << star.Heuristic(1, 2, 3, 4) << "\n";
            cout << "Correct result: 4" << "\n";
            cout << "\n";
        } else if (star.Heuristic(2, -1, 4, -7) != 8) {
            cout << "TestHeuristic Failed" << "\n";
            cout << "\n" << "Heuristic(2, -1, 4, -7) = " << star.Heuristic(2, -1, 4, -7) << "\n";
            cout << "Correct result: 8" << "\n";
            cout << "\n";
        } else {
             cout << "passed" << "\n";
        }
        cout << "----------------------" << "\n";
    }


    int MultiplyByTwo_passbyvalue(int i) {
        i = 2 * i;
        return i;
    }

    //有一个间接寻址的过程
    int MultiplyByTwo_passreference(int &i){
        i = 2 * i;
        return i;
    }

    //直接操作
    int MultiplyByTwo_passpointer(int *i){
        *i = 2 * (*i);
        return *i;
    }

    void DoubleString(string &value){
        value = value + " " + value;
    }
    
    void TestAddToOpen(){
        cout << "-------------" << "\n";
        cout << "AddToOpen Function Test:";
        int x = 3;
        int y = 0;
        int g = 5;
        int h = 7;
        
        //open list
        vector<vector<int>> open{{0, 0, 2, 9}, {1, 0, 2, 2}, {2, 0, 2, 4}};
        vector<vector<int>> solution_open = open;
        solution_open.push_back(vector<int>{3, 0 , 5, 7});
        
        //网格
        vector<vector<State>> grid{{State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                                  {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                                  {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                                  {State::kEmpty, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                                  {State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty, State::kObstacle, State::kEmpty}};
        vector<vector<State>> solution_grid = grid;
        solution_grid[3][0] = State::kClosed; //x,y 设置kcolse
        
        AStartSearch star;
        star.AddToOpen(x, y, g, h, open, grid);
        if (open != solution_open) {
            cout << "failed" << "\n";
            cout << "\n";
            cout << "Your open list is: " << "\n";
            PrintVectorOfVectors(open);
            cout << "Solution open list is: " << "\n";
            PrintVectorOfVectors(solution_open);
            cout << "\n";
        } else if (grid != solution_grid) {
            cout << "failed" << "\n";
            cout << "\n";
            cout << "Your grid is: " << "\n";
            PrintVectorOfVectors(grid);
            cout << "\n";
            cout << "Solution grid is: " << "\n";
            PrintVectorOfVectors(solution_grid);
            cout << "\n";
        } else {
            cout << "passed" << "\n";
            cout << "\n";
            cout << "Your grid is: " << "\n";
            PrintVectorOfVectors(grid);
            cout << "\n";
            cout << "Solution grid is: " << "\n";
            PrintVectorOfVectors(solution_grid);
            cout << "\n";
        }
        cout << "----------------------" << "\n";
    }
    
private:
    void PrintVectorOfVectors(vector<vector<int>> v) {
        for (auto row : v) {
            cout << "{ ";
            for (auto col : row) {
                cout << col << " ";
            }
            cout << "}" << "\n";
        }
    }
    
    void PrintVectorOfVectors(vector<vector<State>> v) {
        AStartSearch star;
        for (auto row : v) {
            cout << "{ ";
            for (auto col : row) {
                cout << star.CellString(col) << " ";
            }
            cout << "}" << "\n";
        }
    }
    
};

#endif /* Test_hpp */

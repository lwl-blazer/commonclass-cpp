//
//  main.cpp
//  CommonClass-cpp
//
//  Created by luowailin on 2020/3/12.
//  Copyright © 2020 luowailin. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include "AstarSearch.hpp"

using std::cout;


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    AStartSearch star;
    vector<vector<State>> board  = star.ReadBoardFile("/Users/blazer/Documents/blazer/Code/commonclass-cpp/CommonClass-cpp/1.board");
    star.PrintBoard(board);

    
    int init[2]{0, 0};
    int goal[2]{4, 5};
    
    vector<vector<State>>path = star.Search(board, init, goal);
    star.PrintBoard(path);
    
    
    /*
    Test test;
    test.example();
     */
        
    /*
    int a = 5;
    cout << "The int a equals:" << a << "\n";
    
    int b = test.MultiplyByTwo_passbyvalue(a);
    cout << "b:"<<b<<"\n";
    cout << "a:" <<a << "\n";
    
    int c = 5;
    cout << "c:" << c << "\n";
    int d = test.MultiplyByTwo_passreference(c);
    printf("%p--%p\n", &c, &d);
    cout << "c:" << c << "\n";
    
    int e = 5;
    cout << "e:" << e << "\n";
    int f = test.MultiplyByTwo_passpointer(&e);
    printf("%p--%p\n", &e, &f);
    cout << "e:" << e << "\n";
    */
    
    return 0;
}

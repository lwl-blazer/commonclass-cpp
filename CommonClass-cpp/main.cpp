//
//  main.cpp
//  CommonClass-cpp
//
//  Created by luowailin on 2020/3/12.
//  Copyright © 2020 luowailin. All rights reserved.
//

#include <iostream>
#include "AstarSearch.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    AStartSearch star;
    vector<vector<State>> states  = star.ReadBoardFile("/Users/blazer/Documents/blazer/Code/commonclass-cpp/CommonClass-cpp/1.board");
    
    star.PrintBoard(states);
    

    return 0;
}

//
//  AstarSearch.hpp
//  CommonClass-cpp
//
//  Created by blazer on 2020/3/14.
//  Copyright © 2020 luowailin. All rights reserved.
//

#ifndef AstarSearch_hpp
#define AstarSearch_hpp

#include <string>
#include <vector>

enum class State{kEmpty, kObstacle};

using std::vector;
using std::string;

class AStartSearch{
  
public:
    AStartSearch();
    ~AStartSearch();
    
    vector<State> ParseLine(string line);
    vector<vector<State>> ReadBoardFile(string path);
    vector<vector<State>> Search(vector<vector<State>>grid, int initial_point[2], int goal_point[2]);
    string CellString(State cell);
    void PrintBoard(const vector<vector<State>>board);
};

#endif /* AstarSearch_hpp */

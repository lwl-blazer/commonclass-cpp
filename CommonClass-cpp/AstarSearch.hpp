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

enum class State{kStart, kFinish, kEmpty, kObstacle, kClosed, kPath};

using std::vector;
using std::string;

class AStartSearch{
    
    //方向
    const int delta[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    
    vector<State> ParseLine(string line);
    string CellString(State cell);
    
    int Heuristic(int x1, int y1, int x2, int y2);
    void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &open_nodes, vector<vector<State>>&grid);
    //bool Compare(const vector<int> a, const vector<int>b);
    void CellSort(vector<vector<int>> *v);
    bool CheckValidCell(int x, int y, vector<vector<State>>&grid);
    void ExpandNeighbors(vector<int>&current_node, int *goal, vector<vector<int>>&openList, vector<vector<State>>&grid);
    
public:
    AStartSearch();
    ~AStartSearch();
    
    vector<vector<State>> ReadBoardFile(string path);
    vector<vector<State>> Search(vector<vector<State>>grid, int initial_point[2], int goal_point[2]);
    void PrintBoard(const vector<vector<State>>board);
};

#endif /* AstarSearch_hpp */

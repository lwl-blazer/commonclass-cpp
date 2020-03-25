//
//  AstarSearch.cpp
//  CommonClass-cpp
//
//  Created by blazer on 2020/3/14.
//  Copyright © 2020 luowailin. All rights reserved.
//

#include "AstarSearch.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

#include <algorithm>

using std::sort;
using std::abs;
using std::ifstream;
using std::istringstream;

AStartSearch::AStartSearch(){
    
}

AStartSearch::~AStartSearch(){
    
}

vector<State> AStartSearch::ParseLine(string line){
    istringstream sline(line);
    int n;
    char c;
    vector<State> row;
    while (sline >> n >> c && c == ',') {
        if (n == 0) {
            row.push_back(State::kEmpty);
        } else {
            row.push_back(State::kObstacle);
        }
    }
    return row;
}

vector<vector<State>> AStartSearch::ReadBoardFile(string path){
    ifstream myfile(path);
    vector<vector<State>> board{};
    if (myfile) {
        string line;
        while (std::getline(myfile, line)) {
            vector<State> row = ParseLine(line);
            board.push_back(row);
        }
    }
    std::cout<< "board.size() or i:"<<board.size()<<", board[0].size() or j:"<<board[0].size() << "\n";
    return board;
}

vector<vector<State>> AStartSearch::Search(vector<vector<State> > grid, int *initial_point, int *goal_point){
   
    vector<vector<int>> open{};
    int x = initial_point[0];
    int y = initial_point[1];
    int g = 0;
    int h = Heuristic(x, y, goal_point[0],goal_point[1]);
    
    AddToOpen(x, y, g, h, open, grid);

    while (open.size() > 0) {
        CellSort(&open);
        vector<int> curminfnode = open.back();
        open.pop_back();
        int curx = curminfnode[0];
        int cury = curminfnode[1];
        grid[curx][cury] = State::kPath;
        
        if (curx == goal_point[0] && cury == goal_point[1]) {
            return grid;
        }
    }
    std::cout << "No Path found!" << "\n";
    return vector<vector<State>>{};
}

string AStartSearch::CellString(State cell){
    switch (cell) {
        case State::kObstacle:
            return "⛰️  ";
            
        default:
            return "0  ";
    }
}

void AStartSearch::PrintBoard(const vector<vector<State> > board){
    for (vector<State> row: board){
        for (State s:row){
            std::cout << CellString(s);
        }
        printf("\n");
    }
}

//manhattan distance 曼哈顿距离
int AStartSearch::Heuristic(int x1, int y1, int x2, int y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

/**此函数做两件事情:
 *1.创建一个node,添加到openlist中
 *2.把x,y坐标设置为kClose(代表此节点已经访问过))*/
void AStartSearch::AddToOpen(int x, int y, int g, int h, vector<vector<int> > &open_nodes, vector<vector<State> > &grid){
    vector<int> node {x, y, g, h};
    open_nodes.push_back(node);
    grid[x][y] = State::kClosed;
}

//compare the f-value
/*bool AStartSearch::Compare(const vector<int> a, const vector<int> b){
    //f=g+h
    int f1 = a[2] + a[3];
    int f2 = b[2] + b[3];
    return f1 > f2;
}*/


void AStartSearch::CellSort(vector<vector<int> > *v){
    
    struct { //compare the f-value
        bool operator()(vector<int>a, vector<int>b){
            int f1 = a[2] + a[3];
            int f2 = b[2] + b[3];
            return f1 > f2;
        }
    }Compare;
    sort(v->begin(), v->end(), Compare);
}


/*检查当前node不是障碍State::kObstacle**/
bool AStartSearch::CheckValidCell(int x, int y, vector<vector<State> > &grid){
    if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) { //判断x,y在grid内 不懂是grid[0].size()
        if (State::kEmpty == grid[x][y]) { //不是障碍物
            return true;
        }
    }
    return false;
}

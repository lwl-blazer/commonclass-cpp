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
    return board;
}

vector<vector<State>> AStartSearch::Search(vector<vector<State> > grid, int *initial_point, int *goal_point){
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

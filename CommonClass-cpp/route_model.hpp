//
//  route_model.hpp
//  CommonClass-cpp
//
//  Created by blazer on 2020/4/14.
//  Copyright © 2020 luowailin. All rights reserved.
//

#ifndef route_model_hpp
#define route_model_hpp

#include <stdio.h>
#include <limits>
#include <cmath>
#include <unordered_map>
#include <iostream>
#include "model.hpp"

class Route_Model : public Model{
public:
    class Node : public Model::Node{
    public:
        Node *parent = nullptr;
        float h_value = std::numeric_limits<float>::max();
        float g_value = 0.0;
        
    };
};




#endif /* route_model_hpp */

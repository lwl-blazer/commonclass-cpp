//
//  model.cpp
//  CommonClass-cpp
//
//  Created by blazer on 2020/4/14.
//  Copyright © 2020 luowailin. All rights reserved.
//

#include "model.hpp"

static Model::Road::Type String2RoadType(std::string_view type){
    if (type == "motorway") {
        return Model::Road::Motorway;
    }
    
    if (type == "trunk") {
        return Model::Road::Trunk;
    }
    
    if (type == "primary") {
        return Model::Road::Primary;
    }
    
    if (type == "secondary") {
        return Model::Road::Secondary;
    }
    
    if (type == "tertiary") {
        return Model::Road::Tertiary;
    }
    
    if (type == "residental") {
        return Model::Road::Residental;
    }
    
    if (type == "living_street") {
        return Model::Road::Residental;
    }
    
    if (type == "service") {
        return Model::Road::Service;
    }
    
    if (type == "unclassified") {
        return Model::Road::Unclassified;
    }
    
    if (type == "footway") {
        return Model::Road::FootWay;
    }
    
    if (type == "bridleway") {
        return Model::Road::FootWay;
    }
    
    if (type == "steps") {
        return Model::Road::FootWay;
    }
    
    if (type == "path") {
        return Model::Road::FootWay;
    }
    
    if (type == "pedestrian") {
        return Model::Road::FootWay;
    }
    
    return Model::Road::Invaild;
}


static Model::Landuse::Type String2LanduseType(std::string_view type){
    if (type == "commerical") {
        return Model::Landuse::Commerical;
    }
    
    if (type == "construction") {
        return Model::Landuse::Construction;
    }
    
    if (type == "grass") {
        return Model::Landuse::Grass;
    }
    
    if (type == "forest") {
        return Model::Landuse::Forest;
    }
    
    if (type == "industrial") {
        return Model::Landuse::Industrial;
    }
    
    if (type == "railway") {
        return Model::Landuse::Railway;
    }
    
    if (type == "residential") {
        return Model::Landuse::Residential;
    }
    
    return Model::Landuse::Invalid;
}


Model::Model(const std::vector<std::byte> &xml){
    LoadData(xml);
    AdjustCoordinates();
    
    std::sort(m_Roads.begin(), m_Roads.end(), [](const auto &_1st, const auto &2_nd){
        return (int)_1st.type < (int)2_nd.type;
    });
}

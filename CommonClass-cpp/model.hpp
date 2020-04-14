//
//  model.hpp
//  CommonClass-cpp
//
//  Created by blazer on 2020/4/14.
//  Copyright © 2020 luowailin. All rights reserved.
//

#ifndef model_hpp
#define model_hpp

#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <string>
#include <cstddef>

class Model{
    
public:
    struct Node{
        double x = 0.0f;
        double y = 0.0f;
    };
    
    struct Way{
        std::vector<int>nodes;
    };
    
    struct Road{
        enum Type{Invaild, Unclassified, Service, Residental, Tertiary, Secondary, Primary, Trunk, Motorway, FootWay};
        
        int way;
        Type type;
    };
    
    struct Railway{
        int way;
    };
    
    struct Multipolygon{
        std::vector<int>outer;
        std::vector<int>inner;
    };
    
    struct Building : Multipolygon{};
    
    struct Leisure : Multipolygon{};
    
    struct Water : Multipolygon{};
    
    struct Landuse : Multipolygon {
        enum Type{Invalid, Commerical, Construction, Grass, Forest, Industrial, Railway, Residential};
        Type type;
    };
    
    Model(const std::vector<std::byte>&xml);
    
    auto MetricScale() const noexcept {
        return m_MetricScale;
    }
    
    auto &Nodes() const noexcept {
        return m_Nodes;
    }
    
    auto &Ways() const noexcept {
        return m_Ways;
    }
    
    auto &Roads() const noexcept {
        return m_Roads;
    }
    
    auto &Buildings() const noexcept {
        return m_Buildings;
    }
    
    auto &Leisures() const noexcept {
        return m_Leisures;
    }
    
    auto &Waters() const noexcept {
        return m_Waters;
    }
    
    auto &Landuses() const noexcept {
        return m_Landuses;
    }
    
    auto &RailWays() const noexcept {
        return m_Railways;
    }
    
private:
    double m_MetricScale = 1.0f;
    double m_MinLat = 0.0f;
    double m_MaxLat = 0.0f;
    double m_MinLon = 0.0f;
    double m_MaxLon = 0.0f;
    
    
    std::vector<Node> m_Nodes;
    std::vector<Way> m_Ways;
    std::vector<Road> m_Roads;
    std::vector<Railway> m_Railways;
    std::vector<Building> m_Buildings;
    std::vector<Leisure> m_Leisures;
    std::vector<Water> m_Waters;
    std::vector<Landuse> m_Landuses;
    
    void AdjustCoordinates();
    void BuildRings(Multipolygon &mp);
    void LoadData(const std::vector<std::byte> &xml);
};


#endif /* model_hpp */

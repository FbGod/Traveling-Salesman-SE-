#pragma once
#include <vector>

//City struct
struct City {
    int id;
    double x, y;
};

//distance func
double distance(const City& c1, const City& c2);

//vector of nearest neighbors
std::vector<City> nearestNeighbor(std::vector<City>& cities, int startCity);
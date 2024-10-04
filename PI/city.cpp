#include "city.h"
#include <vector>
#include <cmath>

double distance(const City& c1, const City& c2) {
    return sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));
}

std::vector<City> nearestNeighbor(std::vector<City>& cities, int startCity) {
    std::vector<City> tour;
    tour.push_back(cities[startCity]);
    std::vector<bool> visited(cities.size(), false);
    visited[startCity] = true;

    int currentCity = startCity;
    while (tour.size() < cities.size()) {
        int nextCity = -1;
        double minDistance = INFINITY;
        for (int i = 0; i < cities.size(); i++) {
            if (!visited[i]) {
                double dist = distance(cities[currentCity], cities[i]);
                if (dist < minDistance) {
                    minDistance = dist;
                    nextCity = i;
                }
            }
        }
        tour.push_back(cities[nextCity]);
        visited[nextCity] = true;
        currentCity = nextCity;
    }

    // Return to the starting city
    tour.push_back(cities[startCity]);
    return tour;
}

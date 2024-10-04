#include "city.h"
#include <iostream>
#include <vector>

int main() {
    int numCities;
    std::cout << "Enter the number of cities: ";
    std::cin >> numCities;

    std::vector<City> cities(numCities);
    for (int i = 0; i < numCities; i++) {
        std::cout << "Enter city " << i + 1 << " coordinates (x, y): ";
        std::cin >> cities[i].x >> cities[i].y;
        cities[i].id = i;
    }

    int startCity;
    std::cout << "Enter the starting city (0-" << numCities - 1 << "): ";
    std::cin >> startCity;

    std::vector<City> tour = nearestNeighbor(cities, startCity);

    std::cout << "Optimal tour: ";
    for (const City& city : tour) {
        std::cout << city.id << " ";
    }
    std::cout << std::endl;

    return 0;
}
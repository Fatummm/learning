#include <iostream>
#include <stdexcept>
#include <vector>
#include <memory>

#include "animals.h"

using Zoo = std::vector<std::shared_ptr<Animal>>;

Zoo CreateZoo() {
    Zoo zoo;
    std::string word;
    while (std::cin >> word) {
        if (word == "Tiger") {
            auto t = std::make_shared<Tiger>();
            zoo.push_back(t);
        }
        else if (word == "Wolf") {
            auto w = std::make_shared<Wolf>();
            zoo.push_back(w);
        }
        else if (word == "Fox") {
            auto f = std::make_shared<Fox>();
            zoo.push_back(f);
        }
        else
            throw std::runtime_error("Unknown animal!");
    }
    return zoo;
}

void Process(const Zoo& zoo) {
    for (const auto& animal : zoo) {
        std::cout << animal->Voice() << "\n";
    }
}
int main() {
    auto zoo = CreateZoo();
    Process(zoo);
}
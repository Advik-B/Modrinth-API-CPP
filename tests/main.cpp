#include <iostream>
#include <ModrinthAPI.hpp>
#include <ModrinthProject.hpp>
#include <nlohmann/json.hpp>

using nlohmann::json;

int main() {
    std::cout << modrinth::version << std::endl;
    json j;
    j["id"] = "test";
    auto project = modrinth::Project::from_json(j);
    return 0;
}

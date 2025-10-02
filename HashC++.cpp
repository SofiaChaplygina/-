#include <unordered_map>
#include <string>

std::unordered_map<std::string, int> ages = {{"Alice", 25}, {"Bob", 30}};
ages["Charlie"] = 28;
std::cout << ages["Alice"];
ages.erase("Bob");

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.erase(list.begin() + 1);
    cout << list[0] << endl;
    return 0;
}

#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<string> st;
    st.push("Hello");
    st.push("World");
    st.push("!");
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    return 0;
}

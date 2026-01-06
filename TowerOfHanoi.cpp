#include <iostream>
#include <stack>
#include <cstdlib>
using namespace std;

struct Frame {
    int n;
    char s, d, i;
    int stage;
};

void TOH_iterative(int n, char s, char d, char i) {
    stack<Frame> st;
    st.push({n, s, d, i, 0});

    while (!st.empty()) {
        Frame &top = st.top();

        if (top.n == 1) {
            cout << "Move one disk from tower " << top.s << " to tower " << top.d << endl;
            st.pop();
        } else if (top.stage == 0) {
            top.stage = 1;
            st.push({top.n - 1, top.s, top.i, top.d, 0});
        } else if (top.stage == 1) {
            cout << "Move one disk from tower " << top.s << " to tower " << top.d << endl;
            top.stage = 2;
            st.push({top.n - 1, top.i, top.d, top.s, 0});
        } else {
            st.pop();
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        cout << "Enter number of disks.\n";
        return 1;
    }

    int n = atoi(argv[1]);
    TOH_iterative(n, 'S', 'D', 'I');
    return 0;
}
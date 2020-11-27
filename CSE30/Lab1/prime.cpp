#include <iostream>

using namespace std;

int main() {

    int n;
    int b = 0;

    cin >> n;

    for (int i = 2; i < n; i++) {
        if (i != 2 && i != 1) {
            for (int j = 2; j < i; j++) {
                if (i % j == 0) {
                    b++;
                }
            }
        }
        if (b == 0)
            cout << i << endl;
            b = 0;       
    }
    return 0;
}
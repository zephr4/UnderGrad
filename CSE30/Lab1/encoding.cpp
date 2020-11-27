#include <iostream>

using namespace std;

int main() {

    char a;
    int b;

    while (b != -2) {
        cin >> a;
        cin >> b;

        if (b == -1) {
            cout << endl;
        }
        else {
            for (int i = b; i > 0; i--) {
                cout << a;
            }
        }
    }
    cout << endl;
    return 0;
}
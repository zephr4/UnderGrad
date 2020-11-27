#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() { 
    vector <string> a;
    string str;

    while(str.compare("quit") != 0) {
        cin >> str;

        if (str.length() != 1) {
            a.push_back(str);
        }
        else if (str.length() == 1) {
            for (int i = 0; i < a.size(); i++) {
                string c = a[i];
                if (str[0] == c[0]) {
                    cout << a[i];
                }
            }
        }
    }
    return 0;
}
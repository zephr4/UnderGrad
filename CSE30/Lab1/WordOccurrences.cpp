#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    
    ifstream in;
    in.open("words.txt");
    int count = 0;
    string a;
    string b;

    cin >> a;

    while (in >> b) {
        int c = 1;
        for (int i = 0; i <a.length(); i++) {
            if(!(tolower(b[i]) == tolower(a[i]))) {
                c = 0;
                break;
            }
        }
        if (c == 1) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
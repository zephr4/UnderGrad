#include <iostream>
#include <string>

using namespace std;

string sentence;
int num;

int main() {
    getline(cin, sentence);
    cin >> num;
    for (int i = 1; i <= num; i++) {
        cout <<sentence << endl;
    }
    return 0; 
}
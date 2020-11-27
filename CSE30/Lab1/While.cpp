#include <iostream>

using namespace std;

int main() {
    int integer;
    while (integer != -1) {
        cin >> integer;
    if (integer % 2 == 0) {
        cout <<"EVEN" << endl;
     } 
    else if (integer == -1) {
         break;
     }
    else{
        cout <<"ODD" << endl;
     }
    }
    return 0;

}
#include <iostream>
#include <vector>

int main() {

    // User inputs size of the list, which is denoted by n
    int n;
    std::cin >> n;

    // Initialization of variables
    int i = 0;
    int input;
    std::vector<int> list;

    // User inputs each element of the list up to size n
    for(i = 0; i < n; i++) {

        std::cin >> input; 
        list.push_back(input);
    }

    // Max/Min algorithm is implemented
    int max = list[0];
    int min = list[0];
    for(i = 0; i < n; i++) {

        if (list[i] < min)
            min = list[i];
        else if (list[i] > max)
            max = list[i];
    }
    
    // Output
    std::cout << max << ";" << min;
    return 0;
    
}
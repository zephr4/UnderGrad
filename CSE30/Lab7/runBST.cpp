#include <iostream>
#include "BST.h"
#include "RandomSupport.h"
#include "BSTUtil.h"

int main() {

    int N;
    std::cin >> N;

    randomizer device = new_randomizer();
    uniform_distribution range = new_distribution(1,N);

    Node* BST = NULL;

    for(long i = 0; i < N; i++) {
        long num = sample(range, device);
        BST = insert(BST, num);  
    }
    BST = insertSpecialNumber(BST);
    findSpecialNumber(BST);
}
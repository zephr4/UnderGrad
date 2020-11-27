#include <iostream>

int x, y;
int *px, *py;

int f() {
    int s = *px + *py;
    std::cout << s << std::endl;
    return s;
}

int main() {
    x = 4;
    y = 3;
    px = &x;
    py = &y;
    x = y = f();
    std::cout << f() << std::endl;
}
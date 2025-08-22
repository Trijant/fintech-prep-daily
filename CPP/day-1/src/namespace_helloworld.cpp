#include <iostream>

namespace greet{
    void hello(){
        std::cout << "Hello World from namespace!";
    }
}

int main(){
    greet::hello();
}
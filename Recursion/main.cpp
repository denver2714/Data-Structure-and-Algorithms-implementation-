#include <iostream>

int factorial(int n) {
    if (n == 0) {  // Base case: factorial of 0 is 1
        return 1;
    }
    return n * factorial(n - 1);  // Recursive case: n * (n-1)!
}



int main(){
    
    factorial(5);
    return 0;
}
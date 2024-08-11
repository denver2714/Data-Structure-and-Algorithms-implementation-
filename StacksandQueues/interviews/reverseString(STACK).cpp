#include <iostream>
#include <string>
#include <stack>

// Reverse a string using stack

std::string reverseString(const std::string& str){
    std::stack<char> stk;
    for(int i = 0; i < str.length(); i++){
        stk.push(str[i]);
    }

    std::string reversedStr;
    while (!stk.empty()) {
        reversedStr += stk.top(); // Append the top character to the reversed string
        stk.pop(); // Remove the top character from the stack
    }

    return reversedStr; // Return the reversed string

}

void printString(const std::string& str) { // Pass by reference for efficiency
    std::cout << str << std::endl; // Print the string
}

int main() {
    std::string str = "hello"; // Correct way to initialize a string
    std::cout << "Original: " << str << "\n";
    std::string reversedStr = reverseString(str); // Call the reverse function
    std::cout << "Reversed: ";
    std::cout << reversedStr << "\n"; // Print the reversed string using the printStack function
    return 0;
}

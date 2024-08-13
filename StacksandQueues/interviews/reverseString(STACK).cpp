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

    return reversedStr;

}


int main() {
    std::string str = "hello";
    std::cout << "Original: " << str << "\n";
    std::string reversedStr = reverseString(str);
    std::cout << "Reversed: ";
    std::cout << reversedStr << "\n"; 
    return 0;
}

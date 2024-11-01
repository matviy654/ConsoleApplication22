#include <iostream>
#include <stack>
#include <string>

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
        (open == '{' && close == '}') ||
        (open == '[' && close == ']');
}

void checkBrackets(const std::string& str) {
    std::stack<char> bracketStack;

    for (size_t i = 0; i < str.length(); ++i) {
        char ch = str[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            bracketStack.push(ch);
        }
      
        else if (ch == ')' || ch == '}' || ch == ']') {
     
            if (!bracketStack.empty() && isMatchingPair(bracketStack.top(), ch)) {
                bracketStack.pop();
            }
            else {
             
                std::cout << "Помилка у рядку: " << str.substr(0, i + 1) << std::endl;
                return;
            }
        }
     
        else if (ch == ';') {
            break;
        }
    }

    if (bracketStack.empty()) {
        std::cout << "Рядок коректний." << std::endl;
    }
    else {
        std::cout << "Помилка: не всі дужки закриті." << std::endl;
    }
}

int main() {
    std::string input;
    std::cout << "Введіть рядок: ";
    std::getline(std::cin, input);

    checkBrackets(input);
    return 0;
}

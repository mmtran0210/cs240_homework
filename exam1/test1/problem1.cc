// Minh My Tran - CSCE 240 003 - Exam 1 

#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char c;
    int alphabets = 0, digits = 0;
    while (cin.get(c) && c != '.' && c != '?' && c != '!') {
        if (isalpha(c)) {
            alphabets++;
        } else if (isdigit(c)) {
            digits++;
        }
    }
    cout << "Input sentence contains " << alphabets << " alphabetic " << (alphabets == 1 ? "character" : "characters")
         << " and " << digits << " digit" << (digits == 1 ? "" : "s") << "." << endl;
    return 0;
}
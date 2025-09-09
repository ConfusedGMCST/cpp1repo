/*
    Christian Haase
    Calculator
    9/9/25
    remade that readline function from scratch because I was bored and finding a useable gui library is hard
*/

#include <iostream>
using namespace std;

string readLine(string input) {
    string output;
    cout<<input;
    cin>>output;
    return output;
}

int main() {
    string number1 = readLine("enter number 1: ");
    string number2 = readLine("enter number 2: ");
    double sum = stod(number1) + stod(number2);
    double dif = stod(number1) - stod(number2);
    double quot = stod(number1) / stod(number2);
    double prod = stod(number1) * stod(number2);
    int mod = stoi(number1) % stoi(number2);
    double pInc = sum++;
    double nInc = sum--;
    double values[] = {sum, dif, quot, prod, mod, pInc, nInc};
    string operators[] = {"sum", "difference", "quotient", "product", "modulo'd version of", "sum plus one", "sum minus one"};
    
    for (int i = 0; i < size(values); i++) {
        cout << "The " << operators[i] << " of " << number1 << " and " << number2 << " is " << values[i] << "\n";
    }
}
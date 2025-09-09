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
    string strSum = to_string(sum);
    cout << "The sum of these numbers is "<< strSum;
}
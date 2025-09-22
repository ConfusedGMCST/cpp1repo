/*
    Christian Haase
    random timmyWimmy program
    9/15/25
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(nullptr))); //sets the seed for the rand int
    int timmyWimmy = (rand()%6) + 1; //random number with range of 6<-->1
    cout<<timmyWimmy<<endl;
    if (timmyWimmy == 5) {
        cout<<"hot dogs"<<endl;
    } else if (timmyWimmy == 6) {
        cout<<"corn dogs"<<endl;
    } else {
        cout<<"chili dogs"<<endl;
    }
}
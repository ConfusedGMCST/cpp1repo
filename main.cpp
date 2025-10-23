//Christian Haase
//loop program buffet
//my extra is a unity game

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
//#include "cftn.hpp"
//cftn.hpp was a header file for a utility library in the works 
//(so I don't keep pasting readLine at the beginning of my programs)

std::string readLine(std::string input) {
    std::string uInput;
    std::cout << input << std::endl;
    std::getline(std::cin, uInput);
    while (uInput.empty()) {
        std::getline(std::cin, uInput);
    }

    return uInput;
}

//found this code here: https://cplusplus.com/forum/beginner/243351/ from user Gando
bool iequals(const std::string& a, const std::string& b)
{
    return std::equal(a.begin(), a.end(),
                      b.begin(), b.end(),
                      [](char a, char b) {
                          return tolower(a) == tolower(b);
                      });
}

std::string qotd() {
    std::vector<std::string> quoteArray(7);
    std::string dayArray[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    for (int i = 0; i < 7; i++) {
        quoteArray[i] = readLine("Current day: " + dayArray[i] + ", please enter the quote for this day!");
    }
    std::string day = readLine("What is the current day of the week?: ");
    bool foundMatch = false;
    int quoteIndex = 0;
    while (!foundMatch) {
        std::string day = readLine("What is the current day of the week?: ");
        for (int i = 0; i < 7; i++) {
            if (iequals(day, dayArray[i])) {
                foundMatch = true;
                quoteIndex = i;
                std::cout<<quoteArray[i]<<std::endl;
            }
        }
    }
    return quoteArray[quoteIndex];
}

void zombieMinigame() {
    int energy = 5;
    int supply = 0;

    while (supply < 10 and energy > 0) {
        std::string choice = readLine("Do you gather supplies (GATHER) or rest (REST)?");
        if (iequals(choice, "gather")) {
            supply++;
            energy--;
            std::cout<<"ENERGY ("<<energy<<") - 1,\n"<<"SUPPLY ("<<supply<<") + 1!"<<std::endl;
        }
        if (iequals(choice, "rest")) {
            energy+=2;
            std::cout<<"ENERGY ("<<energy<<") + 2!"<<std::endl;
        }
        if (!(iequals(choice, "rest")) && !(iequals(choice, "gather"))) {
            supply--;
            energy--;
            std::cout<<"Your inaction has cost you DEARLY! You've lost ENERGY ("<<energy<<"),\n and SUPPLY ("<<supply<<")."<<std::endl;
        }
    }
    if (energy < 1) {
        std::cout<<"You've perished in the depths of... wherever you were."<<std::endl;
    } else {
        std::cout<<"You've lived to escape... wherever that was!"<<std::endl;
    }
}

int secretCode() {
    srand(static_cast<unsigned int>(time(nullptr)));
    int randomNum = (rand()% (999 - 100 + 1)) + 100;
    int enteredNumber = 0;
    bool winner = false;
    std::string contChoice = "";
    do
    {
        enteredNumber = stoi(readLine("Please enter a 3 number code!"));
        if (enteredNumber != randomNum) {
            contChoice = readLine("Would you like to continue?");
            if (iequals(contChoice, "n")) {
                break;
            }
        } else {
            winner = true;
        }
    } while (enteredNumber != randomNum);
    if (!winner) {
        std::cout<<"Sorry, but the code was: "<<randomNum<<"... better luck next time!"<<std::endl;
        return 0;
    } else {
        std::cout<<"Impressive guess!"<<std::endl;
        return randomNum;
    }
}

int main() {
    std::string quoteFunc = qotd();
    zombieMinigame();
    int code = secretCode();
    return 0;
}
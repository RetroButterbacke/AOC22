#include <fstream>
#include <string.h>
#include <iostream>
#include <map>

std::fstream input ("rucksackList.txt");
std::string rucksack;
std::string second_rucksack;
std::string third_rucksack;
std::map<char, int> value;
int resultPriorities = 0;
int resultBadgePriorities = 0;

void countOutItemPriorities() {
    while (getline(input, rucksack))
    {
        std::string first_compartment = rucksack.substr(0, rucksack.length()/2);
        std::string second_compartment = rucksack.substr(rucksack.length()/2);

        int shouldBreak = 0;
        for(char i : first_compartment) {
            for (char j : second_compartment) {
                if (i == j) {
                    resultPriorities += value[i];
                    shouldBreak = 1;
                    break;
                }
            }
            if (shouldBreak == 1) {
                break;
            }
        }
    }     
}

void countTeamProrities() {
    input.clear();
    input.seekg(0);
    while (!input.eof()) {
        int shouldBreak = 0;
        getline(input, rucksack);
        getline(input, second_rucksack);
        getline(input, third_rucksack);
        for (char first : rucksack) {
            for (char second : second_rucksack) {
                if (first == second) {
                    for (char last : third_rucksack) {
                        if (second == last) {
                            shouldBreak = 1; 
                            resultBadgePriorities += value[last];
                            break;
                        }
                    }
                }
                if (shouldBreak == 1) break;
            }
            if (shouldBreak == 1) break;
        }   
    }   
}

void initValues() {
    value['a'] = 1;
    value['b'] = 2;
    value['c'] = 3;
    value['d'] = 4;
    value['e'] = 5;
    value['f'] = 6;
    value['g'] = 7;
    value['h'] = 8;
    value['i'] = 9;
    value['j'] = 10;
    value['k'] = 11;
    value['l'] = 12;
    value['m'] = 13;
    value['n'] = 14;
    value['o'] = 15;
    value['p'] = 16;
    value['q'] = 17;
    value['r'] = 18;
    value['s'] = 19;
    value['t'] = 20;
    value['u'] = 21;
    value['v'] = 22;
    value['w'] = 23;
    value['x'] = 24;
    value['y'] = 25;
    value['z'] = 26;
    value['A'] = 27;
    value['B'] = 28;
    value['C'] = 29;
    value['D'] = 30;
    value['E'] = 31;
    value['F'] = 32;
    value['G'] = 33;
    value['H'] = 34;
    value['I'] = 35;
    value['J'] = 36;
    value['K'] = 37;
    value['L'] = 38;
    value['M'] = 39;
    value['N'] = 40;
    value['O'] = 41;
    value['P'] = 42;
    value['Q'] = 43;
    value['R'] = 44;
    value['S'] = 45;
    value['T'] = 46;
    value['U'] = 47;
    value['V'] = 48;
    value['W'] = 49;
    value['X'] = 50;
    value['Y'] = 51;
    value['Z'] = 52;
}

int main() {
    initValues();
    countOutItemPriorities();
    countTeamProrities();
    std::cout << resultPriorities << std::endl;
    std::cout << resultBadgePriorities << std::endl;
}
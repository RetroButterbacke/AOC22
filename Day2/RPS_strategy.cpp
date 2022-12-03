#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <map>

std::fstream rpsInput ("RockPaperSisorRounds.txt");
std::string rpsText;
int result;

int calculateItem(int, int);

void count(int a, int b) {
    while (getline(rpsInput, rpsText))
    {
        if (rpsText.find("A") != -1) {
            a = 1;
        } else if (rpsText.find("B") != -1) {
            a = 2;
        } else if (rpsText.find("C") != -1) {
            a = 3;
        }
        if (rpsText.find("X") != -1) {
            b = 1;
        } else if (rpsText.find("Y") != -1) {
            b = 2;
        } else if (rpsText.find("Z") != -1) {
            b = 3;
        }
        b = calculateItem(a, b);
        switch (a)
        {
        case 1:
            switch (b)
            {
            case 1:
                result += 3 + b;
                break;
            case 2:
                result += 6 + b;
                break;
            case 3:
                result += b;    
            }
            break;
        case 2:
            switch (b)
            {
            case 1:
                result += b;
                break;
            case 2:
                result += 3 + b;    
                break;
            case 3:
                result += 6 + b;
                break;       
            }
            break;
        case 3:
            switch (b)
            {
            case 1:
                result += 6 + b;
                break;
            case 2:
                result += b;   
                break;
            case 3: 
                result += 3 + b;
                break;    
            }
            break;
        }
    }
}

int calculateItem(int a, int b) {
    switch (a)
    {
    case 1:
        switch (b)
        {
        case 1:
            return 3;
            break;
        case 2:
            return 1;
            break;
        case 3:
            return 2;
            break; 
        }       
    break;        
    case 2:
        switch (b)
        {
        case 1:
            return 1;
            break;
        case 2:
            return 2;
            break;
        case 3:
            return 3;
            break; 
        }       
    break;
    case 3:
        switch (b)
        {
        case 1:
            return 2;
            break;
        case 2:
            return 3;
            break;
        case 3:
            return 1;
            break;
        }        
    break;
    }
    return 0;
}

int main() {
    int a = 0, b = 0;
    count(a, b);
    std::cout << result << std::endl;
}
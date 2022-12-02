#include <iostream>
#include <fstream>
#include <string>
#include <stack>

std::fstream calories ("elf_calories.txt");
std::stack<int> counted_calories;
std::stack<int> placeholder;
std::stack<int> top3;
std::string caloriesText;

void count() {
    int val = 0;
    while (getline(calories, caloriesText, '\n')) {
        if (caloriesText.empty()) {
            counted_calories.push(val);
            val = 0;
        } else {
            val += std::stoi(caloriesText);
        }
    }
}

void print() {
    int elf_number;
    int highest = 0;
    int second_highest = 0;
    int third_highest = 0;
    int fourth_highest = 0;
    for (int i = counted_calories.size(); i > 0; i--) {
        elf_number = i;
        if (counted_calories.top() > highest) {
            second_highest = highest;
            highest = counted_calories.top();
        } else if (counted_calories.top() < highest && counted_calories.top() > second_highest) {
            third_highest = second_highest;
            second_highest = counted_calories.top();
        } else if (counted_calories.top() < second_highest && counted_calories.top() > third_highest) {
            third_highest = counted_calories.top();
        }
        top3.push(third_highest);
        top3.push(second_highest);
        top3.push(highest);
        std::cout << "Elf " << elf_number << ": " << counted_calories.top() << std::endl;
        counted_calories.pop();
    }
    int together = 0;
    for(int i = 3; i > 0; i--) {
        if (i == 3) {
            std::cout << "The Elf who carries the most is calories has a value of " << top3.top() << " calories." << std::endl;
            together += top3.top();
            top3.pop();
        } else if (i == 2) {
            std::cout << "The Elf who carries the second most is calories has a value of " << top3.top() << " calories." << std::endl;
            together += top3.top();
            top3.pop();
        } else if (i == 1) {
            std::cout << "The Elf who carries the third most is calories has a value of " << top3.top() << " calories." << std::endl;
            together += top3.top();
        }
    }
    std::cout << "All three together carry: " << together << " calories." << std::endl;
}

int main() {
    top3.push(0);
    count();
    print();
    return 0;
}

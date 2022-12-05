#include "./elf.cpp"
#include <fstream>
#include <iostream>
#include <ncurses.h>
#include <string>

using namespace std;

class Main1 {
public:
  static int main() {
    printw("--- #1 ---");
    
    list<Elf *> elves;
    ifstream file;
    string content;

    try {
      file.open("../assets/1.txt");
    } catch (exception &exp) {
      printw("Failed to load file...");
    }

    // Read input file
    if (file.is_open()) {
      while (file) {
        int counter = 0;
        Elf *elf = new Elf();
        while (getline(file, content) && content != "") {
          ++counter;
          elf->collect(stoi(content));
        }
        elves.push_back(elf);
      }
    }

    // Finding the masterChief with most calories (O(n) solution)
    Elf *masterChief;
    Elf *masterChief2;
    Elf *masterChief3;
    list<Elf *>::iterator elf;
    int biggestCalories = 0;
    for (elf = elves.begin(); elf != elves.end(); ++elf) {
      int calories = (*elf)->getTotalCalories();
      if (biggestCalories < calories) {
        biggestCalories = calories;
        masterChief = *elf;
      }
    }

    biggestCalories = 0;
    for (elf = elves.begin(); elf != elves.end(); ++elf) {
      int calories = (*elf)->getTotalCalories();
      if (biggestCalories < calories &&
          calories < masterChief->getTotalCalories()) {
        biggestCalories = calories;
        masterChief2 = *elf;
      }
    }

    biggestCalories = 0;
    for (elf = elves.begin(); elf != elves.end(); ++elf) {
      int calories = (*elf)->getTotalCalories();
      if (biggestCalories < calories &&
          calories < masterChief2->getTotalCalories()) {
        biggestCalories = calories;
        masterChief3 = *elf;
      }
    }

    // Printing the elf
    char ch;
    do {
      masterChief->draw(1);
      masterChief2->draw(2);
      masterChief3->draw(3);
      int sum = masterChief->getTotalCalories() +
                masterChief2->getTotalCalories() +
                masterChief3->getTotalCalories();
      printw("Sum: ");
      printw(to_string(sum).c_str());
    } while ((ch = getch()) != 'q');
    return 0;
  }
};

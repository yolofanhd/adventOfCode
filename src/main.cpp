#include "./elf.cpp"
#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  initscr();
  cbreak();
  refresh();
  list<Elf *> elves;
  printw("Type p or ctrl+c to quit!");


  ifstream file;
  file.open("../assets/assets.txt");
  string content;

  if (file.is_open()) {
    while (file) {
      int counter = 0;
      Elf* elf = new Elf();
      while (getline(file, content) && content != "") {
        ++counter;
        printw(content.c_str());
        elf->collect(stoi(content));
        printw(" ");
      }
      elves.push_back(elf);
      printw("\nNEW ELF\n");
    }
  }

  //Finding the masterChief with most calories (O(n) solution)
  Elf *masterChief;
  list<Elf *>::iterator elf;
  int biggestCalories = 0;
  for (elf = elves.begin(); elf != elves.end(); ++elf) {
    int calories = (*elf)->getTotalCalories();
    if (biggestCalories < calories) {
      biggestCalories = calories;
      masterChief = *elf;
    }
  }

  //Printing the elf
  char ch;
  do{

    masterChief->draw(1);
  } while ((ch = getch()) != 'q');

  endwin();
  return 0;
}

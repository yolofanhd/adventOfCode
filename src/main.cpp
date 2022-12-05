#include "./1/main.cpp"
#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  initscr();
  cbreak();
  refresh();
  printw("Type p or ctrl+c to quit!");
  Main1().startFirst();
  endwin();
  return 0;
}

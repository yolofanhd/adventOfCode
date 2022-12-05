#include "./1/main.cpp"
#include "./2/main.cpp"
#include "./3/main.cpp"
#include "./4/main.cpp"
#include "./5/main.cpp"
#include "./6/main.cpp"
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
  //Main1().main();
  //Main2().main();
  Main3().main();
  Main4().main();
  Main5().main();
  Main6().main();
  endwin();
  return 0;
}

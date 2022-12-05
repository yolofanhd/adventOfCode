#include <list>
#include <ncurses.h>
#include <stdlib.h>
#include <string>
#include <tuple>

using namespace std;

class Elf {
public:
  int getTotalCalories() {
    int sum = 0;
    list<int>::iterator i;
    for(i=inventory.begin(); i!=inventory.end(); ++i) {
      sum += *i;
    }
    return sum;
  }

  void collect(int calories) {
    inventory.push_back(calories);
  }

  void draw(int n) {
    WINDOW *win = this->window;

    //delete old window and remove remaining chars from console
    for (int i = 0; i < 25; ++i) {
      for (int j = 0; j < 10; ++j) {
        mvwprintw(win, i, j, " ");
      }
    }
    wrefresh(win);
    delwin(win);

    //print fresh window containing information and sum
    win = newwin(25, 10, 1, 10 * (n - 1) + 1);
    box(win, 0, 0);

    list<int>::iterator item;
    int i = 1;
    for(item=inventory.begin(); item!=inventory.end(); ++item) {
      i++;
      mvwprintw(win, i, 1, to_string(*item).c_str());
    }
    mvwprintw(win, i+1, 1, "-------");
    mvwprintw(win, i+2, 1, to_string(this->getTotalCalories()).c_str());
    wrefresh(win);
    this->window = win;
  }

private:
  WINDOW *window;
  list<int> inventory;
};



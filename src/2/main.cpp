#include <curses.h>
#include <fstream>
#include <iostream>
#include <ncurses.h>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

typedef vector<pair<char,char>> Moves;

class Main2 {
public:
  static int main() {
    printw("--- #2 ---");
    ifstream file;
    string content;
    Moves* moves = new Moves();

    try {
      file.open("../assets/2.txt");
    } catch (exception &exp) {
      printw("Failed to load file...");
    }

    // Read input file
    if (file.is_open()) {
      while (file) {
        while (getline(file, content) && content != "") {
          (*moves).push_back(pair<char, char>(content[0],content[2]));
        }
      }
    }
    int points = getPoints2(moves);
    printw(to_string(points).c_str());
    
    char ch;
    do {
      
    } while ((ch = getch()) != 'q');
    return 0;
  }
  
  static int getPoints1(Moves *moves) {
    int points = 0;
    Moves::iterator i;
    for(i = (*moves).begin(); i != (*moves).end(); ++i) {
      string s = "Move: ";
      s = s + (*i).first;
      s = s + " || My Move: ";
      s = s + (*i).second;

      char move = (*i).first;
      char myMove = (*i).second;
      if (myMove=='X') {
        points += 1;
      } else if (myMove=='Y') {
        points += 2;
      } else if (myMove=='Z') {
        points += 3;
      } else {
        printw("Invalid move!");
      }

      if (
        (move=='A' && myMove=='X') ||
        (move=='B' && myMove=='Y') ||
        (move=='C' && myMove=='Z')) {
        points += 3;
      } else if (
        (move=='A' && myMove=='Y') ||
        (move=='B' && myMove=='Z') ||
        (move=='C' && myMove=='X')) {
        points += 6;
      } else if (
        (move=='A' && myMove=='Z') ||
        (move=='B' && myMove=='X') ||
        (move=='C' && myMove=='Y')) {
        points += 0;
      }
    }
    return points;
  }

  static int getPoints2(Moves *moves) {
    int points = 0;
    Moves::iterator i;
    for(i = (*moves).begin(); i != (*moves).end(); ++i) {
      string s = "Move: ";
      s = s + (*i).first;
      s = s + " || My Move: ";
      s = s + (*i).second;

      char move = (*i).first;
      char myMove = (*i).second;
      if (myMove=='X') {
        points += 0;
      } else if (myMove=='Y') {
        points += 3;
      } else if (myMove=='Z') {
        points += 6;
      } else {
        printw("So you want to win or loose?");
      }

      if (
        (move=='A' && myMove=='X') ||
        (move=='B' && myMove=='Z') ||
        (move=='C' && myMove=='Y')) {
        points += 3;
      } else if (
        (move=='A' && myMove=='Z') ||
        (move=='B' && myMove=='Y') ||
        (move=='C' && myMove=='X')) {
        points += 2;
      } else if (
        (move=='A' && myMove=='Y') ||
        (move=='B' && myMove=='X') ||
        (move=='C' && myMove=='Z')) {
        points += 1;
      }
    }
    return points;
  }
};

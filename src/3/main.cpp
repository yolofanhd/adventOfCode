#include <fstream>
#include <iostream>
#include <list>
#include <ncurses.h>
#include <string>

using namespace std;
typedef pair<string, string> Rucksack;
typedef list<Rucksack> Rucksacks;
typedef Rucksacks Group;
typedef list<Group> Groups;

class Main3 {
public:
  static int main() {
    printw("--- #3 ---");
    ifstream file;
    string content;
    Rucksacks *rucksacks = new Rucksacks();

    try {
      file.open("../assets/3.txt");
    } catch (exception &exp) {
      printw("Failed to load file...");
    }

    // Read input file
    if (file.is_open()) {
      while (file) {
        while (getline(file, content) && content != "") {
          int contentHalfSize = content.length() / 2;
          string compartment1 = content.substr(0, contentHalfSize);
          string compartment2 = content.substr(contentHalfSize, content.size());
          Rucksack rucksack = Rucksack(compartment1, compartment2);
          (*rucksacks).push_back(rucksack);
        }
      }
    }

    Rucksacks::iterator rucksack;
    int sum = 0;
    for (rucksack = (*rucksacks).begin(); rucksack != (*rucksacks).end(); ++rucksack) {
      sum = sum + calculatePriority(findDuplicateInRucksack(*rucksack));
    }
    printw("\n");
    printw(to_string(sum).c_str());

    Groups* groups = new Groups();
    Group group;
    int counter = 0;
    for (rucksack = (*rucksacks).begin(); rucksack != (*rucksacks).end(); ++rucksack) {
      group.push_back(*rucksack);
      if(counter>=2) {
        groups->push_back(group);
        group.erase(group.begin(), group.end());
        counter=0;
      } else {
        ++counter;
      }
    }

    sum = 0;
    Groups::iterator groupIterator;
    for (groupIterator = (*groups).begin(); groupIterator != (*groups).end(); ++groupIterator) {
      sum += calculatePriority(findBatchOfGroup(*groupIterator));
    }
    printw("\n");
    printw(to_string(sum).c_str());


    char ch;
    do {

    } while ((ch = getch()) != 'q');
    return 0;
  }

  static char findBatchOfGroup(Group g) {
    if (g.size()<2) return ' ';
    Group::iterator i = g.begin();
    Rucksack rucksack1 = *i;
    advance(i, 1);
    Rucksack rucksack2 = *i;
    advance(i, 1);
    Rucksack rucksack3 = *i;

    string contents1 = rucksack1.first + rucksack1.second;
    string contents2 = rucksack2.first + rucksack2.second;
    string contents3 = rucksack3.first + rucksack3.second;

    for(int i=0; i<contents1.length(); ++i) {
      char c1 = contents1.at(i);
      for (int j=0; j<contents2.length(); ++j) {
        char c2 = contents2.at(j);
        if (c1 != c2) {
          continue;
        }
        for (int k=0; k<contents3.length(); ++k) {
          char c3 = contents3.at(k);
          if(c1 == c2 && c2 == c3) {
            return c3;
          }
        }
      }
    }
    return ' ';
  }

  static char findDuplicateInRucksack(Rucksack r) {
    string compartment1 = r.first;
    string compartment2 = r.second;

    char duplicateItem;
    for (int i = 0; i < compartment1.length(); ++i) {
      char itemInCompartment1 = compartment1.at(i);
      for (int j = 0; j < compartment2.length(); ++j) {
        if (itemInCompartment1 == compartment2.at(j)) {
          duplicateItem = itemInCompartment1;
        }
      }
    }
    return duplicateItem;
  }

  static int calculatePriority(char c) {
    switch (c) {
    case 'a':
      return 1;
    case 'b':
      return 2;
    case 'c':
      return 3;
    case 'd':
      return 4;
    case 'e':
      return 5;
    case 'f':
      return 6;
    case 'g':
      return 7;
    case 'h':
      return 8;
    case 'i':
      return 9;
    case 'j':
      return 10;
    case 'k':
      return 11;
    case 'l':
      return 12;
    case 'm':
      return 13;
    case 'n':
      return 14;
    case 'o':
      return 15;
    case 'p':
      return 16;
    case 'q':
      return 17;
    case 'r':
      return 18;
    case 's':
      return 19;
    case 't':
      return 20;
    case 'u':
      return 21;
    case 'v':
      return 22;
    case 'w':
      return 23;
    case 'x':
      return 24;
    case 'y':
      return 25;
    case 'z':
      return 26;
    case 'A':
      return 27;
    case 'B':
      return 28;
    case 'C':
      return 29;
    case 'D':
      return 30;
    case 'E':
      return 31;
    case 'F':
      return 32;
    case 'G':
      return 33;
    case 'H':
      return 34;
    case 'I':
      return 35;
    case 'J':
      return 36;
    case 'K':
      return 37;
    case 'L':
      return 38;
    case 'M':
      return 39;
    case 'N':
      return 40;
    case 'O':
      return 41;
    case 'P':
      return 42;
    case 'Q':
      return 43;
    case 'R':
      return 44;
    case 'S':
      return 45;
    case 'T':
      return 46;
    case 'U':
      return 47;
    case 'V':
      return 48;
    case 'W':
      return 49;
    case 'X':
      return 50;
    case 'Y':
      return 51;
    case 'Z':
      return 52;
    default:
      return 0;
    }
  }
};

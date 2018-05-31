#include "polish.h"

#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

Polish::Polish(char *xs) {
  char *i = xs;
  char *j = xs;

  while (*j != '\0') {
    while (*i == ' ') {
      j = ++i;
    }
    if (isNumber(*i))
      while (isNumber(*(j + 1))) {
        ++j;
      }

    int parsedSize = j - i + 1;
    char *parsed = new char[parsedSize + 1];
    strncpy(parsed, i, parsedSize);
    polish.push_back(parsed);
    i = ++j;
  }
}

Polish::~Polish() {
  while (polish.size() > 0) {
    delete[] polish.back();
    polish.pop_back();
  }
}


double Polish::solve() {
  vector<double> polNumbers;
  vector<char*> tmpPolish = polish;
  int sp = -1;
  while (++sp < tmpPolish.size()) {
    if ( !isNumber(tmpPolish[sp][0]) ) {
      double val1 = polNumbers.back();
      polNumbers.pop_back();
      double val2 = polNumbers.back();
      polNumbers.pop_back();
      switch ( tmpPolish[sp][0] ) {
        case '+': polNumbers.push_back(val2 + val1);
                  break;
        case '-': polNumbers.push_back(val2 - val1);
                  break;
        case 'x': case '*':
                  polNumbers.push_back(val2 * val1);
                  break;
        case '/': polNumbers.push_back(val2 / val1);
                  break;
        default: break;
      }
    } else {
      polNumbers.push_back(atof(tmpPolish[sp]));
    }
  } 
  return polNumbers.front();
}

bool Polish::isNumber(char c) {
  return c == '.' || (c <= '9') && (c >= '0');
}

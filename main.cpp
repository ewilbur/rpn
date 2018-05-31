#include "polish.h"
#include <iostream>
#include <string>

using namespace std;

char *concats(int, char*, char**);

int main(int argc, char **argv) {
  char ops[2048];
  concats(argc - 1, ops, argv + 1);
  Polish p(ops);
  cout << p.solve() << endl;
  return 0;
}


char *concats(int size, char *destination, char **source) {
  string s;
  for (int i = 0; i < size; ++i){
    s += source[i];
    s += " ";
  }
  strncpy(destination, s.c_str(), s.length() - 1);
  return destination;
}

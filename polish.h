#ifndef POLISH_H_
#define POLISH_H_

#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

class Polish {
  private:
    vector<char*> polish;
    bool isNumber(char);
  public:
     Polish(char*);
     double solve();
};

#endif // POLISH_H_

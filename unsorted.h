#ifndef UNSORTED_H
#define UNSORTED_H
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

class uns{
private:
    int *num;
    int Q;
    string * randomw ;
    string * unsArr ;
    unsigned long int totalpairs;

public:
    uns(string *pairs,unsigned long int totalpairs,int num[],int Q , string *randomwords);
    ~uns();
    void searchUnsorted();
};
#endif // UNSORTED_H

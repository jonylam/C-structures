#ifndef SORTED_H
#define SORTED_H
#include "Unsorted.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace std;


class Sorted:public Unsorted
{
    public:
        Sorted();
        virtual ~Sorted();


       void sortw(string arr[], int n);
       int Search(std::string d);
       int binarySearch(string arr[], int l, int r, string x);
       int countOccurrences(string arr[], int n, string x);



    protected:

    private:
};

#endif // SORTED_H

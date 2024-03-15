#ifndef Unsorted_H
#define Unsorted_H
#include <iostream>
#include <cstring>
#include <string>


class Unsorted
{
    public:
        Unsorted();
        virtual ~Unsorted();


        void add(std::string);
       // void print();
        virtual int Search(std::string d);
        std::string * Delete(std::string d);

    protected:
        std::string *p;
        int i;
        int length;
        int counter;

    private:
};

#endif // UNSORTED_H

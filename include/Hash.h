#ifndef HASH_H
#define HASH_H
#include <string>
#include <cstring>
#include <iostream>
#define TABLE_SIZE 4096
using std::string;


struct enter
{
    bool se_xrhsh;
   string val;
};

class Hash
{
    public:
        Hash();


        void  insertN(string& );
        int stringoloseira(const string& );
        enter*  Struct__search_function(const string& );
        bool searchN(string& );

    protected:

    private:

        enter entries[TABLE_SIZE];

};

#endif // HASH_H

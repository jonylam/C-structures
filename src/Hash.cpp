#include "Hash.h"

Hash::Hash()
 {

    for (int i = 0; i < TABLE_SIZE; i++)
            entries[i].se_xrhsh = false;
}





//Επιστρεφει τον αριθμο γραμματων απο την λεξη.
 int Hash:: stringoloseira(const string& kek)
{

    int meep = 0;
    for (size_t i = 0; i < kek.length(); i++)
        meep += kek[i];
    return int(meep);
}


 enter* Hash:: Struct__search_function(const string& val)
 {
        int i=0;
        int hhash = stringoloseira(val);
        int stabilizer = hhash % TABLE_SIZE;
        int step = ((hhash%TABLE_SIZE)%TABLE_SIZE);

                step +=1;
        for(i=0;i < TABLE_SIZE; i++)
        {
            enter* test = &entries[stabilizer];
             if (!test->se_xrhsh)
                return test;
            if (test->val == val)
                return test;

        stabilizer =(stabilizer+step)%TABLE_SIZE;
        }

 return nullptr;

 }

 //συναρτηση που επιστρεφει το αν υπαρχει η λεξη στην δομη μας
bool Hash:: searchN(string& val)
{
        enter* ent = Struct__search_function(val);
        return ent->se_xrhsh && ent!=nullptr;

}

//Συναρτηση που κανει insert μιας λεξης στην δομη
void Hash:: insertN(string& val)
{
        enter* ent = Struct__search_function(val);
        if (!ent->se_xrhsh && ent != nullptr)
        {
                ent->se_xrhsh = true;
                ent->val = val;
        }
}

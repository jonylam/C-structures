#include "Unsorted.h"
#include <iostream>
#include <cstring>
#include <string>



using namespace std;




Unsorted::Unsorted()
{
    p=nullptr;
    i=0;
    length=0;
    counter=0;
}

Unsorted::~Unsorted()
{
   delete []p;
}

// συναρτηση που προσθετει καθε λεξη του αρχειου στον πινακα P που ειναι δυναμικος.
void Unsorted::add(string stringtoadd)
{
    if(p==nullptr)
    {
      p=new string[10];
      length=10;
    }
    if(i==length)
    {
        length*=2;
        string *temp=new string[length];
        for(int j=0;j<i;j++)
        {
            temp[j]=p[j];
        }
        delete []p;
        p=temp;
    }
    p[i]=stringtoadd;
    i++;
}

//συναρτηση αναζητησης που επιστρεφει ποσες φορες υπαρχει καθε λεξη στο αρχειο.
int Unsorted::Search(string d)
{
    counter=0;
    for(int j=0;j<i;j++)
    {

        if(d==p[j])
            counter++;
    }
    return counter;
}


/*συναρτηση που υλοποιει την διαγραφη μιας λεξης που θελουμε απο το αρχειο.
επιστρεφουμε string* διοτι μετα την διαγραφη ενος στοιχειο θελουμε να παρουμε τον ανανεωμενο πλεον πινακα P στην main. Οποτε με μια κληση του τυπου Q=c.Delete("leksi")
παιρνουμε το πινακα ανανεωμενο πλεον και στην main.Διαφορετικα μπορουμε να την κανουμε void και να μην επιστρεφουμε τον ανανεωμενο πινακα.*/
string * Unsorted::Delete(string d)
{
    int j=0;
    while(j<i)
    {
      if(d==p[j])
      {
          string *temp=new string[i-1];
          for(int k=0;k<j;k++)
          {
              temp[k]=p[k];
          }
          for(int k=j+1;k<i;k++)
          {
              temp[k-1]=p[k];
          }
          delete []p;
          p=temp;
          i--;
          j=0;
      }
      else
        j++;
    }
    return p;
}






/*void Unsorted::print()
{
    std::cout<<"kelia: "<<i<<endl;
    for(int j=0;j<i;j++)
    {

        std::cout<<"stoixeio: "<<j<<" "<<p[j]<<endl;
    }


//    delete p[];
}*/

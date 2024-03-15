#include <iostream>
#include "BTS.h"
#include "AVL.h"
#include "Hash.h"
#include "Sorted.h"
#include "Unsorted.h"
#include "fstream"
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <stdlib.h>

#include<cstdio>
#include<ctime>



//μερικο πληθος λεξεων που παιρνουμε απο αρχειο που διαβαζουμε(1000 παιρνουμε οπως ζητηθηκε)
#define TOTALWORDS 1000



using namespace std;




int main()
{


    //αν θελω να χρησιμοποιησω τον πινακα p που περιεχει ολες τις λεξεις που διαβαζουμε απο το αρχειο και υλοποιητε μεσα στην κλαση Unsorted.
    // string *Q;


    BTS a;
    Node* tree = NULL;

    AVL b;
    Node* tree1 = NULL;

    Unsorted c;

    Sorted s;

   // Hash h;

    int length1=TOTALWORDS;
    string w[TOTALWORDS];
    int i=0;


    ifstream file;
    std::string str;
    file.open("file.txt");
    while(file>>str)
    {
        //βγαζουμε ολους τους αριθμους και τα σημεια στιξης απο καθε λεξη που εισαγεται απο το αρχειο.
        for (int i = 0, len = str.size(); i < len; i++)
            {

                if (ispunct(str[i]) || isdigit(str[i]) )
                {
                    str.erase(i--, 1);
                    len = str.size();
                }

            }

        //μετατρεπουμε καθε λεξη που εισαγεται με κεφαλαια γραμματα σε μικρα γραμματα.
        transform(str.begin(), str.end(), str.begin(), ::tolower);

        /*κραταω τον πινακα w ο οποιος περιεχει τις 1000 λεξεις απο το αρχειο το οποιο διαβαζεται.Επισης αν βαλω μεσα στο Q=c.add(str) θα εχω
        ολο το αρχειο διαθεσημο για επεξεργασια αποθηκευμενο στον πινακα Q που μπορω να επεξεργαστω για τα αλλα ερωτηματα αν θελω.*/

         if(str!="")
         {

           // h.insertN(str);

            //κραταω τον πινακα w ο οποιος περιεχει τις 1000 λεξεις απο το αρχειο το οποιο διαβαζεται.
             if(i<length1)
                w[i]=str;
             i++;

           /* Επισης αν βαλω μεσα στο Q=c.add(str) θα εχω ολο το αρχειο διαθεσημο για επεξεργασια αποθηκευμενο στον πινακα Q που μπορω
              να επεξεργαστω για τα αλλα ερωτηματα αν θελω.*/
              c.add(str);

              //Μπορω να παραλειψω αυτην την εντολη(s.add(str) διοτι μπορω οπως εξηγω κατω στην cout του Sorted να κανω δυαδικη αναζητηση
              s.add(str);

            //εισαγωγη λεξεων για την δομη BST
              tree=a.Insert(tree,str);
            // εισαγωγη λεξεων για την δομη AVL
              tree1=b.Insert(tree1,str);

         }

    }


    cout<<"::::UNSORTED::::"<<endl;

    clock_t start2 = clock();

    for(int j=0;j<TOTALWORDS;j++)
        cout<<w[j]<<": yparxei: "<<c.Search(w[j])<<" fores"<<endl;

    clock_t end2 = clock();

    double elapsed2 = float(end2 - start2)/CLOCKS_PER_SEC;

    cout<<"TIME FOR UNSORTED SEARCH:: "<<elapsed2<<endl;

    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;

    cout<<"::::SORTED::::"<<endl;


    //δημιουργια πινακα w1 ο οποιος ειναι αντιγραφο του πινακα w ωστε να υλοποιησω την ταξινομηση χωρις να επηρεασω τις αλλες δομες.
    string w1[TOTALWORDS];

    for(int j=0;j<TOTALWORDS;j++)
    {
        w1[j]=w[j];
    }

    //ταξινομηση του πινακα w1 που περιεχει 1000 λεξεις.
    s.sortw(w1,TOTALWORDS);

    clock_t start3 = clock();

    for(int i=0;i<TOTALWORDS;i++)
    {
        /*αν θελετε να χρησιμοποιησετε την διαδικη αναζητηση το κανετε με την πρωτη cout αντι της δευτερης και πλεον επανω στο διαβασμα του αρχειου ειναι περιττη
          η χρηση της εντολης s.add(str)*/
        //  cout<<w1[i]<<": yparxei "<<s.countOccurrences(w1,TOTALWORDS,w1[i])<<" fores"<<endl;
        cout<<w1[i]<<": yparxei "<<s.Search(w1[i])<<" fores"<<endl;
    }

    clock_t end3 = clock();

    double elapsed3 = float(end3 - start3)/CLOCKS_PER_SEC;

    cout<<"TIME FOR UNSORTED SEARCH:: "<<elapsed3<<endl;



    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;


    cout<<"::::BST TREE::::"<<endl;

    clock_t start = clock();

    float count1=0;

    for(int j=0;j<TOTALWORDS;j++)
        cout<<w[j]<<": yparxei: "<<a.Search(tree,w[j])<<" fores"<<endl;

    clock_t end = clock();

    double elapsed = float(end - start)/CLOCKS_PER_SEC;

    cout<<"TIME FOR BST SEARCH:: "<<count1<<endl;

    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;

    cout<<"::::AVL TREE::::"<<endl;


    clock_t start1 = clock();

    for(int j=0;j<TOTALWORDS;j++)
        cout<<w[j]<<": yparxei: "<<b.Search(tree1,w[j])<<" fores"<<endl;

    clock_t end1 = clock();

    double elapsed1 = float(end1 - start1)/CLOCKS_PER_SEC;

    cout<<"TIME FOR AVL SEARCH:: "<<elapsed1<<endl;




    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;


    /*cout<<"::::HASHTABLE ::::"<<endl;


    /* δημιουργω τον πινακα counterh ο οποιος θα κρατα για καθε λεξη ποσες φορες υπαρχει στο κειμενο των 1000 λεξεων.

    clock_t start4 = clock();

    int counterh[TOTALWORDS];

    for(int j=0;j<TOTALWORDS;j++)
        counterh[j]=0;

    for(int j=0;j<TOTALWORDS;j++)
    {
        if(h.searchN(w[j]))
        {
            for(int k=0;k<TOTALWORDS;k++)
            {
                if(w[j]==w[k])
                {
                    counterh[j]+=1;
                }
            }
        }
    }


    for(int j=0;j<TOTALWORDS;j++)
        cout<<w[j]<<": yparxei: "<<counterh[j]<<" fores"<<endl;


    clock_t end4 = clock();

    double elapsed4 = float(end4 - start4)/CLOCKS_PER_SEC;

    cout<<"TIME FOR HASHTABLE SEARCH:: "<<elapsed1<<endl;*/

}
















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



//������ ������ ������ ��� ��������� ��� ������ ��� ����������(1000 ��������� ���� ��������)
#define TOTALWORDS 1000



using namespace std;




int main()
{


    //�� ���� �� ������������� ��� ������ p ��� �������� ���� ��� ������ ��� ���������� ��� �� ������ ��� ��������� ���� ���� ����� Unsorted.
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
        //�������� ����� ���� �������� ��� �� ������ ������ ��� ���� ���� ��� ��������� ��� �� ������.
        for (int i = 0, len = str.size(); i < len; i++)
            {

                if (ispunct(str[i]) || isdigit(str[i]) )
                {
                    str.erase(i--, 1);
                    len = str.size();
                }

            }

        //������������ ���� ���� ��� ��������� �� �������� �������� �� ����� ��������.
        transform(str.begin(), str.end(), str.begin(), ::tolower);

        /*������ ��� ������ w � ������ �������� ��� 1000 ������ ��� �� ������ �� ����� ����������.������ �� ���� ���� ��� Q=c.add(str) �� ���
        ��� �� ������ ��������� ��� ����������� ������������ ���� ������ Q ��� ����� �� ����������� ��� �� ���� ��������� �� ����.*/

         if(str!="")
         {

           // h.insertN(str);

            //������ ��� ������ w � ������ �������� ��� 1000 ������ ��� �� ������ �� ����� ����������.
             if(i<length1)
                w[i]=str;
             i++;

           /* ������ �� ���� ���� ��� Q=c.add(str) �� ��� ��� �� ������ ��������� ��� ����������� ������������ ���� ������ Q ��� �����
              �� ����������� ��� �� ���� ��������� �� ����.*/
              c.add(str);

              //����� �� ��������� ����� ��� ������(s.add(str) ����� ����� ���� ����� ���� ���� cout ��� Sorted �� ���� ������� ���������
              s.add(str);

            //�������� ������ ��� ��� ���� BST
              tree=a.Insert(tree,str);
            // �������� ������ ��� ��� ���� AVL
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


    //���������� ������ w1 � ������ ����� ��������� ��� ������ w ���� �� ��������� ��� ���������� ����� �� �������� ��� ����� �����.
    string w1[TOTALWORDS];

    for(int j=0;j<TOTALWORDS;j++)
    {
        w1[j]=w[j];
    }

    //���������� ��� ������ w1 ��� �������� 1000 ������.
    s.sortw(w1,TOTALWORDS);

    clock_t start3 = clock();

    for(int i=0;i<TOTALWORDS;i++)
    {
        /*�� ������ �� ��������������� ��� ������� ��������� �� ������ �� ��� ����� cout ���� ��� �������� ��� ����� ����� ��� �������� ��� ������� ����� �������
          � ����� ��� ������� s.add(str)*/
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


    /* ��������� ��� ������ counterh � ������ �� ����� ��� ���� ���� ����� ����� ������� ��� ������� ��� 1000 ������.

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
















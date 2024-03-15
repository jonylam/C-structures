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

// ��������� ��� ��������� ���� ���� ��� ������� ���� ������ P ��� ����� ���������.
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

//��������� ���������� ��� ���������� ����� ����� ������� ���� ���� ��� ������.
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


/*��������� ��� �������� ��� �������� ���� ����� ��� ������� ��� �� ������.
������������ string* ����� ���� ��� �������� ���� �������� ������� �� ������� ��� ���������� ����� ������ P ���� main. ����� �� ��� ����� ��� ����� Q=c.Delete("leksi")
��������� �� ������ ���������� ����� ��� ���� main.����������� �������� �� ��� ������� void ��� �� ��� ������������ ��� ���������� ������.*/
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

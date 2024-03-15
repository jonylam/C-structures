#ifndef BTS_H
#define BTS_H
#include <iostream>
#include "Unsorted.h"
//Sruct "������" ��� �������� ��� ����,��� ������� ��� �������� ��� ���� "�����"
struct Node{

    std::string word;
    int counter;
    Node* left;
    Node* right;

};
//����� ����� �������� ������� ����������
class BTS
{
    public:
        BTS();

        virtual Node* Insert(Node*,std::string);
        virtual int Search(Node*,std::string);
        Node* Delete( Node*,std::string);
        Node* FindMin(Node*);
        void Inorder(Node*);
        void Postorder(Node*);
        void Preorder(Node*);
        Node* NewNode(std::string);

    protected:

    private:
};

#endif // BTS_H

#include "BTS.h"
#include <iostream>

BTS::BTS()
{
    //ctor

}

//��������� � ����� ��������� ���� ��� �����,�� ��� ���� ��� �� ��������
struct Node* BTS::NewNode(std::string  word){

    Node* newNode = new Node();
    newNode->word = word;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->counter = 0;

};

//��������� ���������� � ����� ��������� ��� ������� ������ ��� ���� ���� ��������� ����.
struct Node* BTS::Insert(Node *tree , std::string  word){

    //�������� �� ����� NULL,���� ������ ��� ����
    if(tree== NULL){

        tree = NewNode(word);

    }

    //�� � ���� ������� ������ ���� 1 ��� �������.
    if(tree->word == word){

        tree->counter++;

    }

    //�� � ���� ����� ��������� ��� ����� ��� ������ ���� ���� ���������� ��� ��������� �� ��������� �� �������� ��������� ��� ������.
    if(tree->word > word){

        tree->left = Insert(tree->left,word);

    }

    //�� � ���� ����� ���������� ��� ����� ��� ������ ���� ���� ���������� ��� ��������� �� ��������� �� ���� ��������� ��� ������.
    if(tree->word < word){

        tree->right = Insert(tree->right,word);

    }
    return tree;


}

//��������� ����������,� ����� ���������� ����� ����� ��������� ��� ���� ��� ������� ������.
int BTS::Search(Node *tree , std::string  word){

    //�� �������� �� NULL ����� �������� ��� ��� ������� � ����.
    if(tree == NULL){

        return -1;

    }

    //�� � ���� ����� ��������� ��� ����� ��� ������ ���� ���� ���������� ��� ��������� �� ��������� �� �������� ��������� ��� ������.
    if(tree->word > word){

        return Search(tree->left , word);

    }

    //�� � ���� ����� ���������� ��� ����� ��� ������ ���� ���� ���������� ��� ��������� �� ��������� �� ���� ��������� ��� ������.
    if(tree->word < word){

        return Search(tree->right , word);

    }

    // //�� � ���� ������� ��������� ����� ����� ������� � ����.
    if(tree->word == word){

        return tree->counter;

    }

}

//��������� � ����� ���������� ���� � ������ ���� ������,�� ��������� �����.
struct Node* BTS::FindMin(Node* tree){

    while(tree->left != NULL){

        tree = tree->left;

    }

    return tree;

}
//��������� ���������,� ����� ��������� ��� ���� ��� �� ���������.
struct Node* BTS::Delete( struct Node* tree , std::string word){

    //�� �������� �� NULL ����� �������� ��� ��� ������� � ����.
    if(tree== NULL){

        return tree;

    }

    //�� � ���� ����� ��������� ��� ����� ��� ������ ���� ���� ���������� ��� ��������� �� ��������� �� �������� ��������� ��� ������.
    else if(word < tree->word){

        tree->left = Delete(tree->left,word);

    }

    //�� � ���� ����� ���������� ��� ����� ��� ������ ���� ���� ���������� ��� ��������� �� ��������� �� ���� ��������� ��� ������.
    else if(word> tree->word){

        tree->right = Delete(tree->right,word);

    }

    else{
        //��������� �� ������ �����

        if(tree->left == NULL && tree->right == NULL){

            delete tree;
            tree = NULL;

        }

        //��������� �� 1 �����

        else if(tree->left == NULL){

            struct Node *temp = tree;
            tree = tree->right;
            delete temp;

        }

        else if(tree->right == NULL){

            struct Node *temp = tree;
            tree = tree->left;
            delete temp;
        }

        //��������� �� 2 ������

        else{

            struct Node *temp = FindMin(tree->right);
            tree->word = temp->word;
            tree->right = Delete(tree->right,temp->word);

        }

    }

    return tree;

}



void BTS::Inorder(Node* tree){

    if(tree == NULL) return;
    Inorder(tree->left);
    std::cout<<tree->word<<" ";
    Inorder(tree->right);

}

void BTS::Postorder(Node* tree){

     if(tree == NULL) return;
     Postorder(tree->left);
     Postorder(tree->right);
     std::cout<<tree->word<<" ";

}

void BTS::Preorder(Node* tree){

    if(tree == NULL) return;
    std::cout<<tree->word<<" ";
    Preorder(tree->left);
    Preorder(tree->right);

}

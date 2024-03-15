#include "AVL.h"

AVL::AVL():BTS()
{
    //ctor
}

//��������� ��� �������� ��� ���� AVL Tree , ��� ������� ��� ���� ��� ���� �����
struct Node* AVL::Insert(Node* tree , std::string word){

    //�� � ������ ����� NULL ���� ��������� �� ����� ��� ���� ��� ���� �����
    if (tree == NULL){

        tree = NewNode(word);

    }

    //�� � � ���� ��� ������ ���� ���� �� ��� ���� ��� ������� �� ��������� ���� ��������� ��� ������� ���� ���
    if (tree->word == word){

        tree->counter++;

    }

    //�� � ���� ����� ��������� ��� ����� ��� ������ ���� ������� ��� ��������� ���������� �� ��������� �� �������� ��������� ��� ������ ��� ������� ��� ��������� Balance
    if (tree->word > word){

        tree->left = Insert(tree->left , word);
        tree = Balance(tree);

    }

    //�� � ���� ����� ���������� ��� ����� ��� ������ ���� ������� ��� ��������� ���������� �� ��������� �� ���� ��������� ��� ������ ��� ������� ��� ��������� Balance
    if (tree->word < word){

        tree->right = Insert(tree->right , word);
        tree = Balance(tree);

    }
    return tree;

}

//��������� ��� ������������� ��� ����� �������� ����������
struct Node* AVL::llRotate(Node *tree){

    Node* temp = tree->left;
    tree->left = temp->right;
    temp->right = tree;
    return temp;

}
//��������� ��� ������������� ��� ����� ����� ����������
struct Node* AVL::rrRotate(Node* tree){

    Node* temp = tree->right;
    tree->right = temp->left;
    temp->left = tree;
    return temp;

}
//��������� ��� ������������� ����� ��� �������� ��� ���� �������� ��� ����� ����������
struct Node* AVL::lrRotate(Node* tree){

    Node* temp = tree->left;
    tree->left = rrRotate(temp);
    return llRotate(tree);

}
//��������� ��� ������������� ����� ��� ����� ��� ���� �������� ��� �������� ����������
struct Node* AVL::rlRotate(Node* tree){

    Node* temp = tree->right;
    tree->right = llRotate(temp);
    return rrRotate(tree);

}
//��������� ��� ���������� �� ���� ��� ������� ��� �������  �� ���������
int AVL::Height(Node* tree){

    int h = 0;
    if (tree != NULL){

        int lH = Height(tree->left);
        int rH = Height(tree->right);
        if (lH > rH){

            h = lH + 1;

        }
        else{

            h = lH + 1;

        }

    }
    return h;

}

//��������� ��� ������� �� ����������� ����������� , ������� �� ��� ���� ��� ������� ��� ������ ���� ����� ����������� , ��� ������� ��� ���������� ����������� ��� ��� �������������� ��� �����������
struct Node* AVL::Balance(Node* tree){

    if (Height(tree->left) - Height(tree->right) > 1){

        if (Height(tree->left->left) - Height(tree->left->right) > 0){

            tree = llRotate(tree);

        }
        else{

            tree = lrRotate(tree);

        }

    }
    else if (Height(tree->left) - Height(tree->right) < -1){

        if (Height(tree->right->left) - Height(tree->right->right) > 0){

            tree = rlRotate(tree);

        }
        else{

            tree = rrRotate(tree);

        }

    }

    return tree;

}

struct Node* AVL::Delete(Node* tree ,std::string word){

    //������� �� ���� ��������
    if(tree == NULL)
        return tree;

    if(word < tree->word)
        tree->left = Delete(tree->left , word );

    else if(word> tree->word)
        tree->right = Delete(tree->right , word);


    else
    {
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
            tree->right = Delete(tree->right, temp->word);

        }

    }

    tree = Balance(tree);
    return tree;

}

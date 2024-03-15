#ifndef AVL_H
#define AVL_H
#include "BTS.h"


class AVL : public BTS
{
    public:
        AVL();
        virtual Node* Insert(Node*,std::string);
        Node* llRotate(Node*);
        Node* rlRotate(Node*);
        Node* rrRotate(Node*);
        Node* lrRotate(Node*);
        int Height(Node*);
        Node* Balance(Node*);
        virtual Node* Delete(Node*,std::string);


    protected:

    private:
};

#endif // AVL_H

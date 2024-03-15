#include "AVL.h"

AVL::AVL():BTS()
{
    //ctor
}

//Συναρτηση που υλοποιει την δομη AVL Tree , και εισαγει την λεξη που εχει δοθει
struct Node* AVL::Insert(Node* tree , std::string word){

    //Αν ο κομβος ειναι NULL τοτε εισαγουμε σε αυτον την λεξη που εχει δοθει
    if (tree == NULL){

        tree = NewNode(word);

    }

    //Αν ο η λεξη του κομβου εναι ιδια με την λεξη που θελουμε να εισαγουμε τοτε αυξανουμε τον μετρητη κατα ενα
    if (tree->word == word){

        tree->counter++;

    }

    //Αν η λεξη ειναι μικροτερη απο αυτην του κομβου τοτε καλουμε την συναρτηση αναδρομικα με παραμετρο το αριστερο υποδεντρο του κομβου και καλουμε την συανρτηση Balance
    if (tree->word > word){

        tree->left = Insert(tree->left , word);
        tree = Balance(tree);

    }

    //Αν η λεξη ειναι μεγαλυτερη απο αυτην του κομβου τοτε καλουμε την συναρτηση αναδρομικα με παραμετρο το δεξι υποδεντρο του κομβου και καλουμε την συανρτηση Balance
    if (tree->word < word){

        tree->right = Insert(tree->right , word);
        tree = Balance(tree);

    }
    return tree;

}

//συναρτηση που πραγματοποιει μια διπλη αριστερη περιστροφη
struct Node* AVL::llRotate(Node *tree){

    Node* temp = tree->left;
    tree->left = temp->right;
    temp->right = tree;
    return temp;

}
//συναρτηση που πραγματοποιει μια διπλη δεξια περιστροφη
struct Node* AVL::rrRotate(Node* tree){

    Node* temp = tree->right;
    tree->right = temp->left;
    temp->left = tree;
    return temp;

}
//Συναρτηση που πραγματοποιει πρωτα μια αριστερη και στην συνεχεια μια δεξια περιστροφη
struct Node* AVL::lrRotate(Node* tree){

    Node* temp = tree->left;
    tree->left = rrRotate(temp);
    return llRotate(tree);

}
//Συναρτηση που πραγματοποιει πρωτα μια δεξια και στην συνεχεια μια αριστερη περιστροφη
struct Node* AVL::rlRotate(Node* tree){

    Node* temp = tree->right;
    tree->right = llRotate(temp);
    return rrRotate(tree);

}
//Συναρτηση που υπολογιζει το υψος του δεντρου που δεχεται  ως παραμετρο
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

//Συναρτηση που ελεγχει αν χρειαζονται περιστορφες , αναλογα με τος υψος των παιδιων του κομβου στον οποιο βρισκομαστε , και εκτελει τις καταλληλες συναρτησεις για την πραγματοποιηση των περιστροφων
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

    //Ξεκιναω με απλη ΔΙΑΓΡΑΦΗ
    if(tree == NULL)
        return tree;

    if(word < tree->word)
        tree->left = Delete(tree->left , word );

    else if(word> tree->word)
        tree->right = Delete(tree->right , word);


    else
    {
        //Περιπτωση με κανενα παιδι

        if(tree->left == NULL && tree->right == NULL){

            delete tree;
            tree = NULL;

        }

        //Περιπτωση με 1 παιδι

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

        //Περιπτωση με 2 παιδια

        else{

            struct Node *temp = FindMin(tree->right);
            tree->word = temp->word;
            tree->right = Delete(tree->right, temp->word);

        }

    }

    tree = Balance(tree);
    return tree;

}

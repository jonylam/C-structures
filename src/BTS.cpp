#include "BTS.h"
#include <iostream>

BTS::BTS()
{
    //ctor

}

//Συναρτηση η οποια δημουργει εναν νεο κομβο,με την λεξη που θα εισαχθει
struct Node* BTS::NewNode(std::string  word){

    Node* newNode = new Node();
    newNode->word = word;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->counter = 0;

};

//Συναρτηση αναδρομικη η οποια προσθετει στο δυαδικο δενδρο την λεξη στην καταλληλη θεση.
struct Node* BTS::Insert(Node *tree , std::string  word){

    //Καταληξη σε κομβο NULL,οπου εισαγω την λεξη
    if(tree== NULL){

        tree = NewNode(word);

    }

    //Αν η λεξη υπαρχει αυξανω κατα 1 τον μετρητη.
    if(tree->word == word){

        tree->counter++;

    }

    //Αν η λεξη ειναι μικροτερη της λεξης του κομβου τοτε καλω αναδρομικα την συναρτηση με παραμετρο το αριστερο υποδενδρο του κομβου.
    if(tree->word > word){

        tree->left = Insert(tree->left,word);

    }

    //Αν η λεξη ειναι μεγαλυτερη της λεξης του κομβου τοτε καλω αναδρομικα την συναρτηση με παραμετρο το δεξι υποδενδρο του κομβου.
    if(tree->word < word){

        tree->right = Insert(tree->right,word);

    }
    return tree;


}

//Συναρτηση αναδρομικη,η οποια επιστρεφει ποσες φορες βρισκεται μια λεξη στο δυαδικο δενδρο.
int BTS::Search(Node *tree , std::string  word){

    //Αν καταληξω σε NULL κομβο συμαινει οτι δεν υπαρχει η λεξη.
    if(tree == NULL){

        return -1;

    }

    //Αν η λεξη ειναι μικροτερη της λεξης του κομβου τοτε καλω αναδρομικα την συναρτηση με παραμετρο το αριστερο υποδενδρο του κομβου.
    if(tree->word > word){

        return Search(tree->left , word);

    }

    //Αν η λεξη ειναι μεγαλυτερη της λεξης του κομβου τοτε καλω αναδρομικα την συναρτηση με παραμετρο το δεξι υποδενδρο του κομβου.
    if(tree->word < word){

        return Search(tree->right , word);

    }

    // //Αν η λεξη υπαρχει επιστρεφω ποσες φορες υπαρχει η λεξη.
    if(tree->word == word){

        return tree->counter;

    }

}

//Συναρτηση η οποια υπολογιζει εναν ο κομβος εχει παιδια,το μικροτερο παιδι.
struct Node* BTS::FindMin(Node* tree){

    while(tree->left != NULL){

        tree = tree->left;

    }

    return tree;

}
//Συναρτηση διαγραφης,η οποια διαγραφει την λεξη που θα επιλεχθει.
struct Node* BTS::Delete( struct Node* tree , std::string word){

    //Αν καταληξω σε NULL κομβο συμαινει οτι δεν υπαρχει η λεξη.
    if(tree== NULL){

        return tree;

    }

    //Αν η λεξη ειναι μικροτερη της λεξης του κομβου τοτε καλω αναδρομικα την συναρτηση με παραμετρο το αριστερο υποδενδρο του κομβου.
    else if(word < tree->word){

        tree->left = Delete(tree->left,word);

    }

    //Αν η λεξη ειναι μεγαλυτερη της λεξης του κομβου τοτε καλω αναδρομικα την συναρτηση με παραμετρο το δεξι υποδενδρο του κομβου.
    else if(word> tree->word){

        tree->right = Delete(tree->right,word);

    }

    else{
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

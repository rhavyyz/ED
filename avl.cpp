// AVLs arvore de busca binaria balenceada em relação a altura de suas subarvores 
// de modo que a diferenca entre as altuas de subarvores nao pode ser maior do que 
// |1|.

// Fator de balanceamento: Diferenca entre altua das subarvores
// Fb = Hesq - Hdir

// Rotações são de dois tipos esquerda e direita


// Altura de arvore vazia = -1

#include <iostream>

#include "utils.hpp"

class Avl
{
    private:
        struct Node
        {
            Node * left = NULL, * right = NULL;
        
            int height=0;

            int value;
        };  

        void rigthRotation(Node * parent, Node* child)
        {
            swap<int>(parent->value, child->value);

            swap<Node *>(parent->right, child->right);
            swap<Node *>(parent->right, child->left);
            swap<Node *>(parent->right, parent->left);
        }

        void leftRotation(Node * parent, Node* child)
        {
            swap<int>(parent->value, child->value);

            swap<Node *>(parent->left, child->left);
            swap<Node *>(parent->left, child->right);
            swap<Node *>(parent->right, parent->left);
        }

        void rotate(Node * n1, Node * n2)
        {
            if(n2->left == n1 || n2->right == n1)
                swap<Node *>(n1, n2);

            if(n1->left == n2)
                return rigthRotation(n1, n2);

            if(n1->left == n2)
                return leftRotation(n1, n2);
        }


        int getHeight(Node * node)
        {
            if(node == NULL) return -1;

            return node->height;
        }

        Node *root = NULL;

        int _insert(int data, Node ** node)
        {
            if((*node) == NULL)
            {
                (*node) = new Node();
                (*node)->value = data;
                (*node)->height = 0;

                return 0;
            }

            if((*node)->value < data)
            {
                int right_h = _insert(data, &(*node)->right);
                if (right_h == -1) return -1;

                int left_h = (*node)->left->height;
                
                (*node)->height = 1 + max(left_h, right_h);

            }

            if((*node)->value > data)
            {
                int left_h = _insert(data, &(*node)->left);
                if(left_h == -1) return -1; 

                int right_h = (*node)->right->height;

                int delta = left_h - right_h;



            }
            return -2;
        }

        bool _contains(int data, Node*node)
        {
            if(node == NULL) return false;

            if(node->value < data) return _contains(data, node->right);
            if(node->value > data) return _contains(data, node->left);

            return true;
        }

    public:

        void inline insert(int data)
        {
            _insert(data, &root);
        }

        bool inline find(int data)
        {
            return _contains(data, root);
        }

};


int main()
{




    return 0;
}
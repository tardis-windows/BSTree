#ifndef NODE_H
#define NODE_H
#include <iomanip>


//-------------------------Node class for Tree

template<class T>
struct Node {
    Node(const T& v) : m_val(v), m_act(true), m_left(0), m_right(0) {}
    T        m_val;
    bool     m_act;
    Node<T>* m_left;  // pointer to the left subtree.
    Node<T>* m_right; // pointer to the right subtree.
   };

//--------------------------------------------- tree_clear
template<class T>
void tree_clear(Node<T>*& root_ptr){
// Library facilities used: cstdlib
    Node<T>* child;
        if (root_ptr != NULL){
            child = root_ptr->m_left;
            tree_clear( child );
            child = root_ptr->m_right;
            tree_clear( child );

            delete root_ptr;
            root_ptr = NULL;
    }
}

//-------------------------------------------- tree_copy
template <class T>
Node<T>* tree_copy(const Node<T>* root_ptr){
    Node<T>* l_ptr;
    Node<T>* r_ptr;

    if(root_ptr == NULL)
        return NULL;

    else{
        l_ptr = tree_copy(root_ptr->m_left);
        r_ptr = tree_copy(root_ptr->m_right);
        return new Node<T>(root_ptr->m_val, l_ptr, r_ptr);
    }
}

template <class T>
void print(Node<T>* node_ptr, int depth){
    if(node_ptr != NULL)
    {
        print(node_ptr->m_right, depth+1);
        std::cout<< std::setw(4*depth) << " ";
        std::cout<< node_ptr->m_val << std::endl;
        print(node_ptr->m_left, depth+1);

    }
}



#endif // NODE_H

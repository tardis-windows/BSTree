#ifndef BST_H
#define BST_H
#include "Node.h"
#include "Student.h"
#include "Bag.h"

// ----------- Binary Search Tree Class
template<class T>
class BST {
   public:
    BST():m_root(0), m_active(0), m_inactive(0){};
    BST(const BST&);
    void operator=(const BST&);
    ~BST();

    bool remove(const T&);
    void insert(const T&);
    bool is_member(const T&) const;
    long size() const { return m_active; }
    void compress();  // removed all marked nodes.
    Bag<T> sort() const; // produce a sorted Bag.
   private:
    Node<T>* m_root;
    long  m_active;   // count of active nodes.
    long  m_inactive; // count of inactive nodes.
   };

   //----------------------Implementing BS Tree

/*Copy constructor   ---------------------------------------------- */
template <class T>
BST<T>::BST(const BST& source){

    m_root = tree_copy(source.m_root);

}

/*Assignment operator overload   ----------------------------- */
template <class T>
void BST<T>::operator=(const BST& source){
    if(m_root == source.m_root)
        return;
    tree_clear(m_root);
    m_root = tree_copy(source.m_root);

}

/*Destructor  ----------------------------------------------  */
template <class T>
BST<T>::~BST(){
    tree_clear(m_root);
}

/*Remove    */
template <class T>
bool BST<T>::remove(const T&){}

/*Insert    */
template <class T>
void BST<T>::insert(const T& entry){

    Node<T>* cursor;

    if(m_root == NULL){
        m_root = new Node<T>(entry);
        return;
    }

    else{
        cursor = m_root;
        //---------DO THISSSSS BITCH
    }
}

/*is_member    */
template <class T>
bool BST<T>::is_member(const T&) const{}

/*Compress    */
template <class T>
void BST<T>::compress(){}  // removed all marked nodes.

/*Sort    */
template <class T>
Bag<T> BST<T>::sort() const{} // produce a sorted Bag.

#endif // BST_H

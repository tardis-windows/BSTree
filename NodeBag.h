#ifndef NODEBAG_H
#define NODEBAG_H

//----------------Node class for Bag
template<class T>
struct NodeBag{
    NodeBag() : next_ptr(this), prev_ptr(this) {}
    NodeBag(const T& val)
            : NodeBag_data(val), next_ptr(this), prev_ptr(this) {

    }

    T& data(){return NodeBag_data;}
    void setNodeBagData(const T& new_data){NodeBag_data = new_data;}
    void setNext(NodeBag<T>* new_next){next_ptr = new_next;}
    void setPrev(NodeBag<T>* new_prev){prev_ptr = new_prev;}

    T        NodeBag_data;
    NodeBag<T>* next_ptr; // pointer to successor element.
    NodeBag<T>* prev_ptr; // pointer to predecessor element.
};
#endif // NODEBAG_H

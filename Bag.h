#ifndef BAG_H
#define BAG_H
#include "NodeBag.h"
#include "Student.h"


//------------------- Bag class (this bag is sorted)
template<class T>
class Bag {
public:
    Bag() : m_data(0), m_size(0), m_asc(true), m_curr(0), m_tail(0) {}
    Bag(const Bag&);
    void operator =(const Bag&);
    ~Bag();

    bool erase_one(const T&);
    void insert(const T&);
    void operator +=(const Bag&);
    long size() const {return m_size;}
    long count(const T&) const;
    void erase_head();
    void erase_tail();
    void erase(const T& target);


    // SIMPLE ITERATOR
    void begin(const bool ascending = true){m_asc = ascending; m_end = false; m_curr = m_data; if(!ascending){m_curr = m_data->prev_ptr; m_end = true;} }
    bool end() const{if(m_asc==true && m_end==true) return m_curr == m_data; else if(m_asc == false && m_end==false) return m_curr == m_data->prev_ptr; }
    void operator++(){if(m_curr==m_data->next_ptr) m_end = true; m_curr = m_curr->next_ptr;}
    void operator--(){if(m_curr==m_data->next_ptr) m_end = false; m_curr = m_curr->prev_ptr;}
    T& get(){return m_curr->NodeBag_data;}
    T& findPosition(int);
    friend bool operator==(const Bag& b1, const Bag& b2);

private:
    NodeBag<T>* m_data;
    long     m_size; // number of elements in the Bag.
    bool     m_asc;  // flag to indicate iteration in ascending order or not.
    NodeBag<T>* m_curr; // iterator's current position.
    NodeBag<T>* m_tail;
    bool     m_end;
};


//int uniformM(const int a, const int b) {
//    assert(a <= b); return a + rand()%(b-a+1);
//			}

    template <class T>
    NodeBag<T>* list_locate(NodeBag<T>* head_ptr, int position)
    {
	NodeBag<T>* cursor;
	int i;

	cursor = head_ptr;
	for (i = 1; (i < position) && (cursor != NULL); ++i)
	    cursor = cursor->next_ptr;
	return cursor;
    }

template<class T>
void Bag<T>::insert(const T& entry){
    if(m_data==0){

        // insert if list is empty
        m_data = new NodeBag<T>(entry);
        m_tail = m_data;
        m_size++;
    }

    else{

        // set temp to head pointer and create new node.
        NodeBag<T>* temp = m_data;
        NodeBag<T>* newNodeBag = new NodeBag<T>(entry);

        // if entry is smaller than first node insert as head node
        if(entry < m_data->NodeBag_data){
            temp->prev_ptr = newNodeBag;
            newNodeBag->next_ptr = temp;
            m_data = newNodeBag;
            m_data->prev_ptr = m_tail;
            m_tail->next_ptr = m_data;
            m_size++;
        }else
        // if entry is bigger than last node insert at the end
        if(entry > m_tail->NodeBag_data){
            temp = m_tail;
            temp->next_ptr = newNodeBag;
            newNodeBag->prev_ptr = temp;
            m_tail = newNodeBag;
            m_data->prev_ptr = m_tail;
            m_tail->next_ptr = m_data;
            m_size++;
        }
        else{
            //if not smaller than first node or bigger than last node find position and insert
            while(entry > temp->NodeBag_data){
                temp = temp->next_ptr;
            }
            newNodeBag->next_ptr = temp;
            temp->prev_ptr->next_ptr = newNodeBag;
            newNodeBag->prev_ptr = temp->prev_ptr;
            temp->prev_ptr = newNodeBag;
            m_size++;
        }
    }
}

template<class T>
bool operator==(const Bag<T>& b1, const Bag<T>& b2){
        return (b1.m_data->NodeBag_data == b2.m_data->NodeBag_data);
    }

template<class T>
Bag<T> operator+(const Bag<T>&, const Bag<T>&){
}

template<class T>
void Bag<T>::operator=(const Bag& source){
    m_curr->NodeBag_data = source.m_curr->NodeBag_data;
}

template<class T>
Bag<T>::~Bag(){

    for(int i=0; i<m_size; i++){
        NodeBag<T> *curr = m_data;
        m_data = m_data->next_ptr;
        delete(curr);
    }
    m_size = 0;
    m_data = 0;
}


template<class T>
void Bag<T>::erase_head(){
    NodeBag<T>* curr = m_data;
    m_data = m_data->next_ptr;
    m_data->prev_ptr = m_tail;
    m_tail->next_ptr = m_data;

    delete(curr);
    m_size--;
}

template<class T>
void Bag<T>::erase_tail(){

    NodeBag<T>* curr = m_tail;
    m_tail = m_tail->prev_ptr;
    m_tail->next_ptr = m_data;
    m_data->prev_ptr = m_tail;

    delete(curr);
    m_size--;
}

template<class T>
void Bag<T>::erase(const T& entry){
    NodeBag<T> *temp;

          if (m_data->NodeBag_data == entry){
                erase_head();
          }
          else{

             temp = m_data->next_ptr;
             while (temp != m_data){
                if (temp->NodeBag_data == entry){

                    if (temp == m_tail){

                            temp->prev_ptr->next_ptr = m_data;
                            m_data->prev_ptr = temp->prev_ptr;

                            m_size--;
                            delete temp;
                   }else{
                            temp->prev_ptr->next_ptr = temp->next_ptr;
                            temp->next_ptr->prev_ptr = temp->prev_ptr;

                            delete temp;
                            m_size--;
                        }
                    }
                    temp = temp->next_ptr;
                }
         }
    }

template<class T>
void Bag<T>::operator +=(const Bag& addend){

}

template<class T>
T& Bag<T>::findPosition(int index){
          int pos = 0;
          NodeBag<T>* temp = m_data;

          while (pos!=index){
            pos++;
            temp = temp->next_ptr;
          };

          if (pos == index)
              return temp->NodeBag_data;
}

#endif // BAG_H

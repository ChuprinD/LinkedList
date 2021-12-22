#include "linkedList.h"

template <typename T>
Node<T>::Node (T elem)
    {
    next_ = nullptr;
    elem_ = elem;
    }

template <typename T>
Node<T>::Node ()
    {
    next_ = nullptr;
    elem_ = 0;
    } 

template <typename T>
Node<T>::Node (Node<T>& node)
    {
    next_ = node.next_;
    elem_ = node.elem_;
    }

template <typename T>
LinkedList<T>::LinkedList ()
    {
    Node<T>* head = new Node<T>;
    Node<T>* tail = new Node<T>;
    head_ = head;
    tail_ = tail;
    size_ = 0;
    }

template <typename T>
LinkedList<T>::LinkedList (initializer_list<T> nodes)
    {
    Node<T>* head = new Node<T>;
    Node<T>* tail = new Node<T>;
    size_ = 2;

    tail -> elem_ = *(nodes.end() - 1);
    
    Node<T>* prev = tail;
    
    for (auto it = nodes.end() - 2; it != nodes.begin(); --it)
        {
        Node<T>* curNode = new Node<T> (*it);
        curNode -> next_ = prev;
        prev = curNode;
        size_++;
        }

    tail -> next_ = nullptr;
    head -> elem_ = *nodes.begin();
    head -> next_ = prev;

    head_ = head;
    tail_ = tail;
    }

template <typename T>
int LinkedList<T>::size()
    {
    return size_;
    }

template <typename T>
ostream& operator<< (ostream &out, const LinkedList<T> &linkedList)
    {
    Node<T>* cur = linkedList.head_;
    out << "{";
    if (linkedList.size_ == 1)
        out << cur -> elem_;
    else if (linkedList.size_ == 2)
        {
        out << cur -> elem_ << " " << cur -> next_ -> elem_;
        }
    else
        {
        while (cur != linkedList.tail_)
            {
            out << cur -> elem_ << " ";
            cur = cur -> next_;
            }
        out << linkedList.tail_ -> elem_;
        }
    out << "}";
    return out;
    } 

template <typename T>
void LinkedList<T>::print()
    {
    Node<T>* cur = head_;
    while (cur != tail_)
        {
        printf("[%d] -> next(%d)\n", cur->elem_, cur->next_->elem_);
        cur = cur -> next_;
        }
    }
    
template <typename T>
bool LinkedList<T>::empty()
    {
    return size_ == 0;
    }

template <typename T>
void LinkedList<T>::push_front(const T elem)
    {
    Node<T>* cur = new Node<T> (elem);
    if (empty())
        {
        head_ = cur;
        }
    else if (size_ == 1)
        {
        cur -> next_ = head_;
        tail_ = head_;
        head_ = cur;
        }
    else
        {
        cur -> next_ = head_;
        head_ = cur;
        }  
    size_++;
    }

template <typename T>
void LinkedList<T>::push_back(const T elem)
    {
    Node<T>* cur = new Node<T> (elem);
    if (empty())
        {
        head_ = cur;
        }
    else if (size_ == 1)
        {
        head_ -> next_ = cur;
        tail_ = cur;
        }
    else
        {
        tail_ -> next_ = cur;
        tail_ = cur;
        } 
    size_++; 
    }

template <typename T>
void LinkedList<T>::insert (const int index, const T elem)
    {
    Node<T>* cur = head_;
    for (int i = 0; i < index - 1; i++)
        cur = cur -> next_;
    Node<T>* ver = new Node<T> (elem);
    if (size_ == 1)
        {
        head_ -> next_ = ver;
        tail_ = ver;
        }
    else
        {      
        ver -> next_ = cur -> next_;
        cur -> next_ = ver;
        }

    size_++;
    }

template <typename T>
void LinkedList<T>::pop_front ()
    {
    if (size_ == 1)
        {
        head_ = nullptr;
        size_--;
        }
    else
        {
        head_ = head_->next_;
        size_--;
        }
    }

template <typename T>
void LinkedList<T>::pop_back ()
    {
    if (size_ == 1)
        {
        head_ = nullptr;
        size_--;
        }
    else
        {
        Node<T>* cur = head_;
        while (cur -> next_ != tail_)
            cur = cur -> next_;
        
        cur -> next_ = nullptr;
        tail_ = cur;
        size_--;
        }
    }

template <typename T>
void LinkedList<T>::erase (const int index)
    {
    Node<T>* cur = head_;
    for (int i = 0; i < index - 1; i++)
        cur = cur -> next_;

    Node<T>* del = cur -> next_;
    cur -> next_ = del -> next_;

    size_--;
    delete del;
    }

template <typename T>
void LinkedList<T>::erase_value (const T elem)
    {
    Node<T>* cur = head_;
    while (cur -> next_ -> elem_ != elem)
        cur = cur -> next_;

    Node<T>* del = cur -> next_;
    cur -> next_ = del -> next_;

    size_--;
    delete del;
    }

template <typename T>
int LinkedList<T>::find (const T elem)
    {
    Node<T>* cur = head_;
    int index = 0;
    while (cur -> elem_ != elem)
        {
        cur = cur -> next_;
        index++;
        }
    return index;
    }

template <typename T>
T LinkedList<T>::operator[] (const int index)
    {
    Node<T>* cur = head_;
    for (int i = 0; i < index; i++)
        cur = cur -> next_;

    return cur -> elem_;
    }
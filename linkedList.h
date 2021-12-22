#pragma once
#include <iostream>
#include <initializer_list>
#include <fstream>

using namespace std;

#ifndef LIST_H
#define LIST_H

template <typename T>
class Node
    {
    public:
        Node<T>* next_;
        T elem_;

        Node();
        Node (T elem);
        Node (Node<T>& node);

    };

template <typename T>
class LinkedList
    {
    private:
        Node<T>* head_ = nullptr;
        Node<T>* tail_ = nullptr;
        int size_= 0;

    public:
        LinkedList (initializer_list<T> nodes);
        LinkedList ();

        int size();
        bool empty();
        void push_front (const T elem);
        void insert (const int index, const T elem);
        void push_back (const T elem);
        void pop_front();
        void pop_back();
        void print();
        void erase (const int index);
        void erase_value (const T elem);
        int find (const T elem);

        T operator[] (const int index);
        template <typename T> friend ostream& operator<< (ostream &out, const LinkedList<T> &linkedList);
    };

#include "linkedList.inl"

#endif LIST_H
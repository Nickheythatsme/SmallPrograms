/*
 * Nicholas Grout
 * Program 3
 */
//The link to this tree can be found at:
//https://github.com/Nickheythatsme/DataStructures/tree/master/two_three_tree
#include <cstring>
#include <cctype>
#include <iostream>

#ifndef TWO_THREE_TREE_
#define TWO_THREE_TREE_

template <class T>
bool sort_data(T* data, int len);
template <class T>
bool sorted(T* data, int len);

template <class T>
class node;
template <class T>
std::ostream& operator<<(std::ostream & out, const node<T> & obj);

template <class T>
class TwoThreeTree;
template <class T>
std::ostream& operator<<(std::ostream & out, const TwoThreeTree<T> & obj);

template <class T>
class node
{
    public:
        node();
        node(const node<T> & obj);
        node(const T& obj);
        ~node();
        //Operators
        std::ostream& display_all(std::ostream & out, const node<T> * root, int & invoc) const;
        std::ostream& display_ordered(std::ostream & out, const node<T> * root) const;
        friend std::ostream& operator<< <T>(std::ostream & out, const node<T> & data);
        //Public functions
        void remove_all(node *& root);
        bool insert(node<T> *& root, const T & data);
        bool find(const node<T>* root, const T& data) const;
    private:
        bool is_full(void) const;
        bool is_leaf(void) const;
        node<T>* next_man(int child) const; //Traverse manually to the next child
        node<T>* next(const T& data) const;//Traverse based on the data.
        int which_child(const T& data) const;
        bool connect(node<T> * new_child, int child_num);

        bool split(const T& new_data, T& middle_data, node<T> *& new_left, node<T> *& new_right);
        bool absorb(T& middle_data, node<T> *& new_left, node<T> *& new_right);
        bool insert_here(const T& data);
        bool insert(const T& data, node<T> * root, T& middle_data, node<T> *& new_left, node<T> *& new_right);

        T* data; /* Array of 2 datum */
        node<T> ** child; /* Array of 3 children. If there are 4 we split */
        int data_count;
};

template <class T>
class TwoThreeTree
{
    public:
        TwoThreeTree();
        TwoThreeTree(const TwoThreeTree<T> & obj);
        ~TwoThreeTree();
        std::ostream& display_all(std::ostream & out) const;
        std::ostream& display_ordered(std::ostream & out) const;
        friend std::ostream& operator<< <T>(std::ostream & out, const TwoThreeTree & obj);
        TwoThreeTree<T>& operator=(const TwoThreeTree<T> & obj);
        bool insert(const T& data);
    protected:
        bool find(const T& data) const;
        bool assignment(const TwoThreeTree<T>& data);
    private:
        node<T> * root;
};


#include "23node.cpp"
#include "23tree.cpp"

#endif

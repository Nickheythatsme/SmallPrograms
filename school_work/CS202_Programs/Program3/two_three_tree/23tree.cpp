/*
 * Nicholas Grout
 * Program 3
 */
#include "23tree.h"

//WRAPPER for the insert function.
template <class T>
bool TwoThreeTree<T>::insert(const T& data)
{
    node<T> * temp = root;
    if( !root -> insert(temp, data) )
        return false;
    root = temp;
    return true;
}

template <class T>
bool TwoThreeTree<T>::assignment(const TwoThreeTree<T>& obj)
{
    if( obj.root )
        root = new node<T>(*obj.root);
    else
        root = NULL;
    return true;
}


//Display all nodes in the tree.
template <class T>
std::ostream& TwoThreeTree<T>::display_all(std::ostream & out) const
{
    int invoc = 0;
    root -> display_all(out, root, invoc);
    return out;
}

template <class T>
std::ostream& TwoThreeTree<T>::display_ordered(std::ostream & out) const
{
    root -> display_ordered(out, root);
    return out;
}

template <class T>
std::ostream& operator<<(std::ostream & out, const TwoThreeTree<T> & obj)
{
    obj.display_all(out);
    return out;
}

template <class T>
TwoThreeTree<T>& TwoThreeTree<T>::operator=(const TwoThreeTree<T> & obj)
{
    root -> remove_all(root);
    if( obj.root )
    root = new node<T>(*obj.root);
    return *this;
}

//DEFAULT CONSTRUCTOR
template <class T>
TwoThreeTree<T>::TwoThreeTree()
{
    root = new node<T>();
}

//COPY CONSTRUCTOR. This copies all the nodes from another tree into our tree.
template <class T>
TwoThreeTree<T>::TwoThreeTree(const TwoThreeTree<T> & obj)
{
    assignment(obj);
}

//DESCTRUCTOR
template <class T>
TwoThreeTree<T>::~TwoThreeTree()
{
    if( root )
        root -> remove_all(root);
    root = NULL;
}


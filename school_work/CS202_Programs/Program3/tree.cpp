/*
 * Nicholas Grout
 * Program 3
 */
#include "tree.h"

tree::tree() : TwoThreeTree<enode>()
{
}

tree::tree(const tree & obj) : TwoThreeTree<enode>(obj)
{
}

tree::~tree()
{
}

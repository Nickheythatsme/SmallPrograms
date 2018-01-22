/*
 * Nicholas Grout
 * Program 3
 */
#include "two_three_tree/23tree.h"
#include "enode.h"

#ifndef ENODE_TREE_
#define ENDOE_TREE_

class tree : public TwoThreeTree<enode>
{
    public:
        tree();
        tree(const tree & obj);
        ~tree();
    private:
};

#endif

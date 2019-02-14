#ifndef TREE_NODE_H
#define TREE_NODE_H
#include <wx/treebase.h>
#include "node.h"
class TreeNode:public wxTreeItemData{
public:
    TreeNode(Node* data):_data(data){

    }

    Node *getNode(){
        return _data;
    }

private:
    Node* _data;
};
#endif
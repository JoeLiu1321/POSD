#include "set_path_visitor.h"
#include "file.h"
#include "folder.h"
#include "link.h"
#include "node_iterator.h"
#include <cstring>
using namespace std;
void SetPathVisitor::visitFile(File* file){
    if(file->getParent()==nullptr || _isFirst)
        file->setPath(_path.c_str());
    else
        file->setPath(reviseNameToParent(file));
}

void SetPathVisitor::visitFolder(Folder* folder){
    if(_isFirst || folder->getParent()==nullptr){
        folder->setPath(_path.c_str());
        _isFirst=false;
    }
    else
        folder->setPath(reviseNameToParent(folder));
    for(NodeIterator *it=folder->createIterator();!it->isDone();it->next())
        it->currentItem()->acceptInner(this);
}

void SetPathVisitor::visitLink(Link* link){
    if(link->getParent()==nullptr || _isFirst)
        link->setPath(_path.c_str());
    else
        link->setPath(reviseNameToParent(link));
}

const char* SetPathVisitor::reviseNameToParent(Node* node){
    string tmp=node->getParent()->path()+"/"+node->name();
    char *new_path=new char[tmp.size()];
    strcpy(new_path,node->getParent()->path().c_str());
    strcat(new_path,"/");
    strcat(new_path,node->name().c_str());
    return (const char*)new_path;
}
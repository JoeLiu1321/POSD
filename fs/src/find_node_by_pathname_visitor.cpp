#include "find_node_by_pathname_visitor.h"
#include "node_iterator.h"
#include "file.h"
#include "link.h"
#include "folder.h"
void FindNodeByPathnameVisitor::visitFile(File *file){
    if(_path_tmp.size()!=0 && _path_tmp.back()==file->name())
        _result=file;
}

void FindNodeByPathnameVisitor::visitFolder(Folder *folder){
    if(_path_tmp.size()!=0 && _path_tmp.front()==folder->name()){
        _path_tmp.erase(_path_tmp.begin());
        if(_path_tmp.size()==0)
            _result=folder;
        else
            for(NodeIterator *it=folder->createIterator();!it->isDone();it->next())
                it->currentItem()->acceptInner(this);
    }    
}

void FindNodeByPathnameVisitor::visitLink(Link *link){
    if(_path_tmp.size()!=0 && _path_tmp.back()==link->name())
        _result=link;
}

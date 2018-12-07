#include "find_node_by_pathname_visitor.h"
#include "node_iterator.h"
#include "file.h"
#include "link.h"
#include "folder.h"
void FindNodeByPathnameVisitor::visitFile(File *file){
    if(_pathtmp.size()!=0 && _pathtmp.back()==file->name())
        _result=file;
}

void FindNodeByPathnameVisitor::visitFolder(Folder *folder){
    if(_pathtmp.size()!=0 && _pathtmp.front()==folder->name()){
        _pathtmp.erase(_pathtmp.begin());
        if(_pathtmp.size()==0)
            _result=folder;
        else{    
            for(NodeIterator *it=folder->createIterator();!it->isDone();it->next())
                it->currentItem()->acceptInner(this);
        }
    }    
}

void FindNodeByPathnameVisitor::visitLink(Link *link){
    if(_pathtmp.size()!=0 && _pathtmp.back()==link->name())
        _result=link;
}

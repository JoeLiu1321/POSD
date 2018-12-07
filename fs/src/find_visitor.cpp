#include "folder.h"
#include "file.h"
#include "link.h"
#include "find_visitor.h"
#include "node_iterator.h"
#include <memory>
using namespace std;
void FindVisitor::visitFile(File *file){
    if(file->name()==getTarget() && _find.size()==0)
        setResult(file->name());
}

void FindVisitor::visitFolder(Folder *folder){
    if(_find.size()==0)
        _find.push_back(folder);
    for(unique_ptr<NodeIterator> it(folder->createIterator());!it->isDone();it->next()){ 
        if(it->currentItem()->name()==getTarget())
            _find.push_back(it->currentItem());
        it->currentItem()->acceptInner(this); 
    }
}

void FindVisitor::visitLink(Link *link){
    if(link->name()==getTarget() && _find.size()==0)
        setResult(link->name());
}
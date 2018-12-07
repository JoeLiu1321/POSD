#include "info_content_visitor.h"
#include "file.h"
#include "folder.h"
#include "link.h"
#include "node_iterator.h"
#include <memory>
using namespace std;
void InfoContentVisitor::visitFile(File *file){
    _size+=file->size();
}

void InfoContentVisitor::visitFolder(Folder *folder){
    for(unique_ptr<NodeIterator> it(folder->createIterator());!it->isDone();it->next())
        it->currentItem()->acceptInner(this);
}

void InfoContentVisitor::visitLink(Link *link){
    _size+=link->size();
}
#include "find_link_visitor.h"
#include "node_iterator.h"
#include "folder.h"
#include "file.h"
#include "link.h"
#include <memory>
using namespace std;
FindLinkVisitor::FindLinkVisitor(){

}

void FindLinkVisitor::visitFolder(Folder * folder){
    for(unique_ptr<NodeIterator> it(folder->createIterator());!it->isDone();it->next())
       it->currentItem()->acceptInner(this);
}

void FindLinkVisitor::visitFile(File * file){

}

void FindLinkVisitor::visitLink(Link * link){
    _links.push_back(link);
}

void FindLinkVisitor::clean(){
    _links.clear();
}

vector<Node*> FindLinkVisitor::getLinks(){
    return _links;
}

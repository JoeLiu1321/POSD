#ifndef FIND_LINK_VISITOR_H
#define FIND_LINK_VISITOR_H
#include "node_visitor.h"
#include <vector>
class Node;
class File;
class Folder;
class Link;
class FindLinkVisitor:public NodeVisitor{
    public:
        FindLinkVisitor();

        void visitFolder(Folder * folder);
        
        void visitFile(File * file);
        
        void visitLink(Link * link);
        
        void clean();

        std::vector<Node*> getLinks();//return the Link objects.
    private:
        std::vector<Node*> _links;    

};
#endif
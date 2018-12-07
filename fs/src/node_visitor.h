#ifndef NODE_VISITOR_H
#define NODE_VISITOR_H
#include <string>
#include <vector>
using namespace std;

class File;
class Folder;
class Link;
class NodeVisitor{
    public:
        NodeVisitor(){}
        
        virtual ~NodeVisitor(){}

        virtual void visitFile(File *file)=0;

        virtual void visitFolder(Folder *folder)=0;
        
        virtual void visitLink(Link *link)=0;
        
        virtual void clean()=0;
        
};
#endif
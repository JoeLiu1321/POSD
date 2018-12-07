#ifndef INFO_CONTENT_VISITOR_H
#define INFO_CONTENT_VISITOR_H
#include "node_visitor.h"
class File;
class Folder;
class InfoContentVisitor:public NodeVisitor{
    public:
        InfoContentVisitor():_size(0){

        }

        void visitFile(File *file);
        
        void visitFolder(Folder *folder);
        
        void visitLink(Link *link);
        
        int getContentSize(){
            return _size;
        }
        
        void clean(){
            _size=0;
        }
    private:
        int _size;
};
#endif
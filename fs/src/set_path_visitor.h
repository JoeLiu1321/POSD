#ifndef SET_PATH_VISITOR_H
#define SET_PATH_VISITOR_H
#include "node_visitor.h"
#include <string>
using namespace std;
class Node;
class File;
class Folder;
class Link;
class SetPathVisitor:public NodeVisitor{
public:
    SetPathVisitor(string path):_path(path),_isFirst(true){

    }
    void visitFile(File* file);

    void visitFolder(Folder* folder);

    void visitLink(Link* link);

    const char* reviseNameToParent(Node* node);
    
    void clean(){
        _isFirst=true;
    }

    void setPath(string path){
        _path=path;
    }

private:
    string _path;
    bool _isFirst;
};
#endif
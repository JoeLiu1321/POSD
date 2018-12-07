#ifndef FIND_NODE_BY_PATHNAME_VISITOR_H
#define FIND_NODE_BY_PATHNAME_VISITOR_H
#include "node_visitor.h"
#include <string>
#include <vector>
using namespace std;
class Node;
class File; 
class Folder;

class FindNodeByPathnameVisitor:public NodeVisitor{
    public:
      FindNodeByPathnameVisitor(vector<string>* pathnames):_pathnames(pathnames){
          clean();
      }
      
      void visitFolder(Folder * folder);
      
      void visitFile(File * file);
      
      void visitLink(Link * link);
      
      void clean(){
        _pathtmp.clear();
        clonePath();
        _result=nullptr;
      }
      
      Node * getNode() const{
        return _result;
      }

      void clonePath(){
        for(int i=0;i<_pathnames->size();i++)
            _pathtmp.push_back(_pathnames->at(i));
      }
    private:
        Node * _result;
        vector<string>* _pathnames;
        vector<string> _pathtmp;
};
#endif
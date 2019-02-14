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
      FindNodeByPathnameVisitor(vector<string>* path_names):_path_names(path_names){
          clean();
      }
      
      void visitFolder(Folder * folder);
      
      void visitFile(File * file);
      
      void visitLink(Link * link);
      
      void clean(){
        _path_tmp.clear();
        clonePath();
        _result=nullptr;
      }
      
      Node * getNode() const{
        return _result;
      }

      void clonePath(){
        for(int i=0;i<_path_names->size();i++)
            _path_tmp.push_back(_path_names->at(i));
      }
    private:
        Node * _result;
        vector<string>* _path_names;
        vector<string> _path_tmp;
};
#endif
#ifndef folder_h
#define folder_h
#include "node.h"
#include "node_visitor.h"
#include "node_iterator.h"
#include <map>
#include <sys/stat.h>
#include <string>
using namespace std;

class Folder:public Node{
  public:
    class FolderIterator:public NodeIterator{
      public:
        FolderIterator(Folder *folder):_folder(folder){
          first();
        }

        void first(){
          _it=_folder->_children.begin();
        }

        bool isDone(){
          return _it==_folder->_children.end();
        }

        void next(){
          if(!isDone())
            _it++;
          else
            throw string("iterator is in the end!");  
        }

        Node * currentItem(){
          if(!isDone())
            return _it->second;
          else
            throw string("iterator is in the end!");
        }
        
      private:
        map<string,Node*>::iterator _it;
        Folder *_folder;
    };
    
    Folder(const char* path):Node(path){
      if(!S_ISDIR(getStat().st_mode))
        throw string("Type Error !!!  This is not a Folder");
    }

    void add(Node *node){
      _children.insert(pair<string,Node*>(node->name(),node));
      node->setParent(this);
    }

    int numberOfChildren() const{
      return _children.size();
    }

    void accept(NodeVisitor *nv){
      nv->clean();
      nv->visitFolder(this);
    }

    void acceptInner(NodeVisitor *nv){
      nv->visitFolder(this);
    }
    
    NodeIterator * createIterator(){
      return new FolderIterator(this);
    }
  private:
    map<string,Node *> _children;
};
#endif
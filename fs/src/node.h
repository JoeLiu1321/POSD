#ifndef NODE_H
#define NODE_H
#include <sys/stat.h>
#include <dirent.h>
#include <string>
#include <cstring>
#include <vector>
#include "null_iterator.h"
using namespace std;

class NodeVisitor;
class NodeIterator;
class Node{
public:
  Node(const char * path){
    setPath(path);
    if(lstat(_path, &_st)!=0)
      throw string("The path is not correspond!!!!!!!!");
    _parent=nullptr;  
  }
  virtual ~Node(){}
  
  virtual void accept(NodeVisitor *nv)=0;

  virtual void acceptInner(NodeVisitor *nv)=0;

  virtual NodeIterator * createIterator(){
    return new NullIterator();
  }

  virtual void add(Node *node){
    throw string("unable to add");
  }

  virtual int numberOfChildren() const{
    return 0;
  }

  Node * getParent() const{
    return _parent;
  }
  
  void setParent (Node * p){
    _parent=p;
  }

  int size() const{
    return _st.st_size;
  }

  string name(){
    string s(_path);
    int j=0;
    for(int i=s.size();i>0;i--){
      if(_path[i]=='/'){
        j=i+1;
        break;
      }
    }
    s=s.substr(j);
    return s;
  }

  string path(){
    string s(_path);
    return s;
  }

  void setPath(const char* path){
      _path=(char*)path;
  }

  struct stat getStat(){
    return _st;
  }

private:
  char* _path;
  struct stat _st;
  Node *_parent;
};

#endif

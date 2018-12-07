#ifndef NODE_H
#define NODE_H
#include <sys/stat.h>
#include <dirent.h>
#include <string>
#include <vector>
using namespace std;

class NodeVisitor;
class NodeIterator;
class Node{
public:
  Node(const char * path): _path(path){
    if(lstat(_path, &_st)!=0)
      throw string("The path is not correspond!!!!!!!!");
    _parent=nullptr;  
  }
  virtual ~Node(){}
  
  virtual void accept(NodeVisitor *nv)=0;

  virtual void acceptInner(NodeVisitor *nv)=0;

  virtual NodeIterator * createIterator(){
    return nullptr;
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
    int end=(j==0?s.size():s.size()-1);
    s=s.substr(j,end);
    return s;
  }

  string path(){
    string s(_path);
    return s;
  }

  struct stat getStat(){
    return _st;
  }

private:
  const char * _path;
  struct stat _st;
  Node *_parent;
};

#endif

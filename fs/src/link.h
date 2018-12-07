#ifndef LINK_H
#define LINK_H
#include "node.h"
#include "node_visitor.h"
#include <vector>
#include <sys/stat.h>
#include <string>
using namespace std;
class Link : public Node{
public:
  Link(const char * path, Node * node = nullptr) : Node(path){
    if(!S_ISLNK(getStat().st_mode))    
      throw string("Type Error !!This is not a Link");
    this->addLink(node);
  }

  void accept(NodeVisitor * nv){
    nv->clean();
    nv->visitLink(this);
    }

  void acceptInner(NodeVisitor *nv){
    nv->visitLink(this);
  }

  void addLink(Node * node){
    _source = node;
  }

  Node * getSource() {
    if(_source==nullptr)
      throw std::string("Null");
    return _source;
  }

private:
  Node * _source;
};

#endif

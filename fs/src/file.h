#ifndef FILE_H
#define FILE_H
#include <vector>
#include <sys/stat.h>
#include "node.h"
#include "node_visitor.h"
#include "null_iterator.h"
using namespace std;

class File: public Node{
  public:
    File(const char * path): Node(path){
      if(!S_ISREG(getStat().st_mode))
        throw string("Type Error !!This is not a File");
    }
    
    void accept(NodeVisitor *nv){
      nv->clean();
      nv->visitFile(this);
    }

    void acceptInner(NodeVisitor *nv){
      nv->visitFile(this);
    }

    NodeIterator * createIterator(){
      return new NullIterator();
    }
};

#endif

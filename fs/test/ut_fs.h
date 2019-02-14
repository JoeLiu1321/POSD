#ifndef UT_FS_H
#define UT_FS_H
#include "../src/folder.h"
#include "../src/file.h"
#include "../src/link.h"
#include "../src/info_content_visitor.h"
#include "../src/find_visitor.h"
#include "../src/find_link_visitor.h"
#include "../src/find_node_by_pathname_visitor.h"
#include "../src/set_path_visitor.h"
#include "../src/node_iterator.h"
#include "../src/node_builder.h"
#include <sys/stat.h>
#include <memory>
using namespace std;
TEST(FileSystemTest,setPath){
  NodeBuilder nb;
  nb.build("test_data");
  Node *test_data=nb.getRoot();
  Node* hello_cpp=new File("test_data/hello.cpp"); 
  SetPathVisitor *sv=new SetPathVisitor("test_data3");
  sv->setPath("test_data1");
  test_data->accept(sv);
  test_data->accept(sv);
  for(NodeIterator *it=test_data->createIterator();!it->isDone();it->next())
    cout<<"node:"<<it->currentItem()->name()<<"="<<it->currentItem()->path()<<endl;
}
#endif
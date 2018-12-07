#ifndef UT_FS_H
#define UT_FS_H
#include "../src/folder.h"
#include "../src/file.h"
#include "../src/link.h"
#include "../src/info_content_visitor.h"
#include "../src/find_visitor.h"
#include "../src/find_link_visitor.h"
#include "../src/find_node_by_pathname_visitor.h"
#include "../src/node_iterator.h"
#include "../src/node_builder.h"
#include <sys/stat.h>
#include <memory>
using namespace std;
// class FileSystemTest: public ::testing::Test
// {
// protected:
//   void SetUp() override
//   {
//     test_data = new Folder ("./test_data");
//     folder = new Folder("./test_data/folder");
//     hello_cpp = new File("./test_data/hello.cpp");
//     a_out = new File("./test_data/folder/a.out");
//     hello = new Link("./test_data/hello", a_out);
//     folder->add(a_out);
//     test_data->add(folder);
//     test_data->add(hello);
//     test_data->add(hello_cpp);
//   }

//   void TearDown() override
//   {
//     delete a_out;
//     delete hello_cpp;
//     delete hello;
//     delete folder;
//     delete test_data;
//   }

//   Node * test_data;
//   Node * folder;
//   Node * hello_cpp;
//   Node * a_out;
//   Node * hello;

// };

// TEST_F (FileSystemTest, NodeBuilderOnFile) {
//   NodeBuilder nb;
//   nb.build("test_data/hello.cpp");
//   ASSERT_EQ(144, nb.getRoot()->size());

//   nb.build("test_data/hello1");
//   ASSERT_EQ("hello1", nb.getRoot()->name());
 
//   nb.build("test_data/folder");
//   ASSERT_EQ("folder", nb.getRoot()->name());

//   std::unique_ptr<NodeIterator> it(nb.getRoot()->createIterator());
//   nb.build("test_data");
//   ASSERT_EQ("test_data", nb.getRoot()->name());
// }

// TEST_F (FileSystemTest, FindLinkVisitor) {
//     NodeBuilder nb;
//     nb.build("test_data");
//     Node *test_data=nb.getRoot();
//     FindLinkVisitor *flv=new FindLinkVisitor();
//     test_data->accept(flv);
//     ASSERT_EQ(4,flv->getLinks().size());
// }
// TEST_F(FileSystemTest , TypeError){
//   ASSERT_ANY_THROW(Node * makefile=new Folder("test_data/makefile"));
//   ASSERT_ANY_THROW(Node * test_data=new File("test_data"));
//   ASSERT_ANY_THROW(Node * folder=new Link("test_data/folder"));
//   ASSERT_ANY_THROW(Node * hello=new File("test_data/hello1"));
//   Node * makefile=new File("test_data/makefile");
// }
TEST(FileSystemTest , FindVisitor){
  NodeBuilder nb;
  nb.build("test_data");
  FindVisitor *fv=new FindVisitor("hello");

  nb.getRoot()->accept(fv);
  ASSERT_EQ("./hello",fv->findResult());
  
  fv->setTarget("a.out");
  nb.getRoot()->accept(fv);
  ASSERT_EQ("./folder/a.out\n./folder1/a.out",fv->findResult());
  
  fv->setTarget("makefile");
  nb.build("test_data/makefile");
  nb.getRoot()->accept(fv);
  ASSERT_EQ("makefile",fv->findResult());
  
  fv->setTarget("hello");
  nb.build("test_data/hello");
  nb.getRoot()->accept(fv);
  ASSERT_EQ("hello",fv->findResult());
  
}
TEST(FindNodeByPathnameVisitor, Link){
  Node * hello = new Link("./test_data/hello");
  vector<string>* names = new vector<string>{string("hello")};
  FindNodeByPathnameVisitor *fv=new FindNodeByPathnameVisitor(names);
  hello->accept(fv);
  ASSERT_EQ(hello, fv->getNode());
}
TEST(FindNodeByPathnameVisitor, LinkInFolder){
  Node * test_data = new Folder ("./test_data");
  Node * hello = new Link("./test_data/hello");
  test_data->add(hello);
  std::vector<string>* names = new vector<string>{string("test_data"),string("hello")};
  FindNodeByPathnameVisitor *fv=new FindNodeByPathnameVisitor(names);
  test_data->accept(fv);
  ASSERT_EQ(hello, fv->getNode());
}
TEST(FindNodeByPathnameVisitor, nonExistingFileInFileSystem){
  Node * test_data = new Folder ("./test_data");
  vector<string>* names = new vector<string>{string("test_data"),string("helloWorld")};
  FindNodeByPathnameVisitor *fv=new FindNodeByPathnameVisitor(names);
  test_data->accept(fv);
  ASSERT_EQ(nullptr, fv->getNode());
}
TEST(ParentNode, getParent){
  Node * test_data = new Folder ("./test_data");
  Node * folder=new Folder("./test_data/folder");
  test_data->add(folder);
  ASSERT_EQ(test_data, folder->getParent());
  ASSERT_EQ(nullptr, test_data->getParent());
}

#endif
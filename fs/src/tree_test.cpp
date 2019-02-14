#include <wx/wx.h>
#include "tree_test.h"
#include "tree_frame.h"
#include "node_observer.h"
using namespace std;
IMPLEMENT_APP(TreeTestApp)
bool TreeTestApp::OnInit()
{
  TreeFrame *frame = new TreeFrame(wxT("***Tree Test***"),50,100,1200,700);
  frame->Show(true);
  SetTopWindow(frame);
  Observer *renameOb=new FileObserver("fileObserver" , frame); 
  return true;
}

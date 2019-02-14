#ifndef TREE_FRAME_H
#define TREE_FRAME_H
#include <wx/treectrl.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include "node.h"
#include "node_builder.h"
#include "node_iterator.h"
#include "tree_node.h"
#include "observer.h"
using namespace std;
class TreeFrame : public wxFrame
{
public:
  TreeFrame(const wxChar *title, int xpos, int ypos, int width, int height):wxFrame((wxFrame *) nullptr, -1, title, wxPoint(xpos, ypos), wxSize(width, height)){
    _tree = new wxTreeCtrl(this, wxID_ANY, wxPoint(0,0), wxSize(500,800), wxTR_DEFAULT_STYLE | wxTR_SINGLE | wxTR_EDIT_LABELS );
    wxString input_name=wxGetApp().argv[1];
    char* root_name=new char[sizeof(input_name.mb_str())];
    strcpy(root_name,input_name);
    NodeBuilder nb;
    nb.build(root_name);
    Node *rootNode=nb.getRoot();
    createInputFrame();
    if(rootNode!=nullptr){
      wxTreeItemId rootId=_tree->AddRoot(buildNodeTitle(rootNode),-1,-1,new TreeNode(rootNode));
      buildTree(rootNode,rootId);
      _tree->ExpandAllChildren(rootId);
    }
    else
      _text->AppendText("Your path is inValid");
  }
  
  ~TreeFrame(){
    delete _tree;
    delete _text;
    delete _saveButton;
  }

  void attach(Observer *observer){
    _observers.insert(pair<string,Observer*>(observer->getKey(),observer));
  }

  void detach(Observer *observer){
    _observers[observer->getKey()]=nullptr;
  }

  void notify(string observerKey,wxTreeEvent &event){
    if(_observers[observerKey]==nullptr)
      throw string("TreeFrame::notify the null observer");
    else
      _observers[observerKey]->update(event);
  }

  void notify(string observerKey){
    if(_observers[observerKey]==nullptr)
      throw string("TreeFrame::notify the null observer");
    else
      _observers[observerKey]->update();
  }

  wxString buildNodeTitle(Node *node){
    wxString s(node->name()+" , "+to_string(node->size()));
    return s;
  }

  void buildTree(Node *root,wxTreeItemId rootId){
    for(NodeIterator *it=root->createIterator();!it->isDone();it->next()){
      wxTreeItemId childId=_tree->AppendItem(rootId,buildNodeTitle(it->currentItem()),-1,-1,new TreeNode(it->currentItem()));
      buildTree(it->currentItem(),childId);
    }
  }

  wxTreeItemData* getItemById(wxTreeItemId id){
    return _tree->GetItemData(id);
  }

  void createInputFrame(){
    _text= new wxTextCtrl(this, -1, _T(""),wxPoint(500,0), wxSize(705,600), wxTE_MULTILINE);
    _saveButton=new wxButton(this,saveButtonId, "save",wxPoint(500,510), wxSize(705,250),wxBU_EXACTFIT);
  }

  wxTextCtrl* getTextCtrl(){
    return _text;
  }

  Node* getSelectNode(){
    return _selNode;
  }

  void OnSelect(wxTreeEvent& event){
    wxTreeItemId id=event.GetItem();
    TreeNode *tn=dynamic_cast<TreeNode*>(_tree->GetItemData(id));
    _selNode=tn->getNode();
    createInputFrame(); 
    if(_selNode->numberOfChildren()>0)
      _text->AppendText("This file can't display because it is a folder !!!");
    else if(!_text->LoadFile(_selNode->path()))      
      _text->AppendText("The file is not displayed in the editor because it uses an unsupported text encoding.");
  }

   void OnRightClick(wxTreeEvent& event){
    _tree->EditLabel(event.GetItem());
  }

  void OnLabelEditEnd(wxTreeEvent& event){
    wxMessageDialog *dialog=new wxMessageDialog(this,"Click yes to rename","Are you sure to Rename?",wxYES_NO);
    if(!event.IsEditCancelled() && dialog->ShowModal()==wxID_YES)
      notify("fileObserver",event);
    else
      event.Veto();
  }

  void OnSaveClick(wxCommandEvent &event){
    wxMessageDialog *dialog=new wxMessageDialog(this,"Click yes to Save","Save file?",wxYES_NO);
    if(_selNode!=nullptr && _selNode->getParent()!=nullptr && dialog->ShowModal()==wxID_YES)
      notify("fileObserver");
  }

  enum{
    saveButtonId=wxID_HIGHEST+1
  };

private:
  map<string,Observer*> _observers;
  wxTreeCtrl *_tree;
  wxTextCtrl *_text;
  wxButton* _saveButton;
  Node* _selNode;
  DECLARE_EVENT_TABLE()

};

BEGIN_EVENT_TABLE(TreeFrame, wxFrame)
  EVT_TREE_SEL_CHANGED(wxID_ANY,TreeFrame::OnSelect)
  EVT_TREE_ITEM_RIGHT_CLICK(wxID_ANY,TreeFrame::OnRightClick)
  EVT_TREE_END_LABEL_EDIT (wxID_ANY, TreeFrame::OnLabelEditEnd)
  EVT_BUTTON(saveButtonId, TreeFrame::OnSaveClick)
END_EVENT_TABLE()
#endif

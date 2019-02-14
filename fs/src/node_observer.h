#ifndef NODE_OBSERVERS_H
#define NODE_OBSERVERS_H
#include "observer.h"
#include "tree_frame.h"
#include "tree_node.h"
#include "set_path_visitor.h"
#include "node.h"
#include <wx/treectrl.h>
#include <cstring>
class FileObserver:public Observer{
public:
    FileObserver(string key,TreeFrame* frame):Observer(key),_frame(frame){
        _frame->attach(this);
    }
    void update(wxTreeEvent &event){
        wxTreeItemId id=event.GetItem();
        TreeNode *tn=dynamic_cast<TreeNode*>(_frame->getItemById(id));
        Node* cur_node=tn->getNode();
        Node* parent_node=cur_node->getParent();
        if(parent_node!=nullptr){
            char *new_name=new char[sizeof(event.GetLabel().mb_str())];
            strcpy(new_name,event.GetLabel().mb_str());
            char* new_path=new char[parent_node->path().size()+sizeof(new_name)];
            char* old_path=new char[cur_node->path().size()];
            strcpy(old_path,cur_node->path().c_str());
            strcpy(new_path,parent_node->path().c_str());
            strcat(new_path,"/");
            strcat(new_path,new_name);
            if(rename(old_path,new_path)==0){
                SetPathVisitor *sv=new SetPathVisitor(new_path);
                cur_node->accept(sv);
            }
            else
                event.Veto();
        }
    }

    void update(){
        wxTextCtrl *text=_frame->getTextCtrl();
        text->SaveFile(_frame->getSelectNode()->path());
    }
private:
    TreeFrame* _frame;
};

#endif
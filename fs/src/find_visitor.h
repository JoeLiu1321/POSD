#ifndef find_Visitor_H
#define find_Visitor_H
#include <vector>
#include <string>
#include "node_visitor.h"
using namespace std;

class Node;
class File;
class Link;
class Folder;
class FindVisitor:public NodeVisitor{
    public:
        FindVisitor(string target):_target(target),_result(""){

        }
        
        void visitFile(File *file);
        
        void visitFolder(Folder *folder);

        void visitLink(Link *link);
        
        void clean(){
            _result="";
            _find.clear();
        }
        
        void setTarget(string target){
            _target=target;
        }
        
        string getTarget(){
            return _target;
        }
        
        void setResult(string result){
            _result=result;
        }
        
        string findResult(){
            string tmp=_result,s=(_find.size()==0 ? "" : _find.front()->path()+"/");
            for(int i=1 ; i < _find.size() ; i++){
                tmp=tmp+"./"+_find[i]->path().substr( s.size() , _find[i]->path().size()-s.size() );
                if(i!=_find.size()-1)
                    tmp+="\n";
            }
            return tmp;
        } 

    private:
        string _result,_target;    
        vector <Node*> _find;
    };
#endif
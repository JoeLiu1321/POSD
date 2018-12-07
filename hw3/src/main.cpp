#include <iostream>
#include <fstream>
#include <vector>
#include "shape.h"
#include "circle.h"
#include "triangle.h"
#include "rectangle.h"
#include "sort.h"
using namespace std;
enum type {circle,triangle,rectangle,other};
void readData(string file_path,vector<string> &name,vector<string> &attr){
    fstream in;
    in.open(file_path,ios::in);
    if(!in.is_open())
        return;
    string tmp1,tmp2;
    while(!in.eof()){
        in>>tmp1>>tmp2;
        name.push_back(tmp1);
        attr.push_back(tmp2);
    }  
}
void writeData(vector<Shape*>vec,string method,string file_path){
    fstream out;
    out.open(file_path,ios::out);
    if(!out.is_open())
        return;
    out<<"[";
    if(method=="area"){
        for(int i=0;i<vec.size();i++){
            out<<(vec[i]->area());
            if(i!=(vec.size()-1))
                out<<',';
        }
    }
    else if(method=="perimeter"){
        for(int i=0;i<vec.size();i++){
            out<<(vec[i]->perimeter());
            if(i!=(vec.size()-1))
                out<<',';
        }
    }
    else if(method=="compactness"){
        for(int i=0;i<vec.size();i++){
            out<<(vec[i]->compactness());
            if(i!=(vec.size()-1))
                out<<',';
        }
    }
    out<<"]";
}
void printAttr(vector<Shape*> vec,string attr){
    // cout<<"vector size = "<<vec.size()<<endl;
    if(attr=="area"){
        cout<<"print area : ";
        for(int i=0;i<vec.size();i++)
            cout<<vec[i]->area()<<" ";
    }
    else if(attr=="perimeter"){
        for(int i=0;i<vec.size();i++)
            cout<<vec[i]->perimeter()<<" ";
    }
    else if(attr=="compactness"){
        for(int i=0;i<vec.size();i++)
            cout<<vec[i]->compactness()<<" ";
    }
    cout<<endl;
}
void sortShape(vector<Shape*> &vec,string method,string order){
    Sort s(&vec);
    if(method.compare("area")==0){
        if(order.compare("dec")==0){
            s.sortArea(areaDescendingComparison);
        }
        else if(order.compare("inc")==0){
            s.sortArea(areaAscendingComparison);
        }
    }
    else if(method.compare("perimeter")==0){
        if(order.compare("dec")==0){
            s.sortPerimeter(perimeterDescendingComparison);
        }
        else if(order.compare("inc")==0){
            s.sortPerimeter(perimeterAscendingComparison);
        }
    }
    else if(method.compare("compactness")==0){
        if(order.compare("dec")==0){
            s.sortCompactness(compactnessDesc);
        }
        else if(order.compare("inc")==0){
            s.sortCompactness(compactnessAsc);
        }
    }

} 
vector<double> argFilter(string arg){
    string tmp=arg.substr(1,arg.size()-2);
    vector<double> v;
    for(int i=0,j=0;i<tmp.size();i++){
        if(tmp.at(i)==','){
            v.push_back(stod(tmp.substr(j,i-j)));
            j=i+1;
        }
        else if(i==tmp.size()-1)
            v.push_back(stod(tmp.substr(j,i-j+1)));      
    }
    return v;
}
void shapeHandler(string in_path,string out_path,string method,string order){
    vector<Shape*> vec;
    vector<double> arg;
    vector<string> name,attr;
    readData(in_path,name,attr);
    for(int i=0;i<name.size() && attr.size();i++){
        type t;
        if(name.at(i).compare("Circle")==0)
            t=circle;
        else if(name.at(i).compare("Triangle")==0)
            t=triangle;
        else if(name.at(i).compare("Rectangle")==0)
            t=rectangle;  
        else
            continue;
        arg=argFilter(attr.at(i));
        switch(t){
            case circle :
                if(arg.size()!=1)
                    break;
                vec.push_back(new Circle(arg[0]));
                break;
            case rectangle :
                if(arg.size()!=2)
                    break;
                vec.push_back(new Rectangle(arg[0],arg[1]));    
                break;
            case triangle :
                if(arg.size()!=6)
                    break;
                vec.push_back(new Triangle(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5]));    
                break;
            default :
                cout<<"Error format"<<endl;
                break;
        }
    }

    printAttr(vec,method);
    sortShape(vec,method,order);
    writeData(vec,method,out_path);
}
int main(int argc , char **argv){
    if(argc<5){
        cout<<"Arguments is too few!!"<<endl;
        return 0;
    }
    string input=argv[1],output=argv[2],method=argv[3],order=argv[4];  
    shapeHandler(input,output,method,order); 
    return 0;
}

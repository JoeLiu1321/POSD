#ifndef OBSERVER_H
#define OBSERVER_H
#include <string>
class wxTreeEvent;
class Observer{
public:
	Observer(string key):_key(key){

	}
	
	virtual void update(wxTreeEvent &event)=0;

	virtual void update()=0;
	
	string getKey(){
		return _key;
	}
private:
	string _key;
};
#endif
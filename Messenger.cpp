#include "Messenger.h"

Message::Message(){
    id=0;
    name="";
};

Message::Message(int _id, string _name){
    id=_id;
    name=_name;
};

void Messenger::addMessage(string name){    
    messages.push_back(Message(currentID, name));
    currentID+=1;
};

bool Messenger::pollMessage(Message* message){
    if (messages.size()>0){
        *message=messages.back();
        messages.pop_back();
        return true;
    }
    else return false;
};

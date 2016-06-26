#ifndef MESSENGER
#define MESSENGER

#include <vector>
#include <string>

using namespace std;

struct Message
{
    int id;
    string name; 
    Message(int _id, string _name);
    Message();
};

class Messenger{
    private:
        vector <Message> messages;
        int currentID=0;
    public:
        void addMessage(string name);
        bool pollMessage(Message* message);

};

#endif

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(void)
{
    int num_of_cmd;
    cin >> num_of_cmd;
    string cmd_list[num_of_cmd];
    for (int i = 0; i < num_of_cmd; i++)
    {
        cin >> cmd_list[i];
    }
}

class DoublyLinkedList
{
private:
    Element dummy;

public:
    DoublyLinkedList() {
        dummy.next = 0;
        dummy.prev = 0;
    }
    void cmd(string cmd_list) {
        if (cmd_list.find("insert") != string::npos)
        {
            int arg = stoi(getStringAfterN(cmd_list, " "));
            insert_x(arg);
            return
        }
        if (cmd_list.find("deleteFirst") != string::npos)
        {
            deleteFirst();
            return
        }
        if (cmd_list.find("deleteLast") != string::npos)
        {
            deleteLast();
            return
        }
        if (cmd_list.find("delete") != string::npos)
        {
            int arg = stoi(getStringAfterN(cmd_list, " "));
            delete_x(arg);
            return
        }
    }
    void insert_x(int x) {

    }
    void delete_x(int x) {

    }
    void deleteFirst() {

    }
    void deleteLast() {

    }
}

class Element
{
public:
    int data;
    Element* next;
    Element* prev;
}

string getStringAfterN(const string &s, char delim) {
    string elems;
    auto it = s.find(s.begin(), s.end(), delim);
    it++;
    while (it != s.end())
    {
        elems += *it
        it++;
    }
    return elems;
}
#include<iostream>
#include<string>
#include<vector>
using namespace std;

string getStringAfterN(const string &s, char delim);

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

class Element
{
public:
    int data;
    Element* next;
    Element* prev;
};

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
		Elements* insert_prev = &dummy;
		Elements* insert = new Elements();
		insert->data = x;
		insert->next = insert_prev->next;
		insert->prev = insert_prev;
		(insert_prev->next)->prev = insert;
		insert_prev->next = insert;
    }
    void delete_x(int x) {
		Elements* deleted = &dummmy;
		bool find_flag = false;
		while (deleted->next != &dummmy)
		{
			if (x == deleted->data)
			{
				find_flag = true;
				break;
			}
			deleted = deleted->next;
		}
		if (!find_flag)
			return
		Elements* deleted_prev = deleted->prev;
		deleted_prev->next = deleted->next;
		(deleted->next)->prev = deleted_prev;
		delete deleted
    }
    void deleteFirst() {
		delete_x((dummy.next)->data)
    }
    void deleteLast() {
		delete_x(dummy.data)
    }
};

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
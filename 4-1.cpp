#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string getStringAfterN(const string &s, char delim);

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
            int arg = stoi(getStringAfterN(cmd_list, ' '));
            insert_x(arg);
            return;
        }
        if (cmd_list.find("deleteFirst") != string::npos)
        {
            deleteFirst();
            return;
        }
        if (cmd_list.find("deleteLast") != string::npos)
        {
            deleteLast();
            return;
        }
        if (cmd_list.find("delete") != string::npos)
        {
            int arg = stoi(getStringAfterN(cmd_list, ' '));
            delete_x(arg);
            return;
        }
    }
    void insert_x(int x) {
		Element* insert_prev = &dummy;
		Element* insert = new Element();
		insert->data = x;
		insert->next = insert_prev->next;
		insert->prev = insert_prev;
		(insert_prev->next)->prev = insert;
		insert_prev->next = insert;
    }
    void delete_x(int x) {
		Element* deleted = &dummy;
		bool find_flag = false;
		while (deleted->next != &dummy)
		{
			if (x == deleted->data)
			{
				find_flag = true;
				break;
			}
			deleted = deleted->next;
		}
		if (!find_flag)
			return;
		Element* deleted_prev = deleted->prev;
		deleted_prev->next = deleted->next;
		(deleted->next)->prev = deleted_prev;
		delete deleted;
    }
    void deleteFirst() {
		delete_x((dummy.next)->data);
    }
    void deleteLast() {
		delete_x(dummy.data);
    }
	void print() {
		Element* it = dummy.next;
		while (it != dummy)
		{
			cout << it.data << " ";
			it = it.next;
		}
		cout << endl;
	}
};

int main(void)
{
    int num_of_cmd;
    cin >> num_of_cmd;
    string cmd_list[num_of_cmd];
    for (int i = 0; i < num_of_cmd; i++)
    {
        cin >> cmd_list[i];
    }
	DoublyLinkedList dll();
	for (int i = 0; i < num_of_cmd; i++)
	{
		dll.cmd(cmd_list[i]);
	}
	dll.print();
}

string getStringAfterN(const string &s, char delim) {
    string elems;
    auto it = find(s.begin(), s.end(), delim);
    it++;
    while (it != s.end())
    {
        elems += *it;
        it++;
    }
    return elems;
}
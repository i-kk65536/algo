#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Dictionary
{
private:
    struct Chain
    {
        string value;
        Chain* next;
        Chain(const string& v = "", Chain* n = nullptr) : value(v), next(n) {}
        ~Chain() { delete next; }
    };

    const int hash_list_size = 32768;

    vector<Chain> hash_list;

    int Hash(const string& value)
    {
        unsigned int hash_value = 0;
        for (char c : value)
        {
            hash_value = (hash_value + static_cast<unsigned int>(c)) % hash_list_size;
        }
        return hash_value;
    }
public:
    Dictionary() : hash_list(hash_list_size, Chain()) {}

    void insert(const string& key)
    {
        int hashed_key = Hash(key);
        Chain* cursor = &hash_list[hashed_key];

        if (cursor->value == "")
        {
            cursor->value = key;
        }
        else
        {
            while (cursor->next != nullptr)
            {
                cursor = cursor->next;
            }
            cursor->next = new Chain(key);
        }
    }

    string find(const string& key)
    {
        int hashed_key = Hash(key);
        Chain* cursor = &hash_list[hashed_key];

        while (cursor != nullptr)
        {
            if (cursor->value == key)
                return "yes";
            cursor = cursor->next;
        }
        return "no";
    }
};

int main()
{
    Dictionary dictionary;
    int command_size;
    cin >> command_size;

    for (int i = 0; i < command_size; i++)
    {
        string command;
        cin >> command;
        if (command == "insert")
        {
            string key;
            cin >> key;
            dictionary.insert(key);
        }
        else if (command == "find")
        {
            string key;
            cin >> key;
            cout << dictionary.find(key) << endl;
        }
    }
}
/*
String Hash Function
*/
#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 128;

// Linked List
class HashNode
{
public:
    string key;
    int value;
    HashNode *next;

    HashNode(string key, int value)
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
};

class HashTable
{
private:
    HashNode **table; // (Pointer to Pointer) Array of Linked List

public:
    // Initialisation of Array size
    HashTable()
    {
        table = new HashNode *[TABLE_SIZE]();
    }

    // hash function definition
    int hashFunction(string key)
    {
        int hash = 0;
        for (int i = 0; i < key.length(); i++)
        {
            hash = (hash + (int)key[i]) % TABLE_SIZE;
        }
        return hash;
    }

    // Insert
    void insert(string key, int value)
    {
        int hash = hashFunction(key);
        if (!table[hash])
        {
            table[hash] = new HashNode(key, value);
        }
        else
        {
            HashNode *entry = table[hash];
            while (entry->next)
            {
                entry = entry->next;
            }
            entry->next = new HashNode(key, value);
        }
    }

    // Search
    int search(string key)
    {
        int hash = hashFunction(key);
        if (table[hash])
        {
            HashNode *entry = table[hash];
            while (entry)
            {
                if (entry->key == key)
                {
                    return entry->value;
                }
                entry = entry->next;
            }
        }
        return -1;
    }
};

int main()
{
    HashTable ht;
    ht.insert("hello", 1);
    ht.insert("world", 2);
    cout << ht.search("hello") << endl;
    cout << ht.search("world") << endl;
    return 0;
}

/*
get(key): returns the value of the key if it already exists in the cache otherwise returns -1.
set(key, value): if the key is already present, update its value. If not present, add the key-value pair
                to the cache. If the cache reaches its capacity it should invalidate the least recently used item
                before inserting the new item.

Input: cap = 2, Q = 8, Queries = {SET 1 2, SET 2 3, SET 1 5, SET 4 5, SET 6 7, GET 4, SET 1 2, GET 3}
Output: 5 -1
Explanation:
Cache Size = 2
- SET 1 2 : {1->2}
- SET 2 3 : {2->3}->{1->2} (the most recently used one is kept at the rightmost position)
- SET 1 5 : {1->5}->{2->3}
- SET 4 5 : {4->5}->{1->5} (Cache size is 2, hence we delete the least recently used key-value pair)
- SET 6 7 : {6->7}->{4->5}
- GET 4 : Prints 5 (The cache now looks like 6 -> 7, 4->5)
- SET 1 2 : {1->2}->{6->7} (Cache size is 2, hence we delete the least recently used key-value pair)
- GET 3 : No key value pair having key = 3. Hence, -1 is printed.
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key, val;
    Node *prev;
    Node *next;

    Node(int k, int v)
    {
        key = k, val = v;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache
{
private:
    unordered_map<int, Node *> mp;
    int max_cap;
    int curr_sz;

    // these two extra nodes dummyHead, dummyTail always remain intact to list.
    // These dummy nodes helps to encounter edge cases in better way for deletion and insertion operations.
    Node *dummyHead;
    Node *dummyTail;

public:
    // initialising capacity, dummyHead-dummyTail pointer with their links, with curr_sz implying current size of cache
    LRUCache(int cap)
    {
        dummyHead = new Node(-1, -1);
        dummyTail = new Node(-1, -1);

        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;

        max_cap = cap;
        curr_sz = 0;
    }

    // O(1) => deletes the node from cache
    void delNode(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // O(1) => updates the cache after dummyHead
    void addToHead(Node *node)
    {
        node->next = dummyHead->next;
        node->next->prev = node;

        dummyHead->next = node;
        node->prev = dummyHead;
    }

    // O(1) => returns the value of the key if it already exists in the cache otherwise returns -1.
    // Also updates the LRU cache, if key exists in the cache.
    int get(int key)
    {
        if (mp.find(key) == mp.end())
        {
            return -1;
        }

        Node *node = mp[key];
        int value = node->val;

        delNode(node);
        addToHead(node);

        return value;
    }

    /*
    O(1) => if the key is already present, update its value. If not present, add the key-value pair
    to the cache. If the cache reaches its capacity it should invalidate the least recently used item
    before inserting the new item.
    */
    void set(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            Node *node = mp[key];
            mp[key]->val = value;

            delNode(node);
            addToHead(node);
        }
        else
        {
            Node *newNode = new Node(key, value);
            mp[key] = newNode;

            if (curr_sz == max_cap)
            {
                mp.erase(dummyTail->prev->key);
                delNode(dummyTail->prev);
                addToHead(newNode);
            }
            else
            {
                addToHead(newNode);
                curr_sz++;
            }
        }
    }
};

int main()
{

    LRUCache cache(2);

    cache.set(1, 2);
    cache.set(2, 3);
    cache.set(1, 5);
    cache.set(4, 5);
    cout << cache.get(4) << " ";
    cache.set(6, 7);
    cout << cache.get(3);
    cache.set(1, 2);

    return 0;
}
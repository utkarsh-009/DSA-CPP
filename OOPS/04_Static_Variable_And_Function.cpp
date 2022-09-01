#include <bits/stdc++.h>
using namespace std;

class Player
{
public:
    static int count;     // Static Variable
    Player() { count++; } // Whenever object is created => we increment the count
    ~Player() { count--; }

    static int getCount() // Static Function
    {
        return count;
    }
};

int Player::count = 0; // It is recommended to define static data member outside the class

int main()
{
    Player p1;
    cout << Player::count << endl; //  OR  cout << p1.count << endl;

    Player p2;
    cout << Player::count << endl; //  OR  cout << p2.count << endl;

    cout << Player::getCount() << endl; // Using static function

    {
        Player p3;                // Object is Created
        cout << p3.count << endl; //  OR  cout << Player::count << endl;
    }

    // Object is destroyed outside the scope
    cout << Player::count << endl;
}

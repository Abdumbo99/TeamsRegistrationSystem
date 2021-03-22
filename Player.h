#ifndef __PLAYER_H
#define __PLAYER_H
#include <string>
using namespace std;

class Player
{
public:
    Player(const string PlayerName = "", const string PlayerPosition = "");
    Player(const Player &PlayerToCopy);
    ~Player();
    void operator=(const Player &right);
    friend ostream &operator<<(ostream &out, const Player &p);
    string getName() const;
    string getPosition() const;

private:
    string name;
    string position;
};
#endif
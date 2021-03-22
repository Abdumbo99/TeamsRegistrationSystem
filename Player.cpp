#include "Player.h"
#include <string>
using namespace std;
#include <iostream>

Player::Player(const string PlayerName, const string PlayerPosition)
{
    name = PlayerName;
    position = PlayerPosition;
}

Player::Player(const Player &PlayerToCopy)
{
    name = PlayerToCopy.getName();
    position = PlayerToCopy.getPosition();
}

Player::~Player()
{
    // cout <<  "Player object has ben deleted";
}

void Player::operator=(const Player &right)
{
    name = right.getName();
    position = right.getPosition();
}

ostream &operator<<(ostream &output, const Player &p)
{
    output << p.name << ",\t" << p.position;
    return output;
}

string Player::getName() const
{
    return name;
}

string Player::getPosition() const
{
    return position;
}
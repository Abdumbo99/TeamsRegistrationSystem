#ifndef __TEAM_H
#define __TEAM_H
#include <string>
#include "Player.h"
using namespace std;

class Team
{
public:
    Team(const string TeamName = "", const string TeamColor = "", const int FoundingYear = 0);
    Team(const Team &TeamToCopy);
    ~Team();
    void operator=(const Team &right);
    bool operator==(const Team &right);
    Player operator[](int i) const;
    friend ostream &operator<<(ostream &out, const Team &t);
    void addPlayer(string playerName = "", string playerPosition = "");
    void removePlayer(const string playerName);
    string getName() const;
    string getColor() const;
    int getFoundingYear() const;
    int getPlayerCount() const;
    void displayAllPlayers() const;
    bool hasPlayer(string playerName) const;
    string getPlayersPosition(const string playerName) const;
    bool compareStrings(const string &a, const string &b) const;

private:
    // Team properties
    string name;
    string color;
    int foundingYear;

    // Players linked list
    struct Node
    {
        Player p;
        Node *next;
    };
    Node *head;
    int playerCount;
};
#endif
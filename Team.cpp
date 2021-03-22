#include "Team.h"
#include <string>
using namespace std;
#include <iostream>
#include <algorithm>

Team::Team(const string TeamName, const string TeamColor, const int FoundingYear)
{
    name = TeamName;
    color = TeamColor;
    foundingYear = FoundingYear;
    head = NULL;
    playerCount = 0;
}

Team::Team(const Team &TeamToCopy)
{
    name = TeamToCopy.getName();
    color = TeamToCopy.getColor();
    foundingYear = TeamToCopy.getFoundingYear();
    head = NULL;
    playerCount = 0;
    for (int i = 0; i < TeamToCopy.getPlayerCount(); i++)
    {
        Player ithPlayer = TeamToCopy[i];
        if (ithPlayer.getName() != "")
            addPlayer(ithPlayer.getName(), ithPlayer.getPosition());
    }
}

Team::~Team()
{
    Node *n = head, *current = NULL; // initialization part

    while (n) // start cleanup of nodes of the list
    {
        current = n;
        n = n->next;
        delete (current);
    }

    head = NULL;
}

void Team::operator=(const Team &right)
{
    // in assignment overload first delete all previous players
    // and then add new players
    Node *n = head, *current = NULL; // initialization part

    while (n) // start cleanup of nodes of the list
    {
        current = n;
        n = n->next;
        delete (current);
    }

    name = right.getName();
    color = right.getColor();
    foundingYear = right.getFoundingYear();
    head = NULL;
    playerCount = 0;
    for (int i = 0; i < right.getPlayerCount(); i++)
    {
        Player ithPlayer = right[i];
        if (ithPlayer.getName() != "")
            addPlayer(ithPlayer.getName(), ithPlayer.getPosition());
    }
}

bool Team::operator==(const Team &right)
{
    return compareStrings(right.getName(), name);
    // TO-DO: add players comparison
}

Player Team::operator[](int i) const
{
    Node *current = new Node;
    current = head;
    int counter = 0;
    while (counter < i && current != NULL)
    {
        counter++;
        current = current->next; //getting the next element
    }
    return current->p;
}

ostream &operator<<(ostream &output, const Team &t)
{   output << "Displaying team info: "<<endl;
    output << t.name << ", " << t.color << ", " << t.foundingYear << endl;
    output << "---------"
           << "Players" << "---------" << endl;
    t.displayAllPlayers();
    output <<endl;
    return output;
}

void Team::addPlayer(string playerName, string playerPosition)
{
    bool playerExists = false;
    Node *current = new Node;
    current = head;

    while (current != NULL)
    {
        if (compareStrings(current->p.getName(), playerName))
            playerExists = true;
        current = current->next;
    }

    if (playerExists)
    {
        cout << "Player " << playerName << " already exist, thus can't be added." << endl;
    }
    else
    {
        Node *temp = new Node;
        temp->p = Player(playerName, playerPosition);
        temp->next = head;
        head = temp;
        playerCount++;
    }
}

void Team::removePlayer(const string playerName)
{
    Node *current = new Node;
    Node *previous = new Node;
    current = head;

    // If head node itself holds the player
    if (current != NULL && compareStrings(current->p.getName(), playerName))
    {
        head = current->next;
        playerCount--;
        return;
    }

    // Search for the player, keep track of the previous node
    // as we need to change ->next to unlink from current node

    while (current != NULL && !compareStrings(current->p.getName(), playerName))
    {
        previous = current;
        current = current->next;
    }

    // If key was not present in linked list
    if (current == NULL)
    {
        cout << "Player " << playerName << " doesn't exist, thus can't be deleted." << endl;
        return;
    }

    previous->next = current->next;
    playerCount--;
}

string Team::getName() const
{
    return name;
}

string Team::getColor() const
{
    return color;
}

int Team::getFoundingYear() const
{
    return foundingYear;
}

int Team::getPlayerCount() const
{
    return playerCount;
}

void Team::displayAllPlayers() const
{
    Node *current = head; //Initialize current
    if (current == NULL)
    {
        cout << "\t"
             << "--EMPTY--" << endl;
    }
    else
    {
        while (current != NULL)
        {
            cout << current->p << endl;
            current = current->next;
        }
    }
}

bool Team::hasPlayer(string playerName) const
{
    bool result = false;
    Node *current = head;

    while (current != NULL)
    {
        if (compareStrings(current->p.getName(), playerName))
            result = true;
        current = current->next;
    }

    return result;
}

string Team::getPlayersPosition(const string playerName) const
{
    string result = "";
    Node *current = head;

    while (current != NULL)
    {
        if (compareStrings(current->p.getName(), playerName))
            result = current->p.getPosition();
        current = current->next;
    }
    return result;
}

bool Team::compareStrings(const string &a, const string &b) const
{
    unsigned int sz = a.size();
    if (b.size() != sz)
        return false;
    for (unsigned int i = 0; i < sz; ++i)
        if (tolower(a[i]) != tolower(b[i]))
            return false;
    return true;
}
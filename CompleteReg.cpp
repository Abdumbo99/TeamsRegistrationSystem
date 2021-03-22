#include "CompleteReg.h"
#include <string>
using namespace std;
#include <iostream>

CompleteReg::CompleteReg()
{
    head = NULL;
    teamCount = 0;
}

CompleteReg::~CompleteReg()
{
    Node *n = this->head, *current = NULL; // initialization part

    while (n) // start cleanup of nodes of the list
    {
        current = n;
        n = n->next;
        current->next = NULL;
        delete (current);
    }

    head = NULL;
}

CompleteReg::CompleteReg(const CompleteReg &systemToCopy)
{
    head = NULL;
    teamCount = 0;
    Node *temp;
    for (int i = 0; i < systemToCopy.getTeamCount(); i++)
    {
        temp = new Node;
        temp->t = systemToCopy.getTeam(i);
        temp->next = head;
        head = temp;
        teamCount++;
    }
}

CompleteReg &CompleteReg::operator=(const CompleteReg &right)
{
    head = NULL;
    teamCount = 0;
    Node *temp;
    for (int i = 0; i < right.getTeamCount(); i++)
    {
        temp = new Node;
        temp->t = right.getTeam(i);
        temp->next = head;
        head = temp;
        teamCount++;
    }
    return *this;
}

Team CompleteReg::operator[](const int index)
{
    Node *current = new Node;
    current = head;
    int counter = 0;
    while (counter < index && current != NULL)
    {
        counter++;
        current = current->next; //getting the next element
    }
    return current->t;
}

void CompleteReg::addTeam(const string tName, const string tColor, const int tyear)
{
    bool teamExists = false;
    Node *current = new Node;
    current = head;

    while (current != NULL)
    {
        if (compareStrings(current->t.getName(), tName))
            teamExists = true;
        current = current->next;
    }

    if (teamExists)
    {
        cout << "Team " << tName << " already exist, thus can't be added." << endl<<endl;
    }
    else
    {
        Node *temp = new Node;
        temp->t = Team(tName, tColor, tyear);
        temp->next = head;
        head = temp;
        teamCount++;
    }
}

void CompleteReg::removeTeam(const string teamName)
{
    Node *current = new Node;
    Node *previous = new Node;
    current = head;

    // If head node itself holds the team
    if (current != NULL && compareStrings(current->t.getName(), teamName))
    {
        head = current->next;
        teamCount--;
        return;
    }

    // Search for the team, keep track of the previous node
    // as we need to change ->next to unlink from current node

    while (current != NULL && !compareStrings(current->t.getName(), teamName))
    {
        previous = current;
        current = current->next;
    }

    // If key was not present in linked list
    if (current == NULL)
    {
        cout << "Team " << teamName << " doesn't exist, thus can't be deleted." << endl<<endl;
        return;
    }

    previous->next = current->next;
    teamCount--;
}

void CompleteReg::displayAllTeams() const
{
    Node *current = head; // Initialize current
    cout << "Displaying all teams: " << endl;
    if (current == NULL)
    {
        cout << "--EMPTY--" << endl;
    }
    else
    {
        while (current != NULL)
        {
            cout << current->t.getName() << ", "
                 << current->t.getColor() << ", "
                 << current->t.getFoundingYear() << endl;
            current = current->next;
        }
    }
    cout <<endl;
}

void CompleteReg::addPlayer(const string tName, const string pName, const string pPosition)
{
    // check if team exists
    bool teamExists = false;
    // no need to check if player exists because Team::addPlayer already does that

    Node *current = head; // Initialize current

    while (current != NULL)
    {
        if (compareStrings(current->t.getName(), tName))
        {
            teamExists = true;
        }
        current = current->next;
    }

    // if team exists add the player if not print warning
    if (teamExists)
    {
        Node *current = head;
        while (current != NULL)
        {
            if (compareStrings(current->t.getName(), tName))
                current->t.addPlayer(pName, pPosition);
            current = current->next;
        }
    }
    else
        cout << "Team " << tName << "doesn't exist" << endl;
}

void CompleteReg::removePlayer(const string teamName, const string playerName)
{
    // check if team exists
    bool teamExists = false;
    // no need to check if player exists because Team::removePlayer already does that

    Node *current = head; // Initialize current

    while (current != NULL)
    {
        if (compareStrings(current->t.getName(), teamName))
        {
            teamExists = true;
        }
        current = current->next;
    }

    // if team exists remove player the player if not print warning
    if (teamExists)
    {
        Node *current = head;
        while (current != NULL)
        {
            if (compareStrings(current->t.getName(), teamName))
                current->t.removePlayer(playerName);
            current = current->next;
        }
    }
    else
        cout << "Team " << teamName << "doesn't exist" << endl;
}

void CompleteReg::displayTeam(const string teamName) const
{
    // check if team exists
    bool teamExists = false;
    // no need to check if player exists because Team::removePlayer already does that

    Node *current = head; // Initialize current

    while (current != NULL)
    {
        if (compareStrings(current->t.getName(), teamName))
        {
            teamExists = true;
            cout << current->t << endl;
        }
        current = current->next;
    }

    if (!teamExists)
        cout << "Team " << teamName << "does not exist" << endl;
}

void CompleteReg::displayPlayer(const string playerName) const
{
    // check if team exists
    bool playerExists = false;
    // no need to check if player exists because Team::removePlayer already does that

    Node *current = head; // Initialize current

    cout << playerName << " is in the following teams: "<< endl;

    while (current != NULL)
    {
        if (current->t.hasPlayer(playerName))
        {
            playerExists = true;
            cout << current->t.getPlayersPosition(playerName)
                 << ", " << current->t.getName() << ", "
                 << current->t.getColor() << ", "
                 << current->t.getFoundingYear() << endl;
        }
        current = current->next;
    }

    if (!playerExists)
        cout << " --EMPTY-- " << endl;
    cout << endl;
}

int CompleteReg::getTeamCount() const
{
    return teamCount;
}

Team CompleteReg::getTeam(int i) const
{
    Node *current = new Node;
    current = head;
    int counter = 0;
    while (counter < i && current != NULL)
    {
        counter++;
        current = current->next; //getting the next element
    }
    return current->t;
}

bool CompleteReg::compareStrings(const string &a, const string &b) const
{
    unsigned int sz = a.size();
    if (b.size() != sz)
        return false;
    for (unsigned int i = 0; i < sz; ++i)
        if (tolower(a[i]) != tolower(b[i]))
            return false;
    return true;
}
#include "CompleteReg.h"
#include <iostream>

int main()
{

    CompleteReg cr;

    cr.displayAllTeams();
    

    cr.addTeam("Bilkent", "red", 2001);
    cr.addPlayer("Bilkent", "malik", "front");
    cr.removePlayer("Bilkent", "Malik");

    cr.displayTeam("Bilkent");

    cr.addTeam("ODTU", "greed", 1899);
    cr.addTeam("ITU", "blue", 1923);
    cr.addPlayer("ODTU", "malik", "front");
    cr.addPlayer("ITU", "malik", "front");

    cr.displayPlayer("malik");

    cr.addTeam("Koc", "gray", 1975);
    cr.addTeam("Koc", "red", 1111);
    

    cr.displayAllTeams();


    cr.removeTeam("ODTU");
    cr.removeTeam("Koc");
    cr.removeTeam("Sabanci");
    

    cout << "*************************" << endl;
    cout << " --CR-- " << endl;
    cr.displayAllTeams();
    

    cout << "*************************" << endl;
    cout << " --ECR-- " << endl;
    CompleteReg ecr = cr;
    ecr.displayAllTeams();
    ecr.addPlayer("bilkent", "moha", "Keeper");
    ecr.addPlayer("itu", "mohammed", "Keeper");
    ecr.displayTeam("bilkent");
    ecr.displayTeam("itu");
    ecr.removePlayer("bilkent", "moha");
    ecr.displayTeam("bilkent");

    return 0;
}

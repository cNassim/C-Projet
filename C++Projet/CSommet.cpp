#include "CSommet.h"
#include <iostream>

using namespace std;

// Constructeur par défaut
CSommet::CSommet() : uiSOMId(0) {}

// Constructeur de comfort
CSommet::CSommet(int iId, const vector<CArc*> &partant, const vector<CArc*> &entrant)
    : uiSOMId(iId), ARCPartant(partant), ARCEntrant(entrant) {
}

// Constructeur de recopie
CSommet::CSommet(const CSommet& Sommet)
    : uiSOMId(Sommet.uiSOMId), ARCPartant(Sommet.ARCPartant), ARCEntrant(Sommet.ARCEntrant) {
}

// Destructeur
CSommet::~CSommet() {
    ARCPartant.clear();
    ARCEntrant.clear();
}

// Getter du numéro de sommet
unsigned int CSommet::SOMGet_Id() {
    return uiSOMId;
}

// Setter de numéro de sommet
void CSommet::SOMSet_Id(unsigned int iId) {
    uiSOMId = iId;
}

// Ajouter un arc partant
void CSommet::SOMAjouterArcPartant(CArc* ArcPartant) {
    ARCPartant.push_back(ArcPartant);
}

// Ajouter un arc sortant
void CSommet::SOMAjouterArcSortant(CArc* ArcSortant) {
    ARCEntrant.push_back(ArcSortant);
}

//Getter Arc partant
vector<CArc*>CSommet::SOMGet_ARCPartant() {
    return ARCPartant;
}

//Getter Arc sortant
vector<CArc*>CSommet::SOMGet_ARCSortant() {
    return ARCEntrant;
}

void CSommet::SOMModifierArcPartant(unsigned int iIdArc, CArc* ArcPartant) {
    
}


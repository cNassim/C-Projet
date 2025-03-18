#include "CSommet.h"
#include <iostream>

using namespace std;
/***********************************************************
/* CSommet
/************************************************************
/* Entrée : Rien
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : Les attributs de CSommet sont initialisés à NULL
/************************************************************/
CSommet::CSommet() : uiSOMId(0) {}

/***********************************************************
/* CSommet
/************************************************************
/* Entrée : iId : La valeur avec laquelle iSOMId sera initialisé
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : Les attributs de CSommet sont initialisés avec des valeurs données
/************************************************************/
CSommet::CSommet(int iId, const vector<CArc*> &partant, const vector<CArc*> &entrant)
    : uiSOMId(iId), ARCPartant(partant), ARCEntrant(entrant) {
}


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


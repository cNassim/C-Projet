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
CSommet::CSommet(int iId, const vector<CArc*> partant, const vector<CArc*> entrant)
    : uiSOMId(iId), ARCPartant(partant), ARCEntrant(entrant) {
}

/***********************************************************
/* CSommet
/************************************************************
/* Entrée : Sommet : Un objet de la classe CSommet
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : Les attributs de CSommet sont initialisés avec les valeurs de l'objet Sommet
/************************************************************/
CSommet::CSommet(const CSommet& Sommet)
    : uiSOMId(Sommet.uiSOMId), ARCPartant(Sommet.ARCPartant), ARCEntrant(Sommet.ARCEntrant) {
}

/***********************************************************
/* ~CSommet
/************************************************************
/* Entrée : Rien
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : Le sommet est détruit et libéré
/************************************************************/
CSommet::~CSommet() {
    ARCPartant.clear();
    ARCEntrant.clear();
}

/***********************************************************
/* SOMGet_Id
/************************************************************
/* Entrée : Rien
/* Nécessite : Rien
/* Sortie : La valeur de iSOMId
/* Entraîne : Rien
/************************************************************/
unsigned int CSommet::SOMGet_Id() {
    return uiSOMId;
}

/***********************************************************
/* SOMSet_Id
/************************************************************
/* Entrée : iId : Nouvelle valeur pour iSOMId
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : iSOMId est mis à jour
/************************************************************/
void CSommet::SOMSet_Id(unsigned int iId) {
    uiSOMId = iId;
}

/***********************************************************
/* SOMAjouterArcPartant
/************************************************************
/* Entrée : ArcPartant : Pointeur vers un objet CArc
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : Ajoute un arc partant à la liste ARCPartant
/************************************************************/
void CSommet::SOMAjouterArcPartant(CArc* ArcPartant) {
    ARCPartant.push_back(ArcPartant);
}

/***********************************************************
/* SOMAjouterArcSortant
/************************************************************
/* Entrée : ArcSortant : Pointeur vers un objet CArc
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : Ajoute un arc sortant à la liste ARCEntrant
/************************************************************/
void CSommet::SOMAjouterArcSortant(CArc* ArcSortant) {
    ARCEntrant.push_back(ArcSortant);
}

/***********************************************************
/* SOMGet_ARCPartant
/************************************************************
/* Entrée : Rien
/* Nécessite : Rien
/* Sortie : La liste des arcs partants
/* Entraîne : Rien
/************************************************************/
vector<CArc*>CSommet::SOMGet_ARCPartant() {
    return ARCPartant;
}

/***********************************************************
/* SOMGet_ARCSortant
/************************************************************
/* Entrée : Rien
/* Nécessite : Rien
/* Sortie : La liste des arcs sortants
/* Entraîne : Rien
/************************************************************/
vector<CArc*>CSommet::SOMGet_ARCSortant() {
    return ARCEntrant;
}

/***********************************************************
/* SOMModifierArcPartant
/************************************************************
/* Entrée : iIdArc : Identifiant de l'arc
/*          ArcPartant : Pointeur vers un objet CArc
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : Modifie un arc partant dans la liste ARCPartant
/************************************************************/
void CSommet::SOMModifierArcPartant(unsigned int iIdArc, CArc* ArcPartant) {
    for (auto& arc : ARCPartant) {
        if (arc->ARCGet_IdArc() == iIdArc) {
            arc = ArcPartant;
            return;
        }
    }
}

/***********************************************************
/* SOMModifierArcSortant
/************************************************************
/* Entrée : iIdArc : Identifiant de l'arc
/*          ArcSortant : Pointeur vers un objet CArc
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : Modifie un arc sortant dans la liste ARCEntrant
/************************************************************/
void CSommet::SOMModifierArcEntrant(unsigned int iIdArc, CArc* ArcEntrant) {
    for (auto& arc : ARCEntrant) {
        if (arc->ARCGet_IdArc() == iIdArc) {
            arc = ArcEntrant;
            return;
        }
    }
}

/***********************************************************
/* SOMSupprimerArcPartant
/************************************************************
/* Entrée : iIdArc : Identifiant de l'arc
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : Supprime un arc partant de la liste ARCPartant
/************************************************************/
void CSommet::SOMSupprimerArcPartant(unsigned int iIdArc) {
    for (auto it = ARCPartant.begin(); it != ARCPartant.end(); ++it) {
        if ((*it)->ARCGet_IdArc() == iIdArc) {
            ARCPartant.erase(it);
            return;
        }
    }
    }

/***********************************************************
/* SOMSupprimerArcSortant
/************************************************************
/* Entrée : iIdArc : Identifiant de l'arc
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : Supprime un arc sortant de la liste ARCEntrant
/************************************************************/
void CSommet::SOMSupprimerArcEntrant(unsigned int iIdArc) {
    for (auto it = ARCEntrant.begin(); it != ARCEntrant.end(); ++it) {
        if ((*it)->ARCGet_IdArc() == iIdArc) {
            ARCEntrant.erase(it);
            return;
        }
    }
}

/***********************************************************
/* SOMAfficher
/************************************************************
/* Entrée : Rien
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : Affiche les informations du sommet
/************************************************************/
void CSommet::SOMAfficher() {}



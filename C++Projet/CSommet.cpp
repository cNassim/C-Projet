#include "CSommet.h"
#include <iostream>


using namespace std;
/***********************************************************
/* CSommet
/************************************************************
/* Entr�e : Rien
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : Les attributs de CSommet sont initialis�s � NULL
/************************************************************/
CSommet::CSommet() : uiSOMId(0) {}

/***********************************************************
/* CSommet
/************************************************************
/* Entr�e : iId : La valeur avec laquelle iSOMId sera initialis�
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : Les attributs de CSommet sont initialis�s avec des valeurs donn�es
/************************************************************/
CSommet::CSommet(int iId, const vector<CArc*> partant, const vector<CArc*> entrant)
    : uiSOMId(iId), ARCPartant(partant), ARCEntrant(entrant) {
}

/***********************************************************
/* CSommet
/************************************************************
/* Entr�e : Sommet : Un objet de la classe CSommet
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : Les attributs de CSommet sont initialis�s avec les valeurs de l'objet Sommet
/************************************************************/
CSommet::CSommet(const CSommet& Sommet)
    : uiSOMId(Sommet.uiSOMId), ARCPartant(Sommet.ARCPartant), ARCEntrant(Sommet.ARCEntrant) {
}

/***********************************************************
/* ~CSommet
/************************************************************
/* Entr�e : Rien
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : Le sommet est d�truit et lib�r�
/************************************************************/
CSommet::~CSommet() {
    ARCPartant.clear();
    ARCEntrant.clear();
}

/***********************************************************
/* SOMGet_Id
/************************************************************
/* Entr�e : Rien
/* N�cessite : Rien
/* Sortie : La valeur de iSOMId
/* Entra�ne : Rien
/************************************************************/
unsigned int CSommet::SOMGet_Id() {
    return uiSOMId;
}

/***********************************************************
/* SOMSet_Id
/************************************************************
/* Entr�e : iId : Nouvelle valeur pour iSOMId
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : iSOMId est mis � jour
/************************************************************/
void CSommet::SOMSet_Id(unsigned int iId) {
    uiSOMId = iId;
}

/***********************************************************
/* SOMAjouterArcPartant
/************************************************************
/* Entr�e : ArcPartant : Pointeur vers un objet CArc
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : Ajoute un arc partant � la liste ARCPartant
/************************************************************/
void CSommet::SOMAjouterArcPartant(CArc* ArcPartant) {
    ARCPartant.push_back(ArcPartant);
}

/***********************************************************
/* SOMAjouterArcSortant
/************************************************************
/* Entr�e : ArcSortant : Pointeur vers un objet CArc
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : Ajoute un arc sortant � la liste ARCEntrant
/************************************************************/
void CSommet::SOMAjouterArcSortant(CArc* ArcSortant) {
    ARCEntrant.push_back(ArcSortant);
}

/***********************************************************
/* SOMGet_ARCPartant
/************************************************************
/* Entr�e : Rien
/* N�cessite : Rien
/* Sortie : La liste des arcs partants
/* Entra�ne : Rien
/************************************************************/
vector<CArc*>CSommet::SOMGet_ARCPartant() {
    return ARCPartant;
}

/***********************************************************
/* SOMGet_ARCSortant
/************************************************************
/* Entr�e : Rien
/* N�cessite : Rien
/* Sortie : La liste des arcs sortants
/* Entra�ne : Rien
/************************************************************/
vector<CArc*>CSommet::SOMGet_ARCSortant() {
    return ARCEntrant;
}

/***********************************************************
/* SOMModifierArcPartant
/************************************************************
/* Entr�e : iIdArc : Identifiant de l'arc
/*          ArcPartant : Pointeur vers un objet CArc
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : Modifie un arc partant dans la liste ARCPartant
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
/* Entr�e : iIdArc : Identifiant de l'arc
/*          ArcSortant : Pointeur vers un objet CArc
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : Modifie un arc sortant dans la liste ARCEntrant
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
/* Entr�e : iIdArc : Identifiant de l'arc
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : Supprime un arc partant de la liste ARCPartant
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
/* Entr�e : iIdArc : Identifiant de l'arc
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : Supprime un arc sortant de la liste ARCEntrant
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
/* Entr�e : Rien
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : Affiche les informations du sommet
/************************************************************/
void CSommet::SOMAfficher() {}



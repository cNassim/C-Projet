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
template <typename T>
CSommet<T>::CSommet() : uiSOMId(0) {}

/***********************************************************
/* CSommet
/************************************************************
/* Entr�e : uiId : La valeur avec laquelle iSOMId sera initialis�
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : Les attributs de CSommet sont initialis�s avec des valeurs donn�es
/************************************************************/
template <typename T>
CSommet<T>::CSommet(unsigned int uiId, const vector<CArc<T>*> pPartant, const vector<CArc<T>*> pEntrant)
    : uiSOMId(uiId), ARCPartant(pPartant), ARCEntrant(pEntrant) {
}

/***********************************************************
/* CSommet
/************************************************************
/* Entr�e : Sommet : Un objet de la classe CSommet
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : Les attributs de CSommet sont initialis�s avec les valeurs de l'objet Sommet
/************************************************************/
template <typename T>
CSommet<T>::CSommet(const CSommet<T>& Sommet)
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
template <typename T>
CSommet<T>::~CSommet() {
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
template <typename T>
unsigned int CSommet<T>::SOMGet_Id() {
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
template <typename T>
void CSommet<T>::SOMSet_Id(unsigned int uiId) {
    uiSOMId = uiId;
}

/***********************************************************
/* SOMAjouterArcPartant
/************************************************************
/* Entr�e : ArcPartant : Pointeur vers un objet CArc
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : Ajoute un arc partant � la liste ARCPartant
/************************************************************/
template <typename T>
void CSommet<T>::SOMAjouterArcPartant(CArc<T>* ArcPartant) {
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
template <typename T>
void CSommet<T>::SOMAjouterArcSortant(CArc<T>* ArcSortant) {
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
template <typename T>
vector<CArc<T>*> CSommet<T>::SOMGet_ARCPartant() {
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
template <typename T>
vector<CArc<T>*> CSommet<T>::SOMGet_ARCSortant() {
    return ARCEntrant;
}

/***********************************************************
/* SOMModifierArcPartant
/************************************************************
/* Entr�e : uiIdArc : Identifiant de l'arc
/*          ArcPartant : Pointeur vers un objet CArc
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : Modifie un arc partant dans la liste ARCPartant
/************************************************************/
template <typename T>
void CSommet<T>::SOMModifierArcPartant(unsigned int uiIdArc, CArc<T>* ArcPartant) {
    for (auto& arc : ARCPartant) {
        if (arc->ARCGet_IdArc() == uiIdArc) {
            arc = ArcPartant;
            return;
        }
    }
}

/***********************************************************
/* SOMModifierArcSortant
/************************************************************
/* Entr�e : uiIdArc : Identifiant de l'arc
/*          ArcSortant : Pointeur vers un objet CArc
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : Modifie un arc sortant dans la liste ARCEntrant
/************************************************************/
template <typename T>
void CSommet<T>::SOMModifierArcEntrant(unsigned int uiIdArc, CArc<T>* ArcEntrant) {
    for (auto& arc : ARCEntrant) {
        if (arc->ARCGet_IdArc() == uiIdArc) {
            arc = ArcEntrant;
            return;
        }
    }
}

/***********************************************************
/* SOMSupprimerArcPartant
/************************************************************
/* Entr�e : uiIdArc : Identifiant de l'arc
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : Supprime un arc partant de la liste ARCPartant
/************************************************************/
template <typename T>
void CSommet<T>::SOMSupprimerArcPartant(unsigned int uiIdArc) {
    for (auto it = ARCPartant.begin(); it != ARCPartant.end(); ++it) {
        if ((*it)->ARCGet_IdArc() == uiIdArc) {
            ARCPartant.erase(it);
            return;
        }
    }
}

/***********************************************************
/* SOMSupprimerArcSortant
/************************************************************
/* Entr�e : uiIdArc : Identifiant de l'arc
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : Supprime un arc sortant de la liste ARCEntrant
/************************************************************/
template <typename T>
void CSommet<T>::SOMSupprimerArcEntrant(unsigned int uiIdArc) {
    for (auto it = ARCEntrant.begin(); it != ARCEntrant.end(); ++it) {
        if ((*it)->ARCGet_IdArc() == uiIdArc) {
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
template <typename T>
void CSommet<T>::SOMAfficher() {
    cout << "Sommet " << uiSOMId << endl;
    cout << "Arcs partants: " << endl;
    for (const auto& arc : ARCPartant) {
        arc->ARCAfficher();
    }
    cout << "Arcs entrants: " << endl;
    for (const auto& arc : ARCEntrant) {
        arc->ARCAfficher();
    }
}


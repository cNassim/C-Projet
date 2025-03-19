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
template <typename T>
CSommet<T>::CSommet() : uiSOMId(0) {}

/***********************************************************
/* CSommet
/************************************************************
/* Entrée : uiId : La valeur avec laquelle iSOMId sera initialisé
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : Les attributs de CSommet sont initialisés avec des valeurs données
/************************************************************/
template <typename T>
CSommet<T>::CSommet(unsigned int uiId, const vector<CArc<T>*> pPartant, const vector<CArc<T>*> pEntrant)
    : uiSOMId(uiId), ARCPartant(pPartant), ARCEntrant(pEntrant) {
}

/***********************************************************
/* CSommet
/************************************************************
/* Entrée : Sommet : Un objet de la classe CSommet
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : Les attributs de CSommet sont initialisés avec les valeurs de l'objet Sommet
/************************************************************/
template <typename T>
CSommet<T>::CSommet(const CSommet<T>& Sommet)
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
template <typename T>
CSommet<T>::~CSommet() {
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
template <typename T>
unsigned int CSommet<T>::SOMGet_Id() {
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
template <typename T>
void CSommet<T>::SOMSet_Id(unsigned int uiId) {
    uiSOMId = uiId;
}

/***********************************************************
/* SOMAjouterArcPartant
/************************************************************
/* Entrée : ArcPartant : Pointeur vers un objet CArc
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : Ajoute un arc partant à la liste ARCPartant
/************************************************************/
template <typename T>
void CSommet<T>::SOMAjouterArcPartant(CArc<T>* ArcPartant) {
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
template <typename T>
void CSommet<T>::SOMAjouterArcSortant(CArc<T>* ArcSortant) {
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
template <typename T>
vector<CArc<T>*> CSommet<T>::SOMGet_ARCPartant() {
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
template <typename T>
vector<CArc<T>*> CSommet<T>::SOMGet_ARCSortant() {
    return ARCEntrant;
}

/***********************************************************
/* SOMModifierArcPartant
/************************************************************
/* Entrée : uiIdArc : Identifiant de l'arc
/*          ArcPartant : Pointeur vers un objet CArc
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : Modifie un arc partant dans la liste ARCPartant
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
/* Entrée : uiIdArc : Identifiant de l'arc
/*          ArcSortant : Pointeur vers un objet CArc
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : Modifie un arc sortant dans la liste ARCEntrant
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
/* Entrée : uiIdArc : Identifiant de l'arc
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : Supprime un arc partant de la liste ARCPartant
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
/* Entrée : uiIdArc : Identifiant de l'arc
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : Supprime un arc sortant de la liste ARCEntrant
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
/* Entrée : Rien
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : Affiche les informations du sommet
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


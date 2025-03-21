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
inline CSommet<T>::CSommet() : uiSOMId(0) {}

/***********************************************************
/* CSommet
/************************************************************
/* Entrée : uiId : La valeur avec laquelle iSOMId sera initialisé
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : Les attributs de CSommet sont initialisés avec des valeurs données
/************************************************************/
template <typename T>
inline CSommet<T>::CSommet(unsigned int uiId, const vector<CArc<T>*> pPartant, const vector<CArc<T>*> pEntrant)
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
inline CSommet<T>::CSommet(const CSommet<T>& Sommet)
    : uiSOMId(Sommet.SOMGet_Id()), ARCPartant(Sommet.SOMGet_ARCPartant()), ARCEntrant(Sommet.SOMGet_ARCEntrant()) {
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
inline CSommet<T>::~CSommet() {
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
inline unsigned int CSommet<T>::SOMGet_Id() const {
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
inline void CSommet<T>::SOMSet_Id(unsigned int uiId) {
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
inline void CSommet<T>::SOMAjouterArcPartant(CArc<T>* arcPartant) {
    ARCPartant.push_back(arcPartant);
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
inline void CSommet<T>::SOMAjouterArcEntrant(CArc<T>* arcEntrant) {
    ARCEntrant.push_back(arcEntrant);
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
inline vector<CArc<T>*> CSommet<T>::SOMGet_ARCPartant() const {
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
inline vector<CArc<T>*> CSommet<T>::SOMGet_ARCEntrant() const {
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
inline void CSommet<T>::SOMModifierArcPartant(unsigned int uiIdArc, CArc<T>* ArcPartant) {
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
inline void CSommet<T>::SOMModifierArcEntrant(unsigned int uiIdArc, CArc<T>* ArcEntrant) {
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
inline void CSommet<T>::SOMSupprimerArcPartant(unsigned int uiIdArc) {
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
inline void CSommet<T>::SOMSupprimerArcEntrant(unsigned int uiIdArc) {
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
inline void CSommet<T>::SOMAfficher() {
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

// Instanciation des templates pour les types utilisés
template class CSommet<int>;
template class CSommet<float>;
template class CSommet<double>;



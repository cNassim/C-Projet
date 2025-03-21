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
inline CSommet<T>::CSommet() : uiSOMId(0) {}

/***********************************************************
/* CSommet
/************************************************************
/* Entr�e : uiId : La valeur avec laquelle iSOMId sera initialis�
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : Les attributs de CSommet sont initialis�s avec des valeurs donn�es
/************************************************************/
template <typename T>
inline CSommet<T>::CSommet(unsigned int uiId, const vector<CArc<T>*> pPartant, const vector<CArc<T>*> pEntrant)
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
inline CSommet<T>::CSommet(const CSommet<T>& Sommet)
    : uiSOMId(Sommet.SOMGet_Id()), ARCPartant(Sommet.SOMGet_ARCPartant()), ARCEntrant(Sommet.SOMGet_ARCEntrant()) {
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
inline CSommet<T>::~CSommet() {
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
inline unsigned int CSommet<T>::SOMGet_Id() const {
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
inline void CSommet<T>::SOMSet_Id(unsigned int uiId) {
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
inline void CSommet<T>::SOMAjouterArcPartant(CArc<T>* arcPartant) {
    ARCPartant.push_back(arcPartant);
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
inline void CSommet<T>::SOMAjouterArcEntrant(CArc<T>* arcEntrant) {
    ARCEntrant.push_back(arcEntrant);
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
inline vector<CArc<T>*> CSommet<T>::SOMGet_ARCPartant() const {
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
inline vector<CArc<T>*> CSommet<T>::SOMGet_ARCEntrant() const {
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
/* Entr�e : uiIdArc : Identifiant de l'arc
/*          ArcSortant : Pointeur vers un objet CArc
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : Modifie un arc sortant dans la liste ARCEntrant
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
/* Entr�e : uiIdArc : Identifiant de l'arc
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : Supprime un arc partant de la liste ARCPartant
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
/* Entr�e : uiIdArc : Identifiant de l'arc
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : Supprime un arc sortant de la liste ARCEntrant
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
/* Entr�e : Rien
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : Affiche les informations du sommet
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

// Instanciation des templates pour les types utilis�s
template class CSommet<int>;
template class CSommet<float>;
template class CSommet<double>;



#include "CArc.h"
#include "CSommet.h"
#include "CException.h"
#include "CGraphOrient.h"
#include <iostream>

using namespace std;

/***********************************************************
/* CGraphOrient
/***********************************************************
/* Entrée : Rien
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : Les attributs de CGraphOrient sont initialisés
/***********************************************************/
template<typename T>
CGraphOrient<T>::CGraphOrient() : GRASom(), GRAArc() {
}

/***********************************************************
/* CGraphOrient
/***********************************************************
/* Entrée : sommet : Un vecteur de pointeurs vers des objets CSommet
/*          arc : Un vecteur de pointeurs vers des objets CArc
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : Les attributs de CGraphOrient sont initialisés avec les valeurs données
/***********************************************************/
template <typename T>
CGraphOrient<T>::CGraphOrient(const vector<CSommet<T>*> sommet, const vector<CArc<T>*> arc)
    : GRASom(sommet), GRAArc(arc) {
}

/***********************************************************
/* CGraphOrient
/***********************************************************
/* Entrée : GraphOrient : Un objet de la classe CGraphOrient
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : Les attributs de CGraphOrient sont initialisés avec les valeurs de l'objet GraphOrient
/***********************************************************/
template <typename T>
inline CGraphOrient<T>::CGraphOrient(const CGraphOrient& GraphOrient) : GRASom(GraphOrient.CGraphOGET_Sommet()), GRAArc(GraphOrient.CGraphOGET_Arc()) {
}

/***********************************************************
/* ~CGraphOrient
/***********************************************************
/* Entrée : Rien
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : Les attributs de CGraphOrient sont libérés
/***********************************************************/
template <typename T>
inline CGraphOrient<T>::~CGraphOrient() {
    GRASom.clear();
    GRAArc.clear();
}

/***********************************************************
/* CGraphOAjouterSommet
/***********************************************************
/* Entrée : Som : Pointeur vers un objet CSommet
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : Ajoute le sommet au vecteur GRASom
/***********************************************************/
template <typename T>
void CGraphOrient<T>::CGraphOAjouterSommet(CSommet<T>* Som) {
    if (Som) {
        GRASom.push_back(Som);
    }
}

/***********************************************************
/* CGraphOAjouterArc
/***********************************************************
/* Entrée : Arc : Pointeur vers un objet CArc
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : Ajoute l'arc au vecteur GRAArc
/***********************************************************/
template <typename T>
void CGraphOrient<T>::CGraphOAjouterArc(CArc<T>* Arc) {
    if (Arc) {
        GRAArc.push_back(Arc);
    }
}

/***********************************************************
/* CGraphOGET_Sommet
/***********************************************************
/* Entrée : Rien
/* Nécessite : Rien
/* Sortie : Un vecteur de pointeurs vers des objets CSommet
/* Entraîne : Rien
/***********************************************************/
template <typename T>
inline vector<CSommet<T>*> CGraphOrient<T>::CGraphOGET_Sommet() const {
    return GRASom;
}

/***********************************************************
/* CGraphOGET_Arc
/***********************************************************
/* Entrée : Rien
/* Nécessite : Rien
/* Sortie : Un vecteur de pointeurs vers des objets CArc
/* Entraîne : Rien
/***********************************************************/
template <typename T>
inline vector<CArc<T>*> CGraphOrient<T>::CGraphOGET_Arc() const {
    return GRAArc;
}

/***********************************************************
/* CGraphModifierSommet
/***********************************************************
/* Entrée : uiIdsom : Identifiant du sommet
/*          Som : Pointeur vers un objet CSommet
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : Modifie le sommet avec l'identifiant donné
/***********************************************************/
template <typename T>
void CGraphOrient<T>::CGraphModifierSommet(unsigned int uiIdsom, CSommet<T>* Som) {
    for (auto& sommet : GRASom) {
        if (sommet->SOMGet_Id() == uiIdsom) {
            sommet = Som;
            return;
        }
    }
}

/***********************************************************
/* CGraphOModifierArc
/***********************************************************
/* Entrée : uiIdarc : Identifiant de l'arc
/*          Arc : Pointeur vers un objet CArc
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : Modifie l'arc avec l'identifiant donné
/***********************************************************/
template <typename T>
void CGraphOrient<T>::CGraphOModifierArc(unsigned int uiIdarc, CArc<T>* Arc) {
    for (auto& arc : GRAArc) {
        if (arc->ARCGet_IdArc() == uiIdarc) {
            arc = Arc;
            return;
        }
    }
}

/***********************************************************
/* CGraphSupprimerSommet
/***********************************************************
/* Entrée : uiIdsom : Identifiant du sommet
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : Supprime le sommet avec l'identifiant donné
/***********************************************************/
template <typename T>
void CGraphOrient<T>::CGraphSupprimerSommet(unsigned int uiIdsom) {
    for (auto it = GRASom.begin(); it != GRASom.end(); ++it) {
        if ((*it)->SOMGet_Id() == uiIdsom) {
            GRASom.erase(it);
            return;
        }
    }
}
#include "CArc.h"
#include "CSommet.h"
#include "CException.h"
#include "CGraphOrient.h"
#include <iostream>

using namespace std;

/***********************************************************
/* CGraphOrient
/***********************************************************
/* Entr�e : Rien
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : Les attributs de CGraphOrient sont initialis�s
/***********************************************************/
template<typename T>
CGraphOrient<T>::CGraphOrient() : GRASom(), GRAArc() {
}

/***********************************************************
/* CGraphOrient
/***********************************************************
/* Entr�e : sommet : Un vecteur de pointeurs vers des objets CSommet
/*          arc : Un vecteur de pointeurs vers des objets CArc
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : Les attributs de CGraphOrient sont initialis�s avec les valeurs donn�es
/***********************************************************/
template <typename T>
CGraphOrient<T>::CGraphOrient(const vector<CSommet<T>*> sommet, const vector<CArc<T>*> arc)
    : GRASom(sommet), GRAArc(arc) {
}

/***********************************************************
/* CGraphOrient
/***********************************************************
/* Entr�e : GraphOrient : Un objet de la classe CGraphOrient
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : Les attributs de CGraphOrient sont initialis�s avec les valeurs de l'objet GraphOrient
/***********************************************************/
template <typename T>
inline CGraphOrient<T>::CGraphOrient(const CGraphOrient& GraphOrient) : GRASom(GraphOrient.CGraphOGET_Sommet()), GRAArc(GraphOrient.CGraphOGET_Arc()) {
}

/***********************************************************
/* ~CGraphOrient
/***********************************************************
/* Entr�e : Rien
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : Les attributs de CGraphOrient sont lib�r�s
/***********************************************************/
template <typename T>
inline CGraphOrient<T>::~CGraphOrient() {
    GRASom.clear();
    GRAArc.clear();
}

/***********************************************************
/* CGraphOAjouterSommet
/***********************************************************
/* Entr�e : Som : Pointeur vers un objet CSommet
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : Ajoute le sommet au vecteur GRASom
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
/* Entr�e : Arc : Pointeur vers un objet CArc
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : Ajoute l'arc au vecteur GRAArc
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
/* Entr�e : Rien
/* N�cessite : Rien
/* Sortie : Un vecteur de pointeurs vers des objets CSommet
/* Entra�ne : Rien
/***********************************************************/
template <typename T>
inline vector<CSommet<T>*> CGraphOrient<T>::CGraphOGET_Sommet() const {
    return GRASom;
}

/***********************************************************
/* CGraphOGET_Arc
/***********************************************************
/* Entr�e : Rien
/* N�cessite : Rien
/* Sortie : Un vecteur de pointeurs vers des objets CArc
/* Entra�ne : Rien
/***********************************************************/
template <typename T>
inline vector<CArc<T>*> CGraphOrient<T>::CGraphOGET_Arc() const {
    return GRAArc;
}

/***********************************************************
/* CGraphModifierSommet
/***********************************************************
/* Entr�e : uiIdsom : Identifiant du sommet
/*          Som : Pointeur vers un objet CSommet
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : Modifie le sommet avec l'identifiant donn�
/***********************************************************/
template <typename T>
void CGraphOrient<T>::CGraphOModifierSommet(unsigned int uiIdsom, CSommet<T>* Som) {
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
/* Entr�e : uiIdarc : Identifiant de l'arc
/*          Arc : Pointeur vers un objet CArc
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : Modifie l'arc avec l'identifiant donn�
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
/* Entr�e : uiIdsom : Identifiant du sommet
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : Supprime le sommet avec l'identifiant donn�
/***********************************************************/
template <typename T>
void CGraphOrient<T>::CGraphOSupprimerSommet(unsigned int uiIdsom) {
    for (auto it = GRASom.begin(); it != GRASom.end(); ++it) {
        if ((*it)->SOMGet_Id() == uiIdsom) {
            GRASom.erase(it);
            return;
        }
    }
}


template <typename T>
void CGraphOrient<T>::CGraphOSupprimerArc(unsigned int uiIdarc) {
    for (auto it = GRAArc.begin(); it != GRAArc.end(); ++it) {
        if ((*it)->ARCGet_IdArc() == uiIdarc) {
            GRAArc.erase(it);
            return;
        }
    }
}

template <typename T>
void CGraphOrient<T>::CGraphOAfficher() {
    cout << "Sommets" << endl;
    for (const auto& sommet : GRASom) {
        sommet->SOMAfficher();
    }
    cout << "\nArcs" << endl;
    for (const auto& arc : GRAArc) {
        arc->ARCAfficher();
    }
}

// Instanciation des templates pour les types utilis�s
template class CGraphOrient<int>;
template class CGraphOrient<float>;
template class CGraphOrient<double>;
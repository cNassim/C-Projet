#include "CArc.h"
#include "CSommet.h"
#include "CException.h"
#include "CGraphOrient.h"
#include <iostream>

using namespace std;


template<typename T>
CGraphOrient<T>::CGraphOrient() : GRASom(), GRAArc() {
}

template <typename T>
CGraphOrient<T>::CGraphOrient(const vector<CSommet<T>*> sommet, const vector<CArc<T>*> arc)
    : GRASom(sommet), GRAArc(arc) {
}

template <typename T>
inline CGraphOrient<T>::CGraphOrient(const CGraphOrient& GraphOrient) : GRASom(GraphOrient.CGraphOGET_Sommet()), GRAArc(GraphOrient.CGraphOGET_Arc()) {
}

template <typename T>
inline CGraphOrient<T>::~CGraphOrient() {
    GRASom.clear();
    GRAArc.clear();
}


template <typename T>
void CGraphOrient<T>::CGraphOAjouterSommet(CSommet<T>* Som) {
    if (Som) {
        GRASom.push_back(Som);
    }
}

template <typename T>
void CGraphOrient<T>::CGraphOAjouterArc(CArc<T>* Arc) {
    if (Arc) {
        GRAArc.push_back(Arc);
    }
}

template <typename T>
inline vector<CSommet<T>*> CGraphOrient<T>::CGraphOGET_Sommet() const {
    return GRASom;
}


template <typename T>
inline vector<CArc<T>*> CGraphOrient<T>::CGraphOGET_Arc() const {
    return GRAArc;
}


template <typename T>
void CGraphOrient<T>::CGraphModifierSommet(unsigned int uiIdsom, CSommet<T>* Som) {
    for (auto& sommet : GRASom) {
        if (sommet->SOMGet_Id() == uiIdsom) {
            sommet = Som;
            return;
        }
    }
}

template <typename T>
void CGraphOrient<T>::CGraphOModifierArc(unsigned int uiIdarc, CArc<T>* Arc) {
    for (auto& arc : GRAArc) {
        if (arc->ARCGet_IdArc() == uiIdarc) {
            arc = Arc;
            return;
        }
    }
}
/*
template <typename T>
void CGraphOrient<T>::CGraphSupprimerSommet(unsigned int uiIdsom) {
    SOM.erase(remove_if(SOM.begin(), SOM.end(),
        [uiIdsom](CSommet<T>* sommet) { return sommet->SOMGet_Id() == uiIdsom; }),
        SOM.end());
}

template <typename T>
void CGraphOrient<T>::CGraphSupprimerArc(unsigned int uiIdarc) {
    ARC.erase(remove_if(ARC.begin(), ARC.end(),
        [uiIdarc](CArc<T>* arc) { return arc->ARCGet_IdArc() == uiIdarc; }),
        ARC.end());
}
*/
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


template class CGraphOrient<int>;
template class CGraphOrient<float>;
template class CGraphOrient <double>;


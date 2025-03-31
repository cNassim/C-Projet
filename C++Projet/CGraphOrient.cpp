#include "CArc.h"
#include "CSommet.h"
#include "CException.h"
#include "CGraphOrient.h"
#include <iostream>

using namespace std;

template <typename T>
inline CGraphOrient<T>::CGraphOrient(): {}

template <typename T>
CGraphOrient<T>::CGraphOrient(const vector<CSommet<T>*> sommet, const vector<CArc<T>*> arc)
    : SOM(sommet), ARC(arc) {
}

template <typename T>
inline CGraphOrient<T>::CGraphOrient(const CGraphOrient& GraphOrient) : SOM(GraphOrient.CGraphOGET_Sommet()), ARC(GraphOrient.CGraphOGET_Arc()) {
}

template <typename T>
inline CGraphOrient<T>::~CGraphOrient() {
    SOM.clear();
    ARC.clear();
}


template <typename T>
void CGraphOrient<T>::CGraphOAjouterSommet(CSommet<T>* Som) {
    if (Som) {
        SOM.push_back(Som);
    }
}

template <typename T>
void CGraphOrient<T>::CGraphOAjouterArc(CArc<T>* Arc) {
    if (Arc) {
        ARC.push_back(Arc);
    }
}

template <typename T>
inline vector<CSommet<T>*> CGraphOrient<T>::CGraphOGET_Sommet() const {
    return SOM;
}


template <typename T>
inline vector<CArc<T>*> CGraphOrient<T>::CGraphOGET_Arc() const {
    return ARC;
}


template <typename T>
void CGraphOrient<T>::CGraphModifierSommet(unsigned int uiIdsom, CSommet<T>* Som) {
    for (auto& sommet : SOM) {
        if (sommet->SOMGet_Id() == uiIdsom) {
            sommet = Som;
            return;
        }
    }
}

template <typename T>
void CGraphOrient<T>::CGraphOModifierArc(unsigned int uiIdarc, CArc<T>* Arc) {
    for (auto& arc : ARC) {
        if (arc->ARCGet_IdArc() == uiIdarc) {
            arc = Arc;
            return;
        }
    }
}

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

template <typename T>
void CGraphOrient<T>::CGraphOAfficher() {
    cout << "Sommets" << endl;
    for (const auto& sommet : SOM) {
        sommet->SOMAfficher();
    }
    cout << "\nArcs" << endl;
    for (const auto& arc : ARC) {
        arc->ARCAfficher();
    }
}


template class CGraphOrient<int>;
template class CGraphOrient<float>;
template class CGraphOrient <double>;


#include "CSommet.h"
#include <iostream>

using namespace std;

template <typename T>
inline CSommet<T>::CSommet() : uiSOMId(0) {}

template <typename T>
inline CSommet<T>::CSommet(unsigned int uiId, const vector<CArc<T>*> pPartant, const vector<CArc<T>*> pEntrant)
    : uiSOMId(uiId), ARCPartant(pPartant), ARCEntrant(pEntrant) {
}

template <typename T>
inline CSommet<T>::CSommet(const CSommet<T>& Sommet)
    : uiSOMId(Sommet.SOMGet_Id()), ARCPartant(Sommet.SOMGet_ARCPartant()), ARCEntrant(Sommet.SOMGet_ARCEntrant()) {
}

template <typename T>
inline CSommet<T>::~CSommet() {
    ARCPartant.clear();
    ARCEntrant.clear();
}

template <typename T>
inline unsigned int CSommet<T>::SOMGet_Id() const {
    return uiSOMId;
}

template <typename T>
inline void CSommet<T>::SOMSet_Id(unsigned int uiId) {
    uiSOMId = uiId;
}

template <typename T>
inline void CSommet<T>::SOMAjouterArcPartant(CArc<T>* arcPartant) {
    ARCPartant.push_back(arcPartant);
}

template <typename T>
inline void CSommet<T>::SOMAjouterArcEntrant(CArc<T>* arcEntrant) {
    ARCEntrant.push_back(arcEntrant);
}

template <typename T>
inline vector<CArc<T>*> CSommet<T>::SOMGet_ARCPartant() const {
    return ARCPartant;
}

template <typename T>
inline vector<CArc<T>*> CSommet<T>::SOMGet_ARCEntrant() const {
    return ARCEntrant;
}

template <typename T>
inline void CSommet<T>::SOMModifierArcPartant(CArc<T>* ArcToModify, CArc<T>* NewArc) {
    for (auto& arc : ARCPartant) {
        if (arc == ArcToModify) {
            arc = NewArc;
            return;
        }
    }
}

template <typename T>
inline void CSommet<T>::SOMModifierArcEntrant(CArc<T>* ArcToModify, CArc<T>* NewArc) {
    for (auto& arc : ARCEntrant) {
        if (arc == ArcToModify) {
            arc = NewArc;
            return;
        }
    }
}

template <typename T>
inline void CSommet<T>::SOMSupprimerArcPartant(CArc<T>* ArcPartant) {
    for (auto it = ARCPartant.begin(); it != ARCPartant.end(); ++it) {
        if (*it == ArcPartant) {
            ARCPartant.erase(it);
            return;
        }
    }
}

template <typename T>
inline void CSommet<T>::SOMSupprimerArcEntrant(CArc<T>* ArcEntrant) {
    for (auto it = ARCEntrant.begin(); it != ARCEntrant.end(); ++it) {
        if (*it == ArcEntrant) {
            ARCEntrant.erase(it);
            return;
        }
    }
}

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

// Instanciation explicite pour les types les plus utilisés
template class CSommet<int>;
template class CSommet<float>;
template class CSommet<double>;

#include "CSommet.h"
#include <iostream>

using namespace std;

template <typename T>
inline CSommet<T>::CSommet() : uiSOMId(0) {}

template <typename T>
inline CSommet<T>::CSommet(unsigned int uiId, const vector<CArc<T>*>& pPartant, const vector<CArc<T>*>& pEntrant)
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
    if (arcPartant && arcPartant->ARCGet_SomDeb() == this) {
        ARCPartant.push_back(arcPartant);
    }
    else {
        throw CException(10);
    }
}

template <typename T>
inline void CSommet<T>::SOMAjouterArcEntrant(CArc<T>* arcEntrant) {
    if (arcEntrant && arcEntrant->ARCGet_SomA() == this) {
        ARCEntrant.push_back(arcEntrant);
    }
    else {
        throw CException(11);
    }
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
    try {
        if (!NewArc || NewArc->ARCGet_SomDeb() != this) {
            throw CException(12);
        }
        for (auto& arc : ARCPartant) {
            if (arc == ArcToModify) {
                arc = NewArc;
                return;
            }
        }
        throw CException(13);
    }
    catch (const CException& e) {
        switch (e.EXCGet_Val()) {
        case 12:
            cerr << "Erreur : L'arc de remplacement n'est pas sortant de ce sommet." << endl;
            break;
        case 13:
            cerr << "Erreur : Arc à modifier non trouvé dans les arcs partants." << endl;
            break;
        default:
            cerr << "Erreur inconnue dans SOMModifierArcPartant." << endl;
            break;
        }
    }
}


template <typename T>
inline void CSommet<T>::SOMModifierArcEntrant(CArc<T>* ArcToModify, CArc<T>* NewArc) {
    try {
        if (!NewArc || NewArc->ARCGet_SomA() != this) {
            throw CException(14);
        }
        for (auto& arc : ARCEntrant) {
            if (arc == ArcToModify) {
                arc = NewArc;
                return;
            }
        }
        throw CException(15);
    }
    catch (const CException& e) {
        switch (e.EXCGet_Val()) {
        case 14:
            cerr << "Erreur : L'arc de remplacement n'est pas entrant dans ce sommet." << endl;
            break;
        case 15:
            cerr << "Erreur : Arc à modifier non trouvé dans les arcs entrants." << endl;
            break;
        default:
            cerr << "Erreur inconnue dans SOMModifierArcEntrant." << endl;
            break;
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

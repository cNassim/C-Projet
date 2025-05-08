#include "CArc.h"
#include "CSommet.h"
#include "CException.h"

template <typename T>
inline CArc<T>::CArc() : pSommetDeb(nullptr), pSommetA(nullptr){}

template <typename T>
inline CArc<T>::CArc(CSommet<T>* SommetDeb, CSommet<T>* SommetA)
    : pSommetDeb(SommetDeb), pSommetA(SommetA){
    if (SommetDeb) {
        SommetDeb->SOMAjouterArcPartant(this);
    }
    if (SommetA) {
        SommetA->SOMAjouterArcEntrant(this); 
    }
}

template <typename T>
inline CArc<T>::CArc(const CArc<T>& Arc)
    : pSommetDeb(Arc.ARCGet_SomDeb()), pSommetA(Arc.ARCGet_SomA()) {
}

template <typename T>
inline CSommet<T>* CArc<T>::ARCGet_SomDeb() const {
    return pSommetDeb;
}

template <typename T>
inline CSommet<T>* CArc<T>::ARCGet_SomA() const {
    return pSommetA;
}



template <typename T>
inline void CArc<T>::ARCModifierSomDeb(CSommet<T>* SommetDeb) {
    if (SommetDeb) {
        pSommetDeb = SommetDeb;
    }
}

template <typename T>
inline void CArc<T>::ARCModifierSomA(CSommet<T>* SommetA) {
    if (SommetA) {
        pSommetA = SommetA;
    }
}

template <typename T>
inline void CArc<T>::ARCAfficher() {
    if (pSommetDeb && pSommetA) {
        cout << "Sommet Depart: " << pSommetDeb->SOMGet_Id()
            << " | Sommet Arrivee: " << pSommetA->SOMGet_Id() << endl;
    }
    else {
        cout << "Arc invalide" << endl;
    }
}

template <typename T>
CArc<T> CArc<T>::ARCInverserArc(CArc<T>& arc) {
    CSommet<T>* SommetDeb = arc.ARCGet_SomDeb();
    CSommet<T>* SommetA = arc.ARCGet_SomA();      

    CArc<T> ARCinv(SommetA, SommetDeb);
    return ARCinv;
}

template <typename T>
bool CArc<T>::operator==(const CArc<T>& other) const {
    return (this->ARCGet_SomDeb() == other.ARCGet_SomDeb() &&
        this->ARCGet_SomA() == other.ARCGet_SomA());
}

template class CArc<int>;
template class CArc<float>;
template class CArc<double>;
template class CArc<char>;
template class CArc<bool>;
template class CArc<string>;
template class CArc<unsigned int>;
template class CArc<long>;
template class CArc<unsigned long>;
template class CArc<short>;
template class CArc<unsigned short>;
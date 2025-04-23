#include "CGraph.h"
#include "CArc.h"
#include "CSommet.h"
#include <iostream>

using namespace std;

template <typename T>
inline CGraph<T>::CGraph() : CGraphOrient<T>() {}

template <typename T>
inline CGraph<T>::~CGraph() {}


template <typename T>
void CGraph<T>::CGraphAjouterSommet(CSommet<T>* Som) {
    this->CGraphOAjouterSommet(Som);
}

template <typename T>
void CGraph<T>::CGraphAjouterArc(CArc<T>* Arc) {

    this->CGraphOAjouterArc(Arc);
    CArc<T>* arcInverse = new CArc<T>(
        Arc->ARCGet_SommetArrive(),
        Arc->ARCGet_SommetDepart(),
        Arc->ARCGet_Cout()
    );
    this->CGraphOAjouterArc(arcInverse);
}

template <typename T>
vector<CSommet<T>*> CGraph<T>::CGraphGET_Sommet() const {
    return this->CGraphOGET_Sommet();
}

template <typename T>
vector<CArc<T>*> CGraph<T>::CGraphGET_Arc() const {
    return this->CGraphOGET_Arc();
}

template <typename T>
void CGraph<T>::CGraphModifierSommet(unsigned int uiIdsom, CSommet<T>* Som) {
    this->CGraphModifierSommet(uiIdsom, Som);
}

template <typename T>
void CGraph<T>::CGraphOModifierArc(unsigned int uiIdarc, CArc<T>* Arc) {
    this->CGraphOModifierArc(uiIdarc, Arc);
}

template <typename T>
void CGraph<T>::CGraphSupprimerSommet(unsigned int uiIdsom) {
    this->CGraphSupprimerSommet(uiIdsom);
}

template <typename T>
void CGraph<T>::CGraphSupprimerArc(unsigned int uiIdarc) {

    this->CGraphSupprimerArc(uiIdarc);
    this->CGraphSupprimerArc(uiIdarc);
}

template <typename T>
void CGraph<T>::CGraphAfficher() {
    this->CGraphOAfficher();
}

// Pour permettre la compilation avec types courants
template class CGraph<int>;
template class CGraph<float>;
template class CGraph<double>;
template class CGraph<std::string>;

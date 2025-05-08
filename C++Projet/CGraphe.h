#pragma once
#include "CArc.h"
#include "CSommet.h"
#include <vector>
using namespace std;

template <typename T>
class CGraphe {
public:
    CGraphe();
    virtual ~CGraphe();

    virtual void CGrapheAjouterSommet(CSommet<T>* Som) = 0;
    virtual void CGrapheAjouterArc(CArc<T>* Arc) = 0;
    virtual vector<CSommet<T>> CGrapheGetSommets() const = 0;
    virtual vector<CArc<T>> CGrapheGetArcs() const = 0;
    virtual void CGrapheModifierSommet(unsigned int uiIdsom, CSommet<T>* Som) = 0;
    virtual void CGrapheModifierArc(unsigned int uiIdarc, CArc<T>* Arc) = 0;
    virtual void CGrapheSupprimerSommet(unsigned int uiIdsom) = 0;
    virtual void CGrapheSupprimerArc(unsigned int uiIdarc) = 0;
    virtual void CGrapheAfficher() const = 0;
};
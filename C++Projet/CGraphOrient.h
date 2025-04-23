#pragma once
#include "CGraphe.h"
#include <iostream>
using namespace std;


template <typename T>
class CGraphOrient : public CGraphe<T> {
private:
    vector<CSommet<T>> sommets;
    vector<CArc<T>> arcs;

public:
    CGraphOrient();
    virtual ~CGraphOrient();

    void CGrapheAjouterSommet(CSommet<T>* Som) override;
    void CGrapheAjouterArc(CArc<T>* Arc) override;
    vector<CSommet<T>> CGrapheGetSommets() const override;
    vector<CArc<T>> CGrapheGetArcs() const override;
    void CGrapheModifierSommet(unsigned int uiIdsom, CSommet<T>* Som) override;
    void CGrapheModifierArc(unsigned int uiIdarc, CArc<T>* Arc) override;
    void CGrapheSupprimerSommet(unsigned int uiIdsom) override;
    void CGrapheSupprimerArc(unsigned int uiIdarc) override;
    void CGrapheAfficher() const override;
};

#pragma once
#include "CGraphOrient.h"
using namespace std;
template <typename T>
class CGraph : public CGraphOrient<T> {
public:
    CGraph();
    virtual ~CGraph();

    void CGraphAjouterSommet(CSommet<T>* Som);
    void CGraphAjouterArc(CArc<T>* Arc);
    vector<CSommet<T>*> CGraphGET_Sommet() const;
    vector<CArc<T>*> CGraphGET_Arc() const;
    void CGraphModifierSommet(unsigned int uiIdsom, CSommet<T>* Som);
    void CGraphOModifierArc(unsigned int uiIdarc, CArc<T>* Arc);
    void CGraphSupprimerSommet(unsigned int uiIdsom);
    void CGraphSupprimerArc(unsigned int uiIdarc);
    void CGraphAfficher();
};
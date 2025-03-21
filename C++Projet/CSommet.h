#pragma once
#include "CArc.h"
#include <vector>
#include <iostream>
using namespace std;
template <typename T>
class CArc;

template <typename T>
class CSommet
{
    // ATTRIBUTS
private:
    unsigned int uiSOMId;
    vector<CArc<T>*> ARCPartant;
    vector<CArc<T>*> ARCEntrant;

    // METHODES
public:
    CSommet();
    CSommet(unsigned int uiId, const vector<CArc<T>*> partant, const vector<CArc<T>*> entrant);
    CSommet(const CSommet& Sommet);
    ~CSommet();
    unsigned int SOMGet_Id() const;
    void SOMAjouterArcPartant(CArc<T>* ArcPartant);
    void SOMAjouterArcEntrant(CArc<T>* ArcEntrant);
    vector<CArc<T>*> SOMGet_ARCPartant() const;
    vector<CArc<T>*> SOMGet_ARCEntrant() const;
    void SOMSet_Id(unsigned int uiId);
    void SOMModifierArcPartant(unsigned int uiIdArc, CArc<T>* ArcPartant);
    void SOMModifierArcEntrant(unsigned int uiIdArc, CArc<T>* ArcEntrant);
    void SOMSupprimerArcPartant(unsigned int uiIdArc);
    void SOMSupprimerArcEntrant(unsigned int uiIdArc);
    void SOMAfficher();
};


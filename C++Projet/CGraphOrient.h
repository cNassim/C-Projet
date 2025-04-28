#pragma once
#include "CArc.h"
#include "CSommet.h"
#include <vector>
#include <iostream>
using namespace std;
template <typename T>

class CGraphOrient
{
	//ATTRIBUTS
private:
	vector<CSommet<T>*> GRASom;
	vector<CArc<T>*> GRAArc;

	//METHODES
public:
	CGraphOrient();
	CGraphOrient(const vector<CSommet<T>*> sommet,const vector<CArc<T>*> arc);
	CGraphOrient(const CGraphOrient& GraphOrient);
	~CGraphOrient();
	void CGraphOAjouterSommet(CSommet<T>* Som);
	void CGraphOAjouterArc(CArc<T>* Arc);
	vector<CSommet<T>*>CGraphOGET_Sommet() const;
	vector<CArc<T>*> CGraphOGET_Arc() const;
	void CGraphOModifierSommet(unsigned int uiIdsom, CSommet<T>* Som);
	void CGraphOModifierArc(unsigned int uiIdarc, CArc<T>* Arc);
	void CGraphOSupprimerSommet(unsigned int uiIdsom);
	void CGraphOSupprimerArc(unsigned int uiIdarc);
	void CGraphOAfficher();

};
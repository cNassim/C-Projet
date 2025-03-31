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
	vector<CSommet<T>*> SOM;
	vector<<CArc<T>*> ARC;

	//METHODES
public:
	CGraphOrient();
	CGraphOrient(const vector<CSommet<T>*> sommet,const vector<CArc<T>*> arc);
	CGraphOrient(const CGraphOrient& GraphOrient);
	~CGraphOrient();
	void CGraphOAjouterSommet(CSommet<T>* Som);
	void CGraphOAjouterArc(CArc<T>* Arc);
	vector<CSommet<T>*> CGraphOrient<T>::CGraphOGET_Sommet();
	vector<CArc<T>*> CGraphOrient<T>::CGraphOGET_Arc()
	void CGraphModifierSommet(unsigned int uiIdsom, CSommet<T>* Som);
	void CGraphOModifierArc(unsigned int uiIdarc, CArc<T>* Arc);
	void CGraphSupprimerSommet(unsigned int uiIdsom);
	void CGraphSupprimerArc(unsigned int uiIdarc);
	void CGraphOAfficher();

};
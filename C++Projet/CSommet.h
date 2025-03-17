#pragma once
#include "CARC.h"
#include <vector>
using namespace std;

class CSommet
{
	//ATTRIBUTS 
    private:
		int iSOMId;
		vector<CArc*> ARCPartant;
		vector<CArc*> ARCEntrant;
	//METHODES
	public:
		CSommet();
		CSommet(int iId);
		CSommet(const CSommet& Sommet);
		~CSommet();
		int SOMGet_Id();
		void SOMAjouterArcPartant(CArc* ArcPartant);
		void SOMAjouterArcSortant(CArc* ArcSortant);
		vector<CArc*> SOMGet_ARCPartant();
		vector<CArc*> SOMGet_ARCSortant();
		void SOMSet_Id(int iId);
		void SOMModifierArcPartant(int iIdArc, CArc* ArcPartant);
		void SOMModifierArcSortant(int iIdArc, CArc* ArcSortant);
		void SOMSupprimerArcPartant(int iIdArc);
		void SOMSupprimerArcSortant(int iIdArc);
		void SOMAfficher();
};


#pragma once
#include "CSommet.h"
template <typename T>
class CArc
{
	//ATTRIBUTS
	private:
		unsigned int uiARCSomDeb;
		unsigned int uiARCSomA;
		unsigned int uiARCIdArc;
		T tARCDistance;
		T tARCCap;
		T tARCPoids;
	
	//METHODES
	public:
		CArc();
		CArc(CSommet* SommetDeb,CSommet* SommetA,unsigned int uiIdArc,T tDistance,T tCap,T tPoids);
		CArc(const CArc<T>&Arc);
		~CArc(){};
		unsigned int ARCGet_SomDeb() const ;
		unsigned int ARCGet_SomA() const;
		unsigned int ARCGet_IdArc() const;
		T ARCGet_Distance() const;
		T ARCGet_Cap() const ;
		T ARCGet_Poids() const;
		void ARCModifierSomDeb(CSommet* SommetDeb);
		void ARCModifierSomA(CSommet* SommetA);
		void ARCSet_IdArc(unsigned int uiIdArc);
		void ARCSet_Distance(T tDistance);
		void ARCSet_Cap(T tCap);
		void ARCSetPoids(T tPoids);
		void ARCAfficher();
};

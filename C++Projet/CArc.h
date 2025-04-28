#pragma once
#include <iostream>
#include "CSommet.h"
#include "CException.h"
template <typename T>
class CSommet;
template <typename T>
class CArc
{
	//ATTRIBUTS
	private:
		unsigned int uiARCSomDeb;
		unsigned int uiARCSomA;
		unsigned int uiARCIdArc;

	
	//METHODES
	public:
		CArc();
		CArc(CSommet<T>* SommetDeb,CSommet<T>* SommetA,unsigned int uiIdArc);
		CArc(const CArc<T>&Arc);
		~CArc()=default;
		unsigned int ARCGet_SomDeb() const ;
		unsigned int ARCGet_SomA() const;
		unsigned int ARCGet_IdArc() const;
		void ARCModifierSomDeb(CSommet<T>* SommetDeb);
		void ARCModifierSomA(CSommet<T>* SommetA);
		void ARCSet_IdArc(unsigned int uiIdArc);
		void ARCAfficher();
};

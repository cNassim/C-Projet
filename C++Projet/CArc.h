#pragma once  
#include <iostream>  
#include "CSommet.h"  
#include "CException.h"  

template <typename T>  
class CSommet;  

template <typename T>  
class CArc  
{  
// ATTRIBUTS  
	private:  
		CSommet<T>* pSommetDeb;  
		CSommet<T>* pSommetA;    

// METHODES  
	public:  
		/***********************************************************  
		/* CArc  
		/***********************************************************  
		/* Entr�e : Rien  
		/* N�cessite : Rien  
		/* Sortie : Rien  
		/* Entra�ne : Les attributs de CARC sont initialis�s � 0  
		/***********************************************************/  
		CArc();  

		/***********************************************************  
		/* CArc  
		/***********************************************************  
		/* Entr�e : Pointeurs vers les sommets de d�part et d'arriv�e,  
		/*          identifiant de l'arc  
		/* N�cessite : Les sommets doivent �tre valides  
		/* Sortie : Rien  
		/* Entra�ne : Les attributs de CARC sont initialis�s avec les  
		/*            valeurs fournies  
		/***********************************************************/  
		CArc(CSommet<T>* SommetDeb, CSommet<T>* SommetA);  

		/***********************************************************  
		/* CArc (constructeur de copie)  
		/***********************************************************  
		/* Entr�e : R�f�rence � un objet CArc  
		/* N�cessite : L'objet CArc doit �tre valide  
		/* Sortie : Rien  
		/* Entra�ne : Les attributs de CARC sont copi�s depuis l'objet  
		/***********************************************************/  
		CArc(const CArc<T>& Arc);  

		/***********************************************************  
		/* ~CArc  
		/***********************************************************  
		/* Entr�e : Rien  
		/* N�cessite : Rien  
		/* Sortie : Rien  
		/* Entra�ne : Lib�re les ressources si n�cessaire  
		/***********************************************************/  
		~CArc() = default;  

		/***********************************************************  
		/* ARCGet_SomDeb  
		/***********************************************************  
		/* Entr�e : Rien  
		/* N�cessite : Rien  
		/* Sortie : Pointeur vers le sommet de d�part  
		/* Entra�ne : Rien  
		/***********************************************************/  
		CSommet<T>* ARCGet_SomDeb() const;  

		/***********************************************************  
		/* ARCGet_SomA  
		/***********************************************************  
		/* Entr�e : Rien  
		/* N�cessite : Rien  
		/* Sortie : Pointeur vers le sommet d'arriv�e  
		/* Entra�ne : Rien  
		/***********************************************************/  
		CSommet<T>* ARCGet_SomA() const;  

		/***********************************************************  
		/* ARCModifierSomDeb  
		/***********************************************************  
		/* Entr�e : Pointeur vers un sommet de d�part  
		/* N�cessite : Le sommet doit �tre valide  
		/* Sortie : Rien  
		/* Entra�ne : Modifie le sommet de d�part de l'arc  
		/***********************************************************/  
		void ARCModifierSomDeb(CSommet<T>* SommetDeb);  

		/***********************************************************  
		/* ARCModifierSomA  
		/***********************************************************  
		/* Entr�e : Pointeur vers un sommet d'arriv�e  
		/* N�cessite : Le sommet doit �tre valide  
		/* Sortie : Rien  
		/* Entra�ne : Modifie le sommet d'arriv�e de l'arc  
		/***********************************************************/  
		void ARCModifierSomA(CSommet<T>* SommetA);  

		/***********************************************************  
		/* ARCAfficher  
		/***********************************************************  
		/* Entr�e : Rien  
		/* N�cessite : Rien  
		/* Sortie : Rien  
		/* Entra�ne : Affiche les informations de l'arc  
		/***********************************************************/  
		void ARCAfficher();  

		/***********************************************************  
		/* ARCInverserArc  
		/***********************************************************  
		/* Entr�e : R�f�rence � un objet CArc  
		/* N�cessite : L'objet CArc doit �tre valide  
		/* Sortie : Un nouvel objet CArc avec les sommets invers�s  
		/* Entra�ne : Cr�e un nouvel arc avec les sommets de d�part  
		/*            et d'arriv�e �chang�s  
		/***********************************************************/  
		CArc<T> ARCInverserArc(const CArc<T>& arc);  
};

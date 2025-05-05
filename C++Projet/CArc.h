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
		/* Entrée : Rien  
		/* Nécessite : Rien  
		/* Sortie : Rien  
		/* Entraîne : Les attributs de CARC sont initialisés à 0  
		/***********************************************************/  
		CArc();  

		/***********************************************************  
		/* CArc  
		/***********************************************************  
		/* Entrée : Pointeurs vers les sommets de départ et d'arrivée,  
		/*          identifiant de l'arc  
		/* Nécessite : Les sommets doivent être valides  
		/* Sortie : Rien  
		/* Entraîne : Les attributs de CARC sont initialisés avec les  
		/*            valeurs fournies  
		/***********************************************************/  
		CArc(CSommet<T>* SommetDeb, CSommet<T>* SommetA);  

		/***********************************************************  
		/* CArc (constructeur de copie)  
		/***********************************************************  
		/* Entrée : Référence à un objet CArc  
		/* Nécessite : L'objet CArc doit être valide  
		/* Sortie : Rien  
		/* Entraîne : Les attributs de CARC sont copiés depuis l'objet  
		/***********************************************************/  
		CArc(const CArc<T>& Arc);  

		/***********************************************************  
		/* ~CArc  
		/***********************************************************  
		/* Entrée : Rien  
		/* Nécessite : Rien  
		/* Sortie : Rien  
		/* Entraîne : Libère les ressources si nécessaire  
		/***********************************************************/  
		~CArc() = default;  

		/***********************************************************  
		/* ARCGet_SomDeb  
		/***********************************************************  
		/* Entrée : Rien  
		/* Nécessite : Rien  
		/* Sortie : Pointeur vers le sommet de départ  
		/* Entraîne : Rien  
		/***********************************************************/  
		CSommet<T>* ARCGet_SomDeb() const;  

		/***********************************************************  
		/* ARCGet_SomA  
		/***********************************************************  
		/* Entrée : Rien  
		/* Nécessite : Rien  
		/* Sortie : Pointeur vers le sommet d'arrivée  
		/* Entraîne : Rien  
		/***********************************************************/  
		CSommet<T>* ARCGet_SomA() const;  

		/***********************************************************  
		/* ARCModifierSomDeb  
		/***********************************************************  
		/* Entrée : Pointeur vers un sommet de départ  
		/* Nécessite : Le sommet doit être valide  
		/* Sortie : Rien  
		/* Entraîne : Modifie le sommet de départ de l'arc  
		/***********************************************************/  
		void ARCModifierSomDeb(CSommet<T>* SommetDeb);  

		/***********************************************************  
		/* ARCModifierSomA  
		/***********************************************************  
		/* Entrée : Pointeur vers un sommet d'arrivée  
		/* Nécessite : Le sommet doit être valide  
		/* Sortie : Rien  
		/* Entraîne : Modifie le sommet d'arrivée de l'arc  
		/***********************************************************/  
		void ARCModifierSomA(CSommet<T>* SommetA);  

		/***********************************************************  
		/* ARCAfficher  
		/***********************************************************  
		/* Entrée : Rien  
		/* Nécessite : Rien  
		/* Sortie : Rien  
		/* Entraîne : Affiche les informations de l'arc  
		/***********************************************************/  
		void ARCAfficher();  

		/***********************************************************  
		/* ARCInverserArc  
		/***********************************************************  
		/* Entrée : Référence à un objet CArc  
		/* Nécessite : L'objet CArc doit être valide  
		/* Sortie : Un nouvel objet CArc avec les sommets inversés  
		/* Entraîne : Crée un nouvel arc avec les sommets de départ  
		/*            et d'arrivée échangés  
		/***********************************************************/  
		CArc<T> ARCInverserArc(const CArc<T>& arc);  
};

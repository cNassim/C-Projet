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
		vector<CSommet<T>*> GRASom; // Liste des sommets du graphe orienté  
		vector<CArc<T>*> GRAArc;    // Liste des arcs du graphe orienté  

	//METHODES  
	public:  
		/***********************************************************  
		/* CGraphOrient  
		/***********************************************************  
		/* Entrée : Rien  
		/* Nécessite : Rien  
		/* Sortie : Rien  
		/* Entraîne : Les attributs de CGraphOrient sont initialisés  
		/***********************************************************/  
		CGraphOrient();  

		/***********************************************************  
		/* CGraphOrient (constructeur avec paramètres)  
		/***********************************************************  
		/* Entrée : Un vecteur de pointeurs vers des sommets et un vecteur de pointeurs vers des arcs  
		/* Nécessite : Les vecteurs doivent être valides  
		/* Sortie : Rien  
		/* Entraîne : Les attributs sont initialisés avec les valeurs fournies  
		/***********************************************************/  
		CGraphOrient(const vector<CSommet<T>*>& sommet, const vector<CArc<T>*>& arc);

		/***********************************************************  
		/* CGraphOrient (constructeur de copie)  
		/***********************************************************  
		/* Entrée : Une référence constante vers un autre graphe orienté  
		/* Nécessite : Le graphe doit être valide  
		/* Sortie : Rien  
		/* Entraîne : Une copie du graphe est créée  
		/***********************************************************/  
		CGraphOrient(const CGraphOrient& GraphOrient);

		/***********************************************************  
		/* ~CGraphOrient (destructeur)  
		/***********************************************************  
		/* Entrée : Rien  
		/* Nécessite : Rien  
		/* Sortie : Rien  
		/* Entraîne : Les ressources allouées sont libérées  
		/***********************************************************/  
		~CGraphOrient();  

		/***********************************************************  
		/* CGraphOAjouterSommet  
		/***********************************************************  
		/* Entrée : Un pointeur vers un sommet  
		/* Nécessite : Le sommet doit être valide  
		/* Sortie : Rien  
		/* Entraîne : Le sommet est ajouté au graphe  
		/***********************************************************/  
		void CGraphOAjouterSommet(CSommet<T>* Som);

		/***********************************************************  
		/* CGraphOAjouterArc  
		/***********************************************************  
		/* Entrée : Un pointeur vers un arc  
		/* Nécessite : L'arc doit être valide  
		/* Sortie : Rien  
		/* Entraîne : L'arc est ajouté au graphe  
		/***********************************************************/  
		virtual void CGraphOAjouterArc(CArc<T>* Arc);  

		/***********************************************************  
		/* CGraphOGET_Sommet  
		/***********************************************************  
		/* Entrée : Rien  
		/* Nécessite : Rien  
		/* Sortie : Un vecteur contenant les sommets du graphe  
		/* Entraîne : Aucun effet de bord  
		/***********************************************************/  
		vector<CSommet<T>*> CGraphOGET_Sommet() const;

		/***********************************************************  
		/* CGraphOGET_Arc  
		/***********************************************************  
		/* Entrée : Rien  
		/* Nécessite : Rien  
		/* Sortie : Un vecteur contenant les arcs du graphe  
		/* Entraîne : Aucun effet de bord  
		/***********************************************************/  
		vector<CArc<T>*> CGraphOGET_Arc() const;

		/***********************************************************  
		/* CGraphOModifierSommet  
		/***********************************************************  
		/* Entrée : Un identifiant de sommet et un pointeur vers un sommet  
		/* Nécessite : L'identifiant doit être valide  
		/* Sortie : Rien  
		/* Entraîne : Le sommet correspondant est modifié  
		/***********************************************************/  
		void CGraphOModifierSommet(unsigned int uiIdsom, CSommet<T>* Som);

		/***********************************************************  
		/* CGraphOModifierArc  
		/***********************************************************  
		/* Entrée : Un pointeur vers l'arc à modifier et un pointeur vers le nouvel arc  
		/* Nécessite : Les arcs doivent être valides  
		/* Sortie : Rien  
		/* Entraîne : L'arc correspondant est modifié  
		/***********************************************************/  
		void CGraphOModifierArc(CArc<T>* arcToModify, CArc<T>* newArc);

		/***********************************************************  
		/* CGraphOSupprimerSommet  
		/***********************************************************  
		/* Entrée : Un identifiant de sommet  
		/* Nécessite : L'identifiant doit être valide  
		/* Sortie : Rien  
		/* Entraîne : Le sommet correspondant est supprimé  
		/***********************************************************/  
		void CGraphOSupprimerSommet(unsigned int uiIdsom);  

		/***********************************************************  
		/* CGraphOSupprimerArc  
		/***********************************************************  
		/* Entrée : Un pointeur vers l'arc à supprimer  
		/* Nécessite : L'arc doit être valide  
		/* Sortie : Rien  
		/* Entraîne : L'arc correspondant est supprimé  
		/***********************************************************/  
		void CGraphOSupprimerArc(CArc<T>* arcToDelete);  

		/***********************************************************  
		/* CGraphOAfficher  
		/***********************************************************  
		/* Entrée : Rien  
		/* Nécessite : Rien  
		/* Sortie : Rien  
		/* Entraîne : Les informations du graphe sont affichées  
		/***********************************************************/  
		void CGraphOAfficher() const;  

		/***********************************************************  
		/* CGraphOChercherSommetParId  
		/***********************************************************  
		/* Entrée : Un identifiant de sommet  
		/* Nécessite : L'identifiant doit être valide  
		/* Sortie : Un pointeur vers le sommet correspondant ou nullptr si non trouvé  
		/* Entraîne : Aucun effet de bord  
		/***********************************************************/  
		CSommet<T>* CGraphOChercherSommetParId(unsigned int uiIdsom) const;
};
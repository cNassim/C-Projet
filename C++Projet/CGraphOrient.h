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
		vector<CSommet<T>*> GRASom; // Liste des sommets du graphe orient�  
		vector<CArc<T>*> GRAArc;    // Liste des arcs du graphe orient�  

	//METHODES  
	public:  
		/***********************************************************  
		/* CGraphOrient  
		/***********************************************************  
		/* Entr�e : Rien  
		/* N�cessite : Rien  
		/* Sortie : Rien  
		/* Entra�ne : Les attributs de CGraphOrient sont initialis�s  
		/***********************************************************/  
		CGraphOrient();  

		/***********************************************************  
		/* CGraphOrient (constructeur avec param�tres)  
		/***********************************************************  
		/* Entr�e : Un vecteur de pointeurs vers des sommets et un vecteur de pointeurs vers des arcs  
		/* N�cessite : Les vecteurs doivent �tre valides  
		/* Sortie : Rien  
		/* Entra�ne : Les attributs sont initialis�s avec les valeurs fournies  
		/***********************************************************/  
		CGraphOrient(const vector<CSommet<T>*>& sommet, const vector<CArc<T>*>& arc);

		/***********************************************************  
		/* CGraphOrient (constructeur de copie)  
		/***********************************************************  
		/* Entr�e : Une r�f�rence constante vers un autre graphe orient�  
		/* N�cessite : Le graphe doit �tre valide  
		/* Sortie : Rien  
		/* Entra�ne : Une copie du graphe est cr��e  
		/***********************************************************/  
		CGraphOrient(const CGraphOrient& GraphOrient);

		/***********************************************************  
		/* ~CGraphOrient (destructeur)  
		/***********************************************************  
		/* Entr�e : Rien  
		/* N�cessite : Rien  
		/* Sortie : Rien  
		/* Entra�ne : Les ressources allou�es sont lib�r�es  
		/***********************************************************/  
		virtual ~CGraphOrient();  

		/***********************************************************  
		/* CGraphOAjouterSommet  
		/***********************************************************  
		/* Entr�e : Un pointeur vers un sommet  
		/* N�cessite : Le sommet doit �tre valide  
		/* Sortie : Rien  
		/* Entra�ne : Le sommet est ajout� au graphe  
		/***********************************************************/  
		void CGraphOAjouterSommet(CSommet<T>* Som);

		/***********************************************************  
		/* CGraphOAjouterArc  
		/***********************************************************  
		/* Entr�e : Un pointeur vers un arc  
		/* N�cessite : L'arc doit �tre valide  
		/* Sortie : Rien  
		/* Entra�ne : L'arc est ajout� au graphe  
		/***********************************************************/  
		virtual void CGraphOAjouterArc(CArc<T>* Arc);  

		/***********************************************************  
		/* CGraphOGET_Sommet  
		/***********************************************************  
		/* Entr�e : Rien  
		/* N�cessite : Rien  
		/* Sortie : Un vecteur contenant les sommets du graphe  
		/* Entra�ne : Aucun effet de bord  
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
		const vector<CArc<T>*> CGraphOGET_Arc() const;

		/***********************************************************  
		/* CGraphOGET_Arc (surcharge)  
		/***********************************************************  
		/* Entrée : Rien  
		/* Nécessite : Rien  
		/* Sortie : Une référence vers un vecteur contenant les arcs du graphe  
		/* Entraîne : Aucun effet de bord  
		/***********************************************************/  
		vector<CArc<T>*>& CGraphOGET_Arc();



		/***********************************************************  
		/* CGraphOModifierSommet  
		/***********************************************************  
		/* Entr�e : Un identifiant de sommet et un pointeur vers un sommet  
		/* N�cessite : L'identifiant doit �tre valide  
		/* Sortie : Rien  
		/* Entra�ne : Le sommet correspondant est modifi�  
		/***********************************************************/  
		void CGraphOModifierSommet(unsigned int uiIdsom, CSommet<T>* Som);

		/***********************************************************  
		/* CGraphOModifierArc  
		/***********************************************************  
		/* Entr�e : Un pointeur vers l'arc � modifier et un pointeur vers le nouvel arc  
		/* N�cessite : Les arcs doivent �tre valides  
		/* Sortie : Rien  
		/* Entra�ne : L'arc correspondant est modifi�  
		/***********************************************************/  
		void CGraphOModifierArc(CArc<T>* arcToModify, CArc<T>* newArc);

		/***********************************************************  
		/* CGraphOSupprimerSommet  
		/***********************************************************  
		/* Entr�e : Un identifiant de sommet  
		/* N�cessite : L'identifiant doit �tre valide  
		/* Sortie : Rien  
		/* Entra�ne : Le sommet correspondant est supprim�  
		/***********************************************************/  
		void CGraphOSupprimerSommet(unsigned int uiIdsom);  

		/***********************************************************  
		/* CGraphOSupprimerArc  
		/***********************************************************  
		/* Entr�e : Un pointeur vers l'arc � supprimer  
		/* N�cessite : L'arc doit �tre valide  
		/* Sortie : Rien  
		/* Entra�ne : L'arc correspondant est supprim�  
		/***********************************************************/  
		void CGraphOSupprimerArc(CArc<T>* arcToDelete);  

		/***********************************************************  
		/* CGraphOAfficher  
		/***********************************************************  
		/* Entr�e : Rien  
		/* N�cessite : Rien  
		/* Sortie : Rien  
		/* Entra�ne : Les informations du graphe sont affich�es  
		/***********************************************************/  
		void CGraphOAfficher() const;  

		/***********************************************************  
		/* CGraphOChercherSommetParId  
		/***********************************************************  
		/* Entr�e : Un identifiant de sommet  
		/* N�cessite : L'identifiant doit �tre valide  
		/* Sortie : Un pointeur vers le sommet correspondant ou nullptr si non trouv�  
		/* Entra�ne : Aucun effet de bord  
		/***********************************************************/  
		CSommet<T>* CGraphOChercherSommetParId(unsigned int uiIdsom) const;
};
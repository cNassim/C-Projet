#pragma once
#include "CArc.h"   
#include "CSommet.h"   
#include "CException.h" 
#include <vector>      
#include <iostream>    
using namespace std;

template <typename T>
class CGraph : public CGraphOrient<T>
{
	// M�THODES
public:

	/***********************************************************
	/* CGraph
	/***********************************************************
	/* Entr�e : Rien
	/* N�cessite : Rien
	/* Sortie : Rien
	/* Entra�ne : Un graphe non orient� vide est cr��
	/***********************************************************/
	CGraph();

	/***********************************************************
	/* CGraph
	/***********************************************************
	/* Entr�e : Un vecteur de sommets et un vecteur d'arcs
	/* N�cessite : Les vecteurs doivent �tre valides
	/* Sortie : Rien
	/* Entra�ne : Le graphe est initialis� (les arcs doivent �tre sym�triques)
	/***********************************************************/
	CGraph(const std::vector<CSommet<T>*>& sommets, const std::vector<CArc<T>*>& arcs);

	/***********************************************************
	/* CGraph (constructeur de copie)
	/***********************************************************
	/* Entr�e : Un objet CGraph
	/* N�cessite : L'objet doit �tre valide
	/* Sortie : Rien
	/* Entra�ne : Une copie de l'objet est cr��e
	/***********************************************************/
	CGraph(const CGraph& other);

	/***********************************************************
	/* ~CGraph (destructeur)
	/***********************************************************
	/* Entr�e : Rien
	/* N�cessite : Rien
	/* Sortie : Rien
	/* Entra�ne : Lib�re les ressources du graphe
	/***********************************************************/
	~CGraph();

	/***********************************************************
	/* CGraphOAjouterArc
	/***********************************************************
	/* Entr�e : Un pointeur vers un arc
	/* N�cessite : L'arc doit �tre valide
	/* Sortie : Rien
	/* Entra�ne : L'arc est ajout� au graphe avec son sym�trique
	/***********************************************************/
	void CGraphOAjouterArc(CArc<T>* arc) override;

	/***********************************************************
	/* CGraphOSupprimerArc
	/***********************************************************
	/* Entr�e : Un identifiant d'arc
	/* N�cessite : L'identifiant doit �tre valide
	/* Sortie : Rien
	/* Entra�ne : L'arc et son sym�trique sont supprim�s du graphe
	/***********************************************************/
	void CGraphOSupprimerArc(unsigned int uiIdarc) override;

};

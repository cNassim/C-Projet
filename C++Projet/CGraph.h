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
	// MÉTHODES
public:

	/***********************************************************
	/* CGraph
	/***********************************************************
	/* Entrée : Rien
	/* Nécessite : Rien
	/* Sortie : Rien
	/* Entraîne : Un graphe non orienté vide est créé
	/***********************************************************/
	CGraph();

	/***********************************************************
	/* CGraph
	/***********************************************************
	/* Entrée : Un vecteur de sommets et un vecteur d'arcs
	/* Nécessite : Les vecteurs doivent être valides
	/* Sortie : Rien
	/* Entraîne : Le graphe est initialisé (les arcs doivent être symétriques)
	/***********************************************************/
	CGraph(const std::vector<CSommet<T>*>& sommets, const std::vector<CArc<T>*>& arcs);

	/***********************************************************
	/* CGraph (constructeur de copie)
	/***********************************************************
	/* Entrée : Un objet CGraph
	/* Nécessite : L'objet doit être valide
	/* Sortie : Rien
	/* Entraîne : Une copie de l'objet est créée
	/***********************************************************/
	CGraph(const CGraph& other);

	/***********************************************************
	/* ~CGraph (destructeur)
	/***********************************************************
	/* Entrée : Rien
	/* Nécessite : Rien
	/* Sortie : Rien
	/* Entraîne : Libère les ressources du graphe
	/***********************************************************/
	~CGraph();

	/***********************************************************
	/* CGraphOAjouterArc
	/***********************************************************
	/* Entrée : Un pointeur vers un arc
	/* Nécessite : L'arc doit être valide
	/* Sortie : Rien
	/* Entraîne : L'arc est ajouté au graphe avec son symétrique
	/***********************************************************/
	void CGraphOAjouterArc(CArc<T>* arc) override;

	/***********************************************************
	/* CGraphOSupprimerArc
	/***********************************************************
	/* Entrée : Un identifiant d'arc
	/* Nécessite : L'identifiant doit être valide
	/* Sortie : Rien
	/* Entraîne : L'arc et son symétrique sont supprimés du graphe
	/***********************************************************/
	void CGraphOSupprimerArc(unsigned int uiIdarc) override;

};

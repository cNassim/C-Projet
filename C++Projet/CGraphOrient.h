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
	vector<CSommet<T>*> GRASom;
	vector<CArc<T>*> GRAArc;

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
	/* CGraphOrient
	/***********************************************************
	/* Entrée : sommet : Un vecteur de pointeurs vers des objets CSommet
	/*          arc : Un vecteur de pointeurs vers des objets CArc
	/* Nécessite : Rien
	/* Sortie : Rien
	/* Entraîne : Les attributs de CGraphOrient sont initialisés avec les valeurs données
	/***********************************************************/
	CGraphOrient(const vector<CSommet<T>*> sommet,const vector<CArc<T>*> arc);
	
	/***********************************************************
	/* CGraphOrient
	/***********************************************************
	/* Entrée : GraphOrient : Un objet de la classe CGraphOrient
	/* Nécessite : Rien
	/* Sortie : Rien
	/* Entraîne : Les attributs de CGraphOrient sont initialisés avec les valeurs de l'objet GraphOrient
	/***********************************************************/
	CGraphOrient(const CGraphOrient& GraphOrient);
	

	/***********************************************************
	/* ~CGraphOrient
	/***********************************************************
	/* Entrée : Rien
	/* Nécessite : Rien
	/* Sortie : Rien
	/* Entraîne : Les attributs de CGraphOrient sont libérés
	/***********************************************************/
	~CGraphOrient();
	
	/***********************************************************
	/* CGraphOAjouterSommet
	/***********************************************************
	/* Entrée : Som : Pointeur vers un objet CSommet
	/* Nécessite : Rien
	/* Sortie : Rien
	/* Entraîne : Ajoute le sommet au vecteur GRASom
	/***********************************************************/
	void CGraphOAjouterSommet(CSommet<T>* Som);
	
	
	/***********************************************************
	/* CGraphOAjouterArc
	/***********************************************************
	/* Entrée : Arc : Pointeur vers un objet CArc
	/* Nécessite : Rien
	/* Sortie : Rien
	/* Entraîne : Ajoute l'arc au vecteur GRAArc
	/***********************************************************/
	void CGraphOAjouterArc(CArc<T>* Arc);
	
	/***********************************************************
	/* CGraphOGET_Sommet
	/***********************************************************
	/* Entrée : Rien
	/* Nécessite : Rien
	/* Sortie : Un vecteur de pointeurs vers des objets CSommet
	/* Entraîne : Rien
	/***********************************************************/
	vector<CSommet<T>*>CGraphOGET_Sommet() const;
	
	
	/***********************************************************
	/* CGraphOGET_Arc
	/***********************************************************
	/* Entrée : Rien
	/* Nécessite : Rien
	/* Sortie : Un vecteur de pointeurs vers des objets CArc
	/* Entraîne : Rien
	/***********************************************************/
	vector<CArc<T>*> CGraphOGET_Arc() const;
	
	/***********************************************************
	/* CGraphOModifierSommet
	/***********************************************************
	/* Entrée : uiIdsom : Identifiant du sommet
	/*          Som : Pointeur vers un objet CSommet
	/* Nécessite : Rien
	/* Sortie : Rien
	/* Entraîne : Modifie le sommet avec l'identifiant donné
	/***********************************************************/
	void CGraphOModifierSommet(unsigned int uiIdsom, CSommet<T>* Som);
	

	/***********************************************************
	/* CGraphOModifierArc
	/***********************************************************
	/* Entrée : uiIdarc : Identifiant de l'arc
	/*          Arc : Pointeur vers un objet CArc
	/* Nécessite : Rien
	/* Sortie : Rien
	/* Entraîne : Modifie l'arc avec l'identifiant donné
	/***********************************************************/
	void CGraphOModifierArc(unsigned int uiIdarc, CArc<T>* Arc);
	
	/***********************************************************
	/* CGraphOSupprimerSommet
	/***********************************************************
	/* Entrée : uiIdsom : Identifiant du sommet
	/* Nécessite : Rien
	/* Sortie : Rien
	/* Entraîne : Supprime le sommet avec l'identifiant donné
	/***********************************************************/
	void CGraphOSupprimerSommet(unsigned int uiIdsom);
	
	/***********************************************************
	 /* CGraphOSupprimerArc
	 /***********************************************************
	 /* Entrée : uiIdarc : Identifiant de l'arc
	 /* Nécessite : Rien
	 /* Sortie : Rien
	 /* Entraîne : Supprime l'arc avec l'identifiant donné
	 /***********************************************************/
	void CGraphOSupprimerArc(unsigned int uiIdarc);
	
	/***********************************************************
	/* CGraphOAfficher
	/***********************************************************
	/* Entrée : Rien
	/* Nécessite : Rien
	/* Sortie : Rien
	/* Entraîne : Affiche les informations des sommets et des arcs
	/***********************************************************/
	void CGraphOAfficher();

};
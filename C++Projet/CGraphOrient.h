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
	/* Entr�e : Rien
	/* N�cessite : Rien
	/* Sortie : Rien
	/* Entra�ne : Les attributs de CGraphOrient sont initialis�s
	/***********************************************************/
	CGraphOrient();
	
	/***********************************************************
	/* CGraphOrient
	/***********************************************************
	/* Entr�e : sommet : Un vecteur de pointeurs vers des objets CSommet
	/*          arc : Un vecteur de pointeurs vers des objets CArc
	/* N�cessite : Rien
	/* Sortie : Rien
	/* Entra�ne : Les attributs de CGraphOrient sont initialis�s avec les valeurs donn�es
	/***********************************************************/
	CGraphOrient(const vector<CSommet<T>*> sommet,const vector<CArc<T>*> arc);
	
	/***********************************************************
	/* CGraphOrient
	/***********************************************************
	/* Entr�e : GraphOrient : Un objet de la classe CGraphOrient
	/* N�cessite : Rien
	/* Sortie : Rien
	/* Entra�ne : Les attributs de CGraphOrient sont initialis�s avec les valeurs de l'objet GraphOrient
	/***********************************************************/
	CGraphOrient(const CGraphOrient& GraphOrient);
	

	/***********************************************************
	/* ~CGraphOrient
	/***********************************************************
	/* Entr�e : Rien
	/* N�cessite : Rien
	/* Sortie : Rien
	/* Entra�ne : Les attributs de CGraphOrient sont lib�r�s
	/***********************************************************/
	~CGraphOrient();
	
	/***********************************************************
	/* CGraphOAjouterSommet
	/***********************************************************
	/* Entr�e : Som : Pointeur vers un objet CSommet
	/* N�cessite : Rien
	/* Sortie : Rien
	/* Entra�ne : Ajoute le sommet au vecteur GRASom
	/***********************************************************/
	void CGraphOAjouterSommet(CSommet<T>* Som);
	
	
	/***********************************************************
	/* CGraphOAjouterArc
	/***********************************************************
	/* Entr�e : Arc : Pointeur vers un objet CArc
	/* N�cessite : Rien
	/* Sortie : Rien
	/* Entra�ne : Ajoute l'arc au vecteur GRAArc
	/***********************************************************/
	void CGraphOAjouterArc(CArc<T>* Arc);
	
	/***********************************************************
	/* CGraphOGET_Sommet
	/***********************************************************
	/* Entr�e : Rien
	/* N�cessite : Rien
	/* Sortie : Un vecteur de pointeurs vers des objets CSommet
	/* Entra�ne : Rien
	/***********************************************************/
	vector<CSommet<T>*>CGraphOGET_Sommet() const;
	
	
	/***********************************************************
	/* CGraphOGET_Arc
	/***********************************************************
	/* Entr�e : Rien
	/* N�cessite : Rien
	/* Sortie : Un vecteur de pointeurs vers des objets CArc
	/* Entra�ne : Rien
	/***********************************************************/
	vector<CArc<T>*> CGraphOGET_Arc() const;
	
	/***********************************************************
	/* CGraphOModifierSommet
	/***********************************************************
	/* Entr�e : uiIdsom : Identifiant du sommet
	/*          Som : Pointeur vers un objet CSommet
	/* N�cessite : Rien
	/* Sortie : Rien
	/* Entra�ne : Modifie le sommet avec l'identifiant donn�
	/***********************************************************/
	void CGraphOModifierSommet(unsigned int uiIdsom, CSommet<T>* Som);
	

	/***********************************************************
	/* CGraphOModifierArc
	/***********************************************************
	/* Entr�e : uiIdarc : Identifiant de l'arc
	/*          Arc : Pointeur vers un objet CArc
	/* N�cessite : Rien
	/* Sortie : Rien
	/* Entra�ne : Modifie l'arc avec l'identifiant donn�
	/***********************************************************/
	void CGraphOModifierArc(unsigned int uiIdarc, CArc<T>* Arc);
	
	/***********************************************************
	/* CGraphOSupprimerSommet
	/***********************************************************
	/* Entr�e : uiIdsom : Identifiant du sommet
	/* N�cessite : Rien
	/* Sortie : Rien
	/* Entra�ne : Supprime le sommet avec l'identifiant donn�
	/***********************************************************/
	void CGraphOSupprimerSommet(unsigned int uiIdsom);
	
	/***********************************************************
	 /* CGraphOSupprimerArc
	 /***********************************************************
	 /* Entr�e : uiIdarc : Identifiant de l'arc
	 /* N�cessite : Rien
	 /* Sortie : Rien
	 /* Entra�ne : Supprime l'arc avec l'identifiant donn�
	 /***********************************************************/
	void CGraphOSupprimerArc(unsigned int uiIdarc);
	
	/***********************************************************
	/* CGraphOAfficher
	/***********************************************************
	/* Entr�e : Rien
	/* N�cessite : Rien
	/* Sortie : Rien
	/* Entra�ne : Affiche les informations des sommets et des arcs
	/***********************************************************/
	void CGraphOAfficher();

};
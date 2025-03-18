#pragma once
#include "CSommet.h"
class CArc
{
	//ATTRIBUTS
	private:
		unsigned int uiARCSomDeb;
		unsigned int uiARCSomA;
		unsigned int uiARCIdArc;
		unsigned int uiARCDistance;
		unsigned int uiARCCap;
		unsigned int uiARCPoids;
	
	//METHODES
	public:
		/***********************************************************
		/* CArc
		/************************************************************
		/* Entr�e : Rien
		/* N�cessite : Rien
		/* Sortie : Rien
		/* Entra�ne : Les attributs de CARC sont initialis�s � NULL
		/************************************************************/
		CArc();
		
		/***********************************************************
		/* CArc
		/************************************************************
		/* Entr�e : uiSomDeb : La valeur avec laquelle iARCSomDeb sera initialis�,
		/*			uiSomA : La valeur avec laquelle iARCSomA sera initialis�,
		/*			uiIdArc : La valeur avec laquelle iARCIdArc sera initialis�,
		/*			uiDistance : La valeur avec laquelle iARCDistance sera initialis�,
		/*			uiCap : La valeur avec laquelle iARCCap sera initialis�,
		/*			uiPoids : La valeur avec laquelle iARCPoids sera initialis�.
		/*
		/* N�cessite : Rien
		/* Sortie : Rien
		/* Entra�ne : Les attributs de CARC sont initialis�s avec des valeurs donner.
		/************************************************************/
		CArc(unsigned int uiSomDeb,unsigned int uiSomA,unsigned int uiIdArc,unsigned int uiDistance,unsigned int uiCap,unsigned int uiPoids);

		/***********************************************************
		/* CArc
		/************************************************************
		/* Entr�e : Arc : un objet de la classe CARC
		/* N�cessite : Rien
		/* Sortie : Rien
		/* Entra�ne : Les attributs de CARC sont initialis�s avec les valeurs de l'objet ARC
		/************************************************************/
		CArc(const CArc& Arc);

		
		/***********************************************************
		/* CArc
		/************************************************************
		/* Entr�e : Rien
		/* N�cessite : Rien
		/* Sortie : Rien
		/* Entra�ne : L'Arc est detruit et lib�r�
		/************************************************************/
		~CArc();

		/***********************************************************
		/* ARCGet_SomDeb
		/************************************************************
		/* Entr�e : Rien
		/* N�cessite : Rien
		/* Sortie : La valeur de uiARCSomDeb
		/* Entra�ne : Rien
		/************************************************************/
		unsigned int ARCGet_SomDeb() const ;

		/***********************************************************
		/* ARCGet_SomA
		/************************************************************
		/* Entr�e : Rien
		/* N�cessite : Rien
		/* Sortie : La valeur de uiARCSomA
		/* Entra�ne : Rien
		/************************************************************/
		unsigned int ARCGet_SomA() const;

		/***********************************************************
		/* ARCGet_IdArc
		/************************************************************
		/* Entr�e : Rien
		/* N�cessite : Rien
		/* Sortie : La valeur de uiARCIdArc
		/* Entra�ne : Rien
		/************************************************************/
		unsigned int ARCGet_IdArc() const;

		/***********************************************************
		/* ARCGet_Distance
		/************************************************************
		/* Entr�e : Rien
		/* N�cessite : Rien
		/* Sortie : La valeur de uiARCDistance
		/* Entra�ne : Rien
		/************************************************************/
		unsigned int ARCGet_Distance() const;

		/***********************************************************
		/* ARCGet_Cap
		/************************************************************
		/* Entr�e : Rien
		/* N�cessite : Rien
		/* Sortie : La valeur de uiARCCap
		/* Entra�ne : Rien
		/************************************************************/
		unsigned int ARCGet_Cap() const ;

		/***********************************************************
		/* ARCGetPoids
		/************************************************************
		/* Entr�e : Rien
		/* N�cessite : Rien
		/* Sortie : La valeur de uiARCPoids
		/* Entra�ne : Rien
		/************************************************************/
		unsigned int ARCGet_Poids() const;

		/***********************************************************
		/* ARCAjouterSomDeb
		/************************************************************
		/* Entr�e : SommetDeb : Pointeur vers un objet CSommet
		/* N�cessite : Rien
		/* Sortie : Rien
		/* Entra�ne : uiARCSomDeb est mis � jour avec l'identifiant du sommet
		/************************************************************/
		void ARCAjouterSomDeb(CSommet* SommetDeb);

		/***********************************************************
		/* ARCAjouterSomA
		/************************************************************
		/* Entr�e : SommetA : Pointeur vers un objet CSommet
		/* N�cessite : Rien
		/* Sortie : Rien
		/* Entra�ne : uiARCSomA est mis � jour avec l'identifiant du sommet
		/************************************************************/
		void ARCAjouterSomA(CSommet* SommetA);

		/***********************************************************
		/* ARCModifierSomDeb
		/************************************************************
		/* Entr�e : uiIdArc : Identifiant de l'arc
		/*          SommetDeb : Pointeur vers un objet CSommet
		/* N�cessite : Rien
		/* Sortie : Rien
		/* Entra�ne : uiARCSomDeb est mis � jour avec l'identifiant du sommet
		/************************************************************/
		void ARCModifierSomDeb(unsigned int uiIdArc, CSommet* SommetDeb);

		/***********************************************************
		/* ARCModifierSomA
		/************************************************************
		/* Entr�e : uiIdArc : Identifiant de l'arc
		/*          SommetA : Pointeur vers un objet CSommet
		/* N�cessite : Rien
		/* Sortie : Rien
		/* Entra�ne : uiARCSomA est mis � jour avec l'identifiant du sommet
		/************************************************************/
		void ARCModifierSomA(unsigned int uiIdArc, CSommet* SommetA);

		/***********************************************************
		/* ARCSet_IdArc
		/************************************************************
		/* Entr�e : iIdArc : Nouvelle valeur pour iARCIdArc
		/* N�cessite : Rien
		/* Sortie : Rien
		/* Entra�ne : iARCIdArc est mis � jour
		/************************************************************/
		void ARCSet_IdArc(unsigned int uiIdArc);

		/***********************************************************
		/* ARCSet_Distance
		/************************************************************
		/* Entr�e : iDistance : Nouvelle valeur pour iARCDistance
		/* N�cessite : Rien
		/* Sortie : Rien
		/* Entra�ne : iARCDistance est mis � jour
		/************************************************************/
		void ARCSet_Distance(unsigned int uiDistance);

		/***********************************************************
		/* ARCSet_Cap
		/************************************************************
		/* Entr�e : iCap : Nouvelle valeur pour iARCCap
		/* N�cessite : Rien
		/* Sortie : Rien
		/* Entra�ne : iARCCap est mis � jour
		/************************************************************/
		void ARCSet_Cap(unsigned int uiCap);

		/***********************************************************
		/* ARCSetPoids
		/************************************************************
		/* Entr�e : iPoids : Nouvelle valeur pour iARCPoids
		/* N�cessite : Rien
		/* Sortie : Rien
		/* Entra�ne : iARCPoids est mis � jour
		/************************************************************/
		void ARCSetPoids(unsigned int uiPoids);

		/***********************************************************
		/* ARCAfficher
		/************************************************************
		/* Entr�e : Rien
		/* N�cessite : Rien
		/* Sortie : Rien
		/* Entra�ne : Affiche les informations de l'arc
		/************************************************************/
		void ARCAfficher();
};

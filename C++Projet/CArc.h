#pragma once
#include "CSommet.h"
class CArc
{
	//ATTRIBUTS
	private:
		unsigned int iARCSomDeb;
		unsigned int iARCSomA;
		unsigned int iARCIdArc;
		unsigned int iARCDistance;
		unsigned int iARCCap;
		unsigned int iARCPoids;
	
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
		/* Entr�e : iSomDeb : La valeur avec laquelle iARCSomDeb sera initialis�,
		/*			iSomA : La valeur avec laquelle iARCSomA sera initialis�,
		/*			iIdArc : La valeur avec laquelle iARCIdArc sera initialis�,
		/*			iDistance : La valeur avec laquelle iARCDistance sera initialis�,
		/*			iCap : La valeur avec laquelle iARCCap sera initialis�,
		/*			iPoids : La valeur avec laquelle iARCPoids sera initialis�.
		/*
		/* N�cessite : Rien
		/* Sortie : Rien
		/* Entra�ne : Les attributs de CARC sont initialis�s avec des valeurs donner.
		/************************************************************/
		CArc(unsigned int iSomDeb,unsigned int iSomA,unsigned int iIdArc,unsigned int iDistance,unsigned int iCap,unsigned int iPoids);

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
		/* Sortie : La valeur de iARCSomDeb
		/* Entra�ne : Rien
		/************************************************************/
		unsigned int ARCGet_SomDeb();

		/***********************************************************
		/* ARCGet_SomA
		/************************************************************
		/* Entr�e : Rien
		/* N�cessite : Rien
		/* Sortie : La valeur de iARCSomA
		/* Entra�ne : Rien
		/************************************************************/
		unsigned int ARCGet_SomA();

		/***********************************************************
		/* ARCGet_IdArc
		/************************************************************
		/* Entr�e : Rien
		/* N�cessite : Rien
		/* Sortie : La valeur de iARCIdArc
		/* Entra�ne : Rien
		/************************************************************/
		unsigned int ARCGet_IdArc();

		/***********************************************************
		/* ARCGet_Distance
		/************************************************************
		/* Entr�e : Rien
		/* N�cessite : Rien
		/* Sortie : La valeur de iARCDistance
		/* Entra�ne : Rien
		/************************************************************/
		unsigned int ARCGet_Distance();

		/***********************************************************
		/* ARCGet_Cap
		/************************************************************
		/* Entr�e : Rien
		/* N�cessite : Rien
		/* Sortie : La valeur de iARCCap
		/* Entra�ne : Rien
		/************************************************************/
		unsigned int ARCGet_Cap();

		/***********************************************************
		/* ARCGetPoids
		/************************************************************
		/* Entr�e : Rien
		/* N�cessite : Rien
		/* Sortie : La valeur de iARCPoids
		/* Entra�ne : Rien
		/************************************************************/
		unsigned int ARCGetPoids();

		/***********************************************************
		/* ARCAjouterSomDeb
		/************************************************************
		/* Entr�e : SommetDeb : Pointeur vers un objet CSommet
		/* N�cessite : Rien
		/* Sortie : Rien
		/* Entra�ne : iARCSomDeb est mis � jour avec l'identifiant du sommet
		/************************************************************/
		void ARCAjouterSomDeb(CSommet* SommetDeb);

		/***********************************************************
		/* ARCAjouterSomA
		/************************************************************
		/* Entr�e : SommetA : Pointeur vers un objet CSommet
		/* N�cessite : Rien
		/* Sortie : Rien
		/* Entra�ne : iARCSomA est mis � jour avec l'identifiant du sommet
		/************************************************************/
		void ARCAjouterSomA(CSommet* SommetA);

		/***********************************************************
		/* ARCModifierSomDeb
		/************************************************************
		/* Entr�e : iIdArc : Identifiant de l'arc
		/*          SommetDeb : Pointeur vers un objet CSommet
		/* N�cessite : Rien
		/* Sortie : Rien
		/* Entra�ne : iARCSomDeb est mis � jour avec l'identifiant du sommet
		/************************************************************/
		void ARCModifierSomDeb(unsigned int iIdArc, CSommet* SommetDeb);

		/***********************************************************
		/* ARCModifierSomA
		/************************************************************
		/* Entr�e : iIdArc : Identifiant de l'arc
		/*          SommetA : Pointeur vers un objet CSommet
		/* N�cessite : Rien
		/* Sortie : Rien
		/* Entra�ne : iARCSomA est mis � jour avec l'identifiant du sommet
		/************************************************************/
		void ARCModifierSomA(unsigned int iIdArc, CSommet* SommetA);

		/***********************************************************
		/* ARCSet_IdArc
		/************************************************************
		/* Entr�e : iIdArc : Nouvelle valeur pour iARCIdArc
		/* N�cessite : Rien
		/* Sortie : Rien
		/* Entra�ne : iARCIdArc est mis � jour
		/************************************************************/
		void ARCSet_IdArc(unsigned int iIdArc);

		/***********************************************************
		/* ARCSet_Distance
		/************************************************************
		/* Entr�e : iDistance : Nouvelle valeur pour iARCDistance
		/* N�cessite : Rien
		/* Sortie : Rien
		/* Entra�ne : iARCDistance est mis � jour
		/************************************************************/
		void ARCSet_Distance(unsigned int iDistance);

		/***********************************************************
		/* ARCSet_Cap
		/************************************************************
		/* Entr�e : iCap : Nouvelle valeur pour iARCCap
		/* N�cessite : Rien
		/* Sortie : Rien
		/* Entra�ne : iARCCap est mis � jour
		/************************************************************/
		void ARCSet_Cap(unsigned int iCap);

		/***********************************************************
		/* ARCSetPoids
		/************************************************************
		/* Entr�e : iPoids : Nouvelle valeur pour iARCPoids
		/* N�cessite : Rien
		/* Sortie : Rien
		/* Entra�ne : iARCPoids est mis � jour
		/************************************************************/
		void ARCSetPoids(unsigned int iPoids);

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

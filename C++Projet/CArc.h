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
		/* Entrée : Rien
		/* Nécessite : Rien
		/* Sortie : Rien
		/* Entraîne : Les attributs de CARC sont initialisés à NULL
		/************************************************************/
		CArc();
		
		/***********************************************************
		/* CArc
		/************************************************************
		/* Entrée : uiSomDeb : La valeur avec laquelle iARCSomDeb sera initialisé,
		/*			uiSomA : La valeur avec laquelle iARCSomA sera initialisé,
		/*			uiIdArc : La valeur avec laquelle iARCIdArc sera initialisé,
		/*			uiDistance : La valeur avec laquelle iARCDistance sera initialisé,
		/*			uiCap : La valeur avec laquelle iARCCap sera initialisé,
		/*			uiPoids : La valeur avec laquelle iARCPoids sera initialisé.
		/*
		/* Nécessite : Rien
		/* Sortie : Rien
		/* Entraîne : Les attributs de CARC sont initialisés avec des valeurs donner.
		/************************************************************/
		CArc(unsigned int uiSomDeb,unsigned int uiSomA,unsigned int uiIdArc,unsigned int uiDistance,unsigned int uiCap,unsigned int uiPoids);

		/***********************************************************
		/* CArc
		/************************************************************
		/* Entrée : Arc : un objet de la classe CARC
		/* Nécessite : Rien
		/* Sortie : Rien
		/* Entraîne : Les attributs de CARC sont initialisés avec les valeurs de l'objet ARC
		/************************************************************/
		CArc(const CArc& Arc);

		
		/***********************************************************
		/* CArc
		/************************************************************
		/* Entrée : Rien
		/* Nécessite : Rien
		/* Sortie : Rien
		/* Entraîne : L'Arc est detruit et libéré
		/************************************************************/
		~CArc();

		/***********************************************************
		/* ARCGet_SomDeb
		/************************************************************
		/* Entrée : Rien
		/* Nécessite : Rien
		/* Sortie : La valeur de uiARCSomDeb
		/* Entraîne : Rien
		/************************************************************/
		unsigned int ARCGet_SomDeb() const ;

		/***********************************************************
		/* ARCGet_SomA
		/************************************************************
		/* Entrée : Rien
		/* Nécessite : Rien
		/* Sortie : La valeur de uiARCSomA
		/* Entraîne : Rien
		/************************************************************/
		unsigned int ARCGet_SomA() const;

		/***********************************************************
		/* ARCGet_IdArc
		/************************************************************
		/* Entrée : Rien
		/* Nécessite : Rien
		/* Sortie : La valeur de uiARCIdArc
		/* Entraîne : Rien
		/************************************************************/
		unsigned int ARCGet_IdArc() const;

		/***********************************************************
		/* ARCGet_Distance
		/************************************************************
		/* Entrée : Rien
		/* Nécessite : Rien
		/* Sortie : La valeur de uiARCDistance
		/* Entraîne : Rien
		/************************************************************/
		unsigned int ARCGet_Distance() const;

		/***********************************************************
		/* ARCGet_Cap
		/************************************************************
		/* Entrée : Rien
		/* Nécessite : Rien
		/* Sortie : La valeur de uiARCCap
		/* Entraîne : Rien
		/************************************************************/
		unsigned int ARCGet_Cap() const ;

		/***********************************************************
		/* ARCGetPoids
		/************************************************************
		/* Entrée : Rien
		/* Nécessite : Rien
		/* Sortie : La valeur de uiARCPoids
		/* Entraîne : Rien
		/************************************************************/
		unsigned int ARCGet_Poids() const;

		/***********************************************************
		/* ARCAjouterSomDeb
		/************************************************************
		/* Entrée : SommetDeb : Pointeur vers un objet CSommet
		/* Nécessite : Rien
		/* Sortie : Rien
		/* Entraîne : uiARCSomDeb est mis à jour avec l'identifiant du sommet
		/************************************************************/
		void ARCAjouterSomDeb(CSommet* SommetDeb);

		/***********************************************************
		/* ARCAjouterSomA
		/************************************************************
		/* Entrée : SommetA : Pointeur vers un objet CSommet
		/* Nécessite : Rien
		/* Sortie : Rien
		/* Entraîne : uiARCSomA est mis à jour avec l'identifiant du sommet
		/************************************************************/
		void ARCAjouterSomA(CSommet* SommetA);

		/***********************************************************
		/* ARCModifierSomDeb
		/************************************************************
		/* Entrée : uiIdArc : Identifiant de l'arc
		/*          SommetDeb : Pointeur vers un objet CSommet
		/* Nécessite : Rien
		/* Sortie : Rien
		/* Entraîne : uiARCSomDeb est mis à jour avec l'identifiant du sommet
		/************************************************************/
		void ARCModifierSomDeb(unsigned int uiIdArc, CSommet* SommetDeb);

		/***********************************************************
		/* ARCModifierSomA
		/************************************************************
		/* Entrée : uiIdArc : Identifiant de l'arc
		/*          SommetA : Pointeur vers un objet CSommet
		/* Nécessite : Rien
		/* Sortie : Rien
		/* Entraîne : uiARCSomA est mis à jour avec l'identifiant du sommet
		/************************************************************/
		void ARCModifierSomA(unsigned int uiIdArc, CSommet* SommetA);

		/***********************************************************
		/* ARCSet_IdArc
		/************************************************************
		/* Entrée : iIdArc : Nouvelle valeur pour iARCIdArc
		/* Nécessite : Rien
		/* Sortie : Rien
		/* Entraîne : iARCIdArc est mis à jour
		/************************************************************/
		void ARCSet_IdArc(unsigned int uiIdArc);

		/***********************************************************
		/* ARCSet_Distance
		/************************************************************
		/* Entrée : iDistance : Nouvelle valeur pour iARCDistance
		/* Nécessite : Rien
		/* Sortie : Rien
		/* Entraîne : iARCDistance est mis à jour
		/************************************************************/
		void ARCSet_Distance(unsigned int uiDistance);

		/***********************************************************
		/* ARCSet_Cap
		/************************************************************
		/* Entrée : iCap : Nouvelle valeur pour iARCCap
		/* Nécessite : Rien
		/* Sortie : Rien
		/* Entraîne : iARCCap est mis à jour
		/************************************************************/
		void ARCSet_Cap(unsigned int uiCap);

		/***********************************************************
		/* ARCSetPoids
		/************************************************************
		/* Entrée : iPoids : Nouvelle valeur pour iARCPoids
		/* Nécessite : Rien
		/* Sortie : Rien
		/* Entraîne : iARCPoids est mis à jour
		/************************************************************/
		void ARCSetPoids(unsigned int uiPoids);

		/***********************************************************
		/* ARCAfficher
		/************************************************************
		/* Entrée : Rien
		/* Nécessite : Rien
		/* Sortie : Rien
		/* Entraîne : Affiche les informations de l'arc
		/************************************************************/
		void ARCAfficher();
};

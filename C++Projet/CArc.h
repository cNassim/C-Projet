#pragma once
#include "CSommet.h"
class CArc
{
	//ATTRIBUTS
	private:
		int iARCSomDeb;
		int iARCSomA;
		int iARCIdArc;
		int iARCDistance;
		int iARCCap;
		int iARCPoids;
	
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
		/* Entrée : iSomDeb : La valeur avec laquelle iARCSomDeb sera initialisé,
		/*			iSomA : La valeur avec laquelle iARCSomA sera initialisé,
		/*			iIdArc : La valeur avec laquelle iARCIdArc sera initialisé,
		/*			iDistance : La valeur avec laquelle iARCDistance sera initialisé,
		/*			iCap : La valeur avec laquelle iARCCap sera initialisé,
		/*			iPoids : La valeur avec laquelle iARCPoids sera initialisé.
		/*
		/* Nécessite : Rien
		/* Sortie : Rien
		/* Entraîne : Les attributs de CARC sont initialisés avec des valeurs donner.
		/************************************************************/
		CArc(int iSomDeb, int iSomA, int iIdArc, int iDistance, int iCap, int iPoids);

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
		/* Sortie : La valeur de iARCSomDeb
		/* Entraîne : Rien
		/************************************************************/
		int ARCGet_SomDeb();

		/***********************************************************
		/* ARCGet_SomA
		/************************************************************
		/* Entrée : Rien
		/* Nécessite : Rien
		/* Sortie : La valeur de iARCSomA
		/* Entraîne : Rien
		/************************************************************/
		int ARCGet_SomA();

		/***********************************************************
		/* ARCGet_IdArc
		/************************************************************
		/* Entrée : Rien
		/* Nécessite : Rien
		/* Sortie : La valeur de iARCIdArc
		/* Entraîne : Rien
		/************************************************************/
		int ARCGet_IdArc();

		/***********************************************************
		/* ARCGet_Distance
		/************************************************************
		/* Entrée : Rien
		/* Nécessite : Rien
		/* Sortie : La valeur de iARCDistance
		/* Entraîne : Rien
		/************************************************************/
		int ARCGet_Distance();

		/***********************************************************
		/* ARCGet_Cap
		/************************************************************
		/* Entrée : Rien
		/* Nécessite : Rien
		/* Sortie : La valeur de iARCCap
		/* Entraîne : Rien
		/************************************************************/
		int ARCGet_Cap();

		/***********************************************************
		/* ARCGetPoids
		/************************************************************
		/* Entrée : Rien
		/* Nécessite : Rien
		/* Sortie : La valeur de iARCPoids
		/* Entraîne : Rien
		/************************************************************/
		int ARCGetPoids();

		/***********************************************************
		/* ARCAjouterSomDeb
		/************************************************************
		/* Entrée : SommetDeb : Pointeur vers un objet CSommet
		/* Nécessite : Rien
		/* Sortie : Rien
		/* Entraîne : iARCSomDeb est mis à jour avec l'identifiant du sommet
		/************************************************************/
		void ARCAjouterSomDeb(CSommet* SommetDeb);

		/***********************************************************
		/* ARCAjouterSomA
		/************************************************************
		/* Entrée : SommetA : Pointeur vers un objet CSommet
		/* Nécessite : Rien
		/* Sortie : Rien
		/* Entraîne : iARCSomA est mis à jour avec l'identifiant du sommet
		/************************************************************/
		void ARCAjouterSomA(CSommet* SommetA);

		/***********************************************************
		/* ARCModifierSomDeb
		/************************************************************
		/* Entrée : iIdArc : Identifiant de l'arc
		/*          SommetDeb : Pointeur vers un objet CSommet
		/* Nécessite : Rien
		/* Sortie : Rien
		/* Entraîne : iARCSomDeb est mis à jour avec l'identifiant du sommet
		/************************************************************/
		void ARCModifierSomDeb(int iIdArc, CSommet* SommetDeb);

		/***********************************************************
		/* ARCModifierSomA
		/************************************************************
		/* Entrée : iIdArc : Identifiant de l'arc
		/*          SommetA : Pointeur vers un objet CSommet
		/* Nécessite : Rien
		/* Sortie : Rien
		/* Entraîne : iARCSomA est mis à jour avec l'identifiant du sommet
		/************************************************************/
		void ARCModifierSomA(int iIdArc, CSommet* SommetA);

		/***********************************************************
		/* ARCSet_IdArc
		/************************************************************
		/* Entrée : iIdArc : Nouvelle valeur pour iARCIdArc
		/* Nécessite : Rien
		/* Sortie : Rien
		/* Entraîne : iARCIdArc est mis à jour
		/************************************************************/
		void ARCSet_IdArc(int iIdArc);

		/***********************************************************
		/* ARCSet_Distance
		/************************************************************
		/* Entrée : iDistance : Nouvelle valeur pour iARCDistance
		/* Nécessite : Rien
		/* Sortie : Rien
		/* Entraîne : iARCDistance est mis à jour
		/************************************************************/
		void ARCSet_Distance(int iDistance);

		/***********************************************************
		/* ARCSet_Cap
		/************************************************************
		/* Entrée : iCap : Nouvelle valeur pour iARCCap
		/* Nécessite : Rien
		/* Sortie : Rien
		/* Entraîne : iARCCap est mis à jour
		/************************************************************/
		void ARCSet_Cap(int iCap);

		/***********************************************************
		/* ARCSetPoids
		/************************************************************
		/* Entrée : iPoids : Nouvelle valeur pour iARCPoids
		/* Nécessite : Rien
		/* Sortie : Rien
		/* Entraîne : iARCPoids est mis à jour
		/************************************************************/
		void ARCSetPoids(int iPoids);

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

#pragma once
#include "CARC.h"
#include <vector>
using namespace std;

class CSommet
{
	//ATTRIBUTS 
    private:
		unsigned int uiSOMId;
		vector<CArc*> ARCPartant;
		vector<CArc*> ARCEntrant;
	//METHODES
	public:
		/***********************************************************
		/* CSommet
		/************************************************************
		/* Entrée : Rien
		/* Nécessite : Rien
		/* Sortie : Rien
		/* Entraîne : Les attributs de CSommet sont initialisés à NULL
		/************************************************************/
		CSommet();

		/***********************************************************
		/* CSommet
		/************************************************************
		/* Entrée : iId : La valeur avec laquelle iSOMId sera initialisé
		/* Nécessite : Rien
		/* Sortie : Rien
		/* Entraîne : Les attributs de CSommet sont initialisés avec des valeurs données
		/************************************************************/
		CSommet(int iId);

		/***********************************************************
		/* CSommet
		/************************************************************
		/* Entrée : Sommet : Un objet de la classe CSommet
		/* Nécessite : Rien
		/* Sortie : Rien
		/* Entraîne : Les attributs de CSommet sont initialisés avec les valeurs de l'objet Sommet
		/************************************************************/
		CSommet(const CSommet& Sommet);

		/***********************************************************
		/* ~CSommet
		/************************************************************
		/* Entrée : Rien
		/* Nécessite : Rien
		/* Sortie : Rien
		/* Entraîne : Le sommet est détruit et libéré
		/************************************************************/
		~CSommet();

		/***********************************************************
		/* SOMGet_Id
		/************************************************************
		/* Entrée : Rien
		/* Nécessite : Rien
		/* Sortie : La valeur de iSOMId
		/* Entraîne : Rien
		/************************************************************/
		unsigned int SOMGet_Id();

		/***********************************************************
		/* SOMAjouterArcPartant
		/************************************************************
		/* Entrée : ArcPartant : Pointeur vers un objet CArc
		/* Nécessite : Rien
		/* Sortie : Rien
		/* Entraîne : Ajoute un arc partant à la liste ARCPartant
		/************************************************************/
		void SOMAjouterArcPartant(CArc* ArcPartant);

		/***********************************************************
		/* SOMAjouterArcSortant
		/************************************************************
		/* Entrée : ArcSortant : Pointeur vers un objet CArc
		/* Nécessite : Rien
		/* Sortie : Rien
		/* Entraîne : Ajoute un arc sortant à la liste ARCEntrant
		/************************************************************/
		void SOMAjouterArcSortant(CArc* ArcSortant);

		/***********************************************************
		/* SOMGet_ARCPartant
		/************************************************************
		/* Entrée : Rien
		/* Nécessite : Rien
		/* Sortie : La liste des arcs partants
		/* Entraîne : Rien
		/************************************************************/
		vector<CArc*> SOMGet_ARCPartant();

		/***********************************************************
		/* SOMGet_ARCSortant
		/************************************************************
		/* Entrée : Rien
		/* Nécessite : Rien
		/* Sortie : La liste des arcs sortants
		/* Entraîne : Rien
		/************************************************************/
		vector<CArc*> SOMGet_ARCSortant();

		/***********************************************************
		/* SOMSet_Id
		/************************************************************
		/* Entrée : iId : Nouvelle valeur pour iSOMId
		/* Nécessite : Rien
		/* Sortie : Rien
		/* Entraîne : iSOMId est mis à jour
		/************************************************************/
		void SOMSet_Id(unsigned int iId);

		/***********************************************************
		/* SOMModifierArcPartant
		/************************************************************
		/* Entrée : iIdArc : Identifiant de l'arc
		/*          ArcPartant : Pointeur vers un objet CArc
		/* Nécessite : Rien
		/* Sortie : Rien
		/* Entraîne : Modifie un arc partant dans la liste ARCPartant
		/************************************************************/
		void SOMModifierArcPartant(unsigned int iIdArc, CArc* ArcPartant);

		/***********************************************************
		/* SOMModifierArcSortant
		/************************************************************
		/* Entrée : iIdArc : Identifiant de l'arc
		/*          ArcSortant : Pointeur vers un objet CArc
		/* Nécessite : Rien
		/* Sortie : Rien
		/* Entraîne : Modifie un arc sortant dans la liste ARCEntrant
		/************************************************************/
		void SOMModifierArcSortant(unsigned int iIdArc, CArc* ArcSortant);

		/***********************************************************
		/* SOMSupprimerArcPartant
		/************************************************************
		/* Entrée : iIdArc : Identifiant de l'arc
		/* Nécessite : Rien
		/* Sortie : Rien
		/* Entraîne : Supprime un arc partant de la liste ARCPartant
		/************************************************************/
		void SOMSupprimerArcPartant(unsigned int iIdArc);

		/***********************************************************
		/* SOMSupprimerArcSortant
		/************************************************************
		/* Entrée : iIdArc : Identifiant de l'arc
		/* Nécessite : Rien
		/* Sortie : Rien
		/* Entraîne : Supprime un arc sortant de la liste ARCEntrant
		/************************************************************/
		void SOMSupprimerArcSortant(unsigned int iIdArc);

		/***********************************************************
		/* SOMAfficher
		/************************************************************
		/* Entrée : Rien
		/* Nécessite : Rien
		/* Sortie : Rien
		/* Entraîne : Affiche les informations du sommet
		/************************************************************/
		void SOMAfficher();
};
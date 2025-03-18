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
		/* Entr�e : Rien
		/* N�cessite : Rien
		/* Sortie : Rien
		/* Entra�ne : Les attributs de CSommet sont initialis�s � NULL
		/************************************************************/
		CSommet();

		/***********************************************************
		/* CSommet
		/************************************************************
		/* Entr�e : iId : La valeur avec laquelle iSOMId sera initialis�
		/* N�cessite : Rien
		/* Sortie : Rien
		/* Entra�ne : Les attributs de CSommet sont initialis�s avec des valeurs donn�es
		/************************************************************/
		CSommet(int iId);

		/***********************************************************
		/* CSommet
		/************************************************************
		/* Entr�e : Sommet : Un objet de la classe CSommet
		/* N�cessite : Rien
		/* Sortie : Rien
		/* Entra�ne : Les attributs de CSommet sont initialis�s avec les valeurs de l'objet Sommet
		/************************************************************/
		CSommet(const CSommet& Sommet);

		/***********************************************************
		/* ~CSommet
		/************************************************************
		/* Entr�e : Rien
		/* N�cessite : Rien
		/* Sortie : Rien
		/* Entra�ne : Le sommet est d�truit et lib�r�
		/************************************************************/
		~CSommet();

		/***********************************************************
		/* SOMGet_Id
		/************************************************************
		/* Entr�e : Rien
		/* N�cessite : Rien
		/* Sortie : La valeur de iSOMId
		/* Entra�ne : Rien
		/************************************************************/
		unsigned int SOMGet_Id();

		/***********************************************************
		/* SOMAjouterArcPartant
		/************************************************************
		/* Entr�e : ArcPartant : Pointeur vers un objet CArc
		/* N�cessite : Rien
		/* Sortie : Rien
		/* Entra�ne : Ajoute un arc partant � la liste ARCPartant
		/************************************************************/
		void SOMAjouterArcPartant(CArc* ArcPartant);

		/***********************************************************
		/* SOMAjouterArcSortant
		/************************************************************
		/* Entr�e : ArcSortant : Pointeur vers un objet CArc
		/* N�cessite : Rien
		/* Sortie : Rien
		/* Entra�ne : Ajoute un arc sortant � la liste ARCEntrant
		/************************************************************/
		void SOMAjouterArcSortant(CArc* ArcSortant);

		/***********************************************************
		/* SOMGet_ARCPartant
		/************************************************************
		/* Entr�e : Rien
		/* N�cessite : Rien
		/* Sortie : La liste des arcs partants
		/* Entra�ne : Rien
		/************************************************************/
		vector<CArc*> SOMGet_ARCPartant();

		/***********************************************************
		/* SOMGet_ARCSortant
		/************************************************************
		/* Entr�e : Rien
		/* N�cessite : Rien
		/* Sortie : La liste des arcs sortants
		/* Entra�ne : Rien
		/************************************************************/
		vector<CArc*> SOMGet_ARCSortant();

		/***********************************************************
		/* SOMSet_Id
		/************************************************************
		/* Entr�e : iId : Nouvelle valeur pour iSOMId
		/* N�cessite : Rien
		/* Sortie : Rien
		/* Entra�ne : iSOMId est mis � jour
		/************************************************************/
		void SOMSet_Id(unsigned int iId);

		/***********************************************************
		/* SOMModifierArcPartant
		/************************************************************
		/* Entr�e : iIdArc : Identifiant de l'arc
		/*          ArcPartant : Pointeur vers un objet CArc
		/* N�cessite : Rien
		/* Sortie : Rien
		/* Entra�ne : Modifie un arc partant dans la liste ARCPartant
		/************************************************************/
		void SOMModifierArcPartant(unsigned int iIdArc, CArc* ArcPartant);

		/***********************************************************
		/* SOMModifierArcSortant
		/************************************************************
		/* Entr�e : iIdArc : Identifiant de l'arc
		/*          ArcSortant : Pointeur vers un objet CArc
		/* N�cessite : Rien
		/* Sortie : Rien
		/* Entra�ne : Modifie un arc sortant dans la liste ARCEntrant
		/************************************************************/
		void SOMModifierArcSortant(unsigned int iIdArc, CArc* ArcSortant);

		/***********************************************************
		/* SOMSupprimerArcPartant
		/************************************************************
		/* Entr�e : iIdArc : Identifiant de l'arc
		/* N�cessite : Rien
		/* Sortie : Rien
		/* Entra�ne : Supprime un arc partant de la liste ARCPartant
		/************************************************************/
		void SOMSupprimerArcPartant(unsigned int iIdArc);

		/***********************************************************
		/* SOMSupprimerArcSortant
		/************************************************************
		/* Entr�e : iIdArc : Identifiant de l'arc
		/* N�cessite : Rien
		/* Sortie : Rien
		/* Entra�ne : Supprime un arc sortant de la liste ARCEntrant
		/************************************************************/
		void SOMSupprimerArcSortant(unsigned int iIdArc);

		/***********************************************************
		/* SOMAfficher
		/************************************************************
		/* Entr�e : Rien
		/* N�cessite : Rien
		/* Sortie : Rien
		/* Entra�ne : Affiche les informations du sommet
		/************************************************************/
		void SOMAfficher();
};
#pragma once
class CException
{
	//ATTRIBUTS
	private:
		unsigned int uiEXCVal;
	
	//CONSTRUCTEURS
	public:
		/***********************************************************
		/* CException
		/************************************************************
		/* Entrée : Rien
		/* Nécessite : Rien
		/* Sortie : Rien
		/* Entraîne : Les attributs de CException sont initialisés à NULL
		/************************************************************/
		CException();

		/***********************************************************
		/* CException
		/************************************************************
		/* Entrée : uiVal : La valeur avec laquelle uiEXCVal sera initialisé
		/* Nécessite : Rien
		/* Sortie : Rien
		/* Entraîne : Les attributs de CException sont initialisés avec des valeurs données
		/************************************************************/
		CException(unsigned int uiVal);

		/***********************************************************
		/* CException
		/************************************************************
		/* Entrée : Exc : Un objet de la classe CException
		/* Nécessite : Rien
		/* Sortie : Rien
		/* Entraîne : Les attributs de CException sont initialisés avec les valeurs de l'objet Exc
		/************************************************************/
		CException(const CException& Exc);

		/***********************************************************
		/* ~CException
		/************************************************************
		/* Entrée : Rien
		/* Nécessite : Rien
		/* Sortie : Rien
		/* Entraîne : L'exception est détruite et libérée
		/************************************************************/
		~CException();

		//METHODES

		/***********************************************************
		/* EXCGet_Val
		/************************************************************
		/* Entrée : Rien
		/* Nécessite : Rien
		/* Sortie : La valeur de uiEXCVal
		/* Entraîne : Rien
		/************************************************************/
		unsigned int EXCGet_Val();

		/***********************************************************
		/* EXCModifier_Val
		/************************************************************
		/* Entrée : uiVal : Nouvelle valeur pour uiEXCVal
		/* Nécessite : Rien
		/* Sortie : Rien
		/* Entraîne : uiEXCVal est mis à jour
		/************************************************************/
		void EXCModifier_Val(unsigned int uiVal);
};

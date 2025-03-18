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
		/* Entr�e : Rien
		/* N�cessite : Rien
		/* Sortie : Rien
		/* Entra�ne : Les attributs de CException sont initialis�s � NULL
		/************************************************************/
		CException();

		/***********************************************************
		/* CException
		/************************************************************
		/* Entr�e : uiVal : La valeur avec laquelle uiEXCVal sera initialis�
		/* N�cessite : Rien
		/* Sortie : Rien
		/* Entra�ne : Les attributs de CException sont initialis�s avec des valeurs donn�es
		/************************************************************/
		CException(unsigned int uiVal);

		/***********************************************************
		/* CException
		/************************************************************
		/* Entr�e : Exc : Un objet de la classe CException
		/* N�cessite : Rien
		/* Sortie : Rien
		/* Entra�ne : Les attributs de CException sont initialis�s avec les valeurs de l'objet Exc
		/************************************************************/
		CException(const CException& Exc);

		/***********************************************************
		/* ~CException
		/************************************************************
		/* Entr�e : Rien
		/* N�cessite : Rien
		/* Sortie : Rien
		/* Entra�ne : L'exception est d�truite et lib�r�e
		/************************************************************/
		~CException();

		//METHODES

		/***********************************************************
		/* EXCGet_Val
		/************************************************************
		/* Entr�e : Rien
		/* N�cessite : Rien
		/* Sortie : La valeur de uiEXCVal
		/* Entra�ne : Rien
		/************************************************************/
		unsigned int EXCGet_Val();

		/***********************************************************
		/* EXCModifier_Val
		/************************************************************
		/* Entr�e : uiVal : Nouvelle valeur pour uiEXCVal
		/* N�cessite : Rien
		/* Sortie : Rien
		/* Entra�ne : uiEXCVal est mis � jour
		/************************************************************/
		void EXCModifier_Val(unsigned int uiVal);
};

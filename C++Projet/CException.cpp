#include "CException.h"

/***********************************************************
/* CException
/************************************************************
/* Entrée : Rien
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : Les attributs de CException sont initialisés à NULL
/************************************************************/
CException::CException() {
	uiEXCVal = FAUX;
}

/***********************************************************
/* CException
/************************************************************
/* Entrée : uiVal : La valeur avec laquelle uiEXCVal sera initialisé
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : Les attributs de CException sont initialisés avec des valeurs données
/************************************************************/
CException::CException(unsigned int uiVal) {
	uiEXCVal = uiVal;
}

/***********************************************************
/* CException
/************************************************************
/* Entrée : Exc : Un objet de la classe CException
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : Les attributs de CException sont initialisés avec les valeurs de l'objet Exc
/************************************************************/
CException::CException(const CException& Exc) {
	uiEXCVal = Exc.EXCGet_Val();
}

/***********************************************************
/* EXCGet_Val
/************************************************************
/* Entrée : Rien
/* Nécessite : Rien
/* Sortie : La valeur de uiEXCVal
/* Entraîne : Rien
/************************************************************/
unsigned int CException::EXCGet_Val() const {
	return uiEXCVal;
}


/***********************************************************
/* EXCModifier_Val
/************************************************************
/* Entrée : uiVal : Nouvelle valeur pour uiEXCVal
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : uiEXCVal est mis à jour
/************************************************************/
void CException::EXCModifier_Val(unsigned int uiVal) {
	uiEXCVal = uiVal;
}
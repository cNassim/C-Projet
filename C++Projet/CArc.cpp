#include "CArc.h"

/***********************************************************
/* CArc
/***********************************************************
/* Entrée : Rien
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : Les attributs de CARC sont initialisés à 0
/***********************************************************/
CArc::CArc() : uiARCSomDeb(0), uiARCSomA(0), uiARCIdArc(0), uiARCDistance(0), uiARCCap(0), uiARCPoids(0) {}

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
CArc::CArc(unsigned int uiSomDeb, unsigned int uiSomA, unsigned int uiIdArc, unsigned int uiDistance, unsigned int uiCap, unsigned int uiPoids)
	:uiARCSomDeb(uiSomDeb), uiARCSomA(uiSomA), uiARCIdArc(uiIdArc), uiARCDistance(uiDistance), uiARCCap(uiCap), uiARCPoids(uiPoids) {}


/***********************************************************
/* CArc
/************************************************************
/* Entrée : Arc : un objet de la classe CARC
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : Les attributs de CARC sont initialisés avec les valeurs de l'objet ARC
/************************************************************/
CArc::CArc(const CArc& Arc)
    : uiARCSomDeb(Arc.ARCGet_SomDeb()), uiARCSomA(Arc.ARCGet_SomA()), uiARCIdArc(Arc.ARCGet_IdArc()), uiARCDistance(Arc.ARCGet_Distance()),
    uiARCCap(Arc.ARCGet_Cap()), uiARCPoids(Arc.ARCGet_Poids()) {
}


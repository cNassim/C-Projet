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

/***********************************************************
/* ARCGet_SomDeb
/************************************************************
/* Entrée : Rien
/* Nécessite : Rien
/* Sortie : La valeur de uiARCSomDeb
/* Entraîne : Rien
/************************************************************/

unsigned int CArc::ARCGet_SomDeb() const {
    return uiARCSomDeb;
}

/***********************************************************
/* ARCGet_SomA
/************************************************************
/* Entrée : Rien
/* Nécessite : Rien
/* Sortie : La valeur de uiARCSomA
/* Entraîne : Rien
/************************************************************/
unsigned int CArc::ARCGet_SomA() const {
    return uiARCSomA;
}

/***********************************************************
/* ARCGetPoids
/************************************************************
/* Entrée : Rien
/* Nécessite : Rien
/* Sortie : La valeur de uiARCPoids
/* Entraîne : Rien
/************************************************************/
unsigned int CArc::ARCGet_Poids() const {
    return uiARCPoids;
}

/***********************************************************
/* ARCGet_IdArc
/************************************************************
/* Entrée : Rien
/* Nécessite : Rien
/* Sortie : La valeur de uiARCIdArc
/* Entraîne : Rien
/************************************************************/
unsigned int CArc::ARCGet_IdArc() const {
    return uiARCIdArc;
}

/***********************************************************
/* ARCSet_Distance
/************************************************************
/* Entrée : iDistance : Nouvelle valeur pour iARCDistance
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : iARCDistance est mis à jour
/************************************************************/
unsigned int CArc::ARCGet_Distance() const {
    return uiARCDistance;
}

/***********************************************************
/* ARCSet_Cap
/************************************************************
/* Entrée : iCap : Nouvelle valeur pour iARCCap
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : iARCCap est mis à jour
/************************************************************/
unsigned int CArc::ARCGet_Cap() const {
    return uiARCCap;
}
#include "CArc.h"

/***********************************************************
/* CArc
/***********************************************************
/* Entr�e : Rien
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : Les attributs de CARC sont initialis�s � 0
/***********************************************************/
CArc::CArc() : uiARCSomDeb(0), uiARCSomA(0), uiARCIdArc(0), uiARCDistance(0), uiARCCap(0), uiARCPoids(0) {}

/***********************************************************
/* CArc
/************************************************************
/* Entr�e : uiSomDeb : La valeur avec laquelle iARCSomDeb sera initialis�,
/*			uiSomA : La valeur avec laquelle iARCSomA sera initialis�,
/*			uiIdArc : La valeur avec laquelle iARCIdArc sera initialis�,
/*			uiDistance : La valeur avec laquelle iARCDistance sera initialis�,
/*			uiCap : La valeur avec laquelle iARCCap sera initialis�,
/*			uiPoids : La valeur avec laquelle iARCPoids sera initialis�.
/*
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : Les attributs de CARC sont initialis�s avec des valeurs donner.
/************************************************************/
CArc::CArc(unsigned int uiSomDeb, unsigned int uiSomA, unsigned int uiIdArc, unsigned int uiDistance, unsigned int uiCap, unsigned int uiPoids)
	:uiARCSomDeb(uiSomDeb), uiARCSomA(uiSomA), uiARCIdArc(uiIdArc), uiARCDistance(uiDistance), uiARCCap(uiCap), uiARCPoids(uiPoids) {}


/***********************************************************
/* CArc
/************************************************************
/* Entr�e : Arc : un objet de la classe CARC
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : Les attributs de CARC sont initialis�s avec les valeurs de l'objet ARC
/************************************************************/
CArc::CArc(const CArc& Arc)
    : uiARCSomDeb(Arc.ARCGet_SomDeb()), uiARCSomA(Arc.ARCGet_SomA()), uiARCIdArc(Arc.ARCGet_IdArc()), uiARCDistance(Arc.ARCGet_Distance()),
    uiARCCap(Arc.ARCGet_Cap()), uiARCPoids(Arc.ARCGet_Poids()) {
}

/***********************************************************
/* ARCGet_SomDeb
/************************************************************
/* Entr�e : Rien
/* N�cessite : Rien
/* Sortie : La valeur de uiARCSomDeb
/* Entra�ne : Rien
/************************************************************/

unsigned int CArc::ARCGet_SomDeb() const {
    return uiARCSomDeb;
}

/***********************************************************
/* ARCGet_SomA
/************************************************************
/* Entr�e : Rien
/* N�cessite : Rien
/* Sortie : La valeur de uiARCSomA
/* Entra�ne : Rien
/************************************************************/
unsigned int CArc::ARCGet_SomA() const {
    return uiARCSomA;
}

/***********************************************************
/* ARCGetPoids
/************************************************************
/* Entr�e : Rien
/* N�cessite : Rien
/* Sortie : La valeur de uiARCPoids
/* Entra�ne : Rien
/************************************************************/
unsigned int CArc::ARCGet_Poids() const {
    return uiARCPoids;
}

/***********************************************************
/* ARCGet_IdArc
/************************************************************
/* Entr�e : Rien
/* N�cessite : Rien
/* Sortie : La valeur de uiARCIdArc
/* Entra�ne : Rien
/************************************************************/
unsigned int CArc::ARCGet_IdArc() const {
    return uiARCIdArc;
}

/***********************************************************
/* ARCSet_Distance
/************************************************************
/* Entr�e : iDistance : Nouvelle valeur pour iARCDistance
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : iARCDistance est mis � jour
/************************************************************/
unsigned int CArc::ARCGet_Distance() const {
    return uiARCDistance;
}

/***********************************************************
/* ARCSet_Cap
/************************************************************
/* Entr�e : iCap : Nouvelle valeur pour iARCCap
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : iARCCap est mis � jour
/************************************************************/
unsigned int CArc::ARCGet_Cap() const {
    return uiARCCap;
}
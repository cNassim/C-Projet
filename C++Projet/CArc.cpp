#include "CArc.h"
#include "CSommet.h"
#include "CException.h"

/***********************************************************
/* CArc
/***********************************************************
/* Entr�e : Rien
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : Les attributs de CARC sont initialis�s � 0
/***********************************************************/
template <typename T>
inline CArc<T>::CArc() : uiARCSomDeb(0), uiARCSomA(0), uiARCIdArc(0){}

/***********************************************************
/* CArc
/************************************************************
/* Entr�e : uiSomDeb : La valeur avec laquelle iARCSomDeb sera initialis�,
/*			uiSomA : La valeur avec laquelle iARCSomA sera initialis�,
/*			uiIdArc : La valeur avec laquelle iARCIdArc sera initialis�,
/*			tDistance : La valeur avec laquelle iARCDistance sera initialis�,
/*		    tiCap : La valeur avec laquelle iARCCap sera initialis�,
/*			tPoids : La valeur avec laquelle iARCPoids sera initialis�.
/*
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : Les attributs de CARC sont initialis�s avec des valeurs donner.
/************************************************************/
template <typename T>
inline CArc<T>::CArc(CSommet<T>* SommetDeb , CSommet<T>* SommetA, unsigned int uiIdArc)
	:uiARCSomDeb(SommetDeb->SOMGet_Id()), uiARCSomA(SommetA->SOMGet_Id()), uiARCIdArc(uiIdArc){
    if (SommetDeb) {
        SommetDeb->SOMAjouterArcPartant(this);
    }
    if(SommetA){
    SommetA->SOMAjouterArcEntrant(this);
    }
}


/***********************************************************
/* CArc
/************************************************************
/* Entr�e : Arc : un objet de la classe CARC
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : Les attributs de CARC sont initialis�s avec les valeurs de l'objet ARC
/************************************************************/
template <typename T>
inline CArc<T>::CArc(const CArc<T>& Arc)
    : uiARCSomDeb(Arc.ARCGet_SomDeb()), uiARCSomA(Arc.ARCGet_SomA()), uiARCIdArc(Arc.ARCGet_IdArc()) {}

/***********************************************************
/* ARCGet_SomDeb
/************************************************************
/* Entr�e : Rien
/* N�cessite : Rien
/* Sortie : La valeur de uiARCSomDeb
/* Entra�ne : Rien
/************************************************************/
template <typename T>
inline unsigned int CArc<T>::ARCGet_SomDeb() const {
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
template <typename T>
inline unsigned int CArc<T>::ARCGet_SomA() const {
    return uiARCSomA;
}


/***********************************************************
/* ARCGet_IdArc
/************************************************************
/* Entr�e : Rien
/* N�cessite : Rien
/* Sortie : La valeur de uiARCIdArc
/* Entra�ne : Rien
/************************************************************/
template <typename T>
inline unsigned int CArc<T>::ARCGet_IdArc() const {
    return uiARCIdArc;
}



/***********************************************************
/* ARCSet_IdArc
/************************************************************
/* Entr�e : iIdArc : Nouvelle valeur pour iARCIdArc
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : iARCIdArc est mis � jour
/************************************************************/
template <typename T>
inline void CArc<T>::ARCSet_IdArc(unsigned int uiIdArc) {
    uiARCIdArc = uiIdArc;
}


/***********************************************************
/* ARCModifierSomDeb
/************************************************************
/* Entr�e : uiIdArc : Identifiant de l'arc
/*          SommetDeb : Pointeur vers un objet CSommet
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : uiARCSomDeb est mis � jour avec l'identifiant du sommet
/************************************************************/
template <typename T>
inline void CArc<T>::ARCModifierSomDeb(CSommet<T>* SommetDeb) {
    if (SommetDeb) {
        uiARCSomDeb = SommetDeb->SOMGet_Id();
    }
}
/***********************************************************
/* ARCModifierSomA
/************************************************************
/* Entr�e : uiIdArc : Identifiant de l'arc
/*          SommetA : Pointeur vers un objet CSommet
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : uiARCSomA est mis � jour avec l'identifiant du sommet
/************************************************************/
template <typename T>
inline void CArc<T>::ARCModifierSomA(CSommet<T>* SommetA) {
    if (SommetA) {
        uiARCSomA = SommetA->SOMGet_Id();
    }
}
/***********************************************************
/* ARCAfficher
/************************************************************
/* Entr�e : Rien
/* N�cessite : Rien
/* Sortie : Rien
/* Entra�ne : Affiche les informations de l'arc
/************************************************************/
template <typename T>
inline void CArc<T>::ARCAfficher() {
    cout << "Arc ID: " << uiARCIdArc << " | Sommet Depart: " << uiARCSomDeb
        << " | Sommet Arrivee: " << uiARCSomA << endl;
}

// Instanciation des templates pour les types utilis�s
template class CArc<int>;
template class CArc<float>;
template class CArc<double>;
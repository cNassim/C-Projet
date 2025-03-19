#include "CArc.h"

/***********************************************************
/* CArc
/***********************************************************
/* Entrée : Rien
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : Les attributs de CARC sont initialisés à 0
/***********************************************************/
template <typename T>
CArc<T>::CArc() : uiARCSomDeb(0), uiARCSomA(0), uiARCIdArc(0), uiARCDistance(0), uiARCCap(0), uiARCPoids(0) {}

/***********************************************************
/* CArc
/************************************************************
/* Entrée : uiSomDeb : La valeur avec laquelle iARCSomDeb sera initialisé,
/*			uiSomA : La valeur avec laquelle iARCSomA sera initialisé,
/*			uiIdArc : La valeur avec laquelle iARCIdArc sera initialisé,
/*			tDistance : La valeur avec laquelle iARCDistance sera initialisé,
/*		    tiCap : La valeur avec laquelle iARCCap sera initialisé,
/*			tPoids : La valeur avec laquelle iARCPoids sera initialisé.
/*
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : Les attributs de CARC sont initialisés avec des valeurs donner.
/************************************************************/
template <typename T>
CArc<T>::CArc(CSommet<T>* SommetDeb , CSommet<T>* SommetA, unsigned int uiIdArc, T tDistance,T tCap,T tPoids)
	:uiARCSomDeb(SommetDeb->SOMGet_Id()), uiARCSomA(SommetA->SOMGet_Id()), uiARCIdArc(uiIdArc), tARCDistance(tDistance), tARCCap(tCap), tARCPoids(tPoids) {}


/***********************************************************
/* CArc
/************************************************************
/* Entrée : Arc : un objet de la classe CARC
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : Les attributs de CARC sont initialisés avec les valeurs de l'objet ARC
/************************************************************/
template <typename T>
CArc<T>::CArc(const CArc<T>& Arc)
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
template <typename T>
unsigned int CArc<T>::ARCGet_SomDeb() const {
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
template <typename T>
unsigned int CArc<T>::ARCGet_SomA() const {
    return uiARCSomA;
}

/***********************************************************
/* ARCGetPoids
/************************************************************
/* Entrée : Rien
/* Nécessite : Rien
/* Sortie : La valeur de tARCPoids
/* Entraîne : Rien
/************************************************************/
template <typename T>
T CArc<T>::ARCGet_Poids() const {
    return tARCPoids;
}

/***********************************************************
/* ARCGet_IdArc
/************************************************************
/* Entrée : Rien
/* Nécessite : Rien
/* Sortie : La valeur de uiARCIdArc
/* Entraîne : Rien
/************************************************************/
template <typename T>
unsigned int CArc<T>::ARCGet_IdArc() const {
    return uiARCIdArc;
}

/***********************************************************
/* ARCSet_Distance
/************************************************************
/* Entrée : Rien
/* Nécessite : Rien
/* Sortie : La valeur de tDistance
/* Entraîne : Rien
/************************************************************/
template <typename T>
T CArc<T>::ARCGet_Distance() const {
    return tARCDistance;
}

/***********************************************************
/* ARCSet_Cap
/************************************************************
/* Entrée : Rien
/* Nécessite : Rien
/* Sortie : La valeur de tARCCap
/* Entraîne : Rien
/************************************************************/
template <typename T>
T CArc<T>::ARCGet_Cap() const {
    return tARCCap;
}

/***********************************************************
/* ARCSet_IdArc
/************************************************************
/* Entrée : iIdArc : Nouvelle valeur pour iARCIdArc
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : iARCIdArc est mis à jour
/************************************************************/
template <typename T>
void CArc<T>::ARCSet_IdArc(unsigned int uiIdArc) {
    uiARCIdArc = uiIdArc;
}

/***********************************************************
/* ARCSet_Distance
/************************************************************
/* Entrée : iDistance : Nouvelle valeur pour iARCDistance
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : iARCDistance est mis à jour
/************************************************************/
template <typename T>
void CArc<T>::ARCSet_Distance(T tDistance) {
    tARCDistance = tDistance;
}

/***********************************************************
/* ARCSet_Cap
/************************************************************
/* Entrée : iCap : Nouvelle valeur pour iARCCap
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : iARCCap est mis à jour
/************************************************************/
template <typename T>
void CArc<T>::ARCSet_Cap(T tCap) {
    tARCCap = tCap;
}

/***********************************************************
/* ARCSetPoids
/************************************************************
/* Entrée : tPoids : Nouvelle valeur pour tARCPoids
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : tARCPoids est mis à jour
/************************************************************/
template <typename T>
void CArc<T>::ARCSetPoids(T tPoids) {
    tARCPoids = tPoids;
}

/***********************************************************
/* ARCModifierSomDeb
/************************************************************
/* Entrée : uiIdArc : Identifiant de l'arc
/*          SommetDeb : Pointeur vers un objet CSommet
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : uiARCSomDeb est mis à jour avec l'identifiant du sommet
/************************************************************/
template <typename T>
void CArc<T>::ARCModifierSomDeb(CSommet<T>* SommetDeb) {
    if (SommetDeb) {
        uiARCSomDeb = SommetDeb->SOMGet_Id();
    }
}
/***********************************************************
/* ARCModifierSomA
/************************************************************
/* Entrée : uiIdArc : Identifiant de l'arc
/*          SommetA : Pointeur vers un objet CSommet
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : uiARCSomA est mis à jour avec l'identifiant du sommet
/************************************************************/
template <typename T>
void CArc<T>::ARCModifierSomA(CSommet<T>* SommetA) {
    if (SommetA) {
        uiARCSomA = SommetA->SOMGet_Id();
    }
}

/***********************************************************
/* ARCSet_IdArc
/************************************************************
/* Entrée : iIdArc : Nouvelle valeur pour iARCIdArc
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : iARCIdArc est mis à jour
/************************************************************/
template <typename T>
void CArc<T>::ARCSet_IdArc(unsigned int uiIdArc) {
    uiARCIdArc = uiIdArc;
}


/***********************************************************
/* ARCSet_Distance
/************************************************************
/* Entrée : tDistance : Nouvelle valeur pour tARCDistance
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : tARCDistance est mis à jour
/************************************************************/
template <typename T>
void CArc<T>::ARCSet_Distance(T tDistance) {
    tARCDistance = tDistance;
}

/***********************************************************
/* ARCSet_Cap
/************************************************************
/* Entrée : iCap : Nouvelle valeur pour iARCCap
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : iARCCap est mis à jour
/************************************************************/
template <typename T>
void CArc<T>::ARCSet_Cap(T tCap) {
    tARCCap = tCap;
}

/***********************************************************
/* ARCSetPoids
/************************************************************
/* Entrée : iPoids : Nouvelle valeur pour iARCPoids
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : iARCPoids est mis à jour
/************************************************************/
template <typename T>
void CArc<T>::ARCSetPoids(T tPoids) {
    tARCPoids = tPoids;
}

/***********************************************************
/* ARCAfficher
/************************************************************
/* Entrée : Rien
/* Nécessite : Rien
/* Sortie : Rien
/* Entraîne : Affiche les informations de l'arc
/************************************************************/
template <typename T>
void CArc<T>::ARCAfficher() {
    cout << "Arc ID: " << uiARCIdArc << " | Sommet Départ: " << uiARCSomDeb
        << " | Sommet Arrivée: " << uiARCSomA << " | Distance: " << tARCDistance
        << " | Capacité: " << tARCCap << " | Poids: " << tARCPoids << endl;
}

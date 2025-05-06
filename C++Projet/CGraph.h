#pragma once
#include "CGraphOrient.h"
#include <iostream>

using namespace std;

template <typename T>
class CGraph : public CGraphOrient<T>
{
    // M�THODES
public:
    /***********************************************************
    /* CGraph (constructeur par d�faut)
    /***********************************************************
    /* Entr�e : Rien
    /* N�cessite : Rien
    /* Sortie : Rien
    /* Entra�ne : Les attributs de CGraph sont initialis�s
    /***********************************************************/
    CGraph();

    /***********************************************************
    /* CGraph (constructeur avec param�tres)
    /***********************************************************
    /* Entr�e : Un vecteur de pointeurs vers des sommets et un vecteur de pointeurs vers des arcs
    /* N�cessite : Les vecteurs doivent �tre valides
    /* Sortie : Rien
    /* Entra�ne : Les attributs sont initialis�s avec les valeurs fournies
    /***********************************************************/
    CGraph(const vector<CSommet<T>*>& sommet,const vector<CArc<T>*>& arc);

    /***********************************************************
    /* CGraph (constructeur de copie)
    /***********************************************************
    /* Entr�e : Une r�f�rence constante vers un autre graphe
    /* N�cessite : Le graphe doit �tre valide
    /* Sortie : Rien
    /* Entra�ne : Une copie du graphe est cr��e
    /***********************************************************/
    CGraph(const CGraph<T>& graph);

    /***********************************************************
    /* ~CGraph (destructeur)
    /***********************************************************
    /* Entr�e : Rien
    /* N�cessite : Rien
    /* Sortie : Rien
    /* Entra�ne : Les ressources allou�es sont lib�r�es
    /***********************************************************/
    ~CGraph() {}

    /***********************************************************
    /* Ajouter une ar�te
    /***********************************************************
    /* Entr�e : Un pointeur vers un arc (repr�sentant une ar�te)
    /* N�cessite : L'arc doit �tre valide
    /* Sortie : Rien
    /* Entra�ne : L'ar�te est ajout�e au graphe
    /***********************************************************/
    void CGraphAjouterArret(CArc<T>* Arret);

    /***********************************************************
    /* Modifier une ar�te existante
    /***********************************************************
    /* Entr�e : Un pointeur vers l'ar�te � modifier et un pointeur vers la nouvelle ar�te
    /* N�cessite : L'ar�te � modifier doit exister, la nouvelle ar�te doit �tre valide
    /* Sortie : Rien
    /* Entra�ne : L'ar�te est modifi�e dans le graphe
    /***********************************************************/
    void CGraphModifierArret(CArc<T>* ArretActuel, CArc<T>* NouvelArret);

    /***********************************************************
    /* Supprimer une ar�te existante
    /***********************************************************
    /* Entr�e : Un pointeur vers l'ar�te � supprimer
    /* N�cessite : L'ar�te � supprimer doit exister dans le graphe
    /* Sortie : Rien
    /* Entra�ne : L'ar�te est supprim�e du graphe
    /***********************************************************/
    void CGraphSupprimerArret(CArc<T>* Arret);

    /***********************************************************
    /* Afficher les informations du graphe
    /***********************************************************
    /* Entr�e : Rien
    /* N�cessite : Rien
    /* Sortie : Rien
    /* Entra�ne : Les informations sp�cifiques du graphe sont affich�es
    /***********************************************************/
    void CGraphAfficher();
};
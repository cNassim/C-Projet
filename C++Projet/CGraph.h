#pragma once
#include "CGraphOrient.h"
#include <iostream>

using namespace std;

template <typename T>
class CGraph : public CGraphOrient<T>
{
    // MÉTHODES
public:
    /***********************************************************
    /* CGraph (constructeur par défaut)
    /***********************************************************
    /* Entrée : Rien
    /* Nécessite : Rien
    /* Sortie : Rien
    /* Entraîne : Les attributs de CGraph sont initialisés
    /***********************************************************/
    CGraph();

    /***********************************************************
    /* CGraph (constructeur avec paramètres)
    /***********************************************************
    /* Entrée : Un vecteur de pointeurs vers des sommets et un vecteur de pointeurs vers des arcs
    /* Nécessite : Les vecteurs doivent être valides
    /* Sortie : Rien
    /* Entraîne : Les attributs sont initialisés avec les valeurs fournies
    /***********************************************************/
    CGraph(const vector<CSommet<T>*>& sommet,const vector<CArc<T>*>& arc);

    /***********************************************************
    /* CGraph (constructeur de copie)
    /***********************************************************
    /* Entrée : Une référence constante vers un autre graphe
    /* Nécessite : Le graphe doit être valide
    /* Sortie : Rien
    /* Entraîne : Une copie du graphe est créée
    /***********************************************************/
    CGraph(const CGraph<T>& graph);

    /***********************************************************
    /* ~CGraph (destructeur)
    /***********************************************************
    /* Entrée : Rien
    /* Nécessite : Rien
    /* Sortie : Rien
    /* Entraîne : Les ressources allouées sont libérées
    /***********************************************************/
    ~CGraph() {}

    /***********************************************************
    /* Ajouter une arête
    /***********************************************************
    /* Entrée : Un pointeur vers un arc (représentant une arête)
    /* Nécessite : L'arc doit être valide
    /* Sortie : Rien
    /* Entraîne : L'arête est ajoutée au graphe
    /***********************************************************/
    void CGraphAjouterArret(CArc<T>* Arret);

    /***********************************************************
    /* Modifier une arête existante
    /***********************************************************
    /* Entrée : Un pointeur vers l'arête à modifier et un pointeur vers la nouvelle arête
    /* Nécessite : L'arête à modifier doit exister, la nouvelle arête doit être valide
    /* Sortie : Rien
    /* Entraîne : L'arête est modifiée dans le graphe
    /***********************************************************/
    void CGraphModifierArret(CArc<T>* ArretActuel, CArc<T>* NouvelArret);

    /***********************************************************
    /* Supprimer une arête existante
    /***********************************************************
    /* Entrée : Un pointeur vers l'arête à supprimer
    /* Nécessite : L'arête à supprimer doit exister dans le graphe
    /* Sortie : Rien
    /* Entraîne : L'arête est supprimée du graphe
    /***********************************************************/
    void CGraphSupprimerArret(CArc<T>* Arret);

    /***********************************************************
    /* Afficher les informations du graphe
    /***********************************************************
    /* Entrée : Rien
    /* Nécessite : Rien
    /* Sortie : Rien
    /* Entraîne : Les informations spécifiques du graphe sont affichées
    /***********************************************************/
    void CGraphAfficher();
};
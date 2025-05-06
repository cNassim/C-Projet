    #pragma once
    #include "CArc.h"
    #include <vector>
    #include <iostream>
    using namespace std;
    template <typename T>
    class CArc;

    template <typename T>
    class CSommet
    {
       // ATTRIBUTS
    private:
       unsigned int uiSOMId; // Identifiant unique du sommet
       vector<CArc<T>*> ARCPartant; // Liste des arcs partant de ce sommet
       vector<CArc<T>*> ARCEntrant; // Liste des arcs entrant dans ce sommet

       // METHODES
    public:
       /***********************************************************
       /* CSommet
       /************************************************************
       /* Entrée : Rien
       /* Nécessite : Rien
       /* Sortie : Rien
       /* Entraîne : Les attributs de CSommet sont initialisés à NULL
       /************************************************************/
       CSommet();
       /***********************************************************
       /* CSommet
       /************************************************************
       /* Entrée : Identifiant du sommet, vecteurs d'arcs partants et entrants
       /* Nécessite : Les vecteurs doivent être valides
       /* Sortie : Rien
       /* Entraîne : Initialise les attributs avec les valeurs fournies
       /************************************************************/
       CSommet(unsigned int uiId, const vector<CArc<T>*>& partant, const vector<CArc<T>*>& entrant);
       /***********************************************************
       /* CSommet (constructeur de copie)
       /************************************************************
       /* Entrée : Référence à un objet CSommet
       /* Nécessite : L'objet CSommet doit être valide
       /* Sortie : Rien
       /* Entraîne : Copie les attributs depuis l'objet fourni
       /************************************************************/
       CSommet(const CSommet& Sommet);
       /***********************************************************
       /* ~CSommet
       /************************************************************
       /* Entrée : Rien
       /* Nécessite : Rien
       /* Sortie : Rien
       /* Entraîne : Libère les ressources si nécessaire
       /************************************************************/
       ~CSommet();
       /***********************************************************
       /* SOMGet_Id
       /************************************************************
       /* Entrée : Rien
       /* Nécessite : Rien
       /* Sortie : Identifiant unique du sommet
       /* Entraîne : Rien
       /************************************************************/
       unsigned int SOMGet_Id() const;
       /***********************************************************
       /* SOMAjouterArcPartant
       /************************************************************
       /* Entrée : Pointeur vers un arc partant
       /* Nécessite : L'arc doit être valide
       /* Sortie : Rien
       /* Entraîne : Ajoute l'arc à la liste des arcs partants
       /************************************************************/
       void SOMAjouterArcPartant(CArc<T>* ArcPartant);
       /***********************************************************
       /* SOMAjouterArcEntrant
       /************************************************************
       /* Entrée : Pointeur vers un arc entrant
       /* Nécessite : L'arc doit être valide
       /* Sortie : Rien
       /* Entraîne : Ajoute l'arc à la liste des arcs entrants
       /************************************************************/
       void SOMAjouterArcEntrant(CArc<T>* ArcEntrant);
       /***********************************************************
       /* SOMGet_ARCPartant
       /************************************************************
       /* Entrée : Rien
       /* Nécessite : Rien
       /* Sortie : Liste des arcs partants
       /* Entraîne : Rien
       /************************************************************/
       vector<CArc<T>*> SOMGet_ARCPartant() const;
       /***********************************************************
       /* SOMGet_ARCEntrant
       /************************************************************
       /* Entrée : Rien
       /* Nécessite : Rien
       /* Sortie : Liste des arcs entrants
       /* Entraîne : Rien
       /************************************************************/
       vector<CArc<T>*> SOMGet_ARCEntrant() const;
       /***********************************************************
       /* SOMSet_Id
       /************************************************************
       /* Entrée : Identifiant unique du sommet
       /* Nécessite : L'identifiant doit être valide
       /* Sortie : Rien
       /* Entraîne : Modifie l'identifiant du sommet
       /************************************************************/
       void SOMSet_Id(unsigned int uiId);

       /***********************************************************
       /* SOMModifierArcPartant
       /************************************************************
       /* Entrée : Pointeur vers l'arc à modifier, pointeur vers le nouvel arc
       /* Nécessite : Les arcs doivent être valides
       /* Sortie : Rien
       /* Entraîne : Remplace l'arc existant par le nouvel arc dans la liste des arcs partants
       /************************************************************/
       void SOMModifierArcPartant(CArc<T>* ArcToModify, CArc<T>* NewArc);

       /***********************************************************
       /* SOMModifierArcEntrant
       /************************************************************
       /* Entrée : Pointeur vers l'arc à modifier, pointeur vers le nouvel arc
       /* Nécessite : Les arcs doivent être valides
       /* Sortie : Rien
       /* Entraîne : Remplace l'arc existant par le nouvel arc dans la liste des arcs entrants
       /************************************************************/
       void SOMModifierArcEntrant(CArc<T>* ArcToModify, CArc<T>* NewArc);

       /***********************************************************
       /* SOMSupprimerArcPartant
       /************************************************************
       /* Entrée : Pointeur vers l'arc à supprimer
       /* Nécessite : L'arc doit être valide
       /* Sortie : Rien
       /* Entraîne : Supprime l'arc de la liste des arcs partants
       /************************************************************/
       void SOMSupprimerArcPartant(CArc<T>* ArcPartant);

       /***********************************************************
       /* SOMSupprimerArcEntrant
       /************************************************************
       /* Entrée : Pointeur vers l'arc à supprimer
       /* Nécessite : L'arc doit être valide
       /* Sortie : Rien
       /* Entraîne : Supprime l'arc de la liste des arcs entrants
       /************************************************************/
       void SOMSupprimerArcEntrant(CArc<T>* ArcEntrant);

       /***********************************************************
       /* SOMAfficher
       /************************************************************
       /* Entrée : Rien
       /* Nécessite : Rien
       /* Sortie : Rien
       /* Entraîne : Affiche les informations du sommet, y compris ses arcs partants et entrants
       /************************************************************/
       void SOMAfficher();
    };
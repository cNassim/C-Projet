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
       /* Entr�e : Rien
       /* N�cessite : Rien
       /* Sortie : Rien
       /* Entra�ne : Les attributs de CSommet sont initialis�s � NULL
       /************************************************************/
       CSommet();
       /***********************************************************
       /* CSommet
       /************************************************************
       /* Entr�e : Identifiant du sommet, vecteurs d'arcs partants et entrants
       /* N�cessite : Les vecteurs doivent �tre valides
       /* Sortie : Rien
       /* Entra�ne : Initialise les attributs avec les valeurs fournies
       /************************************************************/
       CSommet(unsigned int uiId, const vector<CArc<T>*>& partant, const vector<CArc<T>*>& entrant);
       /***********************************************************
       /* CSommet (constructeur de copie)
       /************************************************************
       /* Entr�e : R�f�rence � un objet CSommet
       /* N�cessite : L'objet CSommet doit �tre valide
       /* Sortie : Rien
       /* Entra�ne : Copie les attributs depuis l'objet fourni
       /************************************************************/
       CSommet(const CSommet& Sommet);
       /***********************************************************
       /* ~CSommet
       /************************************************************
       /* Entr�e : Rien
       /* N�cessite : Rien
       /* Sortie : Rien
       /* Entra�ne : Lib�re les ressources si n�cessaire
       /************************************************************/
       ~CSommet();
       /***********************************************************
       /* SOMGet_Id
       /************************************************************
       /* Entr�e : Rien
       /* N�cessite : Rien
       /* Sortie : Identifiant unique du sommet
       /* Entra�ne : Rien
       /************************************************************/
       unsigned int SOMGet_Id() const;
       /***********************************************************
       /* SOMAjouterArcPartant
       /************************************************************
       /* Entr�e : Pointeur vers un arc partant
       /* N�cessite : L'arc doit �tre valide
       /* Sortie : Rien
       /* Entra�ne : Ajoute l'arc � la liste des arcs partants
       /************************************************************/
       void SOMAjouterArcPartant(CArc<T>* ArcPartant);
       /***********************************************************
       /* SOMAjouterArcEntrant
       /************************************************************
       /* Entr�e : Pointeur vers un arc entrant
       /* N�cessite : L'arc doit �tre valide
       /* Sortie : Rien
       /* Entra�ne : Ajoute l'arc � la liste des arcs entrants
       /************************************************************/
       void SOMAjouterArcEntrant(CArc<T>* ArcEntrant);
       /***********************************************************
       /* SOMGet_ARCPartant
       /************************************************************
       /* Entr�e : Rien
       /* N�cessite : Rien
       /* Sortie : Liste des arcs partants
       /* Entra�ne : Rien
       /************************************************************/
       vector<CArc<T>*> SOMGet_ARCPartant() const;
       /***********************************************************
       /* SOMGet_ARCEntrant
       /************************************************************
       /* Entr�e : Rien
       /* N�cessite : Rien
       /* Sortie : Liste des arcs entrants
       /* Entra�ne : Rien
       /************************************************************/
       vector<CArc<T>*> SOMGet_ARCEntrant() const;
       /***********************************************************
       /* SOMSet_Id
       /************************************************************
       /* Entr�e : Identifiant unique du sommet
       /* N�cessite : L'identifiant doit �tre valide
       /* Sortie : Rien
       /* Entra�ne : Modifie l'identifiant du sommet
       /************************************************************/
       void SOMSet_Id(unsigned int uiId);

       /***********************************************************
       /* SOMModifierArcPartant
       /************************************************************
       /* Entr�e : Pointeur vers l'arc � modifier, pointeur vers le nouvel arc
       /* N�cessite : Les arcs doivent �tre valides
       /* Sortie : Rien
       /* Entra�ne : Remplace l'arc existant par le nouvel arc dans la liste des arcs partants
       /************************************************************/
       void SOMModifierArcPartant(CArc<T>* ArcToModify, CArc<T>* NewArc);

       /***********************************************************
       /* SOMModifierArcEntrant
       /************************************************************
       /* Entr�e : Pointeur vers l'arc � modifier, pointeur vers le nouvel arc
       /* N�cessite : Les arcs doivent �tre valides
       /* Sortie : Rien
       /* Entra�ne : Remplace l'arc existant par le nouvel arc dans la liste des arcs entrants
       /************************************************************/
       void SOMModifierArcEntrant(CArc<T>* ArcToModify, CArc<T>* NewArc);

       /***********************************************************
       /* SOMSupprimerArcPartant
       /************************************************************
       /* Entr�e : Pointeur vers l'arc � supprimer
       /* N�cessite : L'arc doit �tre valide
       /* Sortie : Rien
       /* Entra�ne : Supprime l'arc de la liste des arcs partants
       /************************************************************/
       void SOMSupprimerArcPartant(CArc<T>* ArcPartant);

       /***********************************************************
       /* SOMSupprimerArcEntrant
       /************************************************************
       /* Entr�e : Pointeur vers l'arc � supprimer
       /* N�cessite : L'arc doit �tre valide
       /* Sortie : Rien
       /* Entra�ne : Supprime l'arc de la liste des arcs entrants
       /************************************************************/
       void SOMSupprimerArcEntrant(CArc<T>* ArcEntrant);

       /***********************************************************
       /* SOMAfficher
       /************************************************************
       /* Entr�e : Rien
       /* N�cessite : Rien
       /* Sortie : Rien
       /* Entra�ne : Affiche les informations du sommet, y compris ses arcs partants et entrants
       /************************************************************/
       void SOMAfficher();
    };
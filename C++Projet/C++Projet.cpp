#include "CGraphOrient.h"
#include "CSommet.h"
#include "CArc.h"
#include <iostream>

using namespace std;

int main() {
    // Création d'un graphe orienté
    CGraphOrient<int> graphe;

    // Création de sommets
    CSommet<int>* sommet1 = new CSommet<int>(1,{},{});
    CSommet<int>* sommet2 = new CSommet<int>(2, {}, {});
    CSommet<int>* sommet3 = new CSommet<int>(3, {}, {});

    // Ajout des sommets au graphe
    graphe.CGraphOAjouterSommet(sommet1);
    graphe.CGraphOAjouterSommet(sommet2);
    graphe.CGraphOAjouterSommet(sommet3);

    // Création d'arcs
    CArc<int>* arc1 = new CArc<int>(sommet1, sommet2,1);
    CArc<int>* arc2 = new CArc<int>(sommet2, sommet3,2);

    // Ajout des arcs au graphe
    graphe.CGraphOAjouterArc(arc1);
    graphe.CGraphOAjouterArc(arc2);

    // Affichage du graphe
    cout << "Affichage du graphe après ajout des sommets et arcs :" << endl;
    graphe.CGraphOAfficher();

    // Suppression d'un sommet
    graphe.CGraphOSupprimerSommet(1);
    for (int i = 0; i < 30; i++) {
        printf("\n");
    }
    // Affichage du graphe après suppression
    cout << "Affichage du graphe apres suppression du sommet 1 :" << endl;
    graphe.CGraphOAfficher();

    // Suppression d'un arc
    graphe.CGraphOSupprimerArc(1);

    // Affichage du graphe après suppression
    cout << "Affichage du graphe apres suppression de l'arc 1 :" << endl;
    graphe.CGraphOAfficher();

    // Libération de la mémoire
    delete sommet1;
    delete sommet2;
    delete sommet3;
    delete arc1;
    delete arc2;

    return 0;
}
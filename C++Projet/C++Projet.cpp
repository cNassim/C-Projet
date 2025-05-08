#include <iostream>
#include "CGraph.h"
#include "CSommet.h"
#include "CArc.h"

int main() {
    // Création de sommets
    CSommet<int>* sommet1 = new CSommet<int>(1, {}, {}); // Sommet avec ID 1
    CSommet<int>* sommet2 = new CSommet<int>(2, {}, {}); // Sommet avec ID 2
    CSommet<int>* sommet3 = new CSommet<int>(3, {}, {}); // Sommet avec ID 3

    // Création d'arcs (arêtes)
    CArc<int>* arc1 = new CArc<int>(sommet1, sommet2); // Arête entre sommet 1 et sommet 2
    CArc<int>* arc2 = new CArc<int>(sommet2, sommet3); // Arête entre sommet 2 et sommet 3

    // Création du graphe non orienté
    CGraph<int> graph;

    // Ajout des arêtes au graphe
    std::cout << "Ajout des aretes..." << std::endl;
    graph.CGraphAjouterArret(arc1);
    graph.CGraphAjouterArret(arc2);
    graph.CGraphAfficher();

    // Modification d'une arête
    std::cout << "\nModification d'une arete (2 -> 3 devient 1 -> 3)..." << std::endl;
    CArc<int>* newArc = new CArc<int>(sommet1, sommet3); // Nouvelle arête entre sommet 1 et sommet 3
    graph.CGraphModifierArret(arc2, newArc);
    graph.CGraphAfficher();

    // Suppression d'une arête
    std::cout << "\nSuppression de l'arete entre sommet 1 et sommet 2..." << std::endl;
    graph.CGraphSupprimerArret(arc1);
    graph.CGraphAfficher();

    // Test de suppression d'une arête inexistante
    std::cout << "\nTentative de suppression d'une arete inexistante..." << std::endl;
    graph.CGraphSupprimerArret(arc1); // Cela devrait lever une exception ou ne rien faire

    // Afficher le graphe final
    std::cout << "\nEtat final du graphe : " << std::endl;
    graph.CGraphAfficher();

    delete arc1;
    delete arc2;
    delete newArc;
    delete sommet1;
    delete sommet2;
    delete sommet3;




    return 0;
}
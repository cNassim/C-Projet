#include <iostream>
#include "CGraphOrient.h"
#include "CSommet.h"
#include "CArc.h"

using namespace std;

int main() {
    // Création des sommets
    CSommet<int>* sommet1 = new CSommet<int>(1, vector<CArc<int>*>(), vector<CArc<int>*>());
    CSommet<int>* sommet2 = new CSommet<int>(2, vector<CArc<int>*>(), vector<CArc<int>*>());
    CSommet<int>* sommet3 = new CSommet<int>(3, vector<CArc<int>*>(), vector<CArc<int>*>());

    // Création des arcs
    CArc<int>* arc1 = new CArc<int>(sommet1, sommet2);
    CArc<int>* arc2 = new CArc<int>(sommet2, sommet3);
    CArc<int>* arc3 = new CArc<int>(sommet3, sommet1);

    // Ajout des arcs aux sommets
    sommet1->SOMAjouterArcPartant(arc1);
    sommet2->SOMAjouterArcEntrant(arc1);

    sommet2->SOMAjouterArcPartant(arc2);
    sommet3->SOMAjouterArcEntrant(arc2);

    sommet3->SOMAjouterArcPartant(arc3);
    sommet1->SOMAjouterArcEntrant(arc3);

    // Création du graphe orienté
    CGraphOrient<int> graph;
    graph.CGraphOAjouterSommet(sommet1);
    graph.CGraphOAjouterSommet(sommet2);
    graph.CGraphOAjouterSommet(sommet3);

    graph.CGraphOAjouterArc(arc1);
    graph.CGraphOAjouterArc(arc2);
    graph.CGraphOAjouterArc(arc3);


    graph.CGraphOAfficher();

    // Libération de la mémoire
    delete sommet1;
    delete sommet2;
    delete sommet3;
    delete arc1;
    delete arc2;
    delete arc3;

    return 0;
}
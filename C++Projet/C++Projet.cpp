#include <iostream>
#include "CGraphOrient.h"
#include "CSommet.h"
#include "CArc.h"
#include "CException.h"

using namespace std;

int main() {
    try {
        // Création des sommets
        CSommet<int>* sommet1 = new CSommet<int>(1, vector<CArc<int>*>(), vector<CArc<int>*>());
        CSommet<int>* sommet2 = new CSommet<int>(2, vector<CArc<int>*>(), vector<CArc<int>*>());
        CSommet<int>* sommet3 = new CSommet<int>(3, vector<CArc<int>*>(), vector<CArc<int>*>());
        CSommet<int>* sommetInvalide = nullptr; // Sommet invalide pour tester les erreurs

        // Création des arcs
        CArc<int>* arc1 = new CArc<int>(sommet1, sommet2);
        CArc<int>* arc2 = new CArc<int>(sommet2, sommet3);
        CArc<int>* arc3 = new CArc<int>(sommet3, sommet1);
        CArc<int>* arcInvalide = nullptr; // Arc invalide pour tester les erreurs

        // Création du graphe orienté
        CGraphOrient<int> graph;

        // Ajout des sommets
        cout << "Ajout des sommets :" << endl;
        graph.CGraphOAjouterSommet(sommet1);
        graph.CGraphOAjouterSommet(sommet2);
        graph.CGraphOAjouterSommet(sommet3);
        graph.CGraphOAjouterSommet(sommetInvalide); // Tester l'ajout d'un sommet invalide

        // Ajout des arcs
        cout << "\nAjout des arcs :" << endl;
        graph.CGraphOAjouterArc(arc1);
        graph.CGraphOAjouterArc(arc2);
        graph.CGraphOAjouterArc(arc3);
        graph.CGraphOAjouterArc(arcInvalide); // Tester l'ajout d'un arc invalide

        // Affichage du graphe
        cout << "\nAffichage du graphe orienté :" << endl;
        graph.CGraphOAfficher();

        // Test de suppression d'un sommet
        cout << "\nSuppression du sommet 2 :" << endl;
        graph.CGraphOSupprimerSommet(2);
        graph.CGraphOAfficher();

        // Test de suppression d'un arc
        cout << "\nSuppression d'un arc (1 → 2) :" << endl;
        graph.CGraphOSupprimerArc(arc1);
        graph.CGraphOAfficher();

        // Test de modification d'un sommet
        cout << "\nModification du sommet 3 :" << endl;
        CSommet<int>* sommetNouveau = new CSommet<int>(4, vector<CArc<int>*>(), vector<CArc<int>*>());
        graph.CGraphOModifierSommet(3, sommetNouveau);
        graph.CGraphOAfficher();

        // Test de modification d'un arc
        cout << "\nModification d'un arc (2 → 3) :" << endl;
        CArc<int>* nouvelArc = new CArc<int>(sommet1, sommetNouveau);
        graph.CGraphOModifierArc(arc2, nouvelArc);
        graph.CGraphOAfficher();

        delete arc1;
        delete arc2;
        delete arc3;


    }
    catch (const CException& e) {
        cerr << "Erreur capturée dans le main : " << e.EXCGet_Val() << endl;
    }
    catch (...) {
        cerr << "Erreur inconnue capturée dans le main !" << endl;
    }

    return 0;
}
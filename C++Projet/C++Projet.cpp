#include <iostream>
#include <vector>
#include "CSommet.h"
#include "CArc.h"
#include "CException.h"

using namespace std;

int main() {
    try {
        // Création des sommets
        CSommet<int>* sommet1 = new CSommet<int>(1, {}, {});
        CSommet<int>* sommet2 = new CSommet<int>(2, {}, {});
        CSommet<int>* sommet3 = new CSommet<int>(3, {}, {});

        // Création des arcs
        CArc<int>* arc1 = new CArc<int>(sommet1, sommet2); // arc1 de sommet1 à sommet2
        CArc<int>* arc2 = new CArc<int>(sommet2, sommet3); // arc2 de sommet2 à sommet3

        // Ajout des arcs aux sommets respectifs
        sommet1->SOMAjouterArcPartant(arc1);
        sommet2->SOMAjouterArcEntrant(arc1);
        sommet2->SOMAjouterArcPartant(arc2);
        sommet3->SOMAjouterArcEntrant(arc2);

        // Affichage des informations des sommets
        cout << "Sommet 1 :\n";
        sommet1->SOMAfficher();

        cout << "\nSommet 2 :\n";
        sommet2->SOMAfficher();

        cout << "\nSommet 3 :\n";
        sommet3->SOMAfficher();

        // Test de la suppression et modification d'arc
        cout << "\nModification de l'arc entre sommet1 et sommet2...\n";
        CArc<int>* arcModifie = new CArc<int>(sommet1, sommet3); // Nouveau arc entre sommet1 et sommet3
        sommet1->SOMModifierArcPartant(arc1, arcModifie); // Remplace arc1 par arcModifie
        sommet2->SOMModifierArcEntrant(arc1, arcModifie); // Remplace arc1 par arcModifie

        cout << "\nSommet 1 apres modification :\n";
        sommet1->SOMAfficher();
        cout << "\nSommet 2 apres modification :\n";
        sommet2->SOMAfficher();

        // Test de suppression d'arc
        cout << "\nSuppression de l'arc entre sommet2 et sommet3...\n";
        sommet2->SOMSupprimerArcPartant(arc2); // Suppression de l'arc2 de sommet2
        sommet3->SOMSupprimerArcEntrant(arc2); // Suppression de l'arc2 de sommet3

        cout << "\nSommet 2 apres suppression de l'arc :\n";
        sommet2->SOMAfficher();
        cout << "\nSommet 3 aprs suppression de l'arc :\n";
        sommet3->SOMAfficher();

        // Nettoyage de la mémoire
        delete sommet1;
        delete sommet2;
        delete sommet3;
        delete arc1;
        delete arc2;
        delete arcModifie;
    }
    catch (const CException& e) {
        cerr << "Erreur : " << e.EXCGet_Val() << endl;
    }

    return 0;
}

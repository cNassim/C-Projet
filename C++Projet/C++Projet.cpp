#include <iostream>
#include <vector>
#include "CArc.h"
#include "CSommet.h"

using namespace std;

int main() {
    // Création des objets CSommet
    CSommet<int> sommet1(1, {}, {});  // Sommet avec ID 1
    
    cout << "Affichage 1 : " << endl;
    sommet1.SOMAfficher();
    
    CSommet<int> sommet2(2, {}, {});  // Sommet avec ID 2
    CArc<int> arc1(&sommet1, &sommet2, 1, 10, 5, 2);
    cout << "Affichage 2 : " << endl;
    arc1.ARCAfficher();
    
    CSommet<int> sommet3(3, {}, {});
    CArc<int> arc3(&sommet1, &sommet3, 3, 20, 10, 4);
    sommet1.SOMAjouterArcPartant(&arc1);
    sommet1.SOMAjouterArcPartant(&arc3);
    cout << "Affichage 3 : " << endl;
    sommet1.SOMAfficher();
    
    /*CSommet<int> sommet2(2, {}, {});  // Sommet avec ID 2
    CSommet<int> sommet3(3, {}, {});  // Sommet avec ID 3

    // Création des objets CArc
    CArc<int> arc1(&sommet1, &sommet2, 1, 10, 5, 2);  // Arc entre sommet1 et sommet2
    CArc<int> arc2(&sommet2, &sommet3, 2, 15, 7, 3);  // Arc entre sommet2 et sommet3
    CArc<int> arc3(&sommet1, &sommet3, 3, 20, 10, 4); // Arc entre sommet1 et sommet3
    
    cout << "Affichage du sommet 1 et de ses arcs : " << endl;
    sommet1.SOMAfficher();
    // Ajouter les arcs aux sommets
    sommet1.SOMAjouterArcPartant(&arc1);
    sommet1.SOMAjouterArcPartant(&arc3);
    cout << "Affichage du sommet 1 et de ses arcs : " << endl;
    sommet1.SOMAfficher();

    sommet2.SOMAjouterArcPartant(&arc2);

    sommet3.SOMAjouterArcEntrant(&arc1);
    sommet3.SOMAjouterArcEntrant(&arc2);

    // Affichage des sommets et de leurs arcs
    cout << "Affichage du sommet 1 et de ses arcs : " << endl;
    sommet1.SOMAfficher();

    cout << "\nAffichage du sommet 2 et de ses arcs : " << endl;
    sommet2.SOMAfficher();

    cout << "\nAffichage du sommet 3 et de ses arcs : " << endl;
    sommet3.SOMAfficher();

    // Modification d'un arc
    cout << "\nModification de l'arc entre sommet1 et sommet2" << endl;
    arc1.ARCModifierSomDeb(&sommet3);  // Modifier sommet départ de arc1
    arc1.ARCModifierSomA(&sommet2);    // Modifier sommet arrivée de arc1

    // Affichage après modification
    cout << "\nAffichage du sommet 1 et de ses arcs après modification : " << endl;
    sommet1.SOMAfficher();

    // Suppression d'un arc
    cout << "\nSuppression de l'arc entre sommet1 et sommet3" << endl;
    sommet1.SOMSupprimerArcPartant(3);  // Supprimer arc3 de sommet1

    // Affichage après suppression
    cout << "\nAffichage du sommet 1 après suppression de l'arc : " << endl;
    sommet1.SOMAfficher();
    */
    return 0;
}

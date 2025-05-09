#include <iostream>
#include <string>
#include "CGraphOrient.h"

using namespace std;

void displayHeader() {
    cout << "==============================================" << endl;
    cout << "                 C++ PROJECT                  " << endl;
    cout << "==============================================" << endl;
}

void displayDetails() {
    cout << "\nMade by:" << endl;
    cout << "  - Nassim BELLANAYA (https://github.com/cNassim)" << endl;
    cout << "  - EL YAZID GUERMA" << endl;

    cout << "\nFeatures of the library:" << endl;
    cout << "1. Create graph objects" << endl;
    cout << "2. Perform basic operations on a graph:" << endl;
    cout << "   a. Add/modify/delete a vertex" << endl;
    cout << "   b. Add/modify/delete an edge/arc" << endl;
    cout << "   c. Display a graph in the console" << endl;
    cout << "   d. Reverse an arc" << endl;
    cout << "   e. Reverse an entire graph" << endl;
    cout << "   f. Read from a file" << endl;
    cout << "==============================================" << endl;
}

int main() {
    try {
        displayHeader();
        displayDetails();
        string sNomFichier;
        cout << "Veuillez entrer le nom du fichier : ";
        getline(cin, sNomFichier);

        // Étape 2 : Lire le fichier et créer le graphe associé
        CGraphOrient<int>* graphe = CGraphOrient<int>::CGraphOLireFichier(sNomFichier);
        if (!graphe) {
            cerr << "Erreur : Impossible de creer le graphe a partir du fichier." << endl;
            return 1;
        }

        // Étape 3 : Afficher le graphe
        cout << "Graphe original :" << endl;
        graphe->CGraphOAfficher();

        // Étape 4 : Inverser tous les arcs du graphe
        CGraphOrient<int>* grapheInverse = graphe->CGraphOInverse();

        // Étape 5 : Afficher le graphe inversé
        cout << "\nGraphe inverse :" << endl;
        grapheInverse->CGraphOAfficher();

        // Libérer la mémoire
        delete graphe;
        delete grapheInverse;

    }
    catch (const CException& e) {
        // Gestion des exceptions levées par CException
        cerr << "Une exception a été levée : Code " << e.EXCGet_Val() << endl;
        return 1;
    }
    catch (const exception& e) {
        // Gestion des exceptions standard
        cerr << "Une exception standard a été levée : " << e.what() << endl;
        return 1;
    }

    return 0;
}
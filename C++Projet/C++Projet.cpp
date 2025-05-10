#include <iostream>
#include <string>
#include <cstdlib>
#include "CGraphOrient.h"

using namespace std;

void displayHeader() {
    cout << "+==========================================================+" << endl;
    cout << "|                C++ PROJECT/GRAPH LIBRARY                 |" << endl;
    cout << "+==========================================================+" << endl;
}

void displayDetails() {
    cout << "+==========================================================+" << endl;
    cout << "|                         -Made by:                        |" << endl;
    cout << "|  - Nassim BELLANAYA (https://github.com/cNassim)         |" << endl;
    cout << "|  - EL YAZID GUERMA                                       |" << endl;
    cout << "+==========================================================+" << endl;
    cout << "|                 -Features of the library:                |" << endl;
    cout << "|1. Create graph objects                                   |" << endl;
    cout << "|2. Perform basic operations on a graph:                   |" << endl;
    cout << "|   a. Add/modify/delete a vertex                          |" << endl;
    cout << "|   b. Add/modify/delete an edge/arc                       |" << endl;
    cout << "|   c. Display a graph in the console                      |" << endl;
    cout << "|   d. Reverse an arc                                      |" << endl;
    cout << "|   e. Reverse an entire graph                             |" << endl;
    cout << "|   f. Read from a file                                    |" << endl;
    cout << "+==========================================================+" << endl;
}

int main(int argc, char* argv[]) {
    bool modecin = false;
    try {
        displayHeader();
        displayDetails();

        string sNomFichier;

        // Leve un exception si on a plus d'un paramètre
        if (argc > 2) {
            throw CException(1721);
        }

        // Vérifier si un nom de fichier est passé en paramètre
        if (argc == 2) {
            sNomFichier = argv[1];
        }
        else {
            modecin = true;
            cout << "Pas de parametres detecte, passage en mode 'cin'" << endl;
            cout << "Veuillez entrer le nom du fichier : ";
            getline(cin, sNomFichier);
        }

        // Étape 2 : Lire le fichier et créer le graphe associé
        CGraphOrient<int>* graphe = CGraphOrient<int>::CGraphOLireFichier(sNomFichier);
        if (!graphe) {
            cerr << "Erreur : Impossible de creer le graphe a partir du fichier." << endl;
            if (modecin) {
                cout << "\nAppuyez sur entrer pour fermer le programme..." << endl;
                cin.get();
            }
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
        if (e.EXCGet_Val() == 1721) {
            cerr << "Trop de parametres fournis. Un seul parametre attendu. ! Code erreur : " << e.EXCGet_Val() << endl;
        }
        else {
            cerr << "Une exception a ete levee : Code " << e.EXCGet_Val() << endl;
        }
        if (modecin) {
            cout << "\nAppuyez sur entrer pour fermer le programme..." << endl;
            cin.get();
        }
        return 1;
    }

    if (modecin) {
        cout << "\nAppuyez sur entrer pour fermer le programme..." << endl;
        cin.get();
    }
    return 0;
}
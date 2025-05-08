#include <iostream>
#include <string>
#include "CGraphOrient.h"

int main() {
    try {
        // Spécifiez le chemin du fichier contenant les données du graphe
        std::string cheminFichier = "C:/Users/proma/OneDrive/Documents/graph.txt";

        // Appel de la méthode statique pour lire le graphe depuis le fichier
        CGraphOrient<int>* graphe = CGraphOrient<int>::CGraphOLireFichier(cheminFichier);

        if (graphe) {
            // Afficher les informations du graphe
            graphe->CGraphOAfficher();

            // Libérer la mémoire allouée pour le graphe
            delete graphe;
        }
        else {
            std::cerr << "Erreur : Le graphe n'a pas pu être créé à partir du fichier." << std::endl;
        }
    }
    catch (const CException& e) {
        // Gestion des exceptions levées par CException
        std::cerr << "Une exception a été levée : Code " << e.EXCGet_Val() << std::endl;
    }
    catch (const std::exception& e) {
        // Gestion des exceptions standard
        std::cerr << "Une exception standard a été levée : " << e.what() << std::endl;
    }

    return 0;
}
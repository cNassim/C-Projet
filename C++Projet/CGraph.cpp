#include "CGraph.h"
#include "CArc.h"
#include "CGraphOrient.h"
#include "CSommet.h"
#include "CException.h"
#include <vector>
#include <iostream>

using namespace std;

template <typename T>
CGraph<T>::CGraph() : CGraphOrient<T>() {}

template <typename T>
CGraph<T>::CGraph(const vector<CSommet<T>*>& sommet, const vector<CArc<T>*>& arc)
    : CGraphOrient<T>(sommet, {}) {
    try {
        for (const auto& currentArc : arc) {
            if (!currentArc) {
                throw CException(4);
            }

            this->CGraphAjouterArret(currentArc);

            CArc<T> arcInverse = CArc<T>::ARCInverserArc(*currentArc);
            this->CGraphAjouterArret(new CArc<T>(arcInverse));
        }
    }
    catch (const CException& e) {
        cerr << "Erreur lors de la construction d'un graphe non oriente : " << e.EXCGet_Val() << endl;
    }
}

template <typename T>
CGraph<T>::CGraph(const CGraph<T>& graph) : CGraphOrient<T>(graph) {}

template <typename T>
CGraph<T>::~CGraph() {}

template <typename T>
void CGraph<T>::CGraphAjouterArret(CArc<T>* Arret) {
    try {
        if (!Arret) {
            throw CException(4);
        }

        unsigned int sommetDebId = Arret->ARCGet_SomDeb()->SOMGet_Id();
        unsigned int sommetFinId = Arret->ARCGet_SomA()->SOMGet_Id();

        CSommet<T>* sommetDeb = this->CGraphOChercherSommetParId(sommetDebId);
        if (!sommetDeb) {
            sommetDeb = Arret->ARCGet_SomDeb();
            this->CGraphOAjouterSommet(sommetDeb);
        }

        CSommet<T>* sommetFin = this->CGraphOChercherSommetParId(sommetFinId);
        if (!sommetFin) {
            sommetFin = Arret->ARCGet_SomA();
            this->CGraphOAjouterSommet(sommetFin);
        }

        this->CGraphOAjouterArc(Arret);

        CArc<T> arcInverse = CArc<T>::ARCInverserArc(*Arret);
        this->CGraphOAjouterArc(new CArc<T>(arcInverse));

    }
    catch (const CException& e) {
        std::cerr << "Erreur lors de l'ajout d'une arete : " << e.EXCGet_Val() << std::endl;
    }
}

template <typename T>
void CGraph<T>::CGraphModifierArret(CArc<T>* ArretActuel, CArc<T>* NouvelArret) {
    try {
        if (!ArretActuel || !NouvelArret) {
            throw CException(4);
        }

        CGraphSupprimerArret(ArretActuel);
        CGraphAjouterArret(NouvelArret);

    }
    catch (const CException& e) {
        cerr << "Erreur lors de la modification d'une arete : " << e.EXCGet_Val() << endl;
    }
}


template <typename T>
void CGraph<T>::CGraphSupprimerArret(CArc<T>* Arret) {
    try {
        if (!Arret) {
            throw CException(4);
        }
        unsigned int sommetDebId = Arret->ARCGet_SomDeb()->SOMGet_Id();
        unsigned int sommetFinId = Arret->ARCGet_SomA()->SOMGet_Id();

        CArc<T> arcInverse = CArc<T>::ARCInverserArc(*Arret);

        auto& arcs = this->CGraphOGET_Arc();
        arcs.erase(remove_if(arcs.begin(), arcs.end(),
            [&Arret, &arcInverse](CArc<T>* arc) {
                return (*arc == *Arret || *arc == arcInverse);
            }),
            arcs.end());
    }
    catch (const CException& e) {
        cerr << "Erreur lors de la suppression d'une arete : " << e.EXCGet_Val() << endl;
    }
}



template <typename T>
void CGraph<T>::CGraphAfficher() {
    cout << "=== Affichage du Graphe Non Oriente ===" << endl;
    if (this->CGraphOGET_Arc().empty()) {
        cout << "Le graphe ne contient aucune arete." << endl;
    }
    else {
        cout << "Relations entre sommets (aretes) :" << endl;
        vector<CArc<T>*> arcsAffiches;
        for (const auto& arc : this->CGraphOGET_Arc()) {
            bool dejaAffiche = false;
            for (const auto& arcAffiche : arcsAffiches) {
                if ((arcAffiche->ARCGet_SomDeb() == arc->ARCGet_SomDeb() &&
                    arcAffiche->ARCGet_SomA() == arc->ARCGet_SomA()) ||
                    (arcAffiche->ARCGet_SomDeb() == arc->ARCGet_SomA() &&
                        arcAffiche->ARCGet_SomA() == arc->ARCGet_SomDeb())) {
                    dejaAffiche = true;
                    break;
                }
            }
            if (!dejaAffiche) {
                CSommet<T>* sommetDebut = arc->ARCGet_SomDeb();
                CSommet<T>* sommetFin = arc->ARCGet_SomA();

                if (sommetDebut && sommetFin) {
                    cout << "Sommet(" << sommetDebut->SOMGet_Id() << ") <-----> Sommet("
                        << sommetFin->SOMGet_Id() << ")" << endl;
                    arcsAffiches.push_back(arc);
                }
                else {
                    cout << "Arete invalide (sommets manquants)." << endl;
                }
            }
        }
    }
    cout << "=== Fin de l'Affichage ===" << endl;
}

template class CGraph<int>;
template class CGraph<float>;
template class CGraph<double>;
template class CGraph<char>;
template class CGraph<bool>;
template class CGraph<std::string>;
template class CGraph<unsigned int>;
template class CGraph<long>;
template class CGraph<unsigned long>;
template class CGraph<short>;
template class CGraph<unsigned short>;
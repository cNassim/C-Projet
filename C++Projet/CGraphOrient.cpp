#include "CArc.h"
#include "CSommet.h"
#include "CException.h"
#include "CGraphOrient.h"
#include <iostream>

using namespace std;

template<typename T>
CGraphOrient<T>::CGraphOrient() : GRASom(), GRAArc() {
}

template <typename T>
CGraphOrient<T>::CGraphOrient(const vector<CSommet<T>*>& sommet, const vector<CArc<T>*>& arc)
    : GRASom(sommet), GRAArc(arc) {
    try {
        for (auto& Arc : GRAArc) {
            if (!Arc) {
                throw CException(1);
            }
            if (!Arc->ARCGet_SomDeb() || !Arc->ARCGet_SomA()) {
                throw CException(2);
            }
        }
        for (auto& Arc : GRAArc) {
            bool sommet1Existe = false;
            bool sommet2Existe = false;

            for (auto& sommet : GRASom) {
                if (sommet == Arc->ARCGet_SomDeb()) {
                    sommet1Existe = true;
                }
                if (sommet == Arc->ARCGet_SomA()) {
                    sommet2Existe = true;
                }
            }

            if (!sommet1Existe || !sommet2Existe) {
                throw CException(3);
            }
        }
    }
    catch (const CException& e) {
        if (e.EXCGet_Val() == 1) {
            cerr << "Erreur : Un arc est nul dans le constructeur !" << endl;
        }
        else if (e.EXCGet_Val() == 2) {
            cerr << "Erreur : Un arc contient des sommets invalides !" << endl;
        }
        else if (e.EXCGet_Val() == 3) {
            cerr << "Erreur : Un ou les deux sommets de l'arc n'existent pas !" << endl;
        }
        else {
            cerr << "Erreur inconnue lors de la construction du graphe !" << endl;
        }
    }
}

template <typename T>
CGraphOrient<T>::CGraphOrient(const CGraphOrient& GraphOrient)
    : GRASom(), GRAArc() {
    try {

        for (auto& sommet : GraphOrient.GRASom) {
            CSommet<T>* newSommet = new CSommet<T>(*sommet);
            GRASom.push_back(newSommet);
        }

        for (auto& arc : GraphOrient.GRAArc) {
            CArc<T>* newArc = new CArc<T>(*arc);
            GRAArc.push_back(newArc);
        }
    }
    catch (const CException& e) {
        cerr << "Erreur lors de la copie du graphe ! Code erreur : " << e.EXCGet_Val() << endl;
    }
}

template <typename T>
CGraphOrient<T>::~CGraphOrient() {
    for (auto sommet : GRASom) {
        delete sommet;
    }
    for (auto arc : GRAArc) {
        delete arc;
    }
    GRASom.clear();
    GRAArc.clear();
}

template <typename T>
void CGraphOrient<T>::CGraphOAjouterSommet(CSommet<T>* Som) {
    try {
        if (Som) {
            for (const auto& s : GRASom) {
                if (s == Som) {
                    throw CException(6);
                }
            }
            GRASom.push_back(Som);
        }
        else {
            throw CException(3);
        }
    }
    catch (const CException& e) {
        if (e.EXCGet_Val() == 3) {
            cerr << "Erreur : Sommet nul" << endl;
        }
        else if (e.EXCGet_Val() == 6) {
            cerr << "Erreur : Le sommet existe déjà dans le graphe" << endl;
        }
        else {
            cerr << "Erreur inconnue" << endl;
        }
    }
}

template <typename T>
void CGraphOrient<T>::CGraphOAjouterArc(CArc<T>* Arc) {
    try {
        if (!Arc) {
            throw CException(4);
        }
        for (const auto& a : GRAArc) {
            if (*a == *Arc) {
                throw CException(6); 
            }
        }

        // Si le graphe est vide, on ajoute les deux sommets et l'arc
        if (GRASom.empty() && GRAArc.empty()) {
            GRASom.push_back(Arc->ARCGet_SomDeb());
            GRASom.push_back(Arc->ARCGet_SomA());
            GRAArc.push_back(Arc);
        }
        else {
            // Vérification si au moins un des sommets de l'arc existe déjà
            bool sommet1Existe = false;
            bool sommet2Existe = false;

            for (auto& sommet : GRASom) {
                if (sommet == Arc->ARCGet_SomDeb()) {
                    sommet1Existe = true;
                }
                if (sommet == Arc->ARCGet_SomA()) {
                    sommet2Existe = true;
                }
            }

            // Si un sommet existe, ajouter l'autre sommet manquant
            if (sommet1Existe && !sommet2Existe) {
                GRASom.push_back(Arc->ARCGet_SomA());
                GRAArc.push_back(Arc);
            }
            else if (!sommet1Existe && sommet2Existe) {
                GRASom.push_back(Arc->ARCGet_SomDeb());
                GRAArc.push_back(Arc);
            }
            else if (!sommet1Existe && !sommet2Existe) {
                throw CException(5); // Aucun des deux sommets n'existe
            }
        }
    }
    catch (const CException& e) {
        if (e.EXCGet_Val() == 4) {
            cerr << "Erreur : L'arc est nul !" << endl;
        }
        else if (e.EXCGet_Val() == 5) {
            cerr << "Erreur : Aucun des deux sommets n'existe dans le graphe !" << endl;
        }
        else if (e.EXCGet_Val() == 6) {
            cerr << "Erreur : L'arc existe déjà dans le graphe !" << endl;
        }
        else {
            cerr << "Erreur inconnue lors de l'ajout de l'arc !" << endl;
        }
    }
}


template <typename T>
vector<CSommet<T>*> CGraphOrient<T>::CGraphOGET_Sommet() const {
    return GRASom;
}

template <typename T>
vector<CArc<T>*> CGraphOrient<T>::CGraphOGET_Arc() const {
    return GRAArc;
}

template <typename T>
void CGraphOrient<T>::CGraphOModifierSommet(unsigned int uiIdsom, CSommet<T>* nouveauSommet) {
    try {
        if (!nouveauSommet) {
            throw CException(6);
        }

        CSommet<T>* ancienSommet = CGraphOChercherSommetParId(uiIdsom);
        if (!ancienSommet) {
            throw CException(7);
        }

        for (auto& arc : GRAArc) {
            if (arc->ARCGet_SomDeb() == ancienSommet) {
                arc->ARCModifierSomDeb(nouveauSommet);
            }
            if (arc->ARCGet_SomA() == ancienSommet) {
                arc->ARCModifierSomA(nouveauSommet);
            }
        }

        for (auto& sommet : GRASom) {
            if (sommet == ancienSommet) {
                delete sommet;
                sommet = nouveauSommet;
                return;
            }
        }
    }
    catch (const CException& e) {
        if (e.EXCGet_Val() == 6) {
            cerr << "Erreur : Sommet invalide (nullptr)." << endl;
        }
        else if (e.EXCGet_Val() == 7) {
            cerr << "Erreur : Sommet avec l'ID " << uiIdsom << " non trouvé." << endl;
        }
        else {
            cerr << "Erreur inconnue lors de la modification du sommet." << endl;
        }
    }
}


template <typename T>
void CGraphOrient<T>::CGraphOModifierArc(CArc<T>* arcToModify, CArc<T>* newArc) {
    try {
        if (!newArc) {
            throw CException(8);
        }

        for (auto& arc : GRAArc) {
            if (*arc == *arcToModify) {
                arc = newArc;
                return;
            }
        }

        throw CException(9);
    }
    catch (const CException& e) {
        if (e.EXCGet_Val() == 8) {
            cerr << "Erreur : Arc invalide" << endl;
        } else{
            cerr << "Erreur : Arc non trouvé" << endl;
        }
    }
}

template <typename T>
void CGraphOrient<T>::CGraphOSupprimerSommet(unsigned int uiIdsom) {
    try {
        CSommet<T>* sommetASupprimer = CGraphOChercherSommetParId(uiIdsom);
        if (!sommetASupprimer) {
            throw CException(10);
        }

        for (auto it = GRAArc.begin(); it != GRAArc.end(); ) {
            if ((*it)->ARCGet_SomDeb() == sommetASupprimer || (*it)->ARCGet_SomA() == sommetASupprimer) {
                delete* it;
                it = GRAArc.erase(it);
            }
            else {
                ++it;
            }
        }
        auto it = find(GRASom.begin(), GRASom.end(), sommetASupprimer);
        if (it != GRASom.end()) {
            delete* it;
            GRASom.erase(it);
        }
    }
    catch (const CException& e) {
        if (e.EXCGet_Val() == 10) {
            cerr << "Erreur : Sommet avec l'ID " << uiIdsom << " non trouvé." << endl;
        }
        else {
            cerr << "Erreur inconnue lors de la suppression du sommet." << endl;
        }
    }
}


template <typename T>
void CGraphOrient<T>::CGraphOSupprimerArc(CArc<T>* arcToDelete) {
    for (auto it = GRAArc.begin(); it != GRAArc.end(); ++it) {
        if (*it == arcToDelete) {
            delete* it;
            GRAArc.erase(it);
            return;
        }
    }
}

template <typename T>
CSommet<T>* CGraphOrient<T>::CGraphOChercherSommetParId(unsigned int uiIdsom) const {
    for (auto& sommet : GRASom) {
        if (sommet->SOMGet_Id() == uiIdsom) {
            return sommet;
        }
    }
    return nullptr;
}

template <typename T>
void CGraphOrient<T>::CGraphOAfficher() const {
    cout << "Sommets" << endl;
    for (const auto& sommet : GRASom) {
        sommet->SOMAfficher();
    }
    cout << "\nArcs" << endl;
    for (const auto& arc : GRAArc) {
        arc->ARCAfficher();
    }
}

template class CGraphOrient<int>;
template class CGraphOrient<float>;
template class CGraphOrient<double>;

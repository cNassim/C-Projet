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
            if (!Arc->ARCGet_Sommet1() || !Arc->ARCGet_Sommet2()) {
                throw CException(2);
            }
        }
        for (auto& Arc : GRAArc) {
            bool sommet1Existe = false;
            bool sommet2Existe = false;

            for (auto& sommet : GRASom) {
                if (sommet == Arc->ARCGet_Sommet1()) {
                    sommet1Existe = true;
                }
                if (sommet == Arc->ARCGet_Sommet2()) {
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
        cerr << "Erreur lors de la copie du graphe !" << endl;
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
            GRASom.push_back(Som);
        }
        else {
            throw CException(3);
        }
    }
    catch (const CException& e) {
        if (e.EXCGet_Val() == 3) {  
           cerr << "Erreur : Sommet nul" << endl;  
        } else {  
           cerr << "Erreur inconnue" << endl;  
        }
    }
}

template <typename T>
void CGraphOrient<T>::CGraphOAjouterArc(CArc<T>* Arc) {
    try {
        // Si le graphe est vide, on ajoute les deux sommets et l'arc
        if (GRASom.empty() && GRAArc.empty()) {
            if (!Arc) {
                throw CException(4); // L'arc est nul
            }
            GRASom.push_back(Arc->ARCGet_Sommet1());
            GRASom.push_back(Arc->ARCGet_Sommet2());
            GRAArc.push_back(Arc);
        }
        else {
            // Vérification si au moins un des sommets de l'arc existe déjà
            bool sommet1Existe = false;
            bool sommet2Existe = false;

            for (auto& sommet : GRASom) {
                if (sommet == Arc->ARCGet_Sommet1()) {
                    sommet1Existe = true;
                }
                if (sommet == Arc->ARCGet_Sommet2()) {
                    sommet2Existe = true;
                }
            }

            // Si un sommet existe, ajouter l'autre sommet manquant
            if (sommet1Existe && !sommet2Existe) {
                GRASom.push_back(Arc->ARCGet_Sommet2());
                GRAArc.push_back(Arc);
            }
            else if (!sommet1Existe && sommet2Existe) {
                GRASom.push_back(Arc->ARCGet_Sommet1());
                GRAArc.push_back(Arc);
            }
            else if (!sommet1Existe && !sommet2Existe) {
                throw CException(5);
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
void CGraphOrient<T>::CGraphOModifierSommet(unsigned int uiIdsom, CSommet<T>* Som) {
    try {
        if (!Som) {
            throw CException(6);
        }

        for (auto& sommet : GRASom) {
            if (sommet->SOMGet_Id() == uiIdsom) {
                sommet = Som;
                return;
            }
        }

        throw CException(7);
    }
    catch (const CException& e) {
        if (e.EXCGet_Val() == 6) {  
           cerr << "Erreur : Sommet invalide" << endl;  
        } else {  
           cerr << "Erreur : Sommet non trouvé" << endl;  
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
            if (arc->ARCGet_IdArc() == arcToModify->ARCGet_IdArc()) {
                arc = newArc;
                return;
            }
        }

        throw CException(9);
    }
    catch (const CException& e) {
        if (e.EXCGet_Val() == 8) {
            cerr << "Erreur : Arc invalide" << endl;
        } else {
            cerr << "Erreur : Arc non trouvé" << endl;
        }
    }
}

template <typename T>
void CGraphOrient<T>::CGraphOSupprimerSommet(unsigned int uiIdsom) {
    for (auto it = GRASom.begin(); it != GRASom.end(); ++it) {
        if ((*it)->SOMGet_Id() == uiIdsom) {
            delete* it;
            GRASom.erase(it);
            return;
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
void CGraphOrient<T>::CGraphOAfficher() {
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

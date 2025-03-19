#include <iostream>
#include <queue>
#include <vector>
#include <string>

// Classe représentant un descripteur de processus
class CDDProc
{
    public:
    unsigned int PID;
    unsigned int Priorite;
    std::string NomExecutable;

    CDDProc(unsigned int pid, unsigned int priorite, const std::string& nom)
        : PID(pid), Priorite(priorite), NomExecutable(nom) { }

    // Surcharge de l'opérateur < pour trier par priorité croissante
    bool operator <(const CDDProc& autre) const {
        return Priorite > autre.Priorite; // Plus petite priorité en haut de la file
    }
};

// Classe représentant la file des descripteurs de processus
class CFileDDP
{
    private:
    std::priority_queue<CDDProc> file;

    public:
    void ajouterProcessus(const CDDProc& proc) {
        file.push(proc);
}

void extraireProcessus()
{
    if (!file.empty())
    {
        CDDProc proc = file.top();
        file.pop();
        std::cout << "Processus extrait: PID=" << proc.PID
                  << ", Priorite=" << proc.Priorite
                  << ", Nom=" << proc.NomExecutable << std::endl;
    }
    else
    {
        std::cout << "La file est vide." << std::endl;
    }
}

bool estVide() const {
        return file.empty();
    }
};

int main()
{
    CFileDDP fileDDP;

    fileDDP.ajouterProcessus(CDDProc(1, 5, "process1.exe"));
    fileDDP.ajouterProcessus(CDDProc(2, 2, "process2.exe"));
    fileDDP.ajouterProcessus(CDDProc(3, 8, "process3.exe"));

    while (!fileDDP.estVide())
    {
        fileDDP.extraireProcessus();
    }

    return 0;
}


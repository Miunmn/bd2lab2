#include<iostream>
#include<string>
#include<vector>
#include <algorithm>

struct Registro{
    char codigo[5];
    char nombre[20];
    char carrera[15];
    int ciclo;
    char next[2]; //Si esta en el main file-> 1m, si esta en el aux->1a

    void setData()
    {
        std::cout << "Nombre:";
        std::cin >> nombre;
        std::cout << "Carrera: ";
        std::cin >> carrera;
        std::cout << "Ciclo: ";
        std::cin >> ciclo;
    }

    void showData()
    {
        std::cout << "\nCodigo: " <<codigo;
        std::cout << "\nNombre: " << nombre;
        std::cout << "\nCarrera: " << carrera;
        std::cout << "\nCiclo : " << ciclo;
        std::cout << "\nSgte Registro en:" <<next;
    }

    std::string getKey()
    {
        return nombre;
    }

};

class SequentialFile{
private:
    std::string mainFileName;
    std::string auxFileName;
public:
    SequentialFile(std::string filename){
        this->mainFileName=filename+".dat";
        this->auxFileName="Aux"+filename+".dat";
    }


    void insertAll(std::vector<Registro> registros){
        for(auto& registro: registros){
            
        }
    };


    void add(Registro registr){
        
    }

    Registro search(std::string key){

    }

    std::vector<Registro> rangeSearch(std::string begin, std::string end){

    }
};


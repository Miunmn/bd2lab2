#include "SequentialFile.h"
#include <fstream>
#include <vector>
#include <cstring>

//hacerlo lambda
std::string fill_with_dots(std::string stringval, int size_){
    while(stringval.size()!=size_){
        stringval.append(".");
    }
    return stringval;
}

int main(){

    std::string inputFileName="alumnosInputData.txt";

    std::string intFileName(inputFileName);
    FILE* input_file = fopen(intFileName.c_str(), "r"); 

    std::vector<Registro> registros;


    for(int i = 0 ;i<registros.size() ;i++){
        std::cout<< registros[i].nombre;
    }
    std::string filename="Datos";
    SequentialFile seqFile(filename);




    return EXIT_SUCCESS;
}

    //LEER UN TXT E INGRESARLO A UN VECTOR

    // Registro registro;
        // int atributo=0;
    // int c;
    // int iter=-2;
    // while ((c = fgetc(input_file)) != EOF) {
    //     if(c==';'){
    //         switch (atributo)
    //         {
    //         case 3:
    //             iter=0;
    //             atributo=0;
    //             registros.push_back(registro);
    //             continue;
    //             //break;
    //         default:
    //             /* code */
    //             iter=0;
    //             atributo++;
    //             continue;
    //             //break;
    //         }

    //     }
    //     putchar(c);
    //     switch (atributo)
    //     {
    //         case 0:
    //             registro.codigo[iter]=c;
    //             break;
    //         case 1:
    //             registro.nombre[iter]=c;
    //             break;
    //         case 2:
    //             registro.carrera[iter]=c;
    //             break;
    //         default:
    //             registro.ciclo=c;
    //             break;
    //     }
    //     iter++;
    //    //putchar(c);
    // }
    // fclose(input_file);
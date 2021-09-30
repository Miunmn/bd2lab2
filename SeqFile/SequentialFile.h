#include "lib.h"

#define MAX_AUX 5

//" registro {{{1 
struct Registro{
  int codigo;
  char nombre[20];
  char carrera[15];
  int ciclo;
  bool aux = false;
  int next = -1;
  
};
//" templates {{{1
template<typename T>
std::fstream& readBinaryFile(std::fstream& stream, T& record){
  stream.read((char*)& record, sizeof(record));
  return stream;
}
template<typename T>
std::fstream& appendInBinaryFile(std::fstream& stream, T& record){
  stream.write((char*)& record, sizeof(record));
  return stream;
}

//" sequentialFile {{{1
class SequentialFile{
  public:
    SequentialFile(std::string fileName, std::string auxName){
      this->fileName = fileName;
      this->auxName = auxName;
      std::fstream file, aux;

      file.open(fileName, std::fstream::binary);
      file.seekg(0, std::ios::end);
      size = file.tellg();
      size /= sizeof(Registro);
      file.close();

      aux.open(auxName, std::fstream::binary);
      aux.seekg(0, std::ios::end);
      sizeAux = aux.tellg();
      sizeAux /= sizeof(Registro);
      size += sizeAux;
      aux.close();
      
    }
    void insertAll(std::vector<Registro> registros){

    }

    void add(Registro registro){

    }

    Registro search(int key){

      Registro result{0,0,0,0,-2};

      int auxResult = linarSearchAux(key);

      if(auxResult > -1){
        std::fstream aux;
        aux.open(auxName, std::fstream::binary);
        readBinaryFile(aux, result);
        aux.close();
        return result;
      }

      int fileResult = binarySearch(key);
      if(fileResult > -1){
        std::fstream file;
        file.open(fileName, std::fstream::binary);
        readBinaryFile(file, result);
        file.close();
        return result;
      }
      std::cout << "No se encontrÃ³ el registro!!"<<std::endl;
      return result;
    }

    std::vector<Registro> search(int begin, int end){
      std::vector<Registro> resultados;
      Registro re=search(begin),ref=search(end);

      if(re.next == -2 ||ref.next == -2)
        return resultados;
      resultados.push_back(re);

      std::fstream file,aux;
      file.open(fileName, std::fstream::binary);
      aux.open(auxName, std::fstream::binary);
      while(re.next >= -1 && re.codigo < end +1){

        if(re.aux == true){
          aux.seekg(re.next, std::ios::beg);
          readBinaryFile(aux, re);
        }
        else{
          file.seekg(re.next,std::ios::beg);
          readBinaryFile(file, re);
        }
        resultados.push_back(re);
      }

      file.close();
      aux.close();
      return resultados;
    }

  private:
    std::string fileName;
    std::string auxName;
    int size;
    int sizeAux;

    int linarSearchAux(int key){
      std::fstream aux;
      aux.open(auxName, std::fstream::binary);
      Registro re;
      for(int i = 0 ; i < sizeAux; i++){
        readBinaryFile(aux , re);
        if(re.codigo == key){
          aux.close();
          return i;
        }
      }
      aux.close();
      return -1;
    }

    int binarySearch(int key){
      std::fstream file;
      file.open(fileName, std::fstream::binary);
      int l {}, u = size -1;
      Registro re;
      while(l <= u){
        int m = (u + l)/2;
        file.seekg(m*sizeof(Registro));
        readBinaryFile(file , re);
        if(re.codigo < key)
          l = m+1;
        else if(re.codigo > key)
          u = m-1;
        else {
          file.close();
          return m;
        }
      }
      file.close();
      return -1;
    }

    int minIndex(){
      std::fstream aux,file;
      aux.open(auxName, std::fstream::binary);
      int min = std::numeric_limits<int>::max();
      Registro re;
      int pos, posr;
      for(int i = 0 ; i < sizeAux; i++){
        pos = aux.tellg();
        readBinaryFile(aux , re);
        if(re.codigo < min){
          posr = pos;
        }
      }
      aux.close();
      file.open(fileName, std::fstream::binary);
      Registro redox;
      readBinaryFile(file,redox);
      file.close();
      if(redox.codigo < min)
        return -1;
      return posr;
    }
    void reorganizacion(){
      int posDelMenor;
      std::vector<Registro> reordenado;
      Registro actual, siguiente;
      std::fstream file, aux;

      file.open(fileName, std::fstream::binary);
      aux.open(auxName, std::fstream::binary);

      if(posDelMenor = minIndex() == -1){
        file.seekg(0, std::ios::beg);
        readBinaryFile(file, actual);
        reordenado.push_back(actual);
        while(actual.next >= -1){
          if(actual.aux == true){
            aux.seekg(actual.next, std::ios::beg);
            readBinaryFile(aux, actual);
          }      
        }
      }
      else{

      } 
    }
};

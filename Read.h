#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Read{

    private:
        string temp;
        ifstream file;
        vector <string> vtemp;
    public:
        Read(){}
        ~Read(){}
        vector <string> name;
        vector <string> seq;
        void leer();
};

void Read::leer(){
        //Se abre el archivo
        cout<<"Ingrese el nombre del Archivo con las secuencias: "<<endl;
        cin >> temp;

        file.open(temp.c_str());
        if(file.fail()){
            cout<< "No se pudo abrir el archivo" <<endl;
        };

        //Se copia cada linea del archivo en el string temporal "temp" y se pasa a los vectores "name" y "seq"
        while (getline(file,temp))
        {
            //Discrimina si la linea posee el nombre de la secuencia
            if(temp[0] == '>'){
                name.push_back(temp);
            }
            //Sino, se guarda como secuencia
            else
            {
              seq.push_back(temp);  
            };
        };
        
        file.close();
    };
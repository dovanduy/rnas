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
        int a = 0;
        vector <string> name;
        vector <string> seq;
        void leer();
        void mname();
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
        //Los cout fueron pruebas para ver si funcionaba name
        cout << "Aca: "<<name[0][0]<<endl;
        mname();
        cout << "Aca: "<<name[0][0]<<endl;
        file.close();
    };

    //Modifican el vector name, sacando todo menos el nombre en sí
    void Read::mname(){
        //Se elimina el espacio blanco del ultimo vector
        for (int i = 0; i < name[i].size(); i++)
        {
            name[i].pop_back();
        }
        //Se elimina el signo '>' del principio
        for(int i = 0; i<name.size(); i++){
            for(int j = 0; j<name[i].size();j++){
                if(name[i][j] == '>'){
                    name[i].erase(name[i].begin()+j);
                }

            };    
        };
    };
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Read{

    private:
        string temp;
        ifstream file;
        vector <string> tfile;
        vector <int> l;
        vector <vector <int> > ls;
        void mname();
        void mseq();
        void mfile();
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

        int l = 0;
        int n = 0;
        bool s = false;
        bool m = false;
        //Se copia cada linea del archivo en el string temporal "temp" y se pasa al vector tfile
        while (getline(file,temp))
        {
            tfile.push_back(temp);
        };
        mfile();
        file.close();
    };

    //Modifica el vector "file", que contiene todas las lineas del archivo abierto
    void Read::mfile(){
        int v = -1;
        //Primero: discrimina nombres (se almacenan en el vector "name")
        for(int i = 0; i<tfile.size();i++){
        //Discrimina si cada elemento del array (linea del archivo) posee el nombre de la secuencia
            if(tfile[i][0] == '>'){
                name.push_back(tfile[i]);
                if(v != -1){
                    ls.push_back(l);
                    l.clear();
                };
            }
        //Sino, se guarda como secuencia
            else
            {
                v = 0;
                l.push_back(i);
                if(i == (tfile.size()-1)){
                    ls.push_back(l);
                };
            };
        };
        //Segundo: Se modifica el vector "name"
        mname();
        //Tercero: Se guardan secuencias ya modificadas en el vector "seq"
        mseq();
    };

    //Modifica el vector "name", sacando todo menos el nombre en sí
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

    //Modifica el vector "seq" uninendo las lineas de secuencias en una secuencia 
    void Read::mseq(){
        int c,v,carac;
        vector <string> _seqm;
        for(int i = 0;i<ls.size();i++){
            c = ls[i][0];
            _seqm.push_back(tfile[c]);
            v = _seqm[i].size()-1;
            _seqm[i].erase(v);
            for(int j = 1; j<ls[i].size();j++){
                c = ls[i][j];
                for(int k = 0;k<tfile[c].size();k++){
                    carac = tfile[c][k];
                    if(tfile[c][k] != 13){
                        _seqm[i].push_back(tfile[c][k]);
                    };
                };
            };
        };
        for(int i = 0; i < _seqm.size();i++){
            seq.push_back(_seqm[i]);
        };
    };


#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include "folds.h"

using namespace std;

int main(int argc, char const *argv[])
{
    vector <string> alm;
    vector <string> name;
    string seq, nfile;

    cin>>nfile;
    
    //.c_str() convierte el string de "nombre" en utilizable para la funcion
    ifstream file(nfile.c_str());

    //Se comprueba si el archivo se abrió correctamente
    if(!file.good()){
        cout<<"Error al abrir el archivo"<<endl;
        return -1;
    };
    
    //Se recorre el archivo y lo almacena en nfile (string utilizado anteriomente)
    while(getline(file,nfile)){
        alm.push_back(nfile);
    };
    //Se cierra el archivo
    file.close();
    
    //Se muestra con espacios y sin diferenciar nombres
    cout<<"tamaño de vector inicial: " << alm.size()<<endl;
    for(int i=0; i< alm.size() ;i++){
        cout<<alm[i]<<endl;
    };

    //Se eliminan los espacios en las secuencias
    for(int i =0; i< alm.size() ; i++){
        for(int j= 0; j< alm[i].size() ;j++){
            if(alm[i][j] == ' '){
                    alm[i].erase(alm[i].begin()+j);
                };
            
            };
    };
    //Si las secuencias estan cortadas, las uno y elimino los sobrantes
    
    
    //Guardo los nombres en el vector name y elimino el vector original de alm
    for(int i =0; i< alm.size() ; i++){
        if(alm[i][0]=='>'){
                name.push_back(alm[i]);
                alm.erase(alm.begin()+i);
        };
    };
    
    //Se muestra sin espacios y diferenciando nombres
    cout<<endl;
    cout<<"tamaño de vector despues de aplicarle los cambios: " << alm.size()<<endl;
     for(int i=0; i< alm.size() ;i++){
        cout<<"Nombre: "<<name[i]<<endl;
        cout<<"Seq: "<< alm[i]<<endl;
     };

     //Folds class
		string namev = "pepe";
    Folds* seqf= new Folds(alm[4],namev);
    int seqf2 = seqf->fold();
     
     
     
     return 0;
}
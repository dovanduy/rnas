#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include "Folds.h"
#include "Read.h"

using namespace std;

int main(int argc, char const *argv[])
{
    //Variables
    vector <string> names, seqs;
    //Se crea la clase "Read" que lee el archivo
    Read Sequences;
    Sequences.leer();
    

    //Folds class
    for(int i;i<(Sequences.seq).size();i++){
    string tempm = Sequences.name[i];
	Folds* seqf= new Folds(Sequences.seq[i],tempm);
    int seqf2 = seqf->fold();
    };
     
     
     return 0;
}
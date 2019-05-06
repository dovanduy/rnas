#include <string>
#include "RNAstructure/RNA_class/RNA.h"
using namespace std;
class Folds{
    public:
        Folds (string seq, string save){
            seqFile_ = seq, saveFile_ = save;
        };
        void fold();
    private:
			string seqFile_, saveFile_;
};

void Folds::fold(){
    
	RNA* rnaf = new RNA (seqFile_.c_str(), true);
	int calc = rnaf -> FoldSingleStrand(20,1,0,saveFile_.c_str(),30,true);
	if (calc!=0){
		cout<<"ERROR: "<< calc<<endl;
	} 
	else
	{
	const DotBracketFormat bracketFmt = DBN_FMT_MULTI_TITLE; //see DotBracketFormat.h
		// write DotBracket file
	int writeError = rnaf->WriteDotBracket(saveFile_.c_str(), -1/*write ALL*/, bracketFmt); 
	if(writeError != 0){
			cout<<"Ocurrió un error al escribir el archivo de salida. Error número: "<<writeError<<enld;
		};
	}
	
	};
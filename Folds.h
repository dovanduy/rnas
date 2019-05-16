#include <string>
#include "RNAstructure/RNA_class/RNA.h"
using namespace std;
class Folds{
    public:
        Folds (string seq, string save){
            seqFile_ = seq, saveFile_ = save;
        };
        int fold();
    private:
			string seqFile_, saveFile_;
};

int Folds::fold(){
    
	RNA* rnaf = new RNA (seqFile_.c_str(), true);
	int calc = rnaf -> FoldSingleStrand(20,1,0,"",30,true);
	if (calc!=0){
		cout<<"ERROR: "<< calc<<endl;
	} 
	else
	{
	const DotBracketFormat bracketFmt = DBN_FMT_SIDE_TITLES; //see DotBracketFormat.h
			// write DotBracket file
	int writeError = rnaf->WriteDotBracket(saveFile_.c_str());
	return 0;
	}
	
	};

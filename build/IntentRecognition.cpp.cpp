//IntentRecognition.cpp
#include <iostream>
#include <regex>
#include <unordered_map>

using namespace std;

static unordered_map<string, regex> IntentMap; 

class IntentClassifier{
    
    public:
	void prepareIntent();
    bool extractIntent(string mystr);
};

void IntentClassifier::prepareIntent()
{	
	IntentMap.insert(std::pair<string, regex>("Intent: Get Fact","[Ff][Aa][Cc][Tt]"));
	IntentMap.insert(std::pair<string, regex>("Intent: Get Weather","[Ww][Ee][Aa][Tt][Hh][Ee][Rr]"));
	IntentMap.insert(std::pair<string, regex>("Intent: Get Weather City","[Ww][Ee][Aa][Tt][Hh][Ee][Rr](.*)[in]"));
	
}

bool IntentClassifier::extractIntent(string myStr)
{  
    smatch match;
	for (unordered_map<string, regex>::iterator it = IntentMap.begin(); it != IntentMap.end(); ++it) 
	{	
		if (regex_search(myStr,match,(*it).second))
		{
			cout << (*it).first <<endl;
		    return true;
		}
	}
    
	return false;
}

int main(int argc, char *argv[])
{    
	IntentClassifier Obj;
    
	Obj.prepareIntent();
        bool val = Obj.extractIntent(argv[1]);  
	
	if (val == false)
		cout<<"Intent not found"<<endl;
        return 0;
}
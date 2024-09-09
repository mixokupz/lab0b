#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <map>
using namespace std;

void read_potok(ifstream& file,string& str_word,map<string,int> &chis_slov,int*counts){
    string word;
    while(getline(file,str_word)){
        stringstream potok(str_word);
        while(potok >> word){
            if(chis_slov.count(word)>0){
                chis_slov[word] +=1;
            }
            else{
                chis_slov.insert({word,1});
            }
            (*counts)+=1;
        }
    }
}

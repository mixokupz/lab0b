#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <map>
using namespace std;

void read_potok(ifstream& file,string& str_word,map<string,int> &num_word,int*counts){
    string word;
    while(getline(file,str_word)){
        stringstream potok(str_word);
        while(potok >> word){
            if(num_word.count(word)>0){
                num_word[word] +=1;
            }
            else{
                num_word.insert({word,1});
            }
            (*counts)+=1;
        }
    }
}

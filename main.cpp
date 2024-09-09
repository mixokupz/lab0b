#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include "sorting.h"
#include "reading.h"

using namespace std;


int main(int argc, char** argv){
    ifstream file; 
    ofstream table; 
    string str_word;
    string word;
    map<string,int> chis_slov;
    file.open(argv[1]);
    table.open(argv[2]);
    //сбор информации и подсчет
    int counts = 0;
    read_potok(file,str_word,chis_slov,&counts);
    
    vector<pair<string,int>>vec;
    for(auto m:chis_slov){
        vec.push_back(make_pair(m.first,m.second));
    }
    sorting_pair(vec);

    table << "Words"<<";"<<"Count of word"<<";"<<"Count of word in %"<<"\n";
    for (auto itr = vec.begin(); itr != vec.end(); ++itr) { 
        table << itr->first << ";" <<itr->second<<";"<<itr->second*100/counts<<"\n";
    }


    file.close();
    table.close();

    return 0;     
}
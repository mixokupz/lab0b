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
    map<string,int> num_word; 
    if(argc==1){
        cout << "You have not put files: .txt and .csv"<<"\n";

    }
    else if(argc==2){
        cout << "You have not put .csv file"<<"\n";

    }
    else{
        file.open(argv[1]);
        table.open(argv[2]);
        if(!file.is_open() || !table.is_open()){
            cout << "ERROR: files is not open"<<"\n";
        }
        //сбор информации и подсчет
        int counts = 0;
        read_potok(file,str_word,num_word,&counts);
    
        vector<pair<string,int>>vec;
        for(auto m:num_word){
            vec.push_back(make_pair(m.first,m.second));
        }
        sorting_pair(vec);

        table << "Words"<<";"<<"Count of word"<<";"<<"Count of word in %"<<"\n";
        for (auto itr = vec.begin(); itr != vec.end(); ++itr) { 
            table << itr->first << ";" <<itr->second<<";"<<itr->second*100/counts<<"\n";
        }


        file.close();
        table.close();
    }

    

    return 0;     
}
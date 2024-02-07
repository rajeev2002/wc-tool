#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void number_of_bytes(ifstream& file){

    file.seekg(0,ios::end);
    int num_bytes = file.tellg();
    cout<<num_bytes;

}

void number_of_lines(ifstream& file){

    string line;
    int num_lines=0;
    while(getline(file, line)){
        num_lines+=1;
    }
    cout<<num_lines;
}

void number_of_words(ifstream& file){

    string word;
    int num_words=0;
    while(file>>word){
        num_words+=1;
    }
    cout<<num_words;

}

int main(int argc, char* argv[]){

    string option = argv[1], file_path = argv[2];
    ifstream file(file_path);

    if(option[1] == 'c'){
        number_of_bytes(file);
    }else if(option[1] == 'l'){
        number_of_lines(file);
    }else if(option[1] == 'w'){
        number_of_words(file);
    }
}
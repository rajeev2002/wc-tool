#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void move_pointer_to_start(ifstream& file){
    file.clear();
    file.seekg(0,ios:: beg);
}

void number_of_bytes(ifstream& file){

    file.seekg(0,ios::end);
    int num_bytes = file.tellg();
    cout<<num_bytes<<" ";
    move_pointer_to_start(file);
    
}

void number_of_lines(ifstream& file){

    string line;
    int num_lines=0;
    while(getline(file, line)){
        num_lines+=1;
    }
    cout<<num_lines<<" ";
    move_pointer_to_start(file);

}

void number_of_words(ifstream& file){

    string word;
    int num_words=0;
    while(file>>word){
        num_words+=1;
    }
    cout<<num_words<<" ";
    move_pointer_to_start(file);

}

void number_of_characters(ifstream& file){

    char ch;
    int num_characters = 0;
    while(file.get(ch)){
        num_characters+=1;
    }
    cout<<num_characters<<" ";
    move_pointer_to_start(file);
    
}

int main(int argc, char* argv[]){

    if(argc == 2){
        string first_arg = argv[1];
        if(first_arg[0]!='-'){
            ifstream file(first_arg, ios::binary);
            number_of_lines(file);
            number_of_words(file);
            number_of_bytes(file);
        }
    }else{

        string option = argv[1], file_path = argv[2];
        ifstream file(file_path, ios::binary);

        char action = option[1];

        switch(action){
            case 'c':
                number_of_bytes(file);
                break;
            case 'l':
                number_of_lines(file);
                break;
            case 'w':
                number_of_words(file);
                break;
            case 'm':
                number_of_characters(file);
                break;
            default:
                cout<<"The option you have provided is invalid. please use the following command for help"<<"\n";
                cout<<"cwcc --help";
        }
    }

    return 0;
}
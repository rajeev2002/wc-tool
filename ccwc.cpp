#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void printHelpMsg(){

    cout<<"Usage: ./ccwc [OPTION] [FILE]\n";
    cout<<"With no FILE, read standard input.";
    cout<<"You can use the cat operator and the pipe operator to give input as well.\n";
    cout<<"Like this: cat file | ./ccwc [OPTION]\n\n";
    cout<<"  option                 description\n";
    cout<<"  -c, --bytes            print the byte counts\n";
    cout<<"  -m, --chars            print the character counts\n";
    cout<<"  -l, --lines            print the newline counts\n";
    cout<<"  -w, --words            print the word counts\n\n";
}

void move_pointer_to_start(istream& file){
    file.clear();
    file.seekg(0,ios:: beg);
}

void number_of_bytes(istream& file){

    file.seekg(0,ios::end);
    int num_bytes = file.tellg();
    cout<<num_bytes<<" ";
    move_pointer_to_start(file);
    
}

void number_of_lines(istream& file){

    string line;
    int num_lines=0;
    while(getline(file, line)){
        num_lines+=1;
    }
    cout<<num_lines<<" ";
    move_pointer_to_start(file);

}

void number_of_words(istream& file){

    string word;
    int num_words=0;
    while(file>>word){
        num_words+=1;
    }
    cout<<num_words<<" ";
    move_pointer_to_start(file);

}

void number_of_characters(istream& file){

    char ch;
    int num_characters = 0;
    while(file.get(ch)){
        num_characters+=1;
    }
    cout<<num_characters<<" ";
    move_pointer_to_start(file);
    
}

void do_action(char action, istream& file){

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
    }

}

void printErrMsg(string type){

    string errMsg = "Use the following command for help.\n./ccwc --help";
    cout<<type<<"\n"<<errMsg;

}

bool isActionValid(string action){
    
    if(action.length() !=2 || action[0]!='-' || !(action[1]=='c'||action[1]=='l'||action[1]=='w'||action[1]=='m')){
        printErrMsg("Invalid Action");
        return false;
    }

    return true;
}

int main(int argc, char* argv[]){

    if(argc == 2){
        string first_arg = argv[1];
        if(first_arg == "--help"){
            printHelpMsg();
        }else if(first_arg[0]!='-'){
            ifstream file(first_arg, ios::binary);
            if(!file){
                printErrMsg("Invalid File Path");
                return 0;
            }
            number_of_lines(file);
            number_of_words(file);
            number_of_bytes(file);
        }else{

            if(!isActionValid(first_arg)){
                return 0;
            }

            char action = first_arg[1];
            do_action(action, cin);
        }
    }else if(argc == 3){

        string option = argv[1], file_path = argv[2];
        ifstream file(file_path, ios::binary);

        if(!isActionValid(option)){
            return 0;
        }

        if(!file){
            printErrMsg("Invalid File Path");
            return 0;
        }

        char action = option[1];

        do_action(action, file);
        
    }else{
        if(argc==1){
            printErrMsg("No Arguments");
        }else{
            printErrMsg("Too Many Arguments");
        }
    }

    return 0;
}
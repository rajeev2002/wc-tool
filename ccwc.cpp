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

int main(int argc, char* argv[]){

    string option = argv[1], file_path = argv[2];
    ifstream file(file_path);

    if(option[1] == 'c'){
        number_of_bytes(file);
    }
}
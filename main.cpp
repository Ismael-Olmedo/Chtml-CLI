#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
using namespace std;

struct{
            const char* assets="assets";
            const char* lib="lib";
            const char* output="output";
            const char* packages="packages";
            const char* web="web";
            }folder;

void create_folders();

int main(int argc, char* argv[]) {

    if (argc > 1) {
        string argument = argv[1];
        ifstream file(argument);
//Generates a chtml template
        if (argument == "template") {
        create_folders();
            //Writes the help commands
        } else if (argument == "help") {
            string help_info;
            ifstream help_file ("help.txt");
            if (!help_file.is_open()){
            cout<<"It seems I can´t find the help file...";
            }else{
            while (getline(help_file, help_info)){
            cout<<help_info<<endl;
            }
              help_file.close();
             }
        }
        //lets you edit the file
        else if(argument == "edit"){
        system("clear");
            ofstream maincode ("main.chtml");
            if(!maincode){
                cout<<"can't open this file/ perhaps you haven't created this file yet"<<endl;
                exit(EXIT_FAILURE);
            }
            string mycode;
            while(true){
                getline(cin, mycode);
                if(mycode=="*"){
                    break;
                }
                maincode << mycode <<endl;
            }
            maincode.close();
        }
        else if(argument == "package"){
        cout<<"Package"<<endl;
        }
        //here i convert to html
        else if(argument == "convert"){

        }
        // in this part of the code the, chtml file is read and will generate an output
        else if(file){
        string mycode;
        ifstream opened_file (argument);
        if (!opened_file.is_open()){
            cout<<"It seems I can´t find the help file...";
            }else{
            //main loop for analizing chtml file
            ofstream output("output.txt");
            while (getline(opened_file, mycode)){
            //searching for....
            size_t posprint=mycode.find("print");
            size_t poscode=mycode.find("code");
            //analizing.. and
            //This searches for the code that will be executed in javascript
            if(poscode!=string::npos){
            cout<<"I found the code!"<<endl;
            }

            //This prints the code
            if(posprint!=string::npos){
            size_t start=mycode.find("<",posprint)+ 1;
            size_t end=mycode.find(">",start);
            string content=mycode.substr(start,end -start);
            output << content << endl;
            cout<<content<<endl;
            }
            if(!output){
            cout<<"can't open this file/ perhaps you haven't created this file yet"<<endl;
            exit(EXIT_FAILURE);
            }

            //main loop close
            }
              opened_file.close();
             }

        //size_t POSprint= opened_file.find("print");
        }
        else {
            cout << "non-existent option " << argument << endl;
        }
    } else {
        cout << "especify an argument" << endl;
    }


    return 0;
}







void create_folders(){
            if(mkdir (folder.assets, 0774)==0){
            cout<<"Assets folder created succesfully!"<<endl;
            }
            else{
            cout<<"Error while creating this file"<<endl;
            }
            if(mkdir (folder.lib, 0774)==0){
            cout<<"Lib folder created succesfully!"<<endl;
            }
            else{
            cout<<"Error while creating this file"<<endl;
            }
            if(mkdir (folder.output, 0774)==0){
            cout<<"Output folder created succesfully!"<<endl;
            }
            else{
            cout<<"Error while creating this file"<<endl;
            }
            if(mkdir (folder.packages, 0774)==0){
            cout<<"packages folder created succesfully!"<<endl;
            }
            else{
            cout<<"Error while creating this file"<<endl;
            }
            if(mkdir (folder.web, 0774)==0){
            cout<<"web folder created succesfully!"<<endl;
            }
            else{
            cout<<"Error while creating this file"<<endl;
            }
}

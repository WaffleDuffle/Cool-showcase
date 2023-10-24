//check OS
#ifdef _WIN32
    #include <Windows.h>
    void foo(){
        Sleep(200);       
        system("cls");    
    }                  
#else __linux__
    #include <unistd.h>
    void foo(){
        usleep(200000);
        system("clear");
    }
#endif

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
 //convert sentence into upper
void big_letters(char *string){
    for(int i = 0 ; i < strlen(string) ; ++i){
        if(string[i] >= 'a' && string[i] <= 'z')
            string[i] -= 32;
    }
}

int main(){
    //escape sequences vector
    std::vector<std::string> colour{"\e[1;30m",
                                    "\e[1;31m",
                                    "\e[1;32m",
                                    "\e[1;33m",
                                    "\e[1;34m",   
                                    "\e[1;35m",
                                    "\e[1;36m",
                                    "\e[1;37m",
                                    "\e[1;90m",    
                                    "\e[1;91m"};
    int random_param;
    char character[256];
    std::cout << "ENTER COOL CHARACTER: ";
    gets(character);
    big_letters(character);
    while(true){
        for(int i = 0 ; i < 20 ; ++i, std::cout << "\n"){
            for(int j = 0 ; j < colour.size() ; ++j){
                random_param = rand()%10; // magic
                std::cout << colour[random_param] << character << ' ';     
            }
        }
        foo(); 
    }
    std::cout << "\e[0m";
    return 0;
}

#include <iostream>
#include <cstring>
#include <cstdio>
#include <sstream>  
#include <fstream>
#include "config.hpp"
#include "colors.hpp"
#include "xors.hpp"
#include <stdlib.h>

int main(int argc, char *argv[]){
  std::ifstream file;
  std::ofstream filew;
  std::string files;
  std::ostringstream out;
  std::cout << green << banner << white;
  for (int i=0; i<argc; i++){
    if (strcmp(argv[i], "-h") == 0)
	    std::cout << help;
	  else if(strcmp(argv[i], "-f")==0){
	    files=argv[i+1];
      file.open(files);
      if (!file.is_open())
        std::cout << red << "Файл не может быть открыт!\n" << white;
      else{
        int yea;
        for (int key=0; key<argc; key++){
          if(strcmp(argv[key], "-k")==0)
            keys=atoi(argv[key+1]);
          else if(strcmp(argv[key], "-e")==0)
            yea = 1;
          else if(strcmp(argv[key], "-d")==0)
            yea = 2;
        }
        out << file.rdbuf();
        std::string mystr=out.str();
        std::string crypted = mystr;
        if(yea==1){
          crypted = crypt(mystr, keys);
          std::cout << green << "Файл успешно зашифрован!\n" << white;
        }else if(yea==2){
          crypted = encrypt(mystr, keys);
          std::cout << green << "Файл успешно расшифрован!\n" << white;
        }
        filew.open(files);
        filew << crypted;
        filew.close();
        file.close();
      }
	  }
	  else if(strcmp(argv[i], "-i")==0)
	    std::cout << info;
  }
}
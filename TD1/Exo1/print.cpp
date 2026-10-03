#include "print.h"


my_class::my_class(int argc, char** argv){
        for (int i=1; i<argc;i++){
        a+=argv[i];
    };
}
my_class::my_class(){
    a="Hello World!";
}
void my_class::print(){
    std::cout << a+"\n";
}


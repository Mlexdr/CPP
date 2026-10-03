#include "print.h"

int main(int argc, char**argv){
    my_class hello;
    hello.print();
    my_class message(argc,argv);
    message.print();
    return 0;
}


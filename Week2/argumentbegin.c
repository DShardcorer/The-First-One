#include <stdio.h>
#include <stdlib.h>

int main(int argc, char argv[]){
    double width, height;
    if(argc!=3){
        printf("Wrong number of arguments.\n");
        printf("CORRECT SYNTAX: RECT <WIDTH> <HEIGHT> \n");
        return 1;
        //return khac 0 ham main =exit but theres a problem with a program
    }
    width = atof(argv[1]);
    height = atof(argv[2]);

    printf("Area: %f\n", width*height);
    printf("Perimeter: %f\n", 2*(width+height));
}
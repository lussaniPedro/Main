#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void HelloWorld(char *str);

int main(){
    HelloWorld("printf");

    return 69;
}

void HelloWorld(char *str){
    if(strcmp(str, "printf") == 0){
        printf("Hello World!\n");
    } else{
        printf("%s", str);
    }
}
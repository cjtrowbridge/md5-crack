#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "md5.h"

void appendFile(char * data, int size, char * fname);

int main()
{
    FILE *s;
    s = fopen("rockyou100.txt", "r");
    if (!s)
    {
        printf("Can't read file");
        exit(1);
    }
    
    char word[255];
    
    while(fscanf(s,"%s ",word) != EOF ){
        
        char* hash = md5(word,strlen(word));
        printf("%s\n",hash);
        
        appendFile(hash , strlen(hash), "output.txt");
        
    }
    
    fclose(s);
}


void appendFile(char * data, int size, char * fname)
{
    FILE *fp = fopen(fname, "a+");
    if (!fp)
    {
        fprintf(stderr, "Can't append to %s\n", fname);
        exit(1);
    }
    
    fwrite(data, 1, size, fp);
    char newline[2] = "\n";
    fwrite(newline, 1, 1, fp);
    fclose(fp);   
}
#include "shellPrograms.h"

/*
Count the number of lines in a file 
*/
int shellCountLine_code(char **args)
{

    /** TASK 6  **/
    // ATTENTION: you need to implement this function from scratch and not to utilize other system program to do this
    // 1. Given char** args, open file in READ mode based on the filename given in args[1] using fopen()
    if (args[1]==NULL){
        printf("CSESHELL PLEASE GIVE ME A FILE NAME PLEASE HELLO\n");
        return 1;
    }
    // 2. Check if file exists by ensuring that the FILE* fp returned by fopen() is not NULL

    FILE *filepointer =fopen(args[1],"r");
    // 3. Read the file line by line by using getline(&buffer, &size, fp)
    // 4. Loop, as long as getline() does not return -1, keeps reading and increment the count
    if (filepointer !=NULL){
        int counter = 0;
        size_t size =32;
        char *buffer =malloc(sizeof(char)*size);
        if (buffer==NULL){
            perror("CSESHELL ERROR");
            return 1;
    }

    while (getline(&buffer, &size,filepointer) != -1){
        counter++;
    }
    // 6. Close the FILE*
    fclose(filepointer);
    free(buffer);
    // 7. Print out how many lines are there in this particular filename
    printf("CSESHELL: THERE ARE %d line(s) in %s\n",counter,args[1]);
    }
    // 8. Return 1, to exit program
    else{
        perror("CSESHELL ERROR");
        return 1;
    }

    return 1;
}

int main(int argc, char **args)
{
    return shellCountLine_code(args);
}
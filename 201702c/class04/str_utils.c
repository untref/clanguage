#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

unsigned isInvalid(int argc, char** argv) {
    return argc < 3;
};

void usage() {
    printf("Help!!!!|\n");
}

void doItForEachCharacter(char* arg, int (*action)(int) ){
    while( *arg ) {
        *arg = (*action)( *arg );
        ++arg;
    };
};

void up(char* arg, char* dst) {
    strcpy(dst, arg);
    doItForEachCharacter(dst, toupper);
}

void down(char* arg, char* dst) {
    strcpy(dst, arg);
    doItForEachCharacter(dst, tolower);
}

void dup(char* arg, char* dst) {
    strcpy(dst, arg);
    strcat(dst, arg);
}

void cap(char* arg, char* dst) {
    strcpy(dst, arg);
    *dst = toupper(*dst);
}

int lookUpCommand(char* command, char** commands, unsigned commandsCount ) {
    char** current = commands;

    while ( commandsCount ) {
        if ( strcmp(command, *current) == 0 ) {
            return current - commands;
        };
        current++;
        commandsCount--;
    }

    return -1;

};

int main(int argc, char** argv) {

    if ( isInvalid(argc, argv) ) {
        usage();
        return 1;
    };

    char* command = *(argv + 1);
    char* argument = *(argv + 2);

    char* commands[] =                  { "cap", "up", "down", "dup"   }; 
    unsigned times[] =                  { 1,     1,    1,      2 }; 
    void (*actions[])(char*, char*) =   { &cap,  &up,  &down  , &dup  };

    int inx = lookUpCommand(
        command,
        commands, 
        sizeof(commands) / sizeof(char*)
    );
    unsigned time = times[inx];

    char* dst = (char*)malloc(  time * strlen(argument) + 1 );

    (*actions[inx])( argument, dst );

    printf("%s( %s ). argument(%s)\n", command, dst, argument);

    free(dst);

    printf("dst: %p\n", dst);
    return 0;
}

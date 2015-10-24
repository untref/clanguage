#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* file;

    file = fopen("./my_file.log", "w+" /* for append / writting */);

    char buffer[] = "file content";
    fprintf(file, "%s\n", buffer);

    // Print to the stdout
    fprintf(stdout, "%s\n", buffer);
    fclose(file);
}

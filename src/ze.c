#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/*Function to list files and directories in the given path */
void listFiles(const char *path) {
    struct dirent *de;  /* Pointer for directory entry */

    /* Open the directory specified by the path */
    DIR *dr = opendir(path);

    char red[]  = "\033[1;31m";
    char blue[] = "\033[1;34m";

    if (dr == NULL) {  /* Check if the directory could be opened */
        printf("%s[ERROR]: Could not open directory %s%s\n", red, path, blue);
        return;
    }

    while ((de = readdir(dr)) != NULL)
        printf("%s\n", de->d_name);

    /* Close the directory */
    closedir(dr);
}

int main(int argc, char *argv[]) {
    int choice;
    char path[256];
    char filename[100];

    char red[]    = "\033[1;31m";
    char green[]  = "\033[1;32m";
    char yellow[] = "\033[1;33m";
    char blue[]   = "\033[1;34m";
    char purple[] = "\033[0;35m";
    char cyan[]   = "\033[1;36m";
    char white[]  = "\033[1;37m";

    while (1) {
        /* Display the menu */
        printf("\n%s===================================\n", blue);
        printf("%s|       %sTHE ZE FILE EXPLORER%s      |\n", blue, yellow, blue);
        printf("%s===================================\n", blue);
        printf("%s| %s1. View files%s                   |\n", blue, green, blue);
        printf("%s| %s2. Change directory%s             |\n", blue, green, blue);
        printf("%s| %s3. Create file%s                  |\n", blue, green, blue);
        printf("%s| %s4. Delete file%s                  |\n", blue, green, blue);
        printf("%s| %s5. Run custom command%s           |\n", blue, green, blue);
        printf("%s| %s6. Exit%s                         |\n", blue, red, blue);
        printf("%s===================================\n", blue);
        printf("%s%%%s ", purple, blue);
        scanf("%d", &choice);
        getchar(); /* To consume the newline character after the choice */

        switch (choice) {
            case 1:
                /* List files and directories in the given path */
                printf("%s>%s ", purple, blue);
                fgets(path, sizeof(path), stdin);
                path[strcspn(path, "\n")] = 0; /* Remove the newline character */
                listFiles(path);
                break;

            case 2:
                /* Change the current working directory */
                printf("%s>%s ", purple, blue);
                fgets(path, sizeof(path), stdin);
                path[strcspn(path, "\n")] = 0; /* Remove the newline character */
                if (chdir(path) != 0) {
                    printf("%s[ERROR]: Could not change directory to %s%s\n", red, path, blue);
                } else {
                    printf("%s[INFO]: Successfully changed directory to %s%s\n", green, path, blue);
                }
                break;

            case 3:
                /* Create a new file */
                printf("%s>%s ", purple, blue);
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; /* Remove the newline character */
                FILE *fp = fopen(filename, "w");
                if (!fp) {
                    printf("%s[ERROR]: Could not create the file %s%s\n", red, filename, blue);
                } else {
                    printf("%s[INFO]: Successfully created file %s%s\n", green, filename, blue);
                }
                break;

            case 4:
                /* Delete an existing file */
                printf("%s>%s ", purple, blue);
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; /* Remove the newline character */
                if (remove(filename) != 0) {
                    printf("%s[ERROR]: File \"%s\" couldn't be deleted%s\n", red, filename, blue);
                } else {
                    printf("%s[INFO]: Successfully removed %s%s\n", green, filename, blue);
                }
                break;

            case 5:
                /* Run a custom command */
                printf("%s>%s ", purple, blue);
                char cmd[256];
                scanf("%s", &cmd);
                system(cmd);
                break;

            case 6:
                /* Exit the program */
                printf("%s[INFO]: Exiting...%s\n", green, blue);
                exit(0);

            default:
                printf("\n%s[ERROR]: Invalid expression%s\n", red, blue);
        }
    }

    return 0;
}

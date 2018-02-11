#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXCHAR 1000

int  CharacOrNot(char c) {
        char list[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 \`~!@#$%^&*()_-+={[}}|\:;\"'<>.?/";
        int i = 0;
        int size;
                size = strlen(list);

                for (i = 0; i < size; i++) {
                    if (list[i] == c) {
                        return 1;
                    }
                }
                return 0;
}

int HowManyLines(char* filename) {
    FILE* fp = fopen(filename, "r");
    int i = 0;
    char str[MAXCHAR];

        while (fgets(str, MAXCHAR, fp) != NULL) {
                i++;
            }
    return i;
    fclose(fp);
}

int main()
{

FILE *fp, *fp1;
    char str[MAXCHAR];
    char * pch;
    char filename[MAXCHAR];
    char filename1[MAXCHAR];

    printf("______________________________________ \n");
    printf("______________________________________ \n");
    printf("______________________________________ \n");
    printf("______________________________________ \n");
    printf("\n");
    printf("___TXT file list to JSON converter!___ \n");
    printf("\n");
    printf("______________________________________ \n");
    printf("______________________________________ \n");
    printf("______________________________________ \n");
    printf("______________________________________ \n");

    printf("Enter the \".TXT\" file Path (full path including file name and extension) :  ");
    scanf("%s", &filename);
    printf("\n");

    printf("Enter the \".JSON\" output file Path (full path including file name and extension) :  ");
    scanf("%s", &filename1);
    printf("\n");


    int Lines = HowManyLines(filename);

    fp = fopen(filename, "r");
    fp1 = fopen(filename1, "w");

    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }

    int i = 0;

    if ( i == 0 ) fprintf(fp1, "{ \n");

    while (fgets(str, MAXCHAR, fp) != NULL) {
            int k, j = 0;

            int size;
            char ch1;
            char str1[666];

                size = strlen(str);

                for (k = 0; k < size; k++) {
                    if (CharacOrNot(str[k]) == 1) {
                        ch1 = str[k];
                        str1[j] = ch1;
                        j++;
                    }
                }
                str1[j] = '\0';

            if (i == Lines - 1) fprintf(fp1, "\"element_%i\": \"%s\" \n", i, str1);
            else fprintf(fp1, "\"element_%i\": \"%s\", \n", i, str1);
        i++;
        }

    fprintf(fp1, "}");
    printf("File converted successfully! :D ");
    printf("\n");
    printf("\n");

    fclose(fp);
    fclose(fp1);
    return 0;
    scanf("%s");
}

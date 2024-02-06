#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define loop(i, a, b) for (int i = a; i < b; i++)

char key[256][256];
char value[256][256];
int numberOfCodes = 0;

void insertMap(char cipher[], char plain[])
{
    strcpy(key[numberOfCodes], cipher);
    strcpy(value[numberOfCodes], plain);
    numberOfCodes++;
}

void initMap()
{
    insertMap(".-", "a");
    insertMap("-...", "b");
    insertMap("-.-.", "c");
    insertMap("-..", "d");
    insertMap(".", "e");
    insertMap("..-.", "f");
    insertMap("--.", "g");
    insertMap("....", "h");
    insertMap("..", "i");
    insertMap(".---", "j");
    insertMap("-.-", "k");
    insertMap(".-..", "l");
    insertMap("--", "m");
    insertMap("-.", "n");
    insertMap("---", "o");
    insertMap(".--.", "p");
    insertMap(".--", "w");
    insertMap(".-.", "r");
    insertMap("...", "s");
    insertMap("-", "t");
    insertMap("..-", "u");
    insertMap("...-", "v");
    insertMap("-..-", "x");
    insertMap("-.--", "y");
    insertMap("--..", "z");
    insertMap(".----", "1");
    insertMap("..---", "2");
    insertMap("...--", "3");
    insertMap("....-", "4");
    insertMap(".....", "5");
    insertMap("-....", "6");
    insertMap("--...", "7");
    insertMap("---..", "8");
    insertMap("----.", "9");
    insertMap("-----", "0");
    insertMap(".-.-.-", ".");
    insertMap("..--..", "?");
    insertMap("-....-", "-");
    insertMap("--..--", ",");
    insertMap("---...", ":");
    insertMap("........", "#");
}

int findByKey(char cipher[])
{
    loop(i, 0, numberOfCodes)
    {
        if (strcmp(cipher, key[i]) == 0)
        {
            return i;
        }
    }
    return -1;
}
int findByValue(char plain[])
{
    loop(i, 0, numberOfCodes)
    {
        if (strcmp(plain, value[i]) == 0)
        {
            return i;
        }
    }
    return -1;
}

void morseToText(char inputFile[], char outputFile[])
{
    FILE *fr = fopen(inputFile, "r");
    FILE *fw = fopen(outputFile, "w");
    char cipher[16];
    char ch = fgetc(fr);
    int cipherLength = 0;
    int line = 1;
    while (ch != EOF)
    {
        if (ch == '/' || ch == ' ' || ch == '\n')
        {
            if (cipherLength == 0)
            {
                if (ch == '/')
                    fprintf(fw, " ");
                if (ch == '\n')
                    fprintf(fw, "\n");

                ch = fgetc(fr);
                continue;
            }
            cipher[cipherLength] = '\0';
            cipherLength = 0;
            int index = findByKey(cipher);
            if (index == -1)
            {
                fprintf(fw, "*");
                printf("Error: Invalid Morse code %s on line %d\n", cipher, line);
            }
            else
                fprintf(fw, "%s", value[index]);
            if (ch == '/')
                fprintf(fw, " ");
            if (ch == '\n')
            {
                fprintf(fw, "\n");
                line++;
            }
        }
        else
        {
            cipher[cipherLength++] = ch;
        }
        ch = fgetc(fr);
    }

    // xu ly ky tu cuoi cung
    if (cipherLength != 0)
    {

        cipher[cipherLength] = '\0';
        cipherLength = 0;
        int index = findByKey(cipher);
        if (index == -1)
        {
            fprintf(fw, "*");
            printf("Error: Invalid Morse code %s on line %d.\n", cipher, line);
        }
        else
            fprintf(fw, "%s", value[index]);
    }

    fclose(fr);
    fclose(fw);
}

void textToMorse(char inputFile[], char outputFile[])
{
    FILE *fr = fopen(inputFile, "r");
    FILE *fw = fopen(outputFile, "w");
    char ch = fgetc(fr);
    char plain[2];
    plain[1] = '\0';
    int line = 1;

    while (ch != EOF)
    {
        if (ch == '\n')
        {
            fprintf(fw, "\n");
            line++;
            ch = fgetc(fr);
        }
        else if (ch == ' ')
        {
            fprintf(fw, "/");
            ch = fgetc(fr);
        }
        else
        {
            plain[0] = ch;
            ch = fgetc(fr);

            int index = findByValue(plain);
            if (index == -1)
            {
                printf("Error: Unrecognised character %s on line %d.\n", plain, line);
            }
            else
            {
                fprintf(fw, "%s", key[index]);
                if (ch != '\n' && ch != ' ' && ch != EOF)
                {
                    fprintf(fw, " ");
                }
            }
        }
    }

    fclose(fr);
    fclose(fw);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Invalid number of arguments\n");
        exit(1);
    }
    char inputFile[1024];
    char outputFile[1024];
    strcpy(inputFile, argv[1]);
    strcpy(outputFile, argv[2]);

    FILE *fr = fopen(inputFile, "r");
    if (fr == NULL)
    {
        printf("Error: %s could not be opened.\n", inputFile);
        exit(1);
    }
    fclose(fr);

    FILE *fw = fopen(outputFile, "r");
    if (fw != NULL)
    {
        printf("Warning: %s already exists. Do you wish to overwrite (y,n)?\n", outputFile);
        char ch;
        fflush(stdin);
        scanf("%c", &ch);
        if (ch == 'n' || ch == 'N')
        {
            fclose(fw);
            exit(1);
        }
        else if (ch != 'y' && ch != 'Y')
        {
            printf("Invalid command\n");
            fclose(fw);
            exit(1);
        }
    }

    initMap();

    int cmd = 0;
    char ch;
    ch = fgetc(fw);
    while (ch != EOF)
    {
        if (ch != '.' && ch != '-' && ch != '/' && ch != ' ')
        {
            cmd = 1;
            break;
        }
        ch = fgetc(fw);
    }
    fclose(fw);

    if (cmd)
    {
        textToMorse(inputFile, outputFile);
    }
    else
    {
        morseToText(inputFile, outputFile);
    }
    return 0;
}

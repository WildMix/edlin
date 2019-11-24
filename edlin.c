#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <file.h>

struct doc {

	char lines[80];

	int n_lines;

	char line[80];

	int pos;

} doc;

int main(void) {

	char path[50];

	char nome[50];

    int var, ex;

    do{

            system("clear");

            printf("Inserire :\n 1 per creare un nuovo file\n 2 per leggere un file esistente\n 3 per uscire\n >> ");
        
            scanf ("%d", &var);
        
            if ( var == 3 )
                break;
        
            switch (var)
            {
        
            case 1 : 
            {       
                     printf("Inserire il percorso dove salvare il file ( ricorda di inserire lo / finale ):\n");

                   	scanf("%s", path);

	                 printf("Inserire il nome del file :\n");

	                 scanf("%s", nome);

	                 strcat(path, nome);
   
                     SaveText(path);

                     system ("clear");

                     printf ("Inserire :\n 1 per uscire\n 2 per tornare indietro\n >> ");

                     scanf ("%d",&var);

                     switch (var)
                      {

                        case 1: return 0;
        
                        case 2 :  break;

                        default : printf("hai inserito una scelta non valida \n");

                      }

                    if (var == 2)
            
                        break; 
        
            }
            case 2 :
            {
                    
                   printf("Inserire il percorso del documento da aprire:\n");
        
        	           scanf("%s", path);
        
        	           LoadText(path);  

                   printf ("Inserire :\n 1 per uscire\n 2 per tornare indietro\n >> ");

                   scanf ("%d",&var);

                   switch (var)
                   {

                     case 1: return 0;
        
                     case 2 :  break;

                     default : printf("hai inserito una scelta non valida \n");

                   } 

                   if (var == 2)
            
                        break;
        
            }

            case 3 :

                   return 0;
        
            default : printf("hai inserito una scelta non valida \n");
          
            }
        
        
      }while (1);
	



	//doc.n_lines = GetNumLines(path);

    return 1;   

/*
 	do {
		printf("che riga vuoi vedere?");

		scanf("%d", &doc.pos);

	} while (doc.pos < 1 && doc.pos > doc.n_lines);

	GetLine(doc.pos, path);

	InsertNewLines(3, path, 3);

*/
}

void SaveText(char *path) {

    
    FILE *fd;

	char *exit = "exit";

	fd = fopen(path, "w");

	if (fd == NULL) {

		perror("errore in apertura");

	} else {

		do {

			fflush(stdout);

			printf(">");

			fflush(stdout);

			getchar();

			scanf("%[^\n]s", doc.lines);

			if (strcmp(doc.lines, exit) == 0)
				break;

			fprintf(fd, "%s\n", doc.lines);

		} while (strcmp(doc.lines, exit) != 0);

	}

	fclose(fd);

}

int GetNumLines(char *path) {

	FILE *fp;

	int count = 0;

	char c;

	fp = fopen(path, "r");

	if (fp == NULL) {

		perror("errore in apertura\n");

		return -1;

	} else {

		for (c = getc(fp); c != EOF; c = getc(fp))

			if (c == '\n')

				count = count + 1;

		return count;

		fclose(fp);

	}

}

void LoadText(char *path) {

	FILE *fd;

	fd = fopen(path, "r");

	if (fd == NULL) {

		perror("errore in apertura\n");

	} else {

		doc.n_lines = GetNumLines(path);

		do {

			fgets(doc.lines, 80, fd);

			if (feof(fd))

				break;

			printf("%s", doc.lines);

		} while (!feof(fd));

	}

	fclose(fd);

}

int GetLine(int pos, char *path) {

	FILE *fp;

	int a;

	fp = fopen(path, "r");

	if (fp == NULL) {

		perror("errore in apertura\n");

	} else {

		for (a = 0; a <= pos - 1; a++) {

			fgets(doc.line, sizeof(doc.line), fp);


		}

		printf("%s", doc.line);

	}

	fclose(fp);

}

void InsertNewLines(int linestart, char *path, int times) {
	FILE *fd;

	char *exit = "exit";

	int linend = linestart + 1;

	int a;

	int i;

	fd = fopen(path, "w");

	if (fd == NULL)
		perror("errore in apertura\n");

	else {
		do {
			for (a = 0; a <= linestart - 1; a++) {

				for (i = 0; i <= times - 1; i++) {

					fflush(stdout);

					printf(">");

					fflush(stdout);

					getchar();

					scanf("%[^\n]s", doc.lines);

					if (strcmp(doc.lines, exit) == 0)
						break;

					fprintf(fd, "%s\n", doc.lines);

				}

			}
		} while (a >= linend);
	}
}


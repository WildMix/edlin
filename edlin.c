
/*
* FILENAME :        edlin.c             
*
* DESCRIPTION :
*       terminal text editor for linux. 
*
* PUBLIC FUNCTIONS :
*       
*	see 'file.h'
*       
*
* NOTES :
*       
*       The program is not yet finished
*	Needs to finish the function 'InsertNewLine' and check the function 'GetNumLines'
*	The function 'InsertNewLine' must be changed: including the skill of insert multiple empty line and write them 
*
*       
* 
* AUTHOR :    Luigi Gesualdo        START DATE :    -
*
* CHANGES :
*
*/


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

            printf("Insert :\n 1 for write a new file\n 2 for read an already created file\n 3 exit\n >> ");
        
            scanf ("%d", &var);
        
            if ( var == 3 )
                break;
        
            switch (var)
            {
        
            case 1 : 
            {       
                     printf("Insert the path of the new file ( remember the final / ):\n");

                   	scanf("%s", path);

	                 printf("Insert the name of the file :\n");

	                 scanf("%s", nome);

	                 strcat(path, nome);
   
                     SaveText(path);

                     system ("clear");

                     printf ("Insert :\n 1 exit\n 2 back\n >> ");

                     scanf ("%d",&var);

                     switch (var)
                      {

                        case 1: return 0;
        
                        case 2 :  break;

                        default : printf("invalid selection \n");

                      }

                    if (var == 2)
            
                        break; 
        
            }
            case 2 :
            {
                    
                   printf("Insert the path of the file:\n");
        
        	           scanf("%s", path);
        
                   printf ("Insert :\n 1 print the number of lines\n 2 print all the file\n 3 back\n 4 exit\n the number of the line to print\n >> ");

                   scanf ("%d",&var);

                   switch (var)
                   {

                       case 1 : printf("the file %s\nhas %d righe\n",path,GetNumLines(path));
					
			if (var == 2)   LoadText(path);
	
                        case 3 : break;

                        case 4 : return 0;
						
			if ( var != 2 )
					
				default : GetLine(var,path);
					
                   }
 
                if ( var == 3 )
    
                    break;
        
            }

            case 3 :

                   return 0;
        
            default : printf("invalid selection \n");
          
            }
        
        
      }while (1);
	




    return 1;   


}

void SaveText(char *path) {		// write line by line from the input terminal, input line = exit save and close the file

    
    FILE *fd;

	char *exit = "exit";

	fd = fopen(path, "w");

	if (fd == NULL) {

		perror("opening error ");

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

int GetNumLines(char *path) {        // count the line of the file on the given path 

	FILE *fp;

	int count = 0;

	char c;

	fp = fopen(path, "r");

	if (fp == NULL) {

		perror("opening error");

		return -1;

	} else {

		for (c = getc(fp); c != EOF; c = getc(fp))

			if (c == '\n')

				count = count + 1;

		return count;

		fclose(fp);

	}

}

void LoadText(char *path) {        // print the file on the given path

	FILE *fd;

	fd = fopen(path, "r");

	if (fd == NULL) {

		perror("opening error\n");

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

int GetLine(int pos, char *path) {     // print the single line 'pos' of the file on the given path

	FILE *fp;

	int a;

	fp = fopen(path, "r");

	if (fp == NULL) {

		perror("opening error\n");

	} else {

		for (a = 0; a <= pos - 1; a++) {

			fgets(doc.line, sizeof(doc.line), fp);


		}

		printf("%s", doc.line);

	}

	fclose(fp);

}

void InsertNewLines(int linestart, char *path, int times) {   // create a number of empty line in mid on two lines and write them
	FILE *fd;

	char *exit = "exit";

	int linend = linestart + 1;

	int a;

	int i;

	fd = fopen(path, "w");

	if (fd == NULL)
		perror("opening error\n");

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


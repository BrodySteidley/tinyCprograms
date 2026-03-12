#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/ioctl.h>

#define SAVEFILE "star.data"
#define MAXNAMESIZE 10
#define MAXNAMECOUNT 10

// basic program for assigning people stars! hooray!

int starfile_hasname(char starfile[], char name[])
{ // if substring is inside string, return it's index. -1 otherwise
    char storename[MAXNAMESIZE];
    for (int i = 0; i < MAXNAMESIZE; ++i)
	storename[i] = 0;

    for (int i = 0; name[i] != '\0' && i < MAXNAMESIZE; ++i)
	storename[i] = name[i];

    for (int i = 0; i < MAXNAMECOUNT; ++i)
    {
	int match = 1;

	for (int j = 0; j < MAXNAMESIZE; ++j)
	    if (starfile[i * MAXNAMESIZE + j] != storename[j])
	    {
		match = 0;
		break;
	    }

	if (match)
	    return i;
    }
    
    return -1;
}


void starfile_load(char starfile[])
{   // load starfile from SAVEFILE
    FILE *file;
    file = fopen(SAVEFILE, "rb");
    
    if (file != NULL)
    {
	int c;
	for (int i = 0; (c = fgetc(file)) != EOF && i < MAXNAMESIZE * MAXNAMECOUNT + MAXNAMECOUNT; ++i)   
	    starfile[i] = c;

	fclose(file);
    }
    else
	for (int i = 0; i < MAXNAMESIZE * MAXNAMECOUNT + MAXNAMECOUNT; ++i)
	    starfile[i] = 0;
}

void starfile_save(char starfile[], char savename[])
{
    FILE *file;
    file = fopen(savename, "wb");
    
    for (int i = 0 ; i < MAXNAMESIZE * MAXNAMECOUNT + MAXNAMECOUNT; ++i)
	fputc(starfile[i] , file);

    fclose(file);
}

void starfile_displaystars(char starfile[], int index)
{   // display one guy's stars
    if (index >= 0 && index < MAXNAMECOUNT)
    {
	for (int i = 0; i < MAXNAMESIZE; ++i)
	    putchar(starfile[MAXNAMESIZE * index + i]);
	putchar('\n');

	for (int i = 0; i < starfile[MAXNAMESIZE * MAXNAMECOUNT + index]; ++i)
	    printf("    /\\   ");
	
	putchar('\n');
	
	for (int i = 0; i < starfile[MAXNAMESIZE * MAXNAMECOUNT + index]; ++i)
	    printf(" __/  \\__");

	putchar('\n');
	
	for (int i = 0; i < starfile[MAXNAMESIZE * MAXNAMECOUNT + index]; ++i)
	    printf(" \\      /");
	
	putchar('\n');
	
	for (int i = 0; i < starfile[MAXNAMESIZE * MAXNAMECOUNT + index]; ++i)
	    printf("  \\    / ");
	
	putchar('\n');
	
	for (int i = 0; i < starfile[MAXNAMESIZE * MAXNAMECOUNT + index]; ++i)
	    printf("  /    \\ ");
	
	putchar('\n');
	
	for (int i = 0; i < starfile[MAXNAMESIZE * MAXNAMECOUNT + index]; ++i)
	    printf(" /__/\\__\\");
	
	putchar('\n');
	putchar('\n');
    }

    /*	        /\   
	     __/  \__
	     \      /
	      \    / 
	      /    \ 
	     /__/\__\
    */
}

void starfile_print(char starfile[])
{
    for (int i = 0; i < MAXNAMECOUNT; ++i)
    {
	if (starfile[i * MAXNAMESIZE] != 0)
	    starfile_displaystars(starfile, i);
    }
}

void starfile_storename(char starfile[], char name[])
{
    char storename[MAXNAMESIZE];
    for (int i = 0; i < MAXNAMESIZE; ++i)
	storename[i] = 0;

    for (int i = 0; name[i] != '\0' && i < MAXNAMESIZE; ++i)
	storename[i] = name[i];

    for (int i = 0; i < MAXNAMECOUNT; ++i)
	if (starfile[i * MAXNAMESIZE] == '\0') /* name slot is empty */
	{
	    for (int j = 0; j < MAXNAMESIZE; ++j)
		starfile[i * MAXNAMESIZE + j] = storename[j];
	    return;
	}

    /* if the name storage is full, it just won't get stored. */
}

void starfile_increase(char starfile[], char name[])
{
    if (starfile_hasname(starfile, name) == -1)
	starfile_storename(starfile, name);
    else
	++starfile[MAXNAMECOUNT * MAXNAMESIZE + starfile_hasname(starfile, name)];
}

void starfile_decrease(char starfile[], char name[])
{
    int nameindex = starfile_hasname(starfile, name);
    if (nameindex != -1)
    {
	if (starfile[MAXNAMECOUNT * MAXNAMESIZE + nameindex] == 0)
	    for (int i = 0; i < MAXNAMESIZE; ++i)
		starfile[nameindex + i] = 0;
	else
	    --starfile[MAXNAMECOUNT * MAXNAMESIZE + nameindex];
    }
}

void starfile_clear(char starfile[])
{
    for (int i = 0; i < MAXNAMESIZE * MAXNAMECOUNT + MAXNAMECOUNT; ++i)
	starfile[i] = 0;
}

int strmatch(char string1[], char string2[])
{   // didn't want to import strcmp
    for (int i = 0; string1[i] != '\0' || string2[i] != '\0'; ++i)
	if (string1[i] != string2[i])
	    return 0;
    return 1;
}

void printHelp(void)
{
	printf("Options:\n\t+<name>: If the name does not exist, add the name to the board.\n\t         If the name exists, add a star to <name>"
			"\n\t-<name>: Remove a star from <name>.\n\t         If the name does not have any stars, removes the name from the board."
			"\n<existing name>: Print only the stars belonging to the given name."
			"\n\t  clear: Clear all names and stars from the board.\n export <fname>: Copy the stars file to a file at <fname>\n\t   help: show this dialog\n");
}

int main(int argc, char** argv)
{

    char starfile[MAXNAMESIZE * MAXNAMECOUNT + MAXNAMECOUNT];
    starfile_load(starfile);
   
    int notall = 0;

    if (argc >= 2)
	for (int i = 1; i < argc; ++i)
	{
	    if (argv[i][0] == '+')
		starfile_increase(starfile, argv[i] + 1);
	    else if (argv[i][0] == '-')
		starfile_decrease(starfile, argv[i] + 1);
	    else if (strmatch(argv[i], "clear"))
		starfile_clear(starfile);
	    else if (strmatch(argv[i], "export"))
	    {
		if (i + 1 < argc)
		    starfile_save(starfile, argv[i + 1]);
		else
		    printf("Export expects second argument.\n");
		return 0;
	    }
	    else if (strmatch(argv[i], "help"))
	    {
	        printHelp();
		return 0;
	    }
	    else
	    {
		starfile_displaystars(starfile, starfile_hasname(starfile, argv[i]));
		notall = 1;
	    }
	}
    else
    {
        char empty = 1;
        for (int i = 0; i < MAXNAMECOUNT; ++i)
	    if (starfile[i * MAXNAMESIZE] != '\0')
		empty = 0;

        if (empty)
	{
	    printHelp();
            return 0; 
	}
    }
    
    starfile_save(starfile, SAVEFILE);

    if (notall)
	return 0;

    starfile_print(starfile);
    
    /*
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    printf ("lines %d\n", w.ws_row);
    printf ("columns %d\n", w.ws_col);
    */
    

    return 0;
}

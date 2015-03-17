#include "motion.h"
#include "motion.c"
#include "print_field.c"
#include <stdlib.h>
#include <stdio.h>

int  main()
{
	for (int i = 0; i < SAMPLES; ++i) // run the loop for all the SAMPLES
	{
		
initfield();// set everything in field to 0
fscanf(infile, "%3d%3d%3d%3d\n",&nodeid, &row, &column, &direction);// scan for initial
motion (nodeid,row, column, direction);// call motion on each SAMPLE  
printfield();}// print end field result

	return 0;
}
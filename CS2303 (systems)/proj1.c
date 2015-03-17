#include <stdio.h>
#include <math.h>

// function that takes in a double and returns log base 2 of the inputed double
double myLog(double x){
   double logresult= log(x)/log(2);
   printf(" The log base 2 of the average Euclidian distance is %lf\n",logresult);
    return logresult;

}

//function takes in the two sets of coordinates and calculates the Euclidian distance between them
double myDistance(int x1, int x2, int y1,int y2){
double disresult;
disresult= sqrt(pow((x1-x2),2) + pow((y1-y2),2));
printf("The distance in this set is %lf\n",disresult);
return disresult;
}

/*function takes in a double, rounds it up to the nearest integer and prints out
a horizontal bar graph of =, equal to the rounded integer*/
void bar(double l2){
int r;
int i;
printf("\n Creating a horizontal bar graph to represent the above. \n");
r=ceil(l2);
 printf("| \n");
 printf("| \n");

for (i = 0; i < r; i++){ // creates a line of =, length equal to the value of r
	printf("=");
}
printf("\n");
printf("____________________________________ \n");
printf("0    5    10    15    20    25 \n");
}

/*takes in coordinate pairs then relays them to the distance function, gets the 
average distance and relays them to myLog function and creates a graph of the 
rounded integer value  */

int main(){
	int pairs;
	double accum,average;
	int i;
	accum=0;
	pairs=0;
	printf("How many sets of coordinate pairs do you have ?\n");
	while(pairs<1){
	printf("(please enter a value greater than 1)\n");	
	scanf("%d",&pairs);}
	for(i=0;pairs>i;i++){ // asks for the sets of coordinate pairs and accumalates distance value
		int x1,x2,y1,y2;
		printf("\n Set %d \n",i+1);
		printf("\n Type in the coordinate pairs \n");
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		
	
        accum= accum + myDistance(x1,x2,y1,y2);
 	}
	// prints out accumalted value divided pairs to display average
	printf("\nThe average distance for these sets is %lf \n", accum/pairs); 
	//creating bar graph
	bar(myLog(accum/pairs));
	return 0;
}
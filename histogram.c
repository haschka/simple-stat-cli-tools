#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<float.h>
#include<string.h>

int main(int argc, char** argv) {

  size_t i;
  
  int counter;

  double *values = (double*)malloc(sizeof(double)*10000);
  int n_bins;

  long* bins;
  
  double min = DBL_MAX;
  double max = -1*DBL_MAX;

  double delta;
  
  double current_value;

  if(values == NULL) {
    fprintf(stderr,"Fatal: Memory allocation failed!\n");
    return(1);
  }
  
  if(argc < 2) {
    printf("Histogram Tool:\n"
	   "Requires at least 1 argument and data on stdin\n\n"
	   " argument: number of bins\n\n"
	   " data on stdin: ascii representation of floating point numbers\n"
	   "                to build a histogram from\n\n"
	   " example usage: echo \"1. 2. 5. 8. 5.\" | %s 3\n"
	   "        yields: 1.000000 3.333333 2\n"
	   "                3.333333 5.666667 2\n"
	   "                5.666667 8.000000 1\n\n"
	   " Finding that there are on: \n"
           "    3 (argument) equally spaced intervals\n"
	   "    between 1.(lowest  value)\n" 
	   "        and 8.(highest value):\n"
	   " 2 numbers between 1     and 3 1/3 \n"
	   " 2 numbers between 3 1/3 and 5 2/3 \n"
	   " and \n"
	   " 1 number  between 5 2/3 and 8     \n", argv[0]);
    return(1);
  }	   

  sscanf(argv[1],"%i",&n_bins);
  bins = (long*)malloc(sizeof(long)*(n_bins+1));

  if(bins == NULL) {
    fprintf(stderr,"Fatal: Memory allocation failed!\n");
    return(1);
  }
  
  counter = 0;
  while(1 == scanf("%lf",values+counter)) {

    current_value = values[counter];
    
    if (current_value < min) min = current_value;
    if (current_value > max) max = current_value;

    /*
    if (isinf(current_value)) {
      printf("Current value %lu %lu is not finite\n", x,y);
    }
    */
  
    counter++;
    
    if(counter % 10000 == 0) {
      values = (double*)realloc(values, sizeof(double)*(counter+10000));
      if(values == NULL) {
	fprintf(stderr,"Fatal: Memory allocation failed!\n");
	return(1);
      }
    }
  }

  delta = (max - min)/(double)n_bins;

  memset(bins,0,sizeof(long)*(n_bins+1));
  
  for(i = 0; i < counter;i++) {
    bins[(int)((values[i]-min)/delta)]++;
  }
  
  /* handle edge case */
  bins[n_bins-1] += bins[n_bins];
  
  for(i = 0; i < n_bins; i++) {
    printf( "%lf %lf %li\n", min+i*delta, min+(i+1)*delta, bins[i]);
  }
  
  free(values);
  free(bins);
  return(0);
}

  
	

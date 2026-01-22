#include<stdio.h>
#include<stdlib.h>
#include<math.h>

static inline int comp(const void* a, const void* b) {

  double* dap = (double*)a;
  double* dbp = (double*)b;

  if(dap[0] <  dbp[0]) return(-1);
  if(dap[0] == dbp[0]) return( 0);
  if(dap[0] >  dbp[0]) return( 1);
}

static inline void print_value(double value) {
  printf("%12.6E\n",value);
}

int main(int argc, char** argv) {

  size_t counter;

  double percentile;
  double seeked;
  double *values = (double*)malloc(sizeof(double)*10000);

  double counter_d;
  double index_d, interpolator;
  
  size_t index, index_plus;

  if (argc != 2) {
    fprintf(stderr,
	    "Usage: i.e. echo \"1. 22. 45. 33.\" | %s 55 \n"
	    " calculates the 55th percentile of the values yielded\n",argv[0]);
    return 1;
  }
  
  if (values == NULL) {
    fprintf(stderr,"Fatal: Memory allocation failed!\n");
    return(1);
  }

  /* sanity checks */
  
  if(1 == sscanf(argv[1],"%lf", &seeked)) {
    if (seeked > 100.) {
      fprintf(stderr,"FATAL: Percentile seek larger than 100!\n");
      return(1);
    }
    if (seeked < 0.) {
      fprintf(stderr,"FATAL: Percentil seek smaller than 100!\n");
      return(1);
    }
  } else {
    fprintf(stderr,"FATAL: Could not parse percentile seek!\n");
    return(1);
  }
     
  counter = 0;
  while(1 == scanf("%lf",values+counter)) {

    counter++;
    if(counter % 10000 == 0) {
      values = (double*)realloc(values, sizeof(double)*(counter+10000));
      if(values == NULL) {
	fprintf(stderr,"Fatal: Memory allocation failed!\n");
	return(1);
      }
    }
  }

  counter_d = (double)(counter);
  
  if (counter) {

    if (counter == 1) {
      print_value(values[0]);
      free(values);
      return(0);
      
    } else {

      qsort(values,counter,sizeof(double),comp);

      index_d = 1.+(counter_d-1.0)*(seeked/100.);
      index = (size_t)index_d;

      /* Handle edge case where someone types 99.999999999999999999999 */
      if (index >= counter) {
	index = counter - 1;
      }
      
      interpolator = index_d - floor(index_d);
      
      if(seeked == 100.) {
	percentile = values[counter-1];
	free(values);
      } else if (seeked == 0.) {
	percentile = values[0];	  
      } else {
	percentile =
	  values[index-1]
	  +interpolator*(values[index] - values[index-1]);
	free(values);
      }
      print_value(percentile);
      return(0);
    }
    
  } else {
    free(values);
    fprintf(stderr,
	    "No values recorded from stdin to calculate percentile from\n");
    return(1);
  }
}

    

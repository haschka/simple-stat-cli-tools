#include<stdio.h>
#include<stdlib.h>

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

  double median;
  double *values = (double*)malloc(sizeof(double)*10000);

  if (values == NULL) {
    fprintf(stderr,"Fatal: Memory allocation failed!\n");
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

  if (counter) {

    if (counter == 1) {
      print_value(values[0]);
      free(values);
      return(0);
      
    } else {
    
      qsort(values,counter,sizeof(double),comp);
    
      if(counter%2 == 1) {
	median = values[counter/2];
	free(values);
      } else {
	median = 0.5*(values[counter/2-1] + values[counter/2]);
	free(values);
      }
      print_value(median);
      return(0);
    }
    
  } else {
    free(values);
    fprintf(stderr,"No values recorded from stdin to calculate median from\n");
    return(1);
  }
}

    

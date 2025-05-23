#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char** argv) {

  size_t i;
  
  int counter;

  double *values = (double*)malloc(sizeof(double)*10000);
  
  double current_value;

  double mean,stddev,sum,y,c,t;

  sum = c = 0;
  counter = 0;
  while(1 == scanf("%lf",values+counter)) {

    current_value = values[counter];
    
    y = current_value-c;
    t = sum + y;
    c = (t - sum) - y;
    sum = t;

    counter++;
    
    if(counter % 10000 == 0) {
      values = (double*)realloc(values, sizeof(double)*(counter+10000));
    }
  }

  mean = sum/(double)counter;
  
  sum = c = 0;
  for(i=0; i<counter;i++) {

    current_value = values[i] - mean;
    current_value *= current_value;
    
    y = current_value-c;
    t = sum + y;
    c = (t - sum) - y;
    sum = t;
  }

  stddev = sqrt(sum/(double)counter);

  printf("%lf\n", stddev);
  
  free(values);
  
  return(0);
}

  
	

#include<stdio.h>

int main(int argc, char** argv) {

  size_t i;
  
  long counter;

  double current_value;
  double sum, c, y,t;
  
  counter = 0;
  sum = c = 0.;
  while(1 == scanf("%lf",&current_value)) {
    y = current_value-c;
    t = sum + y;
    c = (t - sum) - y;
    sum = t;

    counter++;
  }
  printf("%lf\n", sum/(double)counter);
    
  return(0);
}

  
	

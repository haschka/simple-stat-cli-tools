#include<stdio.h>

int main(int argc, char** argv) {

  double current_value;
  double max;
  
  if(1==scanf("%lf",&current_value)) {

    max = current_value;

    while(1==scanf("%lf",&current_value)) {

      if(current_value > max) max = current_value;

    }
    printf("%12.6E\n",max);
    return(0);
  } else {
    fprintf(stderr,"No values to find maximum from recorded on stdin!\n");
    return(1);
  }
} 

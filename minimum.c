#include<stdio.h>

int main(int argc, char** argv) {

  double current_value;
  double min;
  
  if(1==scanf("%lf",&current_value)) {

    min = current_value;

    while(1==scanf("%lf",&current_value)) {

      if(current_value < min) min = current_value;

    }
    printf("%12.6E\n",min);
    return(0);
  } else {
    fprintf(stderr,"No values to find minimum from recorded on stdin!\n");
    return(1);
  }
} 

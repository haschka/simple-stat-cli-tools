#include<stdio.h>
#include<stdlib.h>

static inline double calculate_sum(double* array, size_t size) {

  size_t i;
  double y, t, sum,c;

  sum = c = 0;
  for(i=0;i<size;i++) {
    y = array[i]-c;
    t = sum + y;
    c = (t - sum) - y;
    sum = t;
  }
  
  return(sum);
  
}

int main(int argc, char** argv) {

  size_t i;

  size_t counter;
  double counter_d;
  
  double* values_x = (double*)malloc(sizeof(double)*10000);
  double* values_y = (double*)malloc(sizeof(double)*10000);

  double mean_x, mean_y, xx, xy, yy, current_x, current_y;
  double Y_xx, T_xx, C_xx, Y_xy, T_xy, C_xy, Y_yy, T_yy, C_yy;

  double a, b, RR, E, current_E;
  double Y_E, T_E, C_E;

  int scan_test;

  if(argc > 1) {
    printf("Tool that Calculates the 2D Linear Regression:\n"
	   "Requires data on stdin\n\n"
	   " data on stdin: ascii representation of pairs\n"
	   " of floating point numbers to build the regression\n\n"
	   " example usage: echo \"1. 0.5 2. 0.9 3. 1.2\" | %s\n"
	   " calculates the Linear Regression for the points:\n"
	   "   [1. 0.5], [2. 0.9] and [3. 1.2].\n",argv[0]);
    return(1);
  }	 
  
  if (values_x == NULL || values_y == NULL) {
    fprintf(stderr,"Fatal: Memory allocation failed!\n");
    return(1);
  }

  counter = 0;
  while(2 == (scan_test = scanf("%lf %lf",values_x+counter, values_y+counter))){

    counter++;

    if(counter % 10000 == 0) {
      values_x = (double*)realloc(values_x, sizeof(double)*(counter+10000));
      values_y = (double*)realloc(values_y, sizeof(double)*(counter+10000));
      if(values_x == NULL || values_y == NULL) {
	fprintf(stderr,"Fatal: Memory allocation failed!\n");
	return(1);
      }
    }
  }

  if(counter < 2) {
    fprintf(stderr,"FATAL: Insufficient Data! \n");
    return(1);
  }

  if(scan_test == 1) {
    fprintf(stderr,"FATAL: Input non pair! \n");
    return(1);
  }

  counter_d = (double)counter;
  
  mean_x = calculate_sum(values_x,counter);
  mean_y = calculate_sum(values_y,counter);

  mean_x /= counter_d;
  mean_y /= counter_d;

  xx = yy = xy = 0;
  C_xx = C_yy = C_xy = 0;

  for(i=0;i<counter;i++) {
    current_x = values_x[i] - mean_x;
    current_y = values_y[i] - mean_y;

    Y_xx = current_x*current_x - C_xx;
    T_xx = xx + Y_xx;
    C_xx = (T_xx - xx) - Y_xx;
    xx = T_xx;

    Y_xy = current_x*current_y - C_xy;
    T_xy = xy + Y_xy;
    C_xy = (T_xy - xy) - Y_xy;
    xy = T_xy;

    Y_yy = current_y*current_y - C_yy;
    T_yy = yy + Y_yy;
    C_yy = (T_yy - yy) - Y_yy;
    yy = T_yy;
  }

  if (xx == 0.0) {
    fprintf(stderr, "FATAL: all x values identical\n");
    return 1;
  }

  if (yy == 0.0) {
    fprintf(stderr, "FATAL: zero variance in y\n");
    return 1;
  }
  
  b = xy/xx;

  a = mean_y - b*mean_x;

  E = 0;
  C_E = 0;
  
  for(i=0;i<counter;i++) {
    current_E = values_y[i] - (values_x[i]*b+a);
    Y_E = current_E*current_E - C_E;
    T_E = E + Y_E;
    C_E = (T_E - E) - Y_E;
    E = T_E;
  }

  free(values_x);
  free(values_y);
  
  RR = 1 - E/yy;

  printf("  y = %lfx+%lf\n", b, a);
  printf("R^2 = %lf\n", RR);

  return(0);
}
    
      
      
      
  
  

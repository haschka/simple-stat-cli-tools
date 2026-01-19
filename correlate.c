#include<math.h>
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
  
  double* values_a = (double*)malloc(sizeof(double)*10000);
  double* values_b = (double*)malloc(sizeof(double)*10000);

  double mean_a, mean_b, aa, bb, ab, current_a, current_b;
  double y_aa, t_aa, c_aa, y_bb, t_bb, c_bb, y_ab, t_ab, c_ab;
  double result;
  int scan_test;
  
  if (values_a == NULL || values_b == NULL) {
    fprintf(stderr,"Fatal: Memory allocation failed!\n");
    return(1);
  }

  if(argc > 1) {
    printf("Tool that Calculates the Pearson Correlation:\n"
	   "Requires data on stdin\n\n"
	   " data on stdin: ascii representation of pairs\n"
	   " of floating point numbers to correlate\n\n"
	   " example usage: echo \"1. 2. 5. 8. 6. 1.\" | %s\n"
	   " calculates the Pearson Correlation between vectors:\n"
	   "   [1. 5. 6.] and [2. 8. 1.]\n",argv[0]);
    return(1);
  }	   

  counter = 0;
  while(2 == (scan_test = scanf("%lf %lf",values_a+counter, values_b+counter))){

    counter++;

    if(counter % 10000 == 0) {
      values_a = (double*)realloc(values_a, sizeof(double)*(counter+10000));
      values_b = (double*)realloc(values_b, sizeof(double)*(counter+10000));
      if(values_a == NULL || values_b == NULL) {
	fprintf(stderr,"Fatal: Memory allocation failed!\n");
	return(1);
      }
    }
  }

  if(scan_test == 1) {
    fprintf(stderr,"FATAL: Input non pair! \n");
    return(1);
  }

  if(counter < 2) {
    fprintf(stderr,"FATAL: Insufficient Data! \n");
    return(1);
  }
  
  mean_a = calculate_sum(values_a,counter);
  mean_b = calculate_sum(values_b,counter);

  counter_d = (double)counter;
  
  mean_a /= counter_d;
  mean_b /= counter_d;
  
  aa = bb = ab = 0;
  c_aa = c_bb = c_ab = 0;

  for(i=0;i<counter;i++) {
    current_a = values_a[i]-mean_a;
    current_b = values_b[i]-mean_b;
    
    y_aa = current_a*current_a-c_aa;
    t_aa = aa + y_aa;
    c_aa = (t_aa - aa) - y_aa;
    aa = t_aa;

    y_ab = current_a*current_b-c_ab;
    t_ab = ab + y_ab;
    c_ab = (t_ab - ab) - y_ab;
    ab = t_ab;

    y_bb = current_b*current_b-c_bb;
    t_bb = bb + y_bb;
    c_bb = (t_bb - bb) - y_bb;
    bb = t_bb;     
  }
  
  free(values_a);
  free(values_b);
 
  if (aa == 0.0 || bb == 0.0) {
    fprintf(stderr, "FATAL: One of your data vectors is constant \n");
    return(1);
  }
  
  result = ab/(sqrt(aa)*sqrt(bb));

  printf("%lf\n",result);

  return(0);
}
    

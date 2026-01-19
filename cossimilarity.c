#include<math.h>
#include<stdio.h>
#include<stdlib.h>
	     
int main(int argc, char** argv) {

  size_t i;
  
  double mean_a, mean_b, aa, bb, ab, current_a, current_b;
  double y_aa, t_aa, c_aa, y_bb, t_bb, c_bb, y_ab, t_ab, c_ab;
  double result;
  int scan_test;
  
  if(argc > 1) {
    printf("Tool that Calculates the Cosine Similarity:\n"
	   "Requires data on stdin\n\n"
	   " data on stdin: ascii representation of pairs\n"
	   " of floating point numbers.\n\n"
	   " example usage: echo \"1. 2. 5. 8. 6. 1.\" | %s\n"
	   " calculates the Cosine Similarity between vectors:\n"
	   "   [1. 5. 6.] and [2. 8. 1.]\n",argv[0]);
    return(1);
  }	   

  aa = bb = ab = 0.0;
  c_aa = c_bb = c_ab = 0.0;
  while(2 == (scan_test = scanf("%lf %lf",&current_a, &current_b))){

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

  if(scan_test == 1) {
    fprintf(stderr,"FATAL: Input non pair! \n");
    return(1);
  }

  if (aa == 0.0 || bb == 0.0) {
    fprintf(stderr, "FATAL: Zero-length vector\n");
    return 1;
  }
    
  result = ab/(sqrt(aa)*sqrt(bb));

  printf("%lf\n",result);

  return(0);
}
    

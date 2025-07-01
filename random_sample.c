#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv) {

  size_t i,j;
  
  char** buffer = (char**)malloc(sizeof(char*)*1000);
  size_t n_items = 0;

  size_t* extracted_items;
  
  unsigned int seed;
  size_t items_to_extract;
  int random_value_i, random_in_range_i;
  double random_value_d, random_maximum, random_normalized, random_in_range_d;

  if(argc < 3) {
    printf("%s extracts random sample of items acquired from stdin. \n"
	   "  Usage: \n"
	   "  %s [seed] [number_of_items_to_extract] \n"
	   "  Example: \n"
	   "  echo \"1 2 3 4 5\" | %s 42 2 \n"
	   "  yields 2 items from the given ones 1 2 3 4 5\n"
	   "  items are separted strings.\n",argv[0],argv[0],argv[0]);
    return(1);
  }
  
  sscanf(argv[1],"%u",&seed);
  sscanf(argv[2],"%lu",&items_to_extract);
  
  while(1 == fscanf(stdin,"%ms",buffer+n_items)) {
    n_items++;
    if(n_items%1000 == 0) {
      buffer = (char**)realloc(buffer,sizeof(char*)*(n_items+1000));
    }
  }
  
  srand(seed);

  extracted_items = (size_t*)malloc(sizeof(size_t)*items_to_extract);
  
  for(i=0;i<items_to_extract;i++) {

  failed:
    random_value_i = rand();
    random_value_d = (double)random_value_i;
    random_maximum = (double)RAND_MAX;
    random_normalized = random_value_i/random_maximum;
    random_in_range_d = random_normalized*(double)n_items;
    random_in_range_i = (int)random_in_range_d;
    if(random_in_range_i == n_items) random_in_range_i--;
    for(j=0;j<i;j++) {
      if(random_in_range_i == extracted_items[j]) goto failed;
    }
    extracted_items[i] = random_in_range_i;
    printf("%s\n",buffer[random_in_range_i]);
  }
  for(i=0;i<n_items;i++) {
    free(buffer[i]);
  }
  free(buffer);
  return(0);
}
    

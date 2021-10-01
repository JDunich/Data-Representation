#include<stdio.h>
#include<stdlib.h>


unsigned long bitAt(unsigned long num, int bit){
  return(num>>bit & 1);
}

void CreateBinary(unsigned long num, int bit){
  for(int i = bit-1; i>=0; i--){
    unsigned long v = bitAt(num, i);
    printf("%lu", v);
  }
  printf("\n");
}

int main(int argc, char* argv[argc+1]){

  FILE* fp = fopen(argv[1], "r");

  unsigned long num;
  int bit;


  while(fscanf(fp, "%lu %d\n", &num, &bit)!=EOF){
    CreateBinary(num, bit);
  }


  fclose(fp);
  return EXIT_SUCCESS;
}

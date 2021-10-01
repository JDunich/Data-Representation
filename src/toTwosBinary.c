#include<stdio.h>
#include<stdlib.h>
#include<math.h>

unsigned long bitAt(unsigned long num, int bit){
  return((num>>bit & 1)^1);
}

unsigned long bitAt2(unsigned long num, int bit){
  return(num>>bit & 1);
}

void CreateBinaryPos(unsigned long num, int bit){
  for(int i = bit-2; i>=0; i--){
    unsigned long v = bitAt2(num, i);
    printf("%ld", v);
  }
}

void CreateBinaryNeg(unsigned long num, int bit){
  for(int i = bit-2; i>0; i--){
    unsigned long v = bitAt(num, i);
    printf("%ld", v);
  }
  printf("\n");
}

long power(int bit){
  long num = 1;
  for(int i = 0; i<(bit-1); i++){
    if(i == 0){
      num = 2;
    }else{
      num = 2*num;
    }
  }
  return(num);
}

int main(int argc, char* argv[argc+1]){

  FILE* fp = fopen(argv[1], "r");

  unsigned long origNum;
  int bit;

  while(fscanf(fp, "%ld %d\n", &origNum, &bit)!=EOF){
    int sign = 0;
    long num = origNum;
    if(num<0){
      sign = 1;
    }
    if(sign == 1){
      printf("%d", 1);
    }else{
      printf("%d", 0);
    }
    if(pow(2,bit-1)<=abs(origNum)){
      if(sign == 1){
	for(int i = bit-1; i>0; i--){
	  printf("%d", 0);
	}
      }else{
	for(int i = bit-1; i>0; i--){
	  printf("%d", 1);
	}
      }
      bit = 1;
    }


    if(bit != 1){
      CreateBinaryPos(origNum, bit);
    }
    printf("\n");

  }

  fclose(fp);
  return EXIT_SUCCESS;
}

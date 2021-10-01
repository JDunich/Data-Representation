#include<stdio.h>
#include<stdlib.h>
#include<math.h>

long bitAt(long num, int bit){
  return(num>>bit & 1);
}

long decimal(long num, int beg, int end){
  long count = 0;
  for(int i = beg; i>=end; i--){
    if(bitAt(num, i) == 1){
      count = count + pow(2, i-end);
    }
  }
  return count;
}

double printNumber(long num, int frac, int shift, char de){
  double count = 0;
  int decimal;
  if(shift<=0){
    decimal = shift-1;
  }else{
    decimal = -1;
  }
  if(de != 'd'){
    count = pow(2, shift);
  }else{
    decimal++;
  }
  for(int i = frac; i>=0; i--){
    if(i<=(frac-shift)){
      if(bitAt(num, i) == 1){
	count = count + pow(2, decimal);
      }
      decimal--;
    }else{
      if(bitAt(num, i) == 1){
	count = count + pow(2,(i-(frac-shift))-1);
      }
    }
  }
  return count;
}




int over(int exp, long num, int beg, int end){
  long number = decimal(num, beg, end);
  int bias = (pow(2,exp)/2)-1;
  int shift = number-bias;
  return shift;
}

int main(int argc, char* argv[argc+1]){

  FILE* fp = fopen(argv[1], "r");

  int bit;
  int exp;
  int frac;
  long hex;
  int length;

  while(fscanf(fp, "%d %d %d %lx %d\n", &bit, &exp, &frac, &hex, &length)!=EOF){
    int shift = 0;
    double num = 0;
    int shft = 0;
    char de = 0;
    if(bitAt(hex, bit-1) == 1){
      shft = 1;
    }
    shift = over(exp, hex, bit-2, frac);
    if(shift == -((pow(2,exp)/2)-1)){
      de = 'd';
    }
    num = printNumber(hex, (frac-1), shift, de);
    if(shft == 1){
      num = num*-1;
    }
    printf("%.*f\n", length, num);
  }

  fclose(fp);
  return EXIT_SUCCESS;
}
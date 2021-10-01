#include<stdio.h>
#include<stdlib.h>

signed long power(int);
signed long bitAt(signed long, int);
long CreateBinary(signed long, int);

signed long bitAt(signed long num, int bit){
  return(num>>bit & 1);
}

long v;
long CreateBinary(signed long num, int bit){
  int i = bit;
  if(bit < 0){
    return 0;
  }else{
    if(bitAt(num, i) == 1){
      v = power(i) + CreateBinary(num, i-1);
    }else{
      CreateBinary(num, i-1);
    }
  }
  return v;
}

long power(int v){
  long num = 1;
  for(int i = 0; i<v; i++){
    if(i == 0){
      num = 2;
    }else{
      num = 2*num;
    }
  }
  return num;
}

int main(int argc, char* argv[argc+1]){

  FILE* fp = fopen(argv[1], "r");

  long origNum;
  int bit;
  char char1;
  char char2;

  while(fscanf(fp, "%ld %d %c %c\n", &origNum, &bit, &char1, &char2)!=EOF){
    long sign = 0;
    if(char2 == 'u'){
      sign = CreateBinary(origNum, bit-1);
      v = 0;
    }else{
      if(power(bit-1)>origNum){
        sign = origNum;
      }else{
	origNum = ~origNum + 1;
	sign = CreateBinary(origNum, bit-1);
	v = 0;
	sign = -1*sign;
      }
    }
    printf("%ld\n", sign);
  }

  fclose(fp);
  return EXIT_SUCCESS;
}
  
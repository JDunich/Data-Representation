#include<stdio.h>
#include<stdlib.h>
#include<math.h>

long bitAt(long num, int bit){
  return(num>>bit & 1);
}

void CreateBinary(long num, int bit, int v){
  for(int i = bit; i>v; i--){
    printf("%lu", bitAt(num,i));
  }

}

long Rnd(long num, int bit){
  long g = bitAt(num, bit-1);
  long r = bitAt(num, bit-2);
  long s = bitAt(num, bit-3);
  if(g == 0){
    return num;
  }else if(r == 0 && s == 0){
    if(bitAt(num, bit) == 1){
      num = num+pow(2,bit);
      return num;
    }else{
      return num;
    }
  }else{
    num = num+pow(2,bit);
    return num;
  }
}

void Binary(long num, int bit){
  for(int i = bit-1; i>=0; i--){
    printf("%lu", bitAt(num, i));
  }
}

long expon(int exp, int bit){
  int bias;
  long num;
  bias = (pow(2, bit)/2)-1;
  num = bias + exp;
  Binary(num, bit);
  return num;
}

int main(int argc, char* argv[argc+1]){

  FILE* fp = fopen(argv[1], "r");

  double Orignum;
  int bit;
  int exp;
  int frac;

  while(fscanf(fp, "%lf %d %d %dn", &Orignum, &bit, &exp, &frac)!=EOF){
    long num = Orignum;
    int sign = 0;
    long y = 0;
    int x = 0;
    int fin = 0;
    int temp;

    if(Orignum<0){
      sign = 1;
      Orignum = Orignum*-1;
      num = Orignum;
    }

    while(pow(2,x)<=num){
      x++;
    }
    if(Orignum<2){
      y = Orignum*pow(2, frac);
      int count = 1;
      while(y<pow(2,bit)){
	y = Orignum*pow(2, frac+count);
	count++;
      }
      long temp;
      temp = Orignum;
      count = 0;
      int i = 1;
      while(temp<1){
	temp = Orignum * pow(2,i);
	count--;
	fin = count;
	i++;
      }
    }else{
      y= Orignum*pow(2,frac);
    }

    if(fin == 0){
      fin = x-1;
    }
    x = 0;

    while(pow(2,x)<=y){
      x++;
    }
    temp = x;
    y = Rnd(y, (x-1)-frac);
    x = 0;
    while(pow(2,x)<=y){
      x++;
    }
    if(temp<x){
       fin++;
    }

    //num = num/pow(2,x-1);

    long denormal;

    printf("%d", sign);
    denormal = expon(fin, exp);

    if(denormal == 0){
      CreateBinary(y, x-1, (x-1) - frac);
    }else{
      CreateBinary(y, x-2, (x-2) - frac);
    }
    printf("\n");
  }

   fclose(fp);
   return EXIT_SUCCESS;
}


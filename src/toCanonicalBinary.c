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

int main(int argc, char* argv[argc+1]){

  FILE* fp = fopen(argv[1], "r");

  float Orignum;
  int bit;

  while(fscanf(fp, "%f %d\n", &Orignum, &bit)!=EOF){
    long num = Orignum;
    int x = 0;
    long y = 0;
    int fin = 0;

    while(pow(2,x)<=num){
      x++;
    }

    if(Orignum<2){
      y = Orignum*pow(2, bit);
      int count = 1;
      while(y<pow(2,bit)){
	y = Orignum*pow(2, bit+count);
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
      y= Orignum*pow(2,bit);
    }

    if(fin == 0){
      fin = x-1;
    }
    x = 0;


    while(pow(2,x)<=y){
      x++;
    }

    //num = num/pow(2,x-1);

    printf("1.");
    CreateBinary(y, x-2, (x-2) - bit);
    printf(" %d\n", fin);


  }

  fclose(fp);
  return EXIT_SUCCESS;
}



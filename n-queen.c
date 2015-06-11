/* 8queen.c 8-queen puzzle CNF generator for minisat */

#include <stdio.h>
#include <stdlib.h>

int getboxnum(int col, int row, int n){
	return (row-1)*n+col;
}

int main(int argc, char* argv[]){

	int col, row;
    int p, q;
	int n;
	
	n = atoi(argv[1]);

    printf("p cnf %d #NUM\n", n*n);
    
#if defined(DEBUG)
  printf("rule 1 each row has just one queen\n");
#endif

  for (row = 1; row <= n; row++){
      for (col = 1; col <= n; col++){
          printf("%d ", getboxnum(col,row,n));
      }
      printf("0\n");
  }

#if defined(DEBUG)
  printf("rule 2 no duplicates in the row\n");
#endif

  for (row = 1; row <= n; row++){
      for (col = 1; col <= n; col++){
          for (p = col+1; p <= n; p++){             
              printf("-%d -%d 0\n", getboxnum(col,row,n), getboxnum(p,row,n));
          }
      }
  }

#if defined(DEBUG)
  printf("rule 3 no duplicates in the col\n");
#endif

  for (row = 1; row <= n; row++){
      for (col = 1; col <= n; col++){
          for (p = row+1; p <= n; p++){             
              printf("-%d -%d 0\n", getboxnum(col,row,n), getboxnum(col,p,n));
          }
      }
  }

#if defined(DEBUG)
  printf("rule 4 no duplicates in the lower-right angle\n");
#endif

  for (row = 1; row < n; row++){
      for (col = 1; col < n; col++){
          q = row + 1;
          for (p = col+1; p <= n; p++){
              printf("-%d -%d 0\n", getboxnum(col,row,n), getboxnum(p,q,n));
              q++;
              if (q > n){
                  break;
              }
          }
      }
  }

#if defined(DEBUG)
  printf("rule 5 no duplicates in the lower-left angle\n");
#endif

  for (row = 1; row < n; row++){
      for (col = 2; col <= n; col++){
          q = row + 1;
          for (p = col-1; p >= 1; p--){
              printf("-%d -%d 0\n", getboxnum(col,row,n), getboxnum(p,q,n));
              q++;
              if (q > n){
                  break;
              }
          }
      }
  }
  
  return 0;
  
}

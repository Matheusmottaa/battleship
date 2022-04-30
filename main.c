#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

void drawGrid(char ship[][10]); 
void newSeed(); 
unsigned int mapColumn(char column); 


int main(){ 

  char ships[8][10] = {0}; 

  char opt  = 'p',
       sort = 1, 
       col  = 0; 

  unsigned int num, 
               row      = 0, 
               hits     = 0, 
               mistakes = 0; 
  
  register int i, j; 

  do{ 
    if(sort){ 
      system("clear"); 
      newSeed(); 

      for(i=0; i<8; i++){ 
        for(j=0; j<10; j++){ 
          num = rand()%100+1; 

          if(num%2)
            ships[i][j] = '@'; 
          else 
            ships[i][j] = 0x20; 
        }
      }
      drawGrid(ships); 
    } else { 
      printf("Invalid option\n"); 
      sort = 1; 
    }

    printf("(d) Draft again \n"); 
    printf("(p) play the game\n"); 
    scanf(" %c", &opt); 

    if(opt != 'd' && opt != 'D') sort=0;  

  } while(opt != 'p' && opt != 'P'); 

  system("clear"); 
  drawGrid(ships); 
  printf("Targets hits: %3d | Mistakes: %3d\n", hits, mistakes); 

  while(1){ 
    printf("Type the trigger position: ");
    scanf(" %c%d", &col, &row); 

    system("clear"); 

    if(ships[row-1][mapColumn(col)] == '@'){ 
      ships[row-1][mapColumn(col)] = '*';
      hits++; 
      putchar('\a');  
    } else { 
      mistakes++; 
      putchar('\a'); 
      putchar('\a'); 
      putchar('\a'); 
        if(mistakes > 5){ 
          printf("You lost the game :(\n"); 
          for(i=0; i<5; i++){ 
            putchar('\a'); 
          }
          system("pause"); 
          exit(0); 
        }
    }

    drawGrid(ships); 
    printf("Targets hits: %3d | Mistakes: %3d\n", hits, mistakes); 
  }

  system("pause"); 
  return 0; 
}


void drawGrid(char ship[][10]){ 
  register int i, j; 

  printf("  A  B  C  D  E  F  G  H  I  J \n"); 
  puts("-----------------------------------"); 

  for(i=0; i<8; i++){ 
    printf("%d", i+1); 

    for(j=0; j<10; j++){ 
      printf("| %c", ship[i][j]); 
    }
    puts("|"); 
    puts("----------------------------------"); 
  }

}

void newSeed(){ 
  unsigned long int capture;
  time(&capture); 
  srand((unsigned)capture);  
}

unsigned int mapColumn(char column){
    switch(column){ 
      case 'a': 
      case 'A': return 0; break; 
      case 'b': 
      case 'B': return 1; break; 
      case 'c': 
      case 'C': return 2; break; 
      case 'd': 
      case 'D': return 3; break; 
      case 'e': 
      case 'E': return 4; break; 
      case 'f': 
      case 'F': return 5; break; 
      case 'g': 
      case 'G': return 6; break; 
      case 'h': 
      case 'H': return 7; break; 
      case 'i': 
      case 'I': return 8; break; 
      case 'j': 
      case 'J': return 9; break; 
  }
}
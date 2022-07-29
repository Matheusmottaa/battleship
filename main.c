#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

void naval(char b[][10]);
void new_seed(); 
unsigned int map_col(char col); 
void grid(char b[][10]); 

int main(){ 
  char boats[8][10] = {0}, 
       opt = 'j', 
       sort = 1, 
       col = 0; 
  unsigned int num, 
               row = 0, 
               acertos = 0, 
               errors = 0; 
  
  register int i,j; 

  do{ 

    if(sort){ 
      system("clear"); 
      new_seed(); 
      for(i=0;i<8;i++){ 
        for(j=0;j<10;j++){ 
          num = rand()%100+1; 
          if(num%2) boats[i][j] = '@'; 
          else      boats[i][j] = 0x20; 
        }
      }
      naval(boats); 
    } else { 
      printf("Opcao invalida\n"); 
      system("clear"); 
      sort = 1; 
  }
    printf("(s) sortear novamente\n"); 
    printf("(j) jogar!\n"); 
    scanf(" %c", &opt); 

  if(opt!='s' && opt!='S') sort = 0; 

  }while(opt!='j' && opt!='J'); 

  system("clear"); 
  grid(boats);  
  printf("Alvos atingidos: %3d | Erros: %3d\n", acertos, errors);

  while(1){ 
    printf("Digite a posicao de disparo: "); 
    scanf(" %c%d", &col, &row); 
    system("clear"); 

    if(boats[row-1][map_col(col)] == '@'){ 
      boats[row-1][map_col(col)] = '*'; 
      acertos++; 
      putchar('\a'); 
    }else{ 
      errors++; 
      putchar('\a'); 
      putchar('\a'); 
      putchar('\a'); 

      if(errors > 5){ 
        printf("Fomos Derrotados!\n");
        for(i=0;i<5;i++){ 
          putchar('\a'); 
        }
        exit(0); 
      }
    }
    grid(boats); 
    printf("Alvos Atigidos: %3d | Erros: %3d\n", acertos, errors); 
  }

  return 0; 
}

void naval(char b[][10]){ 
  register int i,j; 
  printf("   A   B   C   D   E   F   G   H   I   J\n"); 
  puts("--------------------------------------------\n");
  for(i=0;i<8;i++){ 
    printf("%d", i+1); 
    for(j=0;j<10;j++){ 
      printf("| %c ", b[i][j]); 
    }
    puts("|"); 
  puts("--------------------------------------------\n");
  }
}

void new_seed(){ 
  time_t capture; 
  time(&capture); 
  srand((unsigned)capture); 
}

unsigned int map_col(char col){ 
  switch(col){ 
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

void grid(char b[][10]){ 
  register int i,j; 
  printf("  A  B  C  D  E  F  G  H  I  J\n"); 
  puts("--------------------------------\n");
  for(i=0;i<8;i++){
    printf("%d", i+1); 
    for(j=0;j<10;j++){
      if(b[i][j] == '*'){ 
        printf("| %c ", b[i][j]); 
      }else { 
        printf("|  "); 
      }
    }
    puts("|"); 
    puts("--------------------------------\n");
  }
}

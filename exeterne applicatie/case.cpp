#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(void)
{
    int hoofdcase=0, incase1=0, incase2=0;
    int var=0, i;
    char letters, waarde;
    
    for(; hoofdcase<=2 && hoofdcase>=0; )
    {
    
    printf("\n\nVerkeersplein\n");
    printf("---------------");
    printf("\nKies een van de volgende opties:\n");
    printf("1. Tijden van verkeerslichten aanpassen\n");
    printf("2. Nachtstand aan of uit zetten\n");
    printf("3. exit\n");
    

    /*term_puts("\n\nVerkeersplein\n");
    term_puts("\nKies een van de volgende opties:\n");
    term_puts("---------------");
    term_puts("1. Tijden van verkeerslichten aanpassen\n");
    term_puts("2. Nachtstand aan of uit zetten\n");
    term_puts("3. Exit\n");
    */

    scanf("%d", &hoofdcase);
   // hoofdcase=term_getchar();
   
    switch (hoofdcase)
    {
     case 1:
          {
              
              
              printf("\nTijden van verkeerslichten aanpassen\n");
              printf("---------------");
              printf("\nWelke van de variabelen wil je aan passen, kies een van de volgende:\n");
              printf("1. groen\n");
              printf("2. oranje\n");
              printf("3. rood\n");
              printf("4. nachtstand knipperen\n");

                /*
               
               term_puts("\nTijden van verkeerslichten aanpassen\n");
               term_puts("---------------");
               term_puts("\nWelke van de variabelen wil je aan passen, kies een van de volgende:\n");
               term_puts("1. Het groene licht\n");
               term_puts("2. Het oranje licht\n");
               term_puts("3. Het rode licht\n");
               term_puts("4. De knipper tijd bij nachtsand\n");
               */
                  scanf("%d", &incase1);
                   // incase1=term_getchar();
                 switch (incase1)
                 {
                        case 1:
                             {
                             printf("\nGroen\n");
                             printf("---------------");
                             printf("\nnieuwe tijd:\n");
                             /*
                               term_puts("\nHet groene licht\n");
                               term_puts("---------------");
                               term_puts("\nDe nieuwe tijd\n");
                             */ 
                            letters='g';
                             scanf("%d", &waarde);
                             // waarde=term_getchar(); 
                            //	rs232_putchar(letters);
                            // rs232_putchar(waarde);
                             break;
                             }          
                        case 2:
                             {
                             printf("\nOranje\n");
                             printf("---------------");
                             printf("\nnieuwe tijd:\n");
                             /*
                               term_puts("\nHet oranje licht\n");
                               term_puts("---------------");
                               term_puts("\nDe nieuwe tijd\n");
                             */ 
                            letters='o';
                             scanf("%d", &waarde);
                             // waarde=term_getchar(); 
                            //	rs232_putchar(letters);
                            // rs232_putchar(waarde);
                                                        
                             break;
                             }    
                        case 3:
                             {
                             printf("\nRood\n");
                             printf("---------------");
                             printf("\nnieuwe tijd:\n");
                             /*
                               term_puts("\nHet rood licht\n");
                               term_puts("---------------");
                               term_puts("\nDe nieuwe tijd\n");
                             */ 
                             letters='r';
                             scanf("%d", &waarde);
                             // waarde=term_getchar(); 
                            //	rs232_putchar(letters);
                            // rs232_putchar(waarde);
                                                              
                             break;
                             }
                        case 4:
                             {
                             printf("\nKnipperen\n");
                             printf("---------------");
                             printf("\nnieuwe nachtstand knipperen:\n");
                             /*
                               term_puts("\nHet groene licht\n");
                               term_puts("---------------");
                               term_puts("\nDe nieuwe knipper tijd bij nachtsand\n");
                             */ 
                             letters='n';
                             scanf("%d", &waarde);
                             // waarde=term_getchar(); 
                            //	rs232_putchar(letters);
                            // rs232_putchar(waarde);                             
                                  
                             break;
                             }
                       incase1=0; 
                        
                 }
              
              hoofdcase=0;   
             break;        
          }     
     case 2:
          {
                
              printf("\nNachtstand aan of uit zetten\n");
              printf("---------------");
              printf("\naan of uit:\n");
              printf("1. aan\n");
              printf("2. uit\n");
              

                /*
               
               term_puts("\nNachtstand aan of uit zetten\n");
               term_puts("---------------");
               term_puts("\nWilt u se nachtstand aan of uit zetten, kies een van de volgende 2 opties:\n");
               term_puts("1. Aan zetten\n");
               term_puts("2. Uit zetten\n");
              
               */ 
                
                  scanf("%d", &incase2);
                   // incase2=term_getchar();                
                switch (incase2)
                 {
                        case 1:
                             {
                             letters='a';
                            //	rs232_putchar(letters);

                                printf("aan");
                             break;
                             }          
                        case 2:
                             {
                             letters='u';
                            //	rs232_putchar(letters);

                               printf("uit");
                             break;
                             }   
                  incase2=0;     
                 }   
              hoofdcase=0;
             break;        
          }     
          case 3:
               {
               hoofdcase=3;
                break;           
               }
          }
     waarde=0;
     letters='p';
    }    
    
    
   getchar();     
}

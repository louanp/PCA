#ifndef _SEQUENCE_C_
#define _SEQUENCE_C_

#include "sequence.h"
#include <string.h>
#include <stdlib.h>
static int Ite;
static char *Sequence[Lg_N_gramme];
static char *Mot;
/*****************************************/
// initialisation du tableaux circulaire 
//
/*****************************************/
void sequence_initialize( struct strhash_table * ht )
{
  const char *motVide = " " ;
  char *motVideHash = strhash_wordAdd(ht, motVide);
  if(motVideHash == NULL)
  {
        printf("probleme mot vide");
  }
  int i;
  for(i = 0; i<Lg_N_gramme; i++)
  {
    Sequence[i] = motVideHash;
  }
   sequence_itStart();
}
/*****************************************/
// Initiailise l'iterateur au premier mot
//
/*****************************************/
void sequence_itStart( void )
{
    Ite = 0;

}
/*****************************************/
//Retourne le mot corespondant à la position de l'iterateur 
// avance l'ite de 1
/*****************************************/
const char * sequence_itNext( void )
{
   char *lemot = Sequence[Ite];
    if (sequence_itHasNext() == 1)
    {
        Ite = 0;
    }
    else 
    {
        Ite ++;
    }
   
   return lemot;
}
/*****************************************/
// test si l'itérateur est arrivé à la fin
//
/*****************************************/
int sequence_itHasNext( void )
{
    if (Ite ==2)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}
/*****************************************/
// Nouveaux mot de fin du N-gramme
//Definit le nouveaux mot qui entrera dans le N-gramme 
/*****************************************/
void sequence_addWord( const char * word, struct strhash_table * ht )
{
    Mot= strhash_wordAdd(ht, word);
    sequence_progress();
    Sequence[Ite] = Mot;


}
/*****************************************/
// retourne le nouveaux mot qui entreras 
// dans le N-gramme 
/*****************************************/
const char * sequence_nextWord( void )
{
    
    if(Mot != NULL)
    {
        return Mot;
    }
    else return " ";
}
/*****************************************/
// avance le N-gramme courant pour integrer
// le nouveaux mots ecrit
/*****************************************/
void sequence_progress( void )
{
    //Ite = (Ite+1) % Lg_N_gramme;
    sequence_itNext();

}
/*****************************************/
// affiche le N-gramme courant, 
// les mots sont séparés par des '/'
/*****************************************/
void sequence_print( void )
{
    int compt;
    for (compt=0;compt<Lg_N_gramme; compt++)
    {
        printf("%s/", Sequence[compt]);
    }
    printf("\n");

}
/*****************************************/
// sequence sous forme d'une chaine de caractères
// 
/*****************************************/
char * sequence_printInTab( void )
{
    int compt = 0;  
    size_t taille =0 ;
    while(compt != Lg_N_gramme)
    {
        const char *motCourant = sequence_itNext();
        taille += strlen(motCourant) +1;
        compt++;
    }
    char *leMot=(char *) malloc( taille * sizeof(char) );
    compt= 0;
    while(compt != Lg_N_gramme)
    {
        const char *motCourant = sequence_itNext();
        if(motCourant==NULL)
        {
            strcat(leMot,"null");
        }
        else{
            strcat(leMot,motCourant);
        }
        if (compt < Lg_N_gramme - 1) {
            strcat(leMot, " "); 
        }
        compt++;
    }
    return leMot;

}

#endif

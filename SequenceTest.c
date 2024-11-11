#include <stdio.h>
#include "sequence.h"

int main()
{
    
    // Déclaration de la table de hash
    struct strhash_table * ht;
    if ((ht = strhash_create(1000))==NULL)
    {
        printf("probleme table hash");
    }
    // initialisation de la sequence
    printf("-------------------------------------------------\n");
    printf("tableaux vide : \n");
    sequence_initialize(ht);
    sequence_print();
    //ajoute de mot 
    printf("-------------------------------------------------\n");
    printf("tableaux remplis de mot : \n");
    sequence_addWord("je",ht);sequence_print();
    sequence_addWord("m'appelle",ht);sequence_print();
    sequence_addWord("louan",ht);sequence_print();
    sequence_addWord("j'ai",ht);sequence_print();
    sequence_addWord("21",ht);sequence_print();
    sequence_addWord("ans",ht);sequence_print();
    
    // test méthode sequence_itNext()
    printf("-------------------------------------------------\n");
    printf("Renvois le mot corespondant a l'ite et avance l'ite : \n");
    printf("%s\n",sequence_itNext());
    sequence_print();
    printf("-------------------------------------------------\n");
    printf(" : \n");
    
}
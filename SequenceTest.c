#include <stdio.h>
#include "sequence.h"

int main()
{
    const char *motChaine;
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
    // test du print chaine de cractère 
    printf("-------------------------------------------------\n");
    printf("sequence sous forme de chaine de caractère: \n");
    motChaine=sequence_printInTab();
    printf("%s\n",motChaine);
    // changement de mot
    printf("-------------------------------------------------\n");
    printf("simulation de changement de mot dans ma sequence : \n");
    sequence_addWord("j'ai",ht);sequence_print();
    sequence_addWord("un",ht);sequence_print();
    sequence_addWord("chat",ht);sequence_print();
    // test du print chaine de cractère 
    printf("-------------------------------------------------\n");
    printf("sequence sous forme de chiane de caractère: \n");
    motChaine=sequence_printInTab();
    printf("%s\n",motChaine);
    // test des erreurs 
    printf("-------------------------------------------------\n");
    printf("test des possibles erreur: \n");
    sequence_addWord("",ht);
    sequence_addWord("à",ht);sequence_print();
    sequence_addWord(" ",ht);sequence_print();
    // test méthode sequence_itNext()
    printf("-------------------------------------------------\n");
    printf("Renvois le mot corespondant a l'ite et avance l'ite : \n");
    printf("%s\n",sequence_itNext());
    sequence_print();
    printf("-------------------------------------------------\n");
    printf("Renvois le mot corespondant a l'ite et avance l'ite : \n");
    printf("%s\n",sequence_itNext());
    sequence_print();
    printf("-------------------------------------------------\n");
    // faire des test sur les erreurs !!!!!!!!

    
}
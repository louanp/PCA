#ifndef _SEQUENCE_C_
#define _SEQUENCE_C_

#include "sequence.h"

void sequence_initialize( struct strhash_table * ht )
{
    int i ;
    for (i=0 ; i<Lg_N_gramme ; i++)
    {
        ht->values->first->data = " ";
        ht->values->first->next;
    }
}

#endif

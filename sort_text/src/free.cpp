#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "free.h"
#include "read_file.h"  

void FreeTextInfo(TextInfo *text_info)
{
    assert(text_info);
    
    free(text_info->p_lines);
    free(text_info->text_cont);
}
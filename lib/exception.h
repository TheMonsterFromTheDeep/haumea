#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <setjmp.h>

jmp_buf except_buf;

const char *except_msg;

#define TRY if(!setjmp(except_buf))
#define CATCH else

#define THROW(except,msg) except_msg = msg; longjmp(except_buf,except)

#endif

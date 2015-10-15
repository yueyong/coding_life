/**
 * ************************ Dynamic String Type , C style *****************
 */

#ifndef ALG_DSTRING_H
#define ALG_DSTRING_H

#include "stdlib.h"
#include "base.h"

#define STR_ERR 1
#define STR_OK 0
#define STATUS int

#ifndef size_t

typedef char *str;


struct __attribute__ ((__packed__)) str_t {
    unsigned long len;
    unsigned long cap;
};


/* Functions implement with Macros */
#define strNew(x) (strNewLen((x),0))
#define strDup(x) strNewLen((x),0)
#define strNewEmpty() strNewLen(NULL,0)
#define strFree(s) free(strHead(s))
#define strHead(s) ((struct str_t*)(s-sizeof(struct str_t)))
#define strLength(s) (strHead((s))->len)
#define strCap(s) (strHead((s))->cap)
#define strUpdateLength(s) strHead((s))->len=strlen(s)


/* public functions */
str strNewLen(const char *s, size_t len);  // create a str from normal c style string
str strConcat(str sa, const char *sb);  // concat sa and sb
int strEqual(str sa, const char *sb);
str strJoin(const char *sep, str str_seq[]);  // concat a str array with sep
str strSub(str s, int start, int end);
str strReplace(str s, const char *old, const char *to);
size_t strIndex(str s, const char *target, size_t start);


/* private functions */
str strAddCap(str s, size_t added_len);


#endif //ALG_DSTRING_H

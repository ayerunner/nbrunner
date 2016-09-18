#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>

/* This file was generated by QuasiBASIC to C translator */
/* qb2c  ver.3.41 Free Version 04 May 2000
Check out the Pay version at http://random.com.hr/products/                            */

#define LMAX 1025 /* Max strig length */

/* Function declarations */
extern char  *MID_S(char *, int, int);
extern char  *LEFT_S(char *, int);
extern char  *UCASE_S(char *);
extern char  *STR_S(double);
extern int    LEN(char *);
extern int    eof(FILE *);
extern char  *COMMAND_S(int, char *argv_S[]);
extern double DBL(double);

/* Shared variables and arrays declarations */
static char   w__S[16][LMAX];
static int    j__S = 0, j__Stmp;
static double w__d[16];
static int    i__d = 0, i__dtmp;
static char tws__S[LMAX];

/* Open files pointers */
FILE *fp_1;
char fn1__S[160];

main(int n_arg_int, char *argv_S[])
{
 static int  nl_int, leng_int;
 static char c_S[LMAX], line_S[LMAX], helpf_S[LMAX], key_S[LMAX];

 n_arg_int--;
 /* bhelp for QB2C versions 3.2k and later - by Mario Stipcevic */
 /* This is a QB2C code. Compile it with: bcc */
 strcpy(c_S,COMMAND_S(n_arg_int, argv_S));
 strcpy(line_S,"");
 nl_int = 0;
 /* local_path$ = */
 /* src_path$ = */
 /* if exists() */
 strcpy(helpf_S,"manual.txt");
 if(strcmp(c_S, "") != 0)
 {
  if((fp_1 = fopen(strcpy(fn1__S,helpf_S), "r")) == NULL)
  {
   fprintf(stderr,"Can't open file %s\n",fn1__S); exit(1);
  }
  sprintf(key_S,"%s%s","o ",UCASE_S(c_S));
  leng_int = LEN(key_S);
  while((strcmp(LEFT_S(line_S, 20), "+ Reference Manual +") != 0) && ! eof(fp_1))
  {
   fgets(line_S, LMAX, fp_1);
   line_S[strlen(line_S) - 1] = '\0';
   nl_int = nl_int + 1;
  }
  while((strcmp(LEFT_S(line_S, leng_int), key_S) != 0) && ! eof(fp_1))
  {
   fgets(line_S, LMAX, fp_1);
   line_S[strlen(line_S) - 1] = '\0';
   nl_int = nl_int + 1;
  }
  fclose(fp_1);
  sprintf(tws__S,"%s%s%s%s","vi +",MID_S(STR_S(nl_int), 2, LMAX)," ",helpf_S);
  system(tws__S);
 }
 else
 {
  sprintf(tws__S,"%s%s","vi ",helpf_S);
  system(tws__S);
 }
 exit(0);
} /* End of MAIN */

/* Translates of used QB's intrinsic functions: */

extern char *MID_S(char *a_S, int start, int length)
{

 if (++j__S == 16) j__S=0;
 if(length < 0) { 
  printf("Error: in MID_S: length < 0\n");
  exit(0); }
 if(start  < 0) {
  printf("Error: in MID_S: start < 1\n");
  exit(0); }
 if(start > strlen(a_S)) 
 { w__S[j__S][0]='\0'; }
 else
 { strncpy(w__S[j__S], &a_S[start-1], length);
   w__S[j__S][length]='\0'; }

 return w__S[j__S];
}

extern char *LEFT_S(char *a_S, int length)
{

 if (++j__S == 16) j__S=0;
 if(length < 0) { 
  printf("Error: in LEFT_S: length < 0\n");
  exit(0); }
 strncpy(w__S[j__S], a_S, length);
 w__S[j__S][length]='\0';

 return w__S[j__S];
}

extern char *STR_S(double d)
{

 if (++j__S == 16) j__S=0;
 sprintf(w__S[j__S],"% G",d);
 return w__S[j__S];
}

extern int LEN(char *a_S)
{
 if (++i__d == 16) i__d = 0;
 w__d[i__d] = strlen(a_S);
 return w__d[i__d];
}

extern int eof(FILE *stream)
{
 static int c, istat;

 istat=((c=fgetc(stream))==EOF);
 ungetc(c,stream);
 return istat; 
}

extern char *COMMAND_S(int n_arg_int, char *argv_S[])
{
 int i;

 if (++j__S == 16) j__S=0;
 for(i = 1; i <= n_arg_int; i++)
 {
  strcat(w__S[j__S],argv_S[i]);
  strcat(w__S[j__S]," ");
 }
 w__S[j__S][strlen(w__S[j__S])-1]='\0';
 return w__S[j__S];
}

extern double DBL(double d)
{
 if (++i__d == 16) i__d = 0;
 w__d[i__d] = d;
 return w__d[i__d];
}

extern char *UCASE_S(char *text_S)
{
 int i=0; char c;
 if (++j__S == 16) j__S=0;
 while((c=text_S[i]) != '\0') {
  w__S[j__S][i++] = toupper(c);
 }
 w__S[j__S][i] = '\0';
 return w__S[j__S];
}

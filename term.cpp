#include "term.h"
#include <cstdio>
#include <cstring>
#include <stdarg.h>
#include <string>




void echo(char * info,...){
   if (level.value==4)
   {
   va_list arg;
   std::string mixer=info;
   mixer.append("\n");
   const char * finalinfo=mixer.c_str();
   va_start (arg, finalinfo);
   vfprintf (stdout, finalinfo, arg);
   va_end (arg);}
}
void warning( char * info,...){
   if (level.value>=1)
   {
   va_list arg;
   std::string mixer=YELLOW;
   mixer.append(info); mixer.append("\033[0m\n");
   const char * finalinfo=mixer.c_str();
   va_start (arg, finalinfo);
   vfprintf (stdout, finalinfo, arg);
   va_end (arg);}
}
void error( char * info,...){
   if (level.value>=0)
   {
   va_list arg;
   std::string mixer=BOLDRED;
   mixer.append(info); mixer.append("\033[0m\n");
   const char * finalinfo=mixer.c_str();
   va_start (arg, finalinfo);
   vfprintf (stdout, finalinfo, arg);
   va_end (arg);
}}
void success(char * info , ...){
   if (level.value>=2)
   {
   va_list arg;
   std::string mixer=GREEN;
   mixer.append(info); mixer.append("\033[0m\n");
   const char * finalinfo=mixer.c_str();
   va_start (arg, finalinfo);
   vfprintf (stdout, finalinfo, arg);
   va_end (arg);}
}
void message(char * info , ...){
   if (level.value>=3)
   {
   va_list arg;
   std::string mixer=BOLDWHITE;
   mixer.append(info); mixer.append("\033[0m\n");
   const char * finalinfo=mixer.c_str();
   va_start (arg, finalinfo);
   vfprintf (stdout, finalinfo, arg);
   va_end (arg);}
}
void startup(char* game,char*version){

    echo("%s %s",game,version);
    warning("be warned that");
    error("ERRORS MIGHT OCCUR!!!");
    success("but dont worry");
    message("this is not an error");
}
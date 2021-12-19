#include <stdio.h>
#include <string.h>
#include <ctype.h>
static const char * const alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int check(char *str,char w){
    for(int i = 0;str[i];i++){
        if(w == str[i]){
            return 1; 
        }
    }
    return 0;
}

void removeChar(char *str, char garbage) {

    char *src, *dst;
    int boo = 0;
    int j = 0;
    dst = src = str;
    for (int i = 0;src[i];i++) {
        if (src[i] != garbage || boo == 1){
            dst[j] = src[i];
            j++;
            }
        if (src[i] == garbage)
        {boo =1;}
    }
    dst[j] = '\0';
}

char *strrev(char *str)
{
    if (!str || ! *str)
        return str;

    int i = strlen(str) - 1, j = 0;

    char ch;
    while (i > j)
    {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i--;
        j++;
    }
    return str;
}

char atbash(char c){
    int len = strlen(alphabet);
    int n = 0;
    int m;
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
        char *p = strchr(alphabet, toupper(c));
        if (p)
        {
            n = p - alphabet;
        }
        for(int i = 0;i<len;i++){
            char a = alphabet[i];
            char *s = strchr(alphabet, toupper(a));
            m = s + 1 - alphabet;
            if(m + n == len){
                if(c >= 'a' && c <= 'z'){
                    return tolower(a);
                }
                return a;
            }
        }
    }
    return c;
}

int c_to_n(char c)
{
    int n = 0;
    if (c == ' '||c == ','||c == '\n'||c == '.'){
        return n;
    }
    char *p = strchr(alphabet, toupper(c));
    if (p)
    {
        n = p - alphabet;
    }
return (n+1);
}

int gem(char *t){
    int sum = 0;
    for(int i = 0 ;t[i];i++){
        sum += c_to_n(t[i]);
    }
    return sum;
}

void att(char *t,char *word){
    int pass = 0;
    char w[1024];
    for(int i = 0;word[i];i++){
        w[i] = atbash(word[i]);
    }
    char wr[1024];
    strcpy(wr,w);
    strrev(w);
    for(int j = 0;t[j];j++){
        int i = 0;
        int k = 0;
        char temp_w[1024];
        char temp_ws[1024];
        memset(temp_w, 0, strlen(temp_w));
        memset(temp_ws, 0, strlen(temp_ws));
        while((t[j+i] >= 'a' && t[j+i] <= 'z') || (t[j+i] >= 'A' && t[j+i] <= 'Z')||((t[j+i] == ' '||t[j+i]==','||t[j+i]=='\n'||t[j+i] == '.')&&i>0)){
            if((t[j+i] == w[k])||t[j+i] == wr[k]){
                temp_w[k] = t[j+i];
                temp_ws[i] = t[j+i];
                i++;
                k++;
            }
            else if(t[j+i] == ' '||t[j+i]==','||t[j+i]=='\n'||t[j+i] == '.'){
                temp_ws[i] = t[j+i];
                i++;
            }
            else{
                break;
            }
            if(strcmp(temp_w,wr)== 0||strcmp(temp_w,w) == 0){
                if(pass == 1) printf("~");
                printf("%s",temp_ws);
                pass = 1;
                break;
            }
        }
    }
}

void angram(char *t,char *word){
    int len = strlen(t);
    int pass = 0;
    for(int j = 0;j<len;j++){
        int i = 0;
        char temp_w[1024];
        char temp[1024];
         memset(temp, 0, strlen(temp));
        strcpy(temp_w,word);
        while(len>(j+i)&&(check(temp_w,t[j+i]) == 1||((t[j+i] == ' ')&&i>0))){
            if(check(temp_w,t[j+i]) == 1){
                temp[i] = t[j+i];
                removeChar(temp_w,t[j+i]);
                i++;
            }
            if((t[j+i] == ' ')&&strlen(temp_w) != 0){
                temp[i] = t[j+i];
                i++;
            }
            if((strlen(temp_w) == 0)){
                if(pass == 1)printf("~");
                printf("%s",temp);
                pass = 1;
                break;
            }
        }
    }
}

void gemt(char *t,char *word){
    int pass = 0;
    int n = gem(word);
    for(int j = 0;t[j];j++){
        int i = 0;
        char w[100];
        int sum = 0;
        while((t[j+i] >= 'a' && t[j+i] <= 'z') || (t[j+i] >= 'A' && t[j+i] <= 'Z')||((t[j+i] == ' '||t[j+i]==','||t[j+i]=='\n'||t[j+i] == '.')&&i>0)){
            sum += c_to_n(t[i+j]);
            w[i] = t[j+i];
            w[i+1] = '\0';
            if(sum == n){
                if(pass == 1) printf("~");
                printf("%s",w);
                pass = 1;
                break;
                
            }
            else if(sum < n){
                i++;
            }
            else{
                break;
            }
        }
    }
}


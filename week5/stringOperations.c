#include <stdio.h>
#define N 10000

int strLength(char a[]){
    int i ;
    // return i once a[i] reaches the end of the input string
    for(i = 0; a[i] != 0; i++) 
        // return i;
        break;
    // else
    return i;
}

void strCopy(char a[], char b[]){
    // copy one string into another
    int i;
    for(i =0; (a[i] = b[i]) != 0; i++)
        break;
}

// Compare
int strCmp(char a[], char b[]){
    int i;
    for (i = 0; a[i] == b[i]; i++)
        if (a[i] == 0) return 0;
    return a[i] - b[i];
}



// compare prefix
int strCmpPrefix(char a[], char b[]){ // lengthStr  = strlen(a)
    int strlen_a = strLength(a);
    int i = 0;
    for (i= 0; a[i] == b[i]; i++)
        if (a[i] == 0) return 0;
    if (a[i] == 0) return 0;
    return a[i] - b[i];
}


// Append
void strCat(char a[], char b[]){
    strCopy(a+strLength(a),b);
}





int main(int argc, char* argv[]){
     int i,j,t;
     char a[N];
     char* p = argv[1];
     
    // Compute the length of a string
    for (i =0; i< N-1; i++){
        if ((t = getchar()) == EOF) break;
    }
    a[i] = 0;
    for(i =0; a[i] != 0; i++){
        for(j = 0; p[j] != 0; j++){
            if(a[i+j] != p[j]) break;
        }
        if (p[j] == 0) printf("%d ", i);
    }
    printf("\n");


    return 0;
}
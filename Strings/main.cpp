#include<stdio.h>
#include<iostream>
using namespace std;

void swap(char *x,char *y){
    char temp = *x;
    *x = *y;
    *y = temp;
}
// 10/5/21
int StringLen(char a[]){
    int i;
    for(i = 0;a[i] != '\0';i++){};
    return i;
}
void changeCase(char a[]){
    for(int i = 0;a[i] != '\0';i++){
        if(a[i]>= 65 && a[i] <= 90)a[i]+= 32;
        else if(a[i]>= 97 && a[i] <= 122)a[i]-= 32;
    } 
}

struct Count{
    int vowel,consonant;
};
struct Count vcCount(char a[]){
    int consonant ,vowel = 0;
    for(int i = 0;a[i] != '\0';i++){
        char c = a[i];
        // cout << c << endl;
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'|| c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
            vowel++;
        }else if((c >= 65 && c <=90)||(c >=97 && c<=122)){
            consonant++;
        }
    }
    struct Count count  = {vowel,consonant};
    return count;
}

int validCheck(char a[]){
    for(int i=0;a[i]!='\0';i++){
        cout << a[i] << " "<<(int)a[i] <<endl;
        if(!(a[i] >= 65 && a[i] <= 90) && !(a[i] >= 97 && a[i] <= 122) && !(a[i] >= 48 && a[i] <= 57) && !(a[i] == 32)){
        cout << a[i] << " "<<(int)a[i] <<endl;

            return -1;
        }
    }
    return 1;
}
void StringReverse(char *a){
    int i,j = 0;
    char temp;
    while(a[j] != '\0')j++;
    j--;
    // cout << j;
    while(i<j){
        swap(&a[i],&a[j]);
        // printf("%s\n",a);
        i++;
        j--;
    }
}
int countWords(char *a){
    int count = 0;
    for(int i = 0;a[i] != '\0';i++){
        if(a[i] == ' ' && a[i-1] != ' ')count++;
    }
    return count+1;
}

// 11/5/21
void anagramCheck(char a[],char b[]){
    int flag;
    for(int i = 0;a[i] != '\0' ; i++){
        flag = 0;
        for(int j = 0;b[j] != '\0' ;j++){
            cout << a[i] << " "<< b[j] << endl;
            if(a[i] == b[j]){
                b[j] = -1;
                flag = 1;
            }
        }
        if(flag == 0)break;
    }
    if(flag ==0)cout << "not anagram";
    else cout<<"anagram";
}
void anagramCheckHash(char *a,char*b){
    int h[26] = {0};
    int flag = 0;
    for(int i = 0;a[i] != '\0';i++){
        h[a[i]-97]++;
    }
    for(int i = 0;b[i] != '\0';i++){
        h[b[i]-97]++;
        if(h[b[i] -97] < 0){
            cout << "not anagram";
            flag = 1;
            break;
        }
    }
    if(flag==0)cout << "anagram";
}
void findDuplicates(char *a){
    for(int i = 0 ;a[i] != '\0';i++){
        for(int j = i+1;a[j] != '\0';j++){
            if(a[i] == a[j] && a[i] != -1){
                printf("Duplicate found : %c\n",a[i]);
                a[j] = -1;
            }
        }
    }
}

void findDuplicatesHash(char *a){
    // int *h;
    // h = (int *)malloc(26*sizeof(int));
    int h[26]  ={0};
    
    for(int i = 0;a[i] != '\0';i++){
        h[a[i]-97]++;
    }
    for(int i = 0;i<26;i++){
        if(h[i]> 1){
            printf ("%c found %d times\n",i + 97,h[i]);
        }
    }
}
char * toLowerCase(char a[]){
    for(int i = 0;a[i] != '\0';i++){
        if(a[i] >=65 && a[i] <= 90){
            a[i]+=32;
        }
    }
    return a;
}
// C++ does not allow to return an entire array as an argument to a function. However, you can return a pointer to an array by specifying the array's name without an index.
void stringMatch(char a[],char b[]){
    toLowerCase(a);
    toLowerCase(b);
    int i=0,j=0;
    while (a[i] != '\0' && b[j] != '\0')
    {
        if(a[i] != b[j]){
            printf("mismatch\n");
            break;
        }
        i++;
        j++;
    }
    if(a[i] == b[j])cout << "equal";
    else if(a[i] < b[j])cout << "smaller";
    else cout << "larger";
    
}
void palindrome(/*pointer to a array of characters*/char *a){
    int l = StringLen(a);
    int i =0 , j = l-1;
    while(i<j){
        if(a[i] != a[j]){
            cout << "not palindrome";
            break;
        }
        i++;
        j--;
    }
}
int main(){
    char a[] = "maDag";
    char b[] = "madam";
    palindrome(a);
    // stringMatch(a,b);
    // findDuplicatesHash(a);
    // findDuplicates(a);
    // char n[10] = {'j','o','h','n','\0'};
    // char n[] = {'j','o','h','n','\0'};
    // char n[] = "vowel               this     consonant";
    /*
    // this is a *string literal* and it is not *MUTABLE*
    // char *n = "john";
    */
    // printf("%s",n);
    // cout << StringLen(n);
    // changeCase(n);
    // struct Count c = vcCount(n);
    // cout << c.consonant << endl;
    // cout << c.vowel;

    // int res = validCheck(n);
    // if(res == 1)cout << "valid";
    // else cout << "invalid";
    // StringReverse(n);
    // cout << countWords(n);
    // printf("%s",n);
    return 0;
}
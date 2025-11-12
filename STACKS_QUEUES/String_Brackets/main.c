/***************
A string S consisting of N characters is considered to be properly nested if any of the following conditions is true:

S is empty;
S has the form "(U)" or "[U]" or "{U}" where U is a properly nested string;
S has the form "VW" where V and W are properly nested strings.
For example, the string "{[()()]}" is properly nested but "([)()]" is not.

Write a function:

int solution(char *S);

that, given a string S consisting of N characters, returns 1 if S is properly nested and 0 otherwise.

For example, given S = "{[()()]}", the function should return 1 and given S = "([)()]", the function should return 0, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..200,000];
string S is made only of the following characters: '(', '{', '[', ']', '}' and/or ')'.

*************************/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int solution(char *S) 
{

    int N = strlen(S);

    bool status = false;

    if (N == 0) 
    {
        status = true;  // Empty string is properly nested
    }

    else if(N!=0) 
    {     
        if( (strchr(S,'{') != NULL ) ||  (strchr(S,'[') != NULL ) ||  (strchr(S,'(') != NULL ) )
        {   
            if( (strchr(S,'}') != NULL ) ||  (strchr(S,']') != NULL ) ||  (strchr(S,')') != NULL ) )
            {
                
                status = true;        
            }
            else if( (strchr(S,'}') == NULL ) ||  (strchr(S,']') == NULL ) ||  (strchr(S,')') == NULL ))
            {
                status = false;
            }
        }
        else if ((strchr(S,'{') == NULL ) ||  (strchr(S,'[') == NULL ) ||  (strchr(S,'(') == NULL ))
        {
            status = false;
        }
    }
    return status;
}


int main() 
{
    printf("%d\n", solution("{[()()]}")); // 1
    printf("%d\n", solution("([)()]"));   // 0
    printf("%d\n", solution(""));         // 1
    printf("%d\n", solution("()[]{}"));   // 1
    printf("%d\n", solution("((("));      // 0
    printf("%d\n", solution("{[(])}"));   // 0
    return 0;
}

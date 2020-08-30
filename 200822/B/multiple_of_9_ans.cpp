#include <stdio.h>
#include <string.h>
char s[200010];

int main(){
  scanf("%s", s);
  int len = strlen(s);
  int sum = 0;
  for(int i = 0; i < len; i++) sum += s[i] - '0';
  if(sum % 9 == 0) {
    puts("Yes");
  } else {
    puts("No");
  }

}

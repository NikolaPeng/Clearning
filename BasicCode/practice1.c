#include <stdio.h>
//有1、2、3、4个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？

void printNum(int a[4]){
    int count = 0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(i==j){
                continue;
            }
            for(int k=0;k<4;k++){
                if(i==k||j==k){
                    continue;
                }
                printf("%d, ",(a[i]*100+a[j]*10)+a[k]);
                count++;
            }
        }
    }
    printf("\n");
    printf("%d\n",count);
}
int main(void){
    int var[] = {1,2,3,4};
    printNum(var);
    return 0;
}
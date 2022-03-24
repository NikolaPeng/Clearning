//串，又称字符串。是由0个或多个字符组成的有限序列
//子串、主串
//赋值；复制；判空；求串长；清空；销毁；串连接；求子串；定位；比较
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define Max 10
//1-串的顺序存储
//1-1静态数组实现
typedef struct str1{
    char ch[Max];
    int length;
}SString;
//1-2动态数组实现
typedef struct str2{
    char *data;
    int length;
}HString;

//2-串的链式存储
typedef struct StringNode{
    char data;
    struct StringNode *next;
}String;

//3-串的基于顺序存储的基本操作
//这里以动态数组实现的为例

//初始化串
void InitHString(HString *str){
    str->data = (char *)malloc(sizeof(char));
    str->length = 0;
    for(int i=0;i<Max;i++){
        str->data[i] = '0';
    }
}
//赋值操作
bool strAssign(HString *str,char *t){
    int len = strlen(t);
    if(str==NULL||len==0)
        return false;
    for(int i=0;i<len;i++){
        str->data[i] = t[i];
    }
    str->length = len;
    return true;
}
//复制操作
bool copyString(HString *str,HString t){
    if(str==NULL)
        return false;
    str->data = t.data;
    str->length = t.length;
    return true;
}
//判空
bool StrIsEmpty(HString *str){
    if(str->length == 0)
        return true;
    else
        return false;
}
//打印
void PrintString(HString *S){
    if(S==NULL)
        return;
    char *t = (char *)malloc(sizeof(char));
    for(int i=0;i<S->length;i++){
        t[i] = S->data[i];
    }
    printf("%s\n",t);
}
//求串长
int StrLen(HString *S){
    return S->length;
}
//清空
void ClearString(HString *S){
    S = NULL;
}
//销毁
void DeleteString(HString *S){
    free(S);
}
//串连接
bool Concat(HString *S,char *m,char *n){
    if(S==NULL)
        return false;
    int len_m = strlen(m);
    int len_n = strlen(n);
    for(int i=0;i<len_m;i++)
        S->data[i]=m[i];
    for(int j=0;j<len_n;j++)
            S->data[len_m+j]=n[j];
    S->length =len_n + len_m;
    return true;
}
//求子串
void SubString(HString *Sub,HString S,int pos,int len){
    if(S.length==0||pos<0||pos>S.length||len>S.length||pos+len>S.length){
        return;
    }
    for(int i=0;i<len;i++){
        Sub->data[i] = S.data[pos+i];
    }
    Sub->length = len;
}
//比较
int StrCompare(HString S,HString T){
    for(int i=0;i<S.length&&i<T.length;i++){
        if(S.data[i]!=T.data[i]){
            return S.data[i]-T.data[i];
        }
    }
    return S.length-T.length;
}
//定位
int StrIndex(HString S, HString t){
    HString substr;
    InitHString(&substr);
    for(int i=0;i<S.length-t.length+1;i++){
        SubString(&substr,S,i,t.length);
        if(StrCompare(substr,t)==0){
            return i;
        }
    }
    return -1;
}
//测试代码：
int main(void){
    HString S,T,P,Q,X,Y,Z,substr;
	InitHString(&S);
	InitHString(&T);
	InitHString(&X);
	InitHString(&Y);
	InitHString(&Z);
	InitHString(&P);
	InitHString(&Q);
	InitHString(&substr);

	//赋值操作
	strAssign(&S,"Hello World!");
	printf("输出赋值操作字符串:");
    PrintString(&S);

    //判断串是否为空
    printf("串S是否为空:%d\n",StrIsEmpty(&S)); 
    printf("串T是否为空:%d\n",StrIsEmpty(&T)); 

    //获取串的长度
    printf("串S的长度:%d\n",StrLen(&S)); 
    printf("串T的长度:%d\n",StrLen(&T)); 

	strAssign(&S,"Stay Young!");
	//复制操作
	copyString(&T,S);
	printf("输出复制赋值操作字符串:");
	PrintString(&T);

    //清空操作
    ClearString(&S);
    printf("清空操作后串S是否为空:%d\n",StrIsEmpty(&S)); 
     
    //串连接
    Concat(&Z,"Keep","Moving!");
	printf("输出串连接操作字符串:");
    PrintString(&Z);

	//求子串
	SubString(&substr,S,5,5);
    printf("截取的字符串:");
    PrintString(&S);
	printf("SubString(&substr,S,5,5)=");
	PrintString(&substr);

	//比较操作
	strAssign(&X,"abstraction");
	strAssign(&Y,"abstract");
    int result=StrCompare(X,Y);
	printf("StrCompare(X,Y)=%d\n",result);


	//定位操作
	strAssign(&P,"wangdao");
	strAssign(&Q,"dao");
	printf("P:wangdao,Q:dao\n");
    int result_index=StrIndex(P,Q);
    printf("StrIndex(P,Q)=%d\n",result_index);
    return 0;
}
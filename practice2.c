#include <stdio.h>
/*企业发放的奖金根据利润提成。
    利润(I)低于或等于10万元时，奖金可提10%；
    利润高于10万元，低于20万元时，低于10万元的部分按10%提成，高于10万元的部分，可提成7.5%；
    20万到40万之间时，高于20万元的部分，可提成5%；
    40万到60万之间时高于40万元的部分，可提成3%；
    60万到100万之间时，高于60万元的部分，可提成1.5%；
    高于100万元时，超过100万元的部分按1%提成。
从键盘输入当月利润I，求应发放奖金总数？
*/
double bonus(double I){
    double sum=0;
    if(I<=0){
        printf("错误的数据\n");
    }else if(I<=10&&I>0){
        sum = I*0.1;
    }else if(I>10&&I<=20){
        sum = 10*0.1+(I-10)*0.075;
    }else if(I>20&&I<=40){
        sum = 10*0.1+10*0.075+(I-20)*0.05;
    }else if(I>40&&I<=60){
        sum = 10*0.1+10*0.075+20*0.05+(I-40)*0.03;
    }else if(I>60&&I<=100){
        sum =10*0.1+10*0.075+20*0.05+20*0.03+(I-60)*0.015; 
    }else{
        sum =10*0.1+10*0.075+20*0.05+20*0.03+40*0.015+(I-100)*0.01;  
    }
    return sum;
}
int main(void){
    double I = 10;
    double money = bonus(I);
    printf("%.2f",money); 
}
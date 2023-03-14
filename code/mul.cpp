#include <iostream>
#include <string>
#include <string.h>
using namespace std;

//判断输入是否合法（数字及负号）
bool numJudge(string str) {
    char str_to_char [str.length()];
    strcpy(str_to_char, str.c_str());
    for(int i = 0; i<sizeof str_to_char; i++) {
        if ((str_to_char[i]<48||str_to_char[i]>57)&&str_to_char[i]!='-') {
            return 0;
        }
    }
    return 1;
}

//计算结果并且输出
void calculate(string num1, string num2) {
    //初始化乘数和积的数组
    bool zero_judge;
    int num1_int [num1.length()];
    int num2_int [num2.length()];
    int result [num1.length()+num2.length()];
    for(int i = 0; i < num1.length()+num2.length(); i++){
        result[i]=0;
    } 
    //录入乘数的值(注意负号的干扰))
    for(int i=0; i<num1.length(); i++){
        if(i==0&&num1.substr(0,1)=="-"){
            continue;
        }
        num1_int[i] = atoi(num1.substr(i,1).c_str());
    }
    for(int i=0; i<num2.length(); i++){
        if(i==0&&num2.substr(0,1)=="-"){
            continue;
        }
        num2_int[i] = atoi(num2.substr(i,1).c_str());
    }
    
    //矩阵乘法
    for ( int i = num1.length()-1; i >= 0; i-- ) {
        for( int j = num2.length()-1; j >= 0; j-- ) {
            result[i+j+1] += num1_int[i]*num2_int[j];
        }
    }
    //十进制进位
    for(int i=num1.length()+num2.length()-1; i>0; i--){
        if( result[i] >= 10 ) {
            result[i-1] += result[i]/10;
            result[i] = result[i] % 10;
        }
    }

    //打印表达式
    cout << num1 << " * " << num2 << " = ";
    //打印正负号
    if((num1.substr(0,1)!="-"&&num2.substr(0,1)=="-")||(num1.substr(0,1)=="-"&&num2.substr(0,1)!="-")){
        cout << "-" ;
    }
    //打印结果的绝对值（删除多余的零）
    zero_judge = result[0];
    for(int i = 0; i < num1.length()+num2.length(); i++){
        if(!zero_judge){
            zero_judge=result[i+1];
            continue;
        }
        cout << result[i] ;
    } 
    cout << endl;
}

int main(int argc, char* argv[]) {
    string in1_string;
    string in2_string;
    //string格式的输入值

    //命令行参数输入
    if (argc == 3) {
        in1_string = argv[1];
        in2_string = argv[2];
        if(numJudge(in1_string)&&numJudge(in2_string)) {
            calculate(in1_string, in2_string);
            return 0;
        }
    }
    
    //循环判断输入直到输入值合法并计算
    do{
        cout << "Please  input two integers" <<endl;
        cin >> in1_string;
        cin >> in2_string;
        if (numJudge(in1_string)&&numJudge(in2_string)) {
            calculate(in1_string, in2_string);
            return 0;
        }
    }while (true);
}

#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
using namespace std;

//判断是否为负数：true为负数，false为正数
bool if_neg(string test_str){
    //分割出每个字符
    int len_str=test_str.length();
    char test_char [test_str.length()];
    strcpy(test_char, test_str.c_str());

    bool if_neg=false;
    int start=0;
    if(test_char[0]=='-') if_neg=true;   
 
    return if_neg;  
}

//判断输入类型：false为非法，true为合法
bool judge(string& test_str){

    //引入合法判断,true代表非法
    bool judge=false;

    //分割出每个字符
    int len_str=test_str.length();
    char test_char [test_str.length()];
    strcpy(test_char, test_str.c_str());
    //char test_char[len_str]=test_str.split("");

    //test:
    // for(int i=0;i<len_str;i++){
    //     cout << test_char[i] << " ";
    // }

    //判断是否为负数，如果是，检查从第二位开始
    int start=0;
    if(test_char[0]=='-') start=1;
    else start=0;   

    //test:
    //cout << start << endl;

    int len_char=sizeof(test_char);

    //引入判断是否为小数点
    bool expect_dot=true;

    //引入判断是否为e
    bool expect_e=true;

    //引入判断是否为负号，默认false
    bool expect_neg=false;

    //判断每一位是否为数字、小数点、e
    for(int i=start;i<len_char;i++){
        //test_char[i]=getchar();
        
        //test:
        //cout << test_char[i] << " ";

        if(isdigit(test_char[i])){
            //判断数字
            
            //test:
            //cout << "correct" << " ";
        }else if((test_char[i]=='.')&&(expect_dot)){
            //判断小数点
            expect_dot=false;

            //test:
            //cout << "correct" << " ";
            
        }else if((test_char[i]=='e')&&(expect_e)){
            //判断科学计数法

            expect_dot=false;
            expect_e=false;

            //判断e之后是否为负号
            if((test_char[i+1]!='-')) expect_neg=false;
            else expect_neg=true;

            //test:
            //cout << "correct" << " ";
        }else if((test_char[i]=='-')&&(expect_neg)){
            //判断科学计数负数
            expect_neg=false;

            //test
            //cout << "correct" << " ";
        }else{
            return true;

            //test:
            //cout << "error" << " ";
        }
    }

    //test:
    //cout << "judge:" << judge << " ";
    //cout << "if_neg:" << if_neg;

    return false;
}

double cal_mul(double a, double b){
	double result = a * b;
    return result;
}

int main(){
    string a_input="";
    string b_input="";

    cout << "input a:" <<endl;
    cin >> a_input;
    cout << "input b:" <<endl;
    cin >> b_input; 
    cout << "result:" << endl;

    bool judge_a=judge(a_input);
    bool judge_b=judge(b_input);

    //test:
    //cout << "judge_a: " << judge_a << endl;
    //cout << "judge_b: " << judge_b << endl;

    //if_error为false，输入不合法
    bool if_error = judge(a_input) || judge(b_input);

    //test:
    //cout << "if_error: " << if_error << endl;

    if(if_error){
        cout << "error" << endl;
        return 0;
    }

    //初始化数字变量
    double a_double=stod(a_input);
    double b_double=stod(b_input);

    cout << cal_mul(a_double,b_double) << endl;

    return 0;
}
#include <iostream>
#include <typeinfo>
#include <stdio.h>
#include <string>
#include <cctype>
#include <iomanip>
#include <ctype.h>
#include <sstream>
using namespace std;

int main(){
    string a="3.1315";
    string b="2.0e-2";

    cout << "mul" << endl;

    cout << "input a:" << endl;
    cin >> a;


    // int len_a = a.length();     	    //获得字符串长度
	// for (int i = 0; i < len_a; i++) //使用for循环遍历整个字符串
	// {
	// 	if (!isdigit(a[i]))  		//使用isdigit()函数进行判断
	// 	{
	// 		cout << "error" << endl;
    //         exit(1);
	// 	}
	// }
        
    cout << "input b:" << endl;
    cin >> b;

    // int len_b = b.length();     	    //获得字符串长度
	//     for (int i = 0; i < len_b; i++) //使用for循环遍历整个字符串
	//     {
	//     	if (!isdigit(b[i]))  		//使用isdigit()函数进行判断
	//     	{
	// 		cout << "error" << endl;
    //             exit(1);
	//     	}
	// }

    stringstream geek_a(a);
    float a_float=0;
    geek_a >> a_float;

    stringstream geek_b(b);
    float b_float=0;
    geek_b >> b_float;

    float res=a_float * b_float;

    cout << "result:" << res << endl;


    // bool if_error=(typeid(a) == typeid(char))
    //             ||(typeid(b) == typeid(char))
    //             ||(typeid(a) == typeid(string))
    //             ||(typeid(b) == typeid(string));

    // if(if_error){
    //     //type res= static_cast<type>(error);
    //     //res=std::to_string(res);
    //     //res=error;

    //     cout << "error" << endl;
    // }else{
    //     //cout << a << endl;
    //     //cout << b << endl;
    //     //cout << res << endl;
    // }
    return 0;
}

//题目内容：编写一个算命程序，可以预测前世（本题内容纯属虚构）
//算命方法：
//将某人的出生年月日加起来,如果结果不是一位数，就再相加,
//如果相加之后还是一位数以上的话，就再相加，直到变成一位数.
//例如：1994 年3 月20 日出生的人
//1+9+9+4+0+3+2+0=28
//28>9：需再计算2+8=10
//10>9：需再计算1+0=1
//请在/********program********/与/********end********/处将代码补充完整


#include<iostream>
using namespace std;
/********program********/

int fortune(int iInput){
    int iResult=-1;
    int iNumber1[8]={0};
    for (int i = 0; iInput>0; ++i) {
        iNumber1[i]=iInput%10;
        iInput/=10;
    }
    int iResult1=0;
    for (int i = 0; i < 8; ++i) {
        iResult1+=iNumber1[i];
    }

    int iNumber2[2];
    if (iResult1>9) {
        for (int i = 0; iResult1 > 0; ++i) {
            iNumber2[i] = iResult1 % 10;
            iResult1 /= 10;
        }
    }
    else{
        iResult=iResult1;
        return iResult;
    }


    int iResult2=0;
    for (int i = 0; i < 2; ++i) {
        iResult2+=iNumber2[i];
    }

    int iNumber3[2];
    if (iResult2>9) {
        for (int i = 0; iResult2 > 0; ++i) {
            iNumber3[i] = iResult2 % 10;
            iResult2 /= 10;
        }
    }
    else{
        iResult=iResult2;
        return iResult;
    }

    int iResult3=0;
    for (int i = 0; i < 2; ++i) {
        iResult3+=iNumber3[i];
    }

    iResult=iResult3;

    return iResult;
}
/********end********/
int main()
{
    int birthday,s;
    char d[][40]={ "1你上辈子是神仙",
                   "2你上辈子是皇帝或国王","3你上辈子是贵族",
                   "4你上辈子是读书人","5你上辈子是有钱人",
                   "6你上辈子是穷人","7你上辈子是非人类",
                   "8你上辈子是演员","9你上辈子是出家人"};
    cin>>birthday;
    s=fortune(birthday);
    cout<<d[s-1]<<endl;
    return 0;
}

/*
输入格式：八位整数表示的生日
        输出格式：算出来的命运对应的输出
        输入样例：19940320
输出样例：1你上辈子是神仙
 */
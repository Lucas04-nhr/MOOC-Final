
//题目内容：
//输入一段英文句子（不包含标点符号），求期中最短的一个单词（如果有多个最短单词，以最左边的为准），并输出该单词。
//请在/********program********/与/********end********/处将代码补充完整

#include <iostream>
using namespace std;
/********program********/
#include <cstring>

bool isEnglishChar(char c);
char shortest(char s[],char* answer);

//判断字符是不是英文字符
bool isEnglishChar(char c)
{
    if((c >= 'a' && c <= 'z' ) || (c >= 'A' && c <= 'Z'))
        return true;
    else return false;
}
//查找每个单词，返回最长的
//算法：重复查找，如果英文字符不断增加1，否则如果遇到一个非英文字符，然后
//判断他是不是最长。

char shortest(char s[],char* answer)
{
    int len = strlen(s);
    char shortestWord[100], tempWord[100];
    int longestLen = 9999, tempLen = 0;
    for(int i = 0 ; i <= len ; i ++)
    {
        if(isEnglishChar(s[i])) //英文字符
        {
            tempWord[tempLen] = s[i];
            tempLen ++;
        }
        else //非英文字符
        {
            if(tempLen != 0)
            {
                if(tempLen < longestLen)
                {
                    longestLen = tempLen;
                    tempWord[tempLen] = '\0';
                    //shortestWord = tempWord;(错误)
                    strcpy(shortestWord, tempWord);
                }
                tempLen = 0;
            }
        }
    }

    cout << shortestWord << endl;
}/********end********/

int main()
{
    char c1[1000];
    char c2[100];
    cin.getline(c1,1000);
    shortest(c1,c2);
    return 0;
}

/*
    输入格式：
    一段英文句子
    输出格式：
    英文句子中的最长单词
    输入样例：
    A Grain of Sand William Blake
    输出样例：
    A
 */


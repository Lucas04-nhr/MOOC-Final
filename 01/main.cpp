//题目内容：在二维数组中寻找鞍点，鞍点是指在所在行最大，在所在列最小的元素，
// 请在/********program********/与/********end********/处将代码补充完整

#include<iostream>
using namespace std;

int main()
{
    int i,j,a[5][5];
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            cin>>a[i][j];

/********program********/
    int iMax[5]={0};
    int iColumn[5]={0};
    for (int l = 0; l < 5; ++l){
        for (int k = 0; k < 5; ++k)
            if (iMax[l] <= a[l][k]) {
                iMax[l] = a[l][k];
                iColumn[l] = k;
            }

    }

    int iFlag[5]= {0};
    for (int k = 0; k < 5; ++k) {
        for (int l = 0; l < 5; ++l)
            if (iMax[k] > a[l][iColumn[k]])
                iFlag[k]++;

    }

    int iTemp=0;
    for (int k = 0; k < 5; ++k)
        if (iFlag[k] == 0) {
            cout << k + 1 << ' ' << iColumn[k] + 1 << ' ' << iMax[k] << endl;
            iTemp++;
        }

    if (iTemp == 0)
        cout<<"-1"<<endl;


    /********end********/
    return 0;
}


/*
    输入格式：二维数组的所有元素
    输出格式：如果存在鞍点，则输出行号，列号和元素值（中间留一个空格），如果不存在鞍点，输出-1
    输入样例：

    11  3   5   6   9
    12  4   7   8   10
    10  5   6   9   11
    8   6   4   7   2
    15  10  11  20  25

    输出样例：
    4 1 8
 */
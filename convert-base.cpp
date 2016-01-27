//Function to convert from one base to another

#include<iostream>
#include<cmath>

using namespace std;

bool isDigit(char num)
{
    bool ret = false;
    if(num >= 48 && num <= 57)
    {
        ret = true;
    }
    if(num >= 'A' && num <= 'F')
    {
    	ret = true;
    }
    return ret;
}

int toDigit(char num)
{
    int ret = -1;
    if(num >= 48 && num <= 57)
    {
        ret = num - 48;
    }
    if(num >= 'A' && num <= 'F')
    {
    	ret = 10 + (num - 'A');
    }
    return ret;
}

int convertTo( char * input , int length, int currentBase , int toBase)
{
    int res = 0;
    int i = 0;
    for(int idx = length-1; idx >=0 ; idx--)
    {
        //if (currentBase <= toBase)
        {
           if(isDigit(input[idx]))
           {
               int val = toDigit(input[idx]);
               res += (val * pow(currentBase,i));
               ++i;
           }
        }
    }
    return res;
}

int main(int argc, char **argv)
{
    char inp[4] = {'A' ,'B' ,'8'};
    int len = sizeof(inp)/sizeof(inp[0]);
    int num = convertTo(inp ,len ,16 , 16);
    cout<<num<<endl;
    return 0;
}
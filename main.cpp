#include <iostream>
#include <fstream>

using namespace std;

bool IsKeyword(string s)
{
    if(s=="auto"||"double"||"int"||"struct"||"break"||"else"||"long"||"switch"||"case"||"enum"||"register"||"typedef"||"char"||"extern"||"return"||"union"||"const"||"float"||"short"||"unsigned"||"continue"||"for"||"signed"||"void"||"default"||"goto"||"sizeof"||"volatile"||"do"||"if"||"static"||"while")
    {
        return true;
    }
    else return false;
}

bool IsIdentifier(string s)
{
    int flag=1;
    for(int i=0; i<s.size(); i++)
    {
        if((int)s[i]>=65 && (int)s[i]<=90 && (int)s[i]>=97 && (int)s[i]<=122 && (int)s[i]>=49 && (int)s[i]<=57 && (int)s[i]==95 && (int)s[0]<49 && (int)s[0]>57 && s[i]!= ' ' && s.size()<32) flag=0;
        else
        {
            flag=1;
            break;
        }

        if(flag==0) return true;
        else if(flag==1) return false;
    }
}

bool IsIntConstant(string s)
{
    int flag=0;
    for(int i=0; i<s.size(); i++)
    {
        if((int)s[i]>=48 && (int)s[i]<=57) flag=1;
        else
        {
            flag=0;
            break;
        }
        if(flag==1) return true;
        else if(flag==0) return false;
    }

}

bool IsFloatConstant(string s)
{
    int flag=0, decimalFlag=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='.') decimalFlag=decimalFlag+1;
        if((int)s[i]>=48 && (int)s[i]<=57) flag=1;
        else
        {
            flag=0;
            break;
        }
        if(flag==1 && decimalFlag==1) return true;
        else if(flag==0) return false;
    }
}

bool IsCharConstant(string s)
{
    int flag=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[0]=='\'' && s[s.size()-1]=='\'' && (int)s[i]>=48 && (int)s[i]<=57 && (int)s[i]>=65 && (int)s[i]<=90 && (int)s[i]>=97 && (int)s[i]<=122) flag=1;
        else
        {
            flag=0;
            break;
        }
        if(flag==1 && (s.size()==3 ||s.size()==2)) return true;
        else if(flag==0) return false;
    }
}

bool IsStringConstant(string s)
{
    int flag=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[0]=='\"' && s[s.size()-1]=='\"' && (int)s[i]>=48 && (int)s[i]<=57 && (int)s[i]>=65 && (int)s[i]<=90 && (int)s[i]>=97 && (int)s[i]<=122) flag=1;
        else
        {
            flag=0;
            break;
        }
        if(flag==1 && s.size()>=2) return true;
        else if(flag==0) return false;
    }
}

bool IsString(string s)
{

}

bool IsSpecialSymbol(string s)
{
    if(s=="[","]","{","}","(",")",",",";","*","#") return true;
    else return false;
}

bool IsOperator(string s)
{
    if(s=="<",">",">=","<=","==","+","-","*","/","%","=","++","--","+=","-=","*=","/=","%=","&&","||") return true;
    else return false;
}

int main()
{
    ifstream ifile;
    ifile.open("writtenCode");

    string word="";

    char ch;
    ifile.get(ch);
    while(!ifile.eof())
    {
        if(ch==' ')
        {
            if(IsKeyword(word)==true) cout << "Keyword" << endl;
            else if(IsIdentifier(word)==true) cout << "Identifier" << endl;
            else if(IsIntConstant(word)==true) cout << "IntegerConstant" << endl;
            else if(IsFloatConstant(word)==true) cout << "FloatConstant" << endl;
            else if(IsCharConstant(word)==true) cout << "CharacterConstant" << endl;
            //else if(IsStringConstant(word)==true) cout << "String" << endl;
            else if(IsSpecialSymbol(word)==true) cout << "SpecialSymbol" << endl;
            else if(IsOperator(word)==true) cout << "Operator" << endl;
            else cout << "----------Error----------" << endl;

            word = "";
        }
        else word = word + ch;

        ifile.get(ch);
    }

    return 0;
}

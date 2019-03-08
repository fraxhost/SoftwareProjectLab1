#include <iostream>
#include <fstream>

using namespace std;

//bool var_decl(string)
//{
//
//}

bool bool_literal(string s)
{
    if(s=="true" || s=="false") return true;
    else return false;
}

bool int_literal(string s)
{
    bool flag=false;

    for(int i=0; i<s.size(); i++)
    {
        if(s[i]>='0' && s[i]<='9') flag=true;
        else
        {
            flag=false;
            break;
        }
    }

    if(flag==true) return true;
    else return false;

}

bool float_literal(string s)
{
    int flag1=0, flag2=0;

    for(int i=0; i<s.size(); i++)
    {
        if((s[i]>='0' && s[i]<='9') || s[i]=='.') flag1=1;
        else
        {
            flag1=0;
            break;
        }
        if(s[i]=='.') flag2++;
    }

    if(flag1==1 && flag2==1) return true;
}

bool type_spec(string s)
{
    if(s=="void" || s=="bool" || s=="int" || s=="float") return true;
}

bool ident(string s)
{
    bool flag=false;

    if((s[0]>='0' && s[0]<='9'))
    {
        return false;
    }

    for(int i=0; i<s.size(); i++)
    {
        if(((s[i]>='A' && s[i]<='Z')||(s[i]>='a' && s[i]<='z')||s[i]=='_'||(s[i]>='0' && s[i]<='9')))
        {
            flag = true;
        }
        else
        {
            flag = false;
            break;
        }
    }

    if(flag==true) return true;
    else return false;

}

int main()
{
    char ch;
    string s="";
    ifstream ifile;
    ofstream ofile;
    ifile.open("myCode.txt");
    ofile.open("LexedCode.txt");

    if(ifile.is_open())
    {
        cout << "File has been opened" << endl;
        ifile.get(ch);

        //finding type_spec
//        while(!ifile.eof())
//        {
//            if(ch==' ' || ch=='\t' || ch=='\n')
//            {
//                if(type_spec(s)==true)
//                {
//                    ofile << "type_spec" << ch;
//                    s = "";
//                }
//                else
//                {
//                    ofile << s << ch;
//                    s = "";
//                }
//            }
//            else s = s + ch;
//
//            ifile.get(ch);
//        }
//        if(ch!=' ' || ch!='\t' || ch!='\n') ofile << ch;

        //finding identifier
//        while(!ifile.eof())
//        {
//            if(ch==',' || ch==';' || ch==' ' || ch=='\n' || ch=='\t' || ch==')')
//            {
//                if(ident(s)==true)
//                {
//                    ofile << "ident" << ch;
//                    s = "";
//                }
//                else
//                {
//                    ofile << s << ch;
//                    s = "";
//                }
//            }
//            else s = s + ch;
//
//            ifile.get(ch);
//        }
//        if(ch!=' ' || ch!='\t' || ch!='\n') ofile << ch;

        //combining type_spec and identifier
        while(!ifile.eof())
        {
            if(ch==',' || ch==';' || ch==' ' || ch=='\n' || ch=='\t' || ch==')')
            {
                if(type_spec(s)==true)
                {
                    ofile << "type_spec" << ch;
                    s = "";
                }
                else if(bool_literal(s)==true)
                {
                    ofile << "bool_literal" << ch;
                    s = "";
                }
                else if(float_literal(s)==true)
                {
                    ofile << "float_literal" << ch;
                    s = "";
                }
                else if(int_literal(s)==true)
                {
                    ofile << "int_literal" << ch;
                    s = "";
                }
                else if(ident(s)==true)
                {
                    ofile << "ident" << ch;
                    s = "";
                }
                else
                {
                    ofile << s << ch;
                    s = "";
                }
            }
            else s = s + ch;

            ifile.get(ch);
        }
        if(ch!=' ' || ch!='\t' || ch!='\n') ofile << ch;

    }
    else cout << "File did not open" << endl;


    return 0;
}

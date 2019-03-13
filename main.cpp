#include <iostream>
#include <fstream>

using namespace std;

//bool var_decl(string s1, string s2)
//{
//    if(s1=="type_spec" && s2=="ident")
//}

//bool expr()
//{
//    if(s1=="bool_literal" || s2=="int_literal" || s3=="float_literal")
//    if(s1=="ident" || s2=="=" || s3==expr())
//
//}

string operators(string s)
{
    if(s=="||") return "OR";
    else if(s=="==") return "EQ";
    else if(s=="!=") return "NE";
    else if(s=="<=") return "LE";
    else if(s==">=") return "GE";
    else if(s=="<") return "<";
    else if(s==">") return ">";
    else if(s=="&&") return "AND";
    else if(s=="+") return "+";
    else if(s=="-") return "-";
    else if(s=="*") return "*";
    else if(s=="/") return "/";
    else if(s=="%") return "%";
    else if(s=="!") return "!";
    else return "false";
}

bool primary_exp(string s)
{
    if(s=="bool_literal" || s=="int_literal" || s=="float_literal") return true;
    else return false;
}

bool ret(string s)
{
    if(s=="return") return true;
}

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

    if(s=="return") return false;

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
    ofile.open("LexedCode1.txt");

    if(ifile.is_open())
    {
        cout << "LexedCode1 has been opened" << endl;

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

        //operators
//        string w="";
//        ifile.get(ch);
//        while(!ifile.eof())
//        {
//            w = ch;
//            if(operators(w)!="false") ofile << operators(w);
//            ifile.get(ch);
//            if(ifile.eof()) break;
//            w = w+ch;
//            if(operators(w)!="false") ofile << operators(w);
//        }

//        ifile.open("LexedCode1.txt");
//        ofile.open("LexedCode2.txt");

        //combining type_spec and identifier
        int prev_ch='?';
        ifile.get(ch);
        while(!ifile.eof())
        {
            if((prev_ch==' ' && ch==' ')||(prev_ch=='\t' && ch=='\t')||(prev_ch=='\n' && ch=='\n'))
            {
                prev_ch = ch;
                ifile.get(ch);
                continue;
            }

            if(ch==',' || ch==';' || ch==' ' || ch=='\n' || ch=='\t' || ch=='=' || ch=='('|| ch==')')
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

            prev_ch  = ch;
            ifile.get(ch);
        }
        if(ch!=' ' || ch!='\t' || ch!='\n') ofile << ch;

    }
    else cout << "File did not open" << endl;

    ifile.close();
    ofile.close();

    ifile.open("LexedCode1.txt");
    ofile.open("LexedCode2.txt");

    if(ifile.is_open())
    {
        cout << "LexedCode2 has been opened" << endl;

        string word="";
        char ch='?';
        ifile.get(ch);

        while(!ifile.eof())
        {

            if(ch==',' || ch==';' || ch==' ' || ch=='\n' || ch=='\t' || ch==')' || ch=='=' || ch=='('|| ch==')')
            {
                if(primary_exp(word)==true)
                {
                    ofile << "expr" << ch;
                    word="";
                }
                else
                {
                    ofile << word << ch;
                    word="";
                }
            }
            else word=word+ch;

            ifile.get(ch);
        }
        if(ch!=' ' || ch!='\t' || ch!='\n') ofile << ch;
    }
    else cout << "LexedCode2 has not opened" << endl;

    ifile.close();
    ofile.close();

    ifile.open("LexedCode2.txt");
    ofile.open("LexedCode3.txt");

    if(ifile.is_open())
    {
        cout << "LexedCode3 has been opened" << endl;

        char prev_ch='?';
        char ch='?';
        ifile.get(ch);

        while(!ifile.eof())
        {
            if(ch=='='||ch=='('||ch==')'||ch==';')
            {
                if(prev_ch!=' ') ofile << " ";
            }
            if(prev_ch=='='||prev_ch=='('||prev_ch==')'|| prev_ch==';')
            {
                if(ch!=' ') ofile << " ";
            }

            ofile << ch;

            prev_ch=ch;
            ifile.get(ch);
        }
    }
    else cout << "LexedCode2 has not opened" << endl;

    ifile.close();
    ofile.close();

//    ifile.open("LexedCode3.txt");
//    ofile.open("LexedCode4.txt");
//
//    string s='?';
//    string words="";
//
//    if(ifile.is_open())
//    {
//        cout << "LexedCode4 has been opened" << endl;
//
//        ifile >> s;
//        while(!ifile.eof())
//        {
//            if(s==';' || s=='{' || s=='}'|| s=='(' || s==')')
//            {
//                if(word=="return ;" || word=="return expr") ofile << return_stmt;
//                else
//                {
//                    ofile << word << ch;
//                }
//            }
//            else if() word = word + ch;
//        }
//    }
//    else cout << "LexedCode4 has not opened" << endl;

    return 0;
}

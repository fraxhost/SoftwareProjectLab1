#include <iostream>
#include <fstream>

using namespace std;

int if_else(string s)
{
    if(s=="if") return 11;
    else if(s=="else") return 22;
}

bool ret(string s)
{
    if(s=="return") return true;
}

bool BREAK(string s)
{
    if(s=="break") return true;
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
    int tokenCount=0;
    string s="";
    ifstream ifile;
    ofstream ofile;
    ifile.open("1.txt");
    ofile.open("Lexing.txt");

    if(ifile.is_open())
    {
        cout << "Lexing has been opened" << endl;

        int string_flag=-1;
        char prev_ch='?';
        ifile.get(ch);

        while(true)
        {
            if(ch=='\n'||ch=='\t'||ch==' ')
            {
                if(type_spec(s)==true)
                {
                    ofile << s << " type_spec" << endl;
                    s = "";
                    tokenCount++;
                    ifile.get(ch);
                    break;
                }

                if(s[0]=='#' && s[s.size()-1]=='>')
                {
                    ofile << s << " header_file" << endl;
                    tokenCount++;
                }

                s="";
            }
            else
            {
                if(ch=='#') s=s+(char)35;
                else s=s+ch;
            }

            ifile.get(ch);
        }

        while(!ifile.eof())
        {
            if(ch==',' || ch==';' || ch==' ' || ch=='=' || ch=='\n' || ch=='\t' || ch=='('|| ch==')' || ch=='{'|| ch=='}'|| ch=='"'|| ch==']'|| ch=='['|| ch=='+'|| ch=='-'|| ch=='*'|| ch=='/'|| ch=='%'|| ch=='!'|| ch=='<'|| ch=='>')
            {
                if(type_spec(s)==true)
                {
                    ofile << s << " type_spec" << endl;
                    s = "";
                    tokenCount++;
                }
                else if(BREAK(s)==true)
                {
                    ofile << s << " BREAK" << endl;
                    s = "";
                    tokenCount++;
                }
                else if(if_else(s)==11)
                {
                    ofile << s << " IF" << endl;
                    s = "";
                    tokenCount++;
                }
                else if(if_else(s)==22)
                {
                    ofile << s << " ELSE" << endl;
                    s = "";
                    tokenCount++;
                }
                else if(bool_literal(s)==true)
                {
                    ofile << s << " BOOL_LIT" << endl;
                    s = "";
                    tokenCount++;
                }
                else if(float_literal(s)==true)
                {
                    ofile << s << " FLOAT_LIT" << endl;
                    s = "";
                    tokenCount++;
                }
                else if(int_literal(s)==true)
                {
                    ofile << s << " INT_LIT" << endl;
                    s = "";
                    tokenCount++;
                }
                else if(ret(s)==true)
                {
                    ofile << s << " RETURN" << endl;
                    s = "";
                    tokenCount++;
                }
                else if(ident(s)==true)
                {
                    ofile << s << " IDENT" << endl;
                    s = "";
                    tokenCount++;
                }
                if(ch=='"')
                {
                    s=s+'"';
                    prev_ch = ch;
                    ifile.get(ch);

                    while(ch!='"')
                    {
                        s = s+ch;
                        prev_ch = ch;
                        ifile.get(ch);
                    }

                    ofile << s << ch << " STRING_LITERAL" << endl;
                }
                if(ch==';')
                {
                    ofile << ch << " SEMICOLON" << endl;
                    s = "";
                    tokenCount++;
                }
                if(ch==',')
                {
                    ofile << ch << " COMA" << endl;
                    s = "";
                    tokenCount++;
                }
                if(ch=='(')
                {
                    ofile << ch << " FIRST_BRACKET_OPEN" << endl;
                    s = "";
                    tokenCount++;
                }
                if(ch==')')
                {
                    ofile << ch << " FIRST_BRACKET_CLOSE" << endl;
                    s = "";
                    tokenCount++;
                }
                if(ch=='{')
                {
                    ofile << ch << " SECOND_BRACKET_OPEN" << endl;
                    s = "";
                    tokenCount++;
                }
                if(ch=='}')
                {
                    ofile << ch << " SECOND_BRACKET_CLOSE" << endl;
                    s = "";
                    tokenCount++;
                }
                if(ch=='[')
                {
                    ofile << ch << " THIRD_BRACKET_OPEN" << endl;
                    s = "";
                    tokenCount++;
                }
                if(ch==']')
                {
                    ofile << ch << " THIRD_BRACKET_CLOSE" << endl;
                    s = "";
                    tokenCount++;
                }
                if(ch=='+')
                {
                    ofile << ch << " ADD" << endl;
                    s = "";
                    tokenCount++;
                }
                if(ch=='-')
                {
                    ofile << ch << " SUBTRACT" << endl;
                    s = "";
                    tokenCount++;
                }
                if(ch=='*')
                {
                    ofile << ch << " MULTIPLICATION" << endl;
                    s = "";
                    tokenCount++;
                }
                if(ch=='/')
                {
                    ofile << ch << " DIVISION" << endl;
                    s = "";
                    tokenCount++;
                }
                if(ch=='%')
                {
                    ofile << ch << " MODULUS" << endl;
                    s = "";
                    tokenCount++;
                }
                if(ch=='<')
                {
                    ofile << ch << " LESSER" << endl;
                    s = "";
                    tokenCount++;
                }
                if(ch=='>')
                {
                    ofile << ch << " GREATER" << endl;
                    s = "";
                    tokenCount++;
                }
                if(ch=='!')
                {
                    ofile << ch << " NOT" << endl;
                    s = "";
                    tokenCount++;
                }
            }
            else s = s + ch;

            prev_ch = ch;
            ifile.get(ch);

            if(ch=='='&&prev_ch=='=')
            {
                ofile << prev_ch << ch << " " << "EQ" << endl;
                s = "";
                tokenCount++;
            }
            else if(ch=='='&&prev_ch=='!')
            {
                ofile << prev_ch << ch << " " << "NE" << endl;
                s = "";
                tokenCount++;
            }
            else if(ch=='='&&prev_ch=='>')
            {
                ofile << prev_ch << ch << " " << "GE" << endl;
                s = "";
                tokenCount++;
            }
            else if(ch=='='&&prev_ch=='<')
            {
                ofile << prev_ch << ch << " " << "LE" << endl;
                s = "";
                tokenCount++;
            }
            else if(ch!='='&&prev_ch=='=')
            {
                ofile << "= " << "ASSIGNMENT" << endl;
                s = "";
                tokenCount++;
            }

        }

    }
    else cout << "File did not open" << endl;

    cout << tokenCount << endl;

    ifile.close();
    ofile.close();

    return 0;
}

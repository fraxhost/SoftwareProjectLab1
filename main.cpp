#include <iostream>
#include <fstream>

using namespace std;

string *array_typespec;
string *array_identifier;
string *array_boolliteral;
string *array_intliteral;
string *array_floatliteral;

void trim_to_size()

//void enlarge_array_general(int *a_size, string array_general[])
//{
//    int prev_size = *a_size;
//    int new_size = (*a_size)*2;
//    *a_size = new_size;
//
//    cout << "BHUL-1" << endl;
//
//    string *array_new = new string[new_size];
//
//    for(int i=0; i<new_size; i++)
//    {
//        array_new[i] = "0";
//    }
//
//    cout << "BHUL-2" << endl;
//
//    for(int i=0; i<prev_size; i++)
//    {
//        array_new[i]=array_general[i];
//    }
//
//    cout << "BHUL-3" << endl;
//
//    array_general = array_new;
//
//    cout << "BHUL-4" << endl;
//
//}

void enlarge_array_typespec(int *a_size)
{
    int prev_size = *a_size;
    int new_size = (*a_size)*2;
    *a_size = new_size;

    string *array_new = new string[new_size];

    for(int i=0; i<new_size; i++)
    {
        array_new[i] = "0";
    }

    for(int i=0; i<prev_size; i++)
    {
        array_new[i]=array_typespec[i];
    }

    array_typespec = array_new;

}

void enlarge_array_identifier(int *a_size)
{
    int prev_size = *a_size;
    int new_size = (*a_size)*2;
    *a_size = new_size;

    string *array_new = new string[new_size];

    for(int i=0; i<new_size; i++)
    {
        array_new[i] = "0";
    }

    for(int i=0; i<prev_size; i++)
    {
        array_new[i]=array_identifier[i];
    }

    array_identifier = array_new;
}

void enlarge_array_boolliteral(int *a_size)
{
    int prev_size = *a_size;
    int new_size = (*a_size)*2;
    *a_size = new_size;

    string *array_new = new string[new_size];

    for(int i=0; i<new_size; i++)
    {
        array_new[i] = "0";
    }

    for(int i=0; i<prev_size; i++)
    {
        array_new[i]=array_boolliteral[i];
    }

    array_boolliteral = array_new;
}

void enlarge_array_intliteral(int *a_size)
{
    int prev_size = *a_size;
    int new_size = (*a_size)*2;
    *a_size = new_size;

    string *array_new = new string[new_size];

    for(int i=0; i<new_size; i++)
    {
        array_new[i] = "0";
    }

    for(int i=0; i<prev_size; i++)
    {
        array_new[i]=array_intliteral[i];
    }

    array_intliteral = array_new;
}

void enlarge_array_floatliteral(int *a_size)
{
    int prev_size = *a_size;
    int new_size = (*a_size)*2;
    *a_size = new_size;

    string *array_new = new string[new_size];

    for(int i=0; i<new_size; i++)
    {
        array_new[i] = "0";
    }

    for(int i=0; i<prev_size; i++)
    {
        array_new[i]=array_floatliteral[i];
    }

    array_floatliteral = array_new;
}

//string operators(string s)
//{
//    if(s=="||") return "OR";
//    if(s=="==") return "EQ";
//    else if(s=="!=") return "NE";
//    else if(s=="<=") return "LE";
//    else if(s==">=") return "GE";
//    else if(s=="<") return "<";
//    else if(s==">") return ">";
//    else if(s=="&&") return "AND";
//    else if(s=="+") return "+";
//    else if(s=="-") return "-";
//    else if(s=="*") return "*";
//    else if(s=="/") return "/";
//    else if(s=="%") return "%";
//    else if(s=="!") return "!";
//    else return "false";
//}

//bool primary_exp(string s)
//{
//    if(s=="bool_literal" || s=="int_literal" || s=="float_literal") return true;
//    else return false;
//}

int if_else(string s)
{
    if(s=="if") return 11;
    else if(s=="else") return 22;
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
    int array_typespec_size=1;
    array_typespec = new string[array_typespec_size];
    int array_typespec_filleduptoindex=-1;

    int array_identifier_size=1;
    array_identifier  = new string[100];
    int array_identifier_filleduptoindex=-1;

    int array_boolliteral_size=1;
    array_boolliteral = new string[100];
    int array_boolliteral_filleduptoindex=-1;

    int array_intliteral_size=1;
    array_intliteral = new string[100];
    int array_intliteral_filleduptoindex=-1;

    int array_floatliteral_size=1;
    array_floatliteral = new string[100];
    int array_floatliteral_filleduptoindex=-1;

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

        //detecting type_spec, identifiers, literals, if and else

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

            if(ch==',' || ch==';' || ch==' ' || ch=='=' || ch=='\n' || ch=='\t' || ch=='('|| ch==')')
            {

                if(type_spec(s)==true)
                {
                    ofile << "type_spec" << ch;

                    array_typespec_filleduptoindex++;

                    if(array_typespec_filleduptoindex==array_typespec_size-1)
                    {
                        enlarge_array_typespec(&array_typespec_size);
                        cout << "TS-" << array_typespec_size << endl;
                    }

                    array_typespec[array_typespec_filleduptoindex]=s;

                    s = "";
                }
                else if(if_else(s)==11)
                {
                    ofile << "if" << ch;
                    s = "";
                }
                else if(if_else(s)==22)
                {
                    ofile << "else" << ch;
                    s = "";
                }
                else if(bool_literal(s)==true)
                {
                    ofile << "bool_literal" << ch;
                    array_boolliteral_filleduptoindex++;

                    if(array_boolliteral_filleduptoindex==array_boolliteral_size-1)
                    {
                        enlarge_array_boolliteral(&array_boolliteral_size);
                        cout << "BL-" << array_boolliteral_size << endl;
                    }

                    array_boolliteral[array_boolliteral_filleduptoindex]=s;
                    s = "";
                }
                else if(float_literal(s)==true)
                {
                    ofile << "float_literal" << ch;
                    array_floatliteral_filleduptoindex++;

                    if(array_floatliteral_filleduptoindex==array_floatliteral_size-1)
                    {
                        enlarge_array_floatliteral(&array_floatliteral_size);
                        cout << "FL-" << array_floatliteral_size << endl;
                    }

                    array_floatliteral[array_floatliteral_filleduptoindex]=s;
                    s = "";
                }
                else if(int_literal(s)==true)
                {
                    ofile << "int_literal" << ch;
                    array_intliteral_filleduptoindex++;

                    if(array_intliteral_filleduptoindex==array_intliteral_size-1)
                    {
                        enlarge_array_intliteral(&array_intliteral_size);
                        cout << "IL-" << array_intliteral_size << endl;
                    }

                    array_intliteral[array_intliteral_filleduptoindex]=s;
                    s = "";
                }
                else if(ident(s)==true)
                {
                    ofile << "ident" << ch;
                    array_identifier_filleduptoindex++;

                    if(array_identifier_filleduptoindex==array_identifier_size-1)
                    {
                        enlarge_array_identifier(&array_identifier_size);
                        cout << "ID-" << array_identifier_size << endl;
                    }

                    array_identifier[array_identifier_filleduptoindex]=s;
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

//    ifile.open("LexedCode1.txt");
//    ofile.open("LexedCode2.txt");
//
//    if(ifile.is_open())
//    {
//        cout << "LexedCode2 has been opened" << endl;
//
//        string word="";
//        char ch='?';
//        ifile.get(ch);
//
//        while(!ifile.eof())
//        {
//
//            if(ch==',' || ch==';' || ch==' ' || ch=='\n' || ch=='\t' || ch==')' || ch=='=' || ch=='('|| ch==')')
//            {
//                if(primary_exp(word)==true)
//                {
//                    ofile << "expr" << ch;
//                    word="";
//                }
//                else
//                {
//                    ofile << word << ch;
//                    word="";
//                }
//            }
//            else word=word+ch;
//
//            ifile.get(ch);
//        }
//        if(ch!=' ' || ch!='\t' || ch!='\n') ofile << ch;
//    }
//    else cout << "LexedCode2 has not opened" << endl;
//
//    ifile.close();
//    ofile.close();


    //Handled indentation and operator(==)
    ifile.open("LexedCode1.txt");
    ofile.open("LexedCode2.txt");

    if(ifile.is_open())
    {
        cout << "LexedCode2 has been opened" << endl;

        char prev_ch='?';
        char ch='?';
        ifile.get(ch);

        while(!ifile.eof())
        {
            if(ch=='='||ch=='('||ch==')'||ch==';')
            {
                if(ch=='=' && prev_ch=='=') ;
                else if(prev_ch!=' ') ofile << " ";
            }
            if(prev_ch=='='||prev_ch=='('||prev_ch==')'|| prev_ch==';')
            {
                if(prev_ch=='=' && ch=='=') ;
                else if(ch!=' ') ofile << " ";
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

    for(int i=0; i<=array_boolliteral_filleduptoindex; i++) cout << array_boolliteral[i] << " ";
    cout << endl;
    for(int i=0; i<=array_intliteral_filleduptoindex; i++) cout << array_intliteral[i] << " ";
    cout << endl;
    for(int i=0; i<=array_floatliteral_filleduptoindex; i++) cout << array_floatliteral[i] << " ";
    cout << endl;
    for(int i=0; i<=array_identifier_filleduptoindex; i++) cout << array_identifier[i] << " ";
    cout << endl;
    for(int i=0; i<=array_typespec_filleduptoindex; i++) cout << array_typespec[i] << " ";
    cout << endl;


    return 0;
}

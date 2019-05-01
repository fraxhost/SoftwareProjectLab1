#include <bits/stdc++.h>

using namespace std;

//struct DeclListNode{
//    string data;
//    int numberOfChildren;
//    struct node* children[10];
//};
//
//struct DeclNode{
//    string data;
//    struct node* case1children[1];
//    struct node* case2children[1];
//};
//
//struct VarDecNode{
//    string data;
//    struct node* children[3];
//};
//
//struct FuncDecNode{
//    string data;
//    struct node* children[6];
//};
//
//struct ParamsNode{
//    string data;
//    struct node* children[2];
//};
//
//struct ParamListNode{
//    string data;
//    struct node* case1children[3];
//    struct node* case2children[1];
//};
//
//struct ParamNode{
//    string data;
//    struct node* case1children[3];
//    struct node* case2children[1];
//};



//struct node* getNode(string data, int numberOfChildren)
//{
//    node* p = new newNode();
//
//    p->data = data;
//    p->numberOfChildren = numberOfChildren;
//
//    for(int k=0; k<numberOfChildren; k++)
//    {
//       p->children[k][0] =
//    }
//
//    for(int i=0; i<k; i++)
//    {
//        p->child
//    }
//
//    return p;
//};

void program();
void decl_list();
bool decl();
bool var_decl();
void type_spec();
bool function_decl();
bool params();
bool param_list();
bool param();
bool stmt_list();
bool stmt();
bool expr_stmt();
bool while_stmt();
bool compound_stmt();
bool local_decls();
bool local_decl();
bool if_stmt();
bool return_stmt();
bool expr();
bool arglist();
bool args();

struct node{
    string data;
    struct node* parent;
    vector <struct node*> children;
};

int i=0;
ifstream ifile;
ofstream ofile;

string untokenedArray[500];
int filled_untokened_upto=0;

string tokenedArray[500];
int filled_tokened_upto=0;

bool expr()
{
    if(tokenedArray[i]=="IDENT"&&tokenedArray[i+1]=="ASSIGNMENT"&&expr())
    {
        cout << "expr" << endl;
        i=i+2;
        return true;
    }
    else if(expr()==true&&tokenedArray[i]=="OR"&&expr())
    {
        cout << "expr" << endl;
        i=i++;
        return true;
    }
    else if(expr()==true&&tokenedArray[i]=="EQ"&&expr())
    {
        cout << "expr" << endl;
        i=i++;
        return true;
    }
    else if(expr()==true&&tokenedArray[i]=="NE"&&expr())
    {
        cout << "expr" << endl;
        i=i++;
        return true;
    }
    else if(expr()==true&&tokenedArray[i]=="LE"&&expr())
    {
        cout << "expr" << endl;
        i=i++;
        return true;
    }
    else if(expr()==true&&tokenedArray[i]=="LESSER"&&expr())
    {
        cout << "expr" << endl;
        i=i++;
        return true;
    }
    else if(expr()==true&&tokenedArray[i]=="GE"&&expr())
    {
        cout << "expr" << endl;
        i=i++;
        return true;
    }
    else if(expr()==true&&tokenedArray[i]=="GREATER"&&expr())
    {
        cout << "expr" << endl;
        i=i++;
        return true;
    }
    else if(expr()==true&&tokenedArray[i]=="AND"&&expr())
    {
        cout << "expr" << endl;
        i=i++;
        return true;
    }
    else if(expr()==true&&tokenedArray[i]=="ADD"&&expr())
    {
        cout << "expr" << endl;
        i=i++;
        return true;
    }
    else if(expr()==true&&tokenedArray[i]=="SUBTRACT"&&expr())
    {
        cout << "expr" << endl;
        i=i++;
        return true;
    }
    else if(expr()==true&&tokenedArray[i]=="MULTIPLICATION"&&expr())
    {
        cout << "expr" << endl;
        i=i++;
        return true;
    }
    else if(expr()==true&&tokenedArray[i]=="DIVISION"&&expr())
    {
        cout << "expr" << endl;
        i=i++;
        return true;
    }
    else if(expr()==true&&tokenedArray[i]=="MODULUS"&&expr())
    {
        cout << "expr" << endl;
        i=i++;
        return true;
    }
    else if(tokenedArray[i]=="NOT"&&expr()==true)
    {
        cout << "expr" << endl;
        i=i++;
        return true;
    }
    else if(tokenedArray[i]=="SUBTRACT"&&expr()==true)
    {
        cout << "expr" << endl;
        i=i++;
        return true;
    }
    else if(tokenedArray[i]=="ADD"&&expr()==true)
    {
        cout << "expr" << endl;
        i=i++;
        return true;
    }
    else if(tokenedArray[i]=="FIRST_BRACKET_OPEN"&&expr()==true&&tokenedArray[i]=="FIRST_BRACKET_CLOSE")
    {
        cout << "expr" << endl;
        i=i+2;
        return true;
    }
    else if(tokenedArray[i]=="IDENT")
    {
        cout << "expr" << endl;
        i=i++;
        return true;
    }
    else if(tokenedArray[i]=="IDENT"&&tokenedArray[i]=="FIRST_BRACKET_OPEN"&&args()&&tokenedArray[i]=="FIRST_BRACKET_CLOSE")
    {
        cout << "expr" << endl;
        i=i++;
        return true;
    }
    else
    {
        return false;
    }
}

bool arg_list()
{
    if(expr()==true)
    {
        cout << "arg_list" << endl;
        return true;
    }
    else if(arg_list()==true&&tokenedArray[i]=="COMA"&&expr()==true)
    {
        cout << "arg_list" << endl;
        i++;
        return true;
    }
    else
    {
        return false;
    }
}

bool args()
{
    arg_list();
    return true;
}

bool return_stmt()
{
    if(tokenedArray[i]=="RETURN"&&tokenedArray[i+1]=="SEMICOLON")
    {
        cout << "return_stmt" << endl;
        i=i+2;
        return true;
    }
    else if(tokenedArray[i]=="RETURN"&&expr()&&tokenedArray[i+1]=="SEMICOLON")
    {
        cout << "return_stmt" << endl;
        i=i+2;
        return true;
    }
    else
    {
        return false;
    }
}

bool break_stmt()
{
    if(tokenedArray[i]=="BREAK" && tokenedArray[i+1]=="SEMICOLON")
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool if_stmt()
{
    if(tokenedArray[i]=="IF" && tokenedArray[i+1]=="FIRST_BRACKET_OPEN" && expr() && tokenedArray[i+2]=="FIRST_BRACKET_CLOSE" && stmt() && tokenedArray[i+3]=="ELSE" && stmt())
    {
        cout << "if_stmt" << endl;
        i=i+3;
        return true;
    }
    else if(tokenedArray[i]=="IF" && tokenedArray[i+1]=="FIRST_BRACKET_OPEN" && expr() && tokenedArray[i+2]=="FIRST_BRACKET_CLOSE" && stmt())
    {
        cout << "if_stmt" << endl;
        i=i+3;
        return true;
    }
    else
    {
        return false;
    }
}

bool local_decl()
{
    if(tokenedArray[i+1]=="type_spec" && tokenedArray[i+2]=="IDENT" && tokenedArray[i+3]=="SEMICOLON")
    {
        cout << "local_decl" << endl;
        i=i+4;
        return true;
    }
    else
    {
        return false;
    }
}

bool local_decls()
{
    cout << "local_decls" << endl;

    if(local_decl()==false)
    {
        return true;
    }
    else
    {
        local_decls();
    }
}

bool compound_stmt()
{
    if(tokenedArray[i]=="SECOND_BRACKET_OPEN"  && local_decls()==true && stmt_list() && tokenedArray[i]=="SECOND_BRACKET_CLOSE")
    {
        cout << "compound statement" << endl;
        return true;
    }
    else
    {
        return false;
    }
}

bool while_stmt()
{
    if(tokenedArray[i]=="WHILE"&&tokenedArray[i]=="FIRST_BRACKET_OPEN"&&expr()&&tokenedArray[i]=="FIRST_BRACKET_CLOSE"&&stmt()==true)
    {
        cout << "while_stmt" << endl;
        i=i+3;
        return true;
    }
    else
    {
        return false;
    }
}

bool expr_stmt()
{
    if(tokenedArray[i]=="SEMICOLON")
    {
        cout << "expr_stmt" << endl;
        i++;
        return true;
    }
    else if(expr() && tokenedArray[i]=="SEMICOLON")
    {
        cout << "expr stmt" << endl;
        i++;
        return true;
    }
    else
    {
        return false;
    }
}

bool stmt()
{
    if(expr_stmt()==true || compound_stmt()==true || if_stmt()==true || while_stmt()==true || return_stmt()==true || break_stmt()==true)
    {
        cout << "stmt" << endl;
        return true;
    }
    else
    {
        return false;
    }
}

bool stmt_list()
{
    if(stmt()==false)
    {
        cout << "stmt_list" << endl;
        return true;
    }
    else
    {
        stmt_list();
    }
}

bool param()
{
    if(tokenedArray[i]=="type_spec" && tokenedArray[i+1]=="IDENT")
    {
        cout << "param" << endl;
        type_spec();
        return true;
    }
    else
    {
        return false;
    }
}

int param_list_flag=0;

bool param_list()
{
    if(param_list_flag==0)
    {
        cout << "param_list" << endl;
        param_list_flag=1;
    }

    if(param()==true)
    {
        if(tokenedArray[i]=="COMA")
        {
            i++;
            param_list();
        }
        else
        {
            param_list_flag=0;
            return true;
        }
    }
    else return false;
}

bool params()
{
    cout << "params" << endl;

    if(tokenedArray[i]=="VOID" && tokenedArray[i+1]=="SECOND_BRACKET_CLOSE")
    {
        cout << "VOID" << endl;
        i=i+2;
        return true;
    }
    else if(param_list()==false)
    {
        return false;
    }
}

bool function_decl()
{
    cout << "function_decl" << endl;

    if(params()==true && compound_stmt()==true)
    {
        return true;
    }
    else if(params()==true && compound_stmt()==false)
    {
        cout << "--Incorrect Parameter--" << endl;
        return false;
    }
    else if(params()==false && compound_stmt()==true)
    {
        cout << "--Incorrect Compound Statement--" << endl;
        return false;
    }
    else
    {
        cout << "--Incorrect Function Declaration--" << endl;
        return false;
    }
}

void type_spec()
{
    cout << "type_spec" << endl << untokenedArray[i] << endl;
    i++;
    cout << "IDENT" << endl << untokenedArray[i] << endl;
    i++;

    return;
}

bool var_decl()
{
    cout << "var_decl" << endl;

    type_spec();

    return true;
}

bool decl()
{
    if(tokenedArray[i]=="type_spec" && tokenedArray[i+1]=="IDENT" && (tokenedArray[i+2]=="SEMICOLON"||tokenedArray[i+2]=="FIRST_BRACKET_OPEN"))
    {
        if(tokenedArray[i+2]=="SEMICOLON")
        {
            cout << "decl" << endl;
            var_decl();
            i++;
            return true;
        }
        else if(tokenedArray[i+2]=="FIRST_BRACKET_OPEN")
        {
            cout << "decl" << endl;
            i=i+3;
            function_decl();
            return true;
        }
    }
    else
    {
        return false;
    }
}

int decl_list_flag=0;

void decl_list()
{
    if(decl_list_flag==0)
    {
        cout << "decl_list" << endl;
        decl_list_flag=1;
    }

    if(decl()==false)
    {
        //decl_list_flag=0;
        return;
    }

    decl_list();
}

//    if(tokenedArray[i]=="type_spec" && tokenedArray[i+1]=="IDENT")
//    {
//        i=i+2;
//        if(tokenedArray[i]==";") decl_list(i);
//        else if
//    }


void program()
{
    cout << "program" << endl;

    i++;

    decl_list();
}

int main()
{
    ifile.open("Hudai.txt");
    ofile.open("AST.txt");

    if(ifile.is_open())
    {
        cout << "Hudai file has been opened" << endl;

        string untokened, tokened;



        while(!ifile.eof())
        {
            ifile >> untokened >> tokened;

            untokenedArray[filled_untokened_upto]=untokened;
            filled_untokened_upto++;

            tokenedArray[filled_tokened_upto]=tokened;
            filled_tokened_upto++;
        }

    }
    else
    {
        cout << "Lexing file has not opened" << endl;
    }

    if(tokenedArray[i]=="program") program();

    return 0;
}

#include <bits/stdc++.h>


using namespace std;


void program();
void decl_list();
bool decl();
bool var_decl();
void type_spec();
void function_decl();
bool params();
bool params_print();
bool param_list();
bool param_list_print();
bool param();
bool param_print();
bool stmt_list();
bool stmt_list_print();
bool stmt();
bool stmt_print();
bool expr_stmt();
bool while_stmt();
bool compound_stmt();
bool compound_stmt_print();
bool local_decls();
bool local_decls_print();
bool local_decl();
bool local_decl_print();
bool if_stmt();
bool return_stmt();
bool break_stmt();
bool expr();
bool arglist();
bool args();

//struct node{
//    string data;
//    struct node* parent;
//    vector <struct node*> children;
//};


int i=0;
ifstream ifile;
ofstream ofile;


string untokenedArray[500];
int filled_untokened_upto=0;


string tokenedArray[500];
int filled_tokened_upto=0;


int main()
{
    ifile.open("vau.txt");
    //ofile.open("AST.txt");

    if(ifile.is_open())
    {
        cout << "vau file has been opened" << endl;

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
        cout << "vau file has not opened" << endl;
    }

    if(tokenedArray[i]=="program") program();

    return 0;
}


void program()
{
    cout << "program" << endl;

    i++;

    decl_list();
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
        decl_list_flag=0;
        return;
    }

    decl_list();
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


bool var_decl()
{
    cout << "var_decl" << endl;

    type_spec();

    return true;
}


void type_spec()
{
    cout << "type_spec" << endl << untokenedArray[i] << endl;
    i++;
    cout << "IDENT" << endl << untokenedArray[i] << endl;
    i++;

    return;
}


void function_decl()
{
    int marker=i;

    if(params()==true && compound_stmt()==true)
    {
        cout << "function_decl" << endl;
        i=marker;
        params_print();
        compound_stmt_print();

        return;
    }
    else
    {
        cout << "--Incorrect Compound Statement and Incorrect Parameter--" << endl;
        return;
    }

}


bool params()
{
    if(tokenedArray[i]=="VOID" && tokenedArray[i+1]=="FIRST_BRACKET_CLOSE")
    {
        i=i+2;
        return true;
    }
    else if(param_list()==false)
    {
        return false;
    }
}


bool params_print()
{
    cout << "params" << endl;
    if(tokenedArray[i]=="VOID" && tokenedArray[i+1]=="FIRST_BRACKET_CLOSE")
    {
        i=i+2;
        return true;
    }
    else if(param_list_print()==false)
    {
        return false;
    }
}


bool param_list()
{
    if(param()==true)
    {
        if(tokenedArray[i]=="COMA")
        {
            i++;
            param_list();
        }
        else
        {
            return true;
        }
    }
    else return false;
}


int param_list_flag=0;
bool param_list_print()
{
    if(param_list_flag==0)
    {
        cout << "param_list" << endl;
        param_list_flag=1;
    }

    if(param_print()==true)
    {
        if(tokenedArray[i]=="COMA")
        {
            i++;
            param_list_print();
        }
        else
        {
            param_list_flag=0;
            return true;
        }
    }
    else return false;
}


bool param()
{
    if(tokenedArray[i]=="type_spec" && tokenedArray[i+1]=="IDENT")
    {
        i=i+2;
        return true;
    }
    else
    {
        return false;
    }
}


bool param_print()
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


bool stmt_list()
{
    if(stmt()==true)
    {
        stmt_list();
    }
    else
    {
        return true;
    }

}


int stmt_list_flag=0;
bool stmt_list_print()
{
    cout << stmt_list << endl;

    if(stmt_list_flag==0)
    {
        cout << "stmt_list" << endl;
        stmt_list_flag=1;
    }

    if(stmt()==false)
    {
        stmt_list_flag=0;
        return true;
    }

    stmt_list();

}


bool stmt()
{
//    if(expr_stmt()==true)
//    {
//        return true;
//    }
//    else if(compound_stmt()==true)
//    {
//        i=k;
//        return true;
//    }
//    else if(if_stmt()==true)
//    {
//        i=k;
//        return true;
//    }
//    else if(while_stmt()==true)
//    {
//        i=k;
//        return true;
//    }
    if(return_stmt()==true)
    {
        return true;
    }
//    else if(break_stmt()==true)
//    {
//        i=k;
//        return true;
//    }
    else
    {
        return false;
    }
}


bool stmt_print()
{
    if(expr_stmt()==true)
    {
        cout << "stmt" << endl;
        return true;
    }
    else if(compound_stmt()==true)
    {
        cout << "stmt" << endl;
        return true;
    }
    else if(if_stmt()==true)
    {
        cout << "stmt" << endl;
        return true;
    }
    else if(while_stmt()==true)
    {
        cout << "stmt" << endl;
        return true;
    }
    else if(return_stmt()==true)
    {
        cout << "stmt" << endl;
        return true;
    }
    else if(break_stmt()==true)
    {
        cout << "stmt" << endl;
        return true;
    }
    else
    {
        return false;
    }
}


bool expr_stmt()
{
    i++;
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


bool compound_stmt()
{
    bool tokenArrBool=(tokenedArray[i]=="SECOND_BRACKET_OPEN");
    bool b1 = local_decls(), b2=stmt_list();
    bool tokenArrIPO = (tokenedArray[i+1]=="SECOND_BRACKET_CLOSE");

    cout << "Kutta\n";
    cout << tokenArrBool << endl;
    cout << (b1 || b2) << endl;
    cout << tokenArrIPO << endl;
    cout << "END Kutta\n";

    if( tokenArrBool && (b1 || b2) && tokenArrIPO)
    {
        cout << "MORE JA\n";
        return true;
    }
    else
    {
        return false;
    }
}


bool compound_stmt_print()
{
    cout << "compound statement" << endl;

    if(tokenedArray[i]=="SECOND_BRACKET_OPEN"  && (local_decls_print()==true || stmt_list()==true) && tokenedArray[i+1]=="SECOND_BRACKET_CLOSE")
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool local_decls()
{
    if(local_decl()==false)
    {
        return true;
    }

    local_decls();
}


int local_decls_flag=0;
bool local_decls_print()
{
    if(local_decls_flag==0)
    {
        cout << "local_decls" << endl;
        local_decls_flag=1;
    }

    if(local_decl_print()==false)
    {
        local_decls_flag=0;
        return true;
    }

    local_decls_print();
}


bool local_decl()
{
    if(tokenedArray[i+1]=="type_spec" && tokenedArray[i+2]=="IDENT" && tokenedArray[i+3]=="SEMICOLON")
    {
        i=i+3;
        return true;
    }
    else
    {
        return false;
    }
}


bool local_decl_print()
{
    if(tokenedArray[i+1]=="type_spec" && tokenedArray[i+2]=="IDENT" && tokenedArray[i+3]=="SEMICOLON")
    {
        cout << "local decl" << endl;
        i=i+1;
        type_spec();
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


bool return_stmt()
{
    cout << i+1 << " " << i+2 << endl;

    if(tokenedArray[i+1]=="RETURN"&&tokenedArray[i+2]=="SEMICOLON")
    {
        cout << "return_stmt" << endl;
        i=i+2;
        return true;
    }
//    else if(tokenedArray[i+1]=="RETURN"&&expr()&&tokenedArray[i+2]=="SEMICOLON")
//    {
//        cout << "return_stmt" << endl;
//        i=i+2;
//        return true;
//    }
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

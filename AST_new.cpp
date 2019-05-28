#include <bits/stdc++.h>

using namespace std;

struct node{
    string data;
    node* parent;
    vector <struct node*> children;
};

void PreorderTraversal(node* treeNode);
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
bool expr_stmt_print();
bool while_stmt();
bool while_stmt_print();
bool compound_stmt();
bool compound_stmt_print();
bool local_decls();
bool local_decls_print();
bool local_decl();
bool local_decl_print();
bool if_stmt();
bool if_stmt_print();
bool return_stmt();
bool return_stmt_print();
bool break_stmt();
bool break_stmt_print();
bool expr();
bool expr_print();
bool arglist();
bool args();

int success=0;
node* leaf = new node;
node* root = new node;
node* decl_list_leaf = new node;
node* function_decl_leaf = new node;

node* create_newNode(string data)
{
    node* temp = new node;
    temp->data = data;
    temp->parent = NULL;
    //temp->children = NULL;

    return temp;
}

int i=0;
ifstream ifile;
ofstream ofile;

string untokenedArray[500];
int filled_untokened_upto=0;

string tokenedArray[500];
int filled_tokened_upto=0;

int main()
{
    ifile.open("Lexing.txt");
    //ofile.open("AST.txt");

    if(ifile.is_open())
    {
        cout << "Lexed File has been opened" << endl;

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
        cout << "file has not opened" << endl;
    }

    if(tokenedArray[i]=="header_file") program();

    if(success==1)
    {
        cout << endl << "Pre-Order-Traversal of Abstract Syntax Tree:" << endl << endl;
        PreorderTraversal(root);
    }

    return 0;
}

void PreorderTraversal(node* treeNode)
{
    cout << treeNode->data << endl;

    int size = treeNode->children.size();

    if(size==0) return;
    int i=0;
    while(i < size)
    {
        PreorderTraversal(treeNode->children[i]);
        i++;
    }

}

void program()
{
    leaf = root;

    //cout << "program" << endl;

    leaf->data="program";
    leaf->parent=NULL;

    i++;

    while(true)
    {
        if(tokenedArray[i]=="header_file")
        {
            i++;
        }
        else
        {
            decl_list();
            break;
        }
    }
}


int decl_list_flag=0;
int z=0;
void decl_list()
{
    if(decl_list_flag==0)
    {
        vector <node*> tempVec;
        //tree
        node* temp = create_newNode("decl_list");
        tempVec.push_back(temp);
        leaf->children=tempVec;
        temp->parent=leaf;

        decl_list_leaf = temp;

        //cout << "decl_list" << endl;

        decl_list_flag=1;
    }

    leaf = decl_list_leaf;

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
            //leaf = decl_list_leaf;

            vector <node*> tempVec;
            node* temp = create_newNode("decl");
            tempVec.push_back(temp);
            leaf->children.insert(leaf->children.end(),tempVec.begin(),tempVec.end());
            temp->parent=leaf;

            leaf = tempVec[0];

            //cout << "decl" << endl;
            var_decl();
            i++;
            return true;
        }
        else if(tokenedArray[i+2]=="FIRST_BRACKET_OPEN")
        {
            //leaf = decl_list_leaf;

            vector <node*> tempVec;
            node* temp = create_newNode("decl");
            tempVec.push_back(temp);
            leaf->children.insert(leaf->children.end(),tempVec.begin(),tempVec.end());
            temp->parent=leaf;

            leaf = tempVec[0];

            //cout << "decl" << endl;
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
    node* temp = create_newNode("var_decl");
    vector <node*> tempVec;
    tempVec.push_back(temp);
    leaf->children.insert(leaf->children.end(),tempVec.begin(),tempVec.end());
    temp->parent=leaf;

    leaf = tempVec[0];

    //cout << "var_decl" << endl;

    type_spec();

    return true;
}


void type_spec()
{
    vector <node*> tempVec;
    string s1,s2,s3,s4;
    s1 = "type_spec (";
    s2 = untokenedArray[i];
    s3 = ")";
    s4=s1+s2+s3;
    //cout << s4 << endl;
    i++;

    node* temp1 = create_newNode(s4);
    tempVec.push_back(temp1);
    temp1->parent=leaf;
    leaf->children.insert(leaf->children.end(),tempVec.begin(),tempVec.end());

    s1 = "IDENT (";
    s2 = untokenedArray[i];
    s3 = ")";
    s4=s1+s2+s3;
    //cout << s4 << endl;
    i++;

    node* temp2 = create_newNode(s4);
    tempVec.push_back(temp2);
    temp2->parent=leaf;
    leaf->children.insert(leaf->children.end(),tempVec.begin(),tempVec.end());

    leaf->children=tempVec;


    return;
}


void function_decl()
{
    int marker=i;

    if(params()==true && compound_stmt()==true)
    {
        node* temp = create_newNode("function_decl");
        vector <node*> tempVec;
        tempVec.push_back(temp);
        leaf->children=tempVec;
        temp->parent=leaf;

        leaf = tempVec[0];
        function_decl_leaf = leaf;

        //cout << "function_decl" << endl;

        i=marker;
        params_print();
        compound_stmt_print();

        success=1;

        return;
    }
    else
    {
        cout << "**THE CODE DOES NOT FOLLOW THE CONTEXT FREE GRAMMAR" << endl;
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
    if(tokenedArray[i]=="VOID" && tokenedArray[i+1]=="FIRST_BRACKET_CLOSE")
    {
        node* temp = create_newNode("params (VOID)");
        vector <node*> tempVec;
        tempVec.push_back(temp);
        leaf->children=tempVec;
        temp->parent=leaf;

        leaf = tempVec[0];

        //cout << "params (VOID)" << endl;
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
        node* temp = create_newNode("param_list");
        vector <node*> tempVec;
        tempVec.push_back(temp);
        leaf->children=tempVec;
        temp->parent=leaf;

        leaf = tempVec[0];

        //cout << "param_list" << endl;
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
        node* temp = create_newNode("param");
        vector <node*> tempVec;
        tempVec.push_back(temp);
        leaf->children=tempVec;
        temp->parent=leaf;

        leaf = tempVec[0];

        //cout << "param" << endl;
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
    if(stmt_list_flag==0)
    {
        node* temp = create_newNode("stmt_list");
        vector <node*> tempVec;
        tempVec.push_back(temp);
        leaf->children.insert(leaf->children.end(),tempVec.begin(),tempVec.end());
        temp->parent=leaf;

        leaf = tempVec[0];

        //cout << "stmt_list" << endl;
        stmt_list_flag=1;
    }

    if(stmt_print()==false)
    {
        stmt_list_flag=0;
        return true;
    }

    stmt_list_print();

}


bool stmt()
{
    if(return_stmt()==true)
    {
        return true;
    }
    else if(expr_stmt()==true)
    {
        return true;
    }
//    else if(compound_stmt()==true)
//    {
//        i=k;
//        return true;
//    }
    else if(if_stmt()==true)
    {
        return true;
    }
    else if(while_stmt()==true)
    {
        return true;
    }
    else if(break_stmt()==true)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool stmt_print()
{
    if(return_stmt_print()==true)
    {
        return true;
    }
    else if(break_stmt_print()==true)
    {
        return true;
    }
    else if(expr_stmt_print()==true)
    {
        return true;
    }
//    else if(compound_stmt()==true)
//    {
//        cout << "stmt" << endl;
//        return true;
//    }
    else if(while_stmt_print()==true)
    {
        return true;
    }
    else if(if_stmt_print()==true)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool expr_stmt()
{
    if(tokenedArray[i+1]=="SEMICOLON")
    {
        i++;
        return true;
    }
    else if((tokenedArray[i+6]=="SEMICOLON"||tokenedArray[i+4]=="SEMICOLON") && expr()==true)
    {
        i++;
        return true;
    }
    else
    {
        return false;
    }
}


bool expr_stmt_print()
{
    if(tokenedArray[i+1]=="SEMICOLON")
    {
        node* temp = create_newNode("stmt");
        vector <node*> tempVec;
        tempVec.push_back(temp);
        leaf->children.insert(leaf->children.end(),tempVec.begin(),tempVec.end());
        temp->parent=leaf;

        leaf = tempVec[0];

        node* temp1 = create_newNode("expr_stmt (;)");
        vector <node*> tempVec1;
        tempVec1.push_back(temp1);
        leaf->children.insert(leaf->children.end(),tempVec1.begin(),tempVec1.end());
        temp1->parent=leaf;

        leaf = tempVec1[0];

        //cout << "stmt" << endl;
        //cout << "expr_stmt" << endl;
        //cout << ";" << endl;
        i++;
        return true;
    }
    if((tokenedArray[i+6]=="SEMICOLON"||tokenedArray[i+4]=="SEMICOLON") && expr_print()==true)
    {
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
    if(tokenedArray[i+1]=="WHILE"&&tokenedArray[i+2]=="FIRST_BRACKET_OPEN")
    {
        i=i+2;
        if(expr()==true)
        {

            if(tokenedArray[i+1]=="FIRST_BRACKET_CLOSE")
            {

                i++;
                if(stmt()==true)
                {
                    return true;
                }
            }
        }
    }
    else
    {
        return false;
    }
}

bool while_stmt_print()
{
    if(tokenedArray[i+1]=="WHILE"&&tokenedArray[i+2]=="FIRST_BRACKET_OPEN")
    {
        node* temp = create_newNode("stmt");
        vector <node*> tempVec;
        tempVec.push_back(temp);
        leaf->children.insert(leaf->children.end(),tempVec.begin(),tempVec.end());
        temp->parent=leaf;

        leaf = tempVec[0];

        node* temp1 = create_newNode("while_stmt");
        vector <node*> tempVec1;
        tempVec1.push_back(temp1);
        leaf->children.insert(leaf->children.end(),tempVec1.begin(),tempVec1.end());
        temp1->parent=leaf;

        leaf = tempVec1[0];

        //cout << "stmt" << endl;
        //cout << "while_stmt_print" << endl;
        i=i+2;

        if(expr_print()==true)
        {
            if(tokenedArray[i+1]=="FIRST_BRACKET_CLOSE")
            {
                i++;
                if(stmt_print()==true)
                {
                    return true;
                }
            }
        }
    }
    else
    {
        return false;
    }
}

bool compound_stmt()
{

    bool step1 = (tokenedArray[i]=="SECOND_BRACKET_OPEN");
    bool step2 = local_decls();
    bool step3 = stmt_list();
    bool step4 = (tokenedArray[i+1]=="SECOND_BRACKET_CLOSE");

    if(step1 && (step2 || step3) && step4)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool compound_stmt_print()
{
    int k=i;

    bool step1 = (tokenedArray[i]=="SECOND_BRACKET_OPEN");
    bool step2 = local_decls();
    bool step3 = stmt_list();
    bool step4 = (tokenedArray[i+1]=="SECOND_BRACKET_CLOSE");

    if(step1 && (step2 || step3) && step4)
    {
        i=k;
        if(step2==true)
        {
            local_decls_print();
        }
        if(step3==true)
        {
            stmt_list_print();
        }

        return true;
    }
    else
    {
        return false;
    }
}

int local_decls_flag1=0;
bool local_decls()
{
    if(local_decl()==true)
    {
        local_decls();
        local_decls_flag1=1;
    }
    else
    {
        if(local_decls_flag1==1)
        {
            return true;
            local_decls_flag1=0;
        }
        else
        {
            return false;
        }
    }
}


int local_decls_flag2=0;
bool local_decls_print()
{
    if(local_decls_flag2==0)
    {
        leaf=function_decl_leaf;

        node* temp = create_newNode("local_decls");
        vector <node*> tempVec;
        tempVec.push_back(temp);
        leaf->children.insert(leaf->children.end(),tempVec.begin(),tempVec.end());
        temp->parent=leaf;

        leaf = tempVec[0];

        //cout << "local_decls" << endl;
        local_decls_flag2=1;
    }

    if(local_decl_print()==false)
    {
        local_decls_flag2=0;
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
        node* temp = create_newNode("local_decl");
        vector <node*> tempVec;
        tempVec.push_back(temp);
        leaf->children.insert(leaf->children.end(),tempVec.begin(),tempVec.end());
        temp->parent=leaf;

        leaf = tempVec[0];

        //cout << "local_decl" << endl;
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
    if(tokenedArray[i+1]=="IF" && tokenedArray[i+2]=="FIRST_BRACKET_OPEN")
    {
        i=i+2;

        if(expr()==true)
        {
            if(tokenedArray[i+1]=="FIRST_BRACKET_CLOSE")
            {
                i++;

                if(stmt()==true)
                {
                    if(tokenedArray[i+1]=="ELSE")
                    {
                        i++;

                        if(stmt()==true)
                        {
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }

                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }

        return true;
    }
    else
    {
        return false;
    }
}


bool if_stmt_print()
{
    if(tokenedArray[i+1]=="IF" && tokenedArray[i+2]=="FIRST_BRACKET_OPEN")
    {
//aaa
        node* temp = create_newNode("stmt");
        vector <node*> tempVec;
        tempVec.push_back(temp);
        leaf->children.insert(leaf->children.end(),tempVec.begin(),tempVec.end());
        temp->parent=leaf;

        leaf = tempVec[0];

        node* temp1 = create_newNode("if_stmt");
        vector <node*> tempVec1;
        tempVec1.push_back(temp1);
        leaf->children.insert(leaf->children.end(),tempVec1.begin(),tempVec1.end());
        temp1->parent=leaf;

        leaf = tempVec1[0];
        //cout << "stmt" << endl;
        //cout << "if_stmt" << endl;

        i=i+2;

        if(expr_print()==true)
        {
            if(tokenedArray[i+1]=="FIRST_BRACKET_CLOSE")
            {
                i++;

                if(stmt_print()==true)
                {
                    if(tokenedArray[i+1]=="ELSE")
                    {
                        node* temp2 = create_newNode("else_stmt");
                        vector <node*> tempVec2;
                        tempVec2.push_back(temp2);
                        leaf->children.insert(leaf->children.end(),tempVec2.begin(),tempVec2.end());
                        temp2->parent=leaf;

                        leaf = tempVec2[0];

                        //cout << "else" << endl;

                        i++;

                        if(stmt_print()==true)
                        {
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }

                    return true;
                }
                else
                {
                    return false;
                }

                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }

        return true;
    }
    else
    {
        return false;
    }
}


bool return_stmt()
{
    if(tokenedArray[i+1]=="RETURN"&&tokenedArray[i+2]=="SEMICOLON")
    {
        i=i+2;
        return true;
    }
    else if(tokenedArray[i+1]=="RETURN")
    {
        i=i+1;
        if(expr()==true)
        {
            if(tokenedArray[i+1]=="SEMICOLON")
            {
                i=i++;
                return true;
            }
        }
    }
    else
    {
        return false;
    }
}


bool return_stmt_print()
{
    if(tokenedArray[i+1]=="RETURN"&&tokenedArray[i+2]=="SEMICOLON")
    {
        node* temp = create_newNode("stmt");
        vector <node*> tempVec;
        tempVec.push_back(temp);
        leaf->children.insert(leaf->children.end(),tempVec.begin(),tempVec.end());
        temp->parent=leaf;

        leaf = tempVec[0];

        node* temp1 = create_newNode("return_stmt");
        vector <node*> tempVec1;
        tempVec1.push_back(temp1);
        leaf->children.insert(leaf->children.end(),tempVec1.begin(),tempVec1.end());
        temp1->parent=leaf;

        leaf = tempVec1[0];

        //cout << "stmt" << endl;
        //cout << "return_stmt" << endl;
        i=i+2;
        return true;
    }
    else if(tokenedArray[i+1]=="RETURN")
    {
        i=i+1;
        if(expr()==true)
        {
            if(tokenedArray[i+1]=="SEMICOLON")
            {
                node* temp = create_newNode("stmt");
                vector <node*> tempVec;
                tempVec.push_back(temp);
                leaf->children.insert(leaf->children.end(),tempVec.begin(),tempVec.end());
                temp->parent=leaf;

                leaf = tempVec[0];

                node* temp1 = create_newNode("return_stmt");
                vector <node*> tempVec1;
                tempVec1.push_back(temp1);
                leaf->children.insert(leaf->children.end(),tempVec1.begin(),tempVec1.end());
                temp1->parent=leaf;

                leaf = tempVec1[0];

                //cout << "stmt" << endl;
                //cout << "return_stmt" << endl;
                i=i+2;
                return true;
            }
        }
    }
    else
    {
        return false;
    }
}


bool break_stmt()
{
    if(tokenedArray[i+1]=="BREAK" && tokenedArray[i+2]=="SEMICOLON")
    {
        i=i+2;
        return true;
    }
    else
    {
        return false;
    }
}

bool break_stmt_print()
{
    if(tokenedArray[i+1]=="BREAK" && tokenedArray[i+2]=="SEMICOLON")
    {
        node* temp = create_newNode("stmt");
        vector <node*> tempVec;
        tempVec.push_back(temp);
        leaf->children.insert(leaf->children.end(),tempVec.begin(),tempVec.end());
        temp->parent=leaf;

        leaf = tempVec[0];

        node* temp1 = create_newNode("break_stmt");
        vector <node*> tempVec1;
        tempVec1.push_back(temp1);
        leaf->children.insert(leaf->children.end(),tempVec1.begin(),tempVec1.end());
        temp1->parent=leaf;

        leaf = tempVec1[0];

        //cout << "stmt" << endl;
        //cout << "break_stmt" << endl;
        i=i+2;
        return true;
    }
    else
    {
        return false;
    }
}


bool expr_print()
{
    if(tokenedArray[i+1]=="IDENT"&&tokenedArray[i+2]=="ASSIGNMENT"&&tokenedArray[i+3]=="IDENT"&&(tokenedArray[i+4]=="ADD"||tokenedArray[i+4]=="SUBTRACT"||tokenedArray[i+4]=="MULTIPLICATION"||tokenedArray[i+4]=="DIVISION")&&tokenedArray[i+5]=="IDENT")
    {
        node* temp = create_newNode("stmt");
        vector <node*> tempVec;
        tempVec.push_back(temp);
        leaf->children.insert(leaf->children.end(),tempVec.begin(),tempVec.end());
        temp->parent=leaf;

        leaf = tempVec[0];

        node* temp1 = create_newNode("expr_stmt");
        vector <node*> tempVec1;
        tempVec1.push_back(temp1);
        leaf->children.insert(leaf->children.end(),tempVec1.begin(),tempVec1.end());
        temp1->parent=leaf;

        leaf = tempVec1[0];

        //cout << "stmt" << endl;
        //cout << "expr_stmt" << endl;

        string s1,s2,s3,s4;
        s1="IDENT (";
        s2=untokenedArray[i+1];
        s3=")";
        s4=s1+s2+s3;

        node* temp2 = create_newNode(s4);
        vector <node*> tempVec2;
        tempVec2.push_back(temp2);
        leaf->children.insert(leaf->children.end(),tempVec2.begin(),tempVec2.end());
        temp2->parent=leaf;

        //leaf = tempVec1[0];

        node* temp3 = create_newNode("ASSIGNMENT (=)");
        vector <node*> tempVec3;
        tempVec3.push_back(temp3);
        leaf->children.insert(leaf->children.end(),tempVec3.begin(),tempVec3.end());
        temp3->parent=leaf;

        //leaf = tempVec1[0];

        s1="IDENT (";
        s2=untokenedArray[i+3];
        s3=")";
        s4=s1+s2+s3;

        node* temp4 = create_newNode(s4);
        vector <node*> tempVec4;
        tempVec4.push_back(temp4);
        leaf->children.insert(leaf->children.end(),tempVec4.begin(),tempVec4.end());
        temp1->parent=leaf;

        //leaf = tempVec1[0];

        //cout << "IDENT" << endl << untokenedArray[i+1] << endl;
        //cout << "ASSIGNMENT" << endl << "=" << endl;
        //cout << "IDENT" << endl << untokenedArray[i+3] << endl;

        if(tokenedArray[i+4]=="ADD")
        {
            //cout << "ADD" << endl << "+" << endl;

            node* temp5 = create_newNode("ADD (+)");
            vector <node*> tempVec5;
            tempVec5.push_back(temp5);
            leaf->children.insert(leaf->children.end(),tempVec5.begin(),tempVec5.end());
            temp5->parent=leaf;

            //leaf = tempVec1[0];
        }
        if(tokenedArray[i+4]=="SUBTRACT")
        {
            //cout << "SUBTRACT" << endl << "-" << endl;

            node* temp5 = create_newNode("SUBTRACT (-)");
            vector <node*> tempVec5;
            tempVec5.push_back(temp5);
            leaf->children.insert(leaf->children.end(),tempVec5.begin(),tempVec5.end());
            temp5->parent=leaf;

            //leaf = tempVec5[0];
        }
        if(tokenedArray[i+4]=="MULTIPLICATION")
        {
            //cout << "MULTIPLICATION" << endl << "*" << endl;

            node* temp5 = create_newNode("MULTIPLICATION (*)");
            vector <node*> tempVec5;
            tempVec5.push_back(temp5);
            leaf->children.insert(leaf->children.end(),tempVec5.begin(),tempVec5.end());
            temp5->parent=leaf;

            //leaf = tempVec5[0];
        }
        if(tokenedArray[i+4]=="DIVISION")
        {
            //cout << "DIVISION" << endl << "/" << endl;

            node* temp5 = create_newNode("DIVISION (/)");
            vector <node*> tempVec5;
            tempVec5.push_back(temp5);
            leaf->children.insert(leaf->children.end(),tempVec5.begin(),tempVec5.end());
            temp5->parent=leaf;

            //leaf = tempVec5[0];
        }

        s1="IDENT (";
        s2=untokenedArray[i+5];
        s3=")";
        s4=s1+s2+s3;

        node* temp6 = create_newNode(s4);
        vector <node*> tempVec6;
        tempVec6.push_back(temp6);
        leaf->children.insert(leaf->children.end(),tempVec6.begin(),tempVec6.end());
        temp6->parent=leaf;

        //leaf = tempVec1[0];

        //cout << "IDENT" << endl << untokenedArray[i+5] << endl;
        i=i+5;
        return true;

    }
    else if(tokenedArray[i+1]=="IDENT"&&tokenedArray[i+2]=="ASSIGNMENT"&&tokenedArray[i+3]=="IDENT")
    {
        node* temp = create_newNode("stmt");
        vector <node*> tempVec;
        tempVec.push_back(temp);
        leaf->children.insert(leaf->children.end(),tempVec.begin(),tempVec.end());
        temp->parent=leaf;

        leaf = tempVec[0];

        node* temp1 = create_newNode("expr_stmt");
        vector <node*> tempVec1;
        tempVec1.push_back(temp1);
        leaf->children.insert(leaf->children.end(),tempVec1.begin(),tempVec1.end());
        temp1->parent=leaf;

        leaf = tempVec1[0];

        //cout << "stmt" << endl;
        //cout << "expr_stmt" << endl;

        string s1,s2,s3,s4;
        s1="IDENT (";
        s2=untokenedArray[i+1];
        s3=")";
        s4=s1+s2+s3;

        node* temp2 = create_newNode(s4);
        vector <node*> tempVec2;
        tempVec2.push_back(temp2);
        leaf->children.insert(leaf->children.end(),tempVec2.begin(),tempVec2.end());
        temp2->parent=leaf;

        //leaf = tempVec1[0];

        node* temp3 = create_newNode("ASSIGNMENT (=)");
        vector <node*> tempVec3;
        tempVec3.push_back(temp3);
        leaf->children.insert(leaf->children.end(),tempVec3.begin(),tempVec3.end());
        temp3->parent=leaf;

        //leaf = tempVec1[0];

        s1="IDENT (";
        s2=untokenedArray[i+3];
        s3=")";
        s4=s1+s2+s3;

        node* temp4 = create_newNode(s4);
        vector <node*> tempVec4;
        tempVec4.push_back(temp4);
        leaf->children.insert(leaf->children.end(),tempVec4.begin(),tempVec4.end());
        temp1->parent=leaf;

        //cout << "IDENT" << endl << untokenedArray[i+1] << endl;
        //cout << "ASSIGNMENT" << endl << "=" << endl;
        //cout << "IDENT" << endl << untokenedArray[i+3] << endl;
        i=i+3;
        return true;
    }
    else if(tokenedArray[i+1]=="IDENT"&&(tokenedArray[i+2]=="EQ"||tokenedArray[i+2]=="NE"||tokenedArray[i+2]=="LESSER"||tokenedArray[i+2]=="GREATER")&&tokenedArray[i+3]=="IDENT")
    {
        node* temp = create_newNode("stmt");
        vector <node*> tempVec;
        tempVec.push_back(temp);
        leaf->children.insert(leaf->children.end(),tempVec.begin(),tempVec.end());
        temp->parent=leaf;

        leaf = tempVec[0];

        node* temp1 = create_newNode("expr_stmt");
        vector <node*> tempVec1;
        tempVec1.push_back(temp1);
        leaf->children.insert(leaf->children.end(),tempVec1.begin(),tempVec1.end());
        temp1->parent=leaf;

        leaf = tempVec1[0];

        //cout << "stmt" << endl;
        //cout << "expr_stmt" << endl;

        string s1,s2,s3,s4;
        s1="IDENT (";
        s2=untokenedArray[i+1];
        s3=")";
        s4=s1+s2+s3;

        node* temp2 = create_newNode(s4);
        vector <node*> tempVec2;
        tempVec2.push_back(temp2);
        leaf->children.insert(leaf->children.end(),tempVec2.begin(),tempVec2.end());
        temp2->parent=leaf;

        //leaf = tempVec1[0];

        //cout << "IDENT" << endl << untokenedArray[i+1] << endl;

        if(tokenedArray[i+2]=="EQ")
        {
            node* temp3 = create_newNode("EQ (==)");
            vector <node*> tempVec3;
            tempVec3.push_back(temp3);
            leaf->children.insert(leaf->children.end(),tempVec3.begin(),tempVec3.end());
            temp3->parent=leaf;

            //cout << "EQ" << endl << "==" << endl;
        }
        else if(tokenedArray[i+2]=="NE")
        {
            node* temp3 = create_newNode("NE (!=)");
            vector <node*> tempVec3;
            tempVec3.push_back(temp3);
            leaf->children.insert(leaf->children.end(),tempVec3.begin(),tempVec3.end());
            temp3->parent=leaf;

            //cout << "NE" << endl << "!=" << endl;
        }
        if(tokenedArray[i+2]=="LESSER")
        {
            node* temp3 = create_newNode("LESSER (<)");
            vector <node*> tempVec3;
            tempVec3.push_back(temp3);
            leaf->children.insert(leaf->children.end(),tempVec3.begin(),tempVec3.end());
            temp3->parent=leaf;

            //cout << "LESSER" << endl << "<" << endl;
        }
        if(tokenedArray[i+2]=="GREATER")
        {
            node* temp3 = create_newNode("GREATER (>)");
            vector <node*> tempVec3;
            tempVec3.push_back(temp3);
            leaf->children.insert(leaf->children.end(),tempVec3.begin(),tempVec3.end());
            temp3->parent=leaf;

            //cout << "GREATER" << endl << ">" << endl;
        }

        s1="IDENT (";
        s2=untokenedArray[i+3];
        s3=")";
        s4=s1+s2+s3;

        node* temp4 = create_newNode(s4);
        vector <node*> tempVec4;
        tempVec4.push_back(temp4);
        leaf->children.insert(leaf->children.end(),tempVec4.begin(),tempVec4.end());
        temp1->parent=leaf;

        //cout << "IDENT" << endl << untokenedArray[i+3] << endl;
        i=i+3;
        return true;
    }
    else if(tokenedArray[i+1]=="BOOL_LIT"||tokenedArray[i+1]=="FLOAT_LIT"||tokenedArray[i+1]=="INT_LIT"||tokenedArray[i+1]=="IDENT")
    {
        node* temp = create_newNode("stmt");
        vector <node*> tempVec;
        tempVec.push_back(temp);
        leaf->children.insert(leaf->children.end(),tempVec.begin(),tempVec.end());
        temp->parent=leaf;

        leaf = tempVec[0];

        node* temp1 = create_newNode("expr_stmt");
        vector <node*> tempVec1;
        tempVec1.push_back(temp1);
        leaf->children.insert(leaf->children.end(),tempVec1.begin(),tempVec1.end());
        temp1->parent=leaf;

        leaf = tempVec1[0];

        //cout << "stmt" << endl;
        //cout << "expr_stmt" << endl;


        if(tokenedArray[i+1]=="BOOL_LIT")
        {
            string s1,s2,s3,s4;
            s1="BOOL_LIT (";
            s2=untokenedArray[i+1];
            s3=")";
            s4=s1+s2+s3;

            node* temp2 = create_newNode(s4);
            vector <node*> tempVec2;
            tempVec2.push_back(temp2);
            leaf->children.insert(leaf->children.end(),tempVec2.begin(),tempVec2.end());
            temp2->parent=leaf;

            //cout << "BOOL_LIT (" << endl << untokenedArray[i+1] << ")" << endl;
        }
        else if(tokenedArray[i+1]=="FLOAT_LIT")
        {
            string s1,s2,s3,s4;
            s1="FLOAT_LIT (";
            s2=untokenedArray[i+1];
            s3=")";
            s4=s1+s2+s3;

            node* temp2 = create_newNode(s4);
            vector <node*> tempVec2;
            tempVec2.push_back(temp2);
            leaf->children.insert(leaf->children.end(),tempVec2.begin(),tempVec2.end());
            temp2->parent=leaf;

            //cout << "FLOAT_LIT (" << endl << untokenedArray[i+1] << ")" << endl;
        }
        if(tokenedArray[i+1]=="INT_LIT")
        {
            string s1,s2,s3,s4;
            s1="INT_LIT (";
            s2=untokenedArray[i+1];
            s3=")";
            s4=s1+s2+s3;

            node* temp2 = create_newNode(s4);
            vector <node*> tempVec2;
            tempVec2.push_back(temp2);
            leaf->children.insert(leaf->children.end(),tempVec2.begin(),tempVec2.end());
            temp2->parent=leaf;

            //cout << "INT_LIT (" << endl << untokenedArray[i+1] << ")" << endl;
        }
        if(tokenedArray[i+1]=="IDENT")
        {
            string s1,s2,s3,s4;
            s1="IDENT (";
            s2=untokenedArray[i+1];
            s3=")";
            s4=s1+s2+s3;

            node* temp2 = create_newNode(s4);
            vector <node*> tempVec2;
            tempVec2.push_back(temp2);
            leaf->children.insert(leaf->children.end(),tempVec2.begin(),tempVec2.end());
            temp2->parent=leaf;

            //cout << "IDENT (" << endl << untokenedArray[i+1] << ")" << endl;
        }

        i=i+1;
        return true;
    }
    else
    {
        return false;
    }
}

bool expr()
{
    if(tokenedArray[i+1]=="IDENT"&&tokenedArray[i+2]=="ASSIGNMENT"&&tokenedArray[i+3]=="IDENT"&&(tokenedArray[i+4]=="ADD"||tokenedArray[i+4]=="SUBTRACT"||tokenedArray[i+4]=="MULTIPLICATION"||tokenedArray[i+4]=="DIVISION")&&tokenedArray[i+5]=="IDENT")
    {
        i=i+5;
        return true;
    }
    else if(tokenedArray[i+1]=="IDENT"&&tokenedArray[i+2]=="ASSIGNMENT"&&tokenedArray[i+3]=="IDENT")
    {
        i=i+3;
        return true;
    }
    else if(tokenedArray[i+1]=="IDENT"&&(tokenedArray[i+2]=="EQ"||tokenedArray[i+2]=="NE"||tokenedArray[i+2]=="LESSER"||tokenedArray[i+2]=="GREATER")&&tokenedArray[i+3]=="IDENT")
    {
        i=i+3;
        return true;
    }
    else if(tokenedArray[i+1]=="BOOL_LIT"||tokenedArray[i+1]=="FLOAT_LIT"||tokenedArray[i+1]=="INT_LIT"||tokenedArray[i+1]=="IDENT")
    {
        i=i+1;
        return true;
    }
    else
    {
        return false;
    }
//    if(tokenedArray[i]=="IDENT"&&tokenedArray[i+1]=="ASSIGNMENT"&&expr())
//    {
//        cout << "expr" << endl;
//        i=i+2;
//        return true;
//    }
//    else if(expr()==true&&tokenedArray[i]=="OR"&&expr())
//    {
//        cout << "expr" << endl;
//        i=i++;
//        return true;
//    }
//    else if(expr()==true&&tokenedArray[i]=="EQ"&&expr())
//    {
//        cout << "expr" << endl;
//        i=i++;
//        return true;
//    }
//    else if(expr()==true&&tokenedArray[i]=="NE"&&expr())
//    {
//        cout << "expr" << endl;
//        i=i++;
//        return true;
//    }
//    else if(expr()==true&&tokenedArray[i]=="LE"&&expr())
//    {
//        cout << "expr" << endl;
//        i=i++;
//        return true;
//    }
//    else if(expr()==true&&tokenedArray[i]=="LESSER"&&expr())
//    {
//        cout << "expr" << endl;
//        i=i++;
//        return true;
//    }
//    else if(expr()==true&&tokenedArray[i]=="GE"&&expr())
//    {
//        cout << "expr" << endl;
//        i=i++;
//        return true;
//    }
//    else if(expr()==true&&tokenedArray[i]=="GREATER"&&expr())
//    {
//        cout << "expr" << endl;
//        i=i++;
//        return true;
//    }
//    else if(expr()==true&&tokenedArray[i]=="AND"&&expr())
//    {
//        cout << "expr" << endl;
//        i=i++;
//        return true;
//    }
//    if(expr()==true)
//    {
//        if(tokenedArray[i+1]=="ADD")
//        {
//            i++;
//
//            if(expr()==true)
//            {
//                return true;
//            }
//        }
//    }
//    else if(expr()==true&&tokenedArray[i]=="SUBTRACT"&&expr())
//    {
//        cout << "expr" << endl;
//        i=i++;
//        return true;
//    }
//    else if(expr()==true&&tokenedArray[i]=="MULTIPLICATION"&&expr())
//    {
//        cout << "expr" << endl;
//        i=i++;
//        return true;
//    }
//    else if(expr()==true&&tokenedArray[i]=="DIVISION"&&expr())
//    {
//        cout << "expr" << endl;
//        i=i++;
//        return true;
//    }
//    else if(expr()==true&&tokenedArray[i]=="MODULUS"&&expr())
//    {
//        cout << "expr" << endl;
//        i=i++;
//        return true;
//    }
//    else if(tokenedArray[i]=="NOT"&&expr()==true)
//    {
//        cout << "expr" << endl;
//        i=i++;
//        return true;
//    }
//    else if(tokenedArray[i]=="SUBTRACT"&&expr()==true)
//    {
//        cout << "expr" << endl;
//        i=i++;
//        return true;
//    }
//    if(tokenedArray[i]=="ADD"&&expr()==true)
//    {
//        cout << "expr" << endl;
//        i=i++;
//        return true;
//    }
//    else if(tokenedArray[i]=="FIRST_BRACKET_OPEN"&&expr()==true&&tokenedArray[i]=="FIRST_BRACKET_CLOSE")
//    {
//        cout << "expr" << endl;
//        i=i+2;
//        return true;
//    }
//    else if(tokenedArray[i+1]=="IDENT")
//    {
//        i++;
//        return true;
//    }
//    else if(tokenedArray[i]=="IDENT"&&tokenedArray[i]=="FIRST_BRACKET_OPEN"&&args()&&tokenedArray[i]=="FIRST_BRACKET_CLOSE")
//    {
//        cout << "expr" << endl;
//        i=i++;
//        return true;
//    }
//    else if(tokenedArray[i+1]=="BOOL_LITERAL"||tokenedArray[i+1]=="INT_LITERAL"||tokenedArray[i+1]=="FLOAT_LITERAL"||tokenedArray[i+1]=="STRING_LITERAL")
//    {
//        i++;
//        return true;
//    }
//    else
//    {
//        return false;
//    }
}


bool arg_list()
{
    if(expr()==true)
    {
        //cout << "arg_list" << endl;
        return true;
    }
    else if(arg_list()==true&&tokenedArray[i]=="COMA"&&expr()==true)
    {
        //cout << "arg_list" << endl;
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

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int main()
{
    int i=0,f,z,error=0;
     string key[]=
    {"auto","bool","break","case","catch",
    "char","class","const","continue","default",
    "double","do","else","enum","float",
    "for","goto","if","inline","int",
    "long","namespace","new","private","protected",
    "public","register","return","short","signed",
    "sizeof","static","struct","switch","this",
    "typedef","union","unsigned","using","virtual",
    "void","while"};

    ifstream cin("sample.txt");
    char del[]={";({})"};
    char str[100], *word,ch;
    string a;

    if(!cin)
        exit(0);

    while(!cin.eof())
    {
         cin.get(ch);
        if(ch=='\'')
        {
            cin.get(ch);
            a+=ch;

            cout<<"Character:"<<a<<endl;
             cin.get(ch);
            a.clear();
        }

         if(ch=='\"')
        {
            while(1)
            {
                cin.get(ch);
                if(ch=='\"')
                    break;
                 a+=ch;
            }
            if(!a.empty())
               cout<<"Literal:"<<a<<endl;
            a.clear();
        }

        if(isalpha(ch)||ch=='_')
        {
            while(1)
            {
                a+=ch;
                cin.get(ch);
                if(!(isalnum(ch)||ch=='_'))
                    break;
            }
            for(i=0;i<42;i++)
            {
                if(key[i].compare(a)==0)
                {
                    f=1;
                    break;
                }
            }
            if(f==0)
                cout<<"Identifier:"<<a<<endl;
             else
                cout<<"Keyword:"<<a<<endl;
             f=0;
             cin.unget();
            a.clear();

        }

        else if(isdigit(ch))
        {
            while(isdigit(ch)&&!cin.eof()||ch=='.')
            {
                a+=ch;
                cin.get(ch);
            }
            if(isalpha(ch))
            {
                while(isalpha(ch)&&!cin.eof())
                {
                    a+=ch;
                    cin.get(ch);
                }
                cout<<"Error:Invalid constant:"<<a<<endl;
                error=1;
            }
            if(error==0)
              cout<<"Constant:"<<a<<endl;
            error=0;
            a.clear();
        }
        else if(ch=='$'||ch=='@')
            cout<<"Error: "<<ch<<endl;
        else if(ch=='+')
        {
            a+=ch;
            cin.get(ch);
            if(ch=='+'||ch=='=')
             {
                  a+=ch;
                  cin.get(ch);
             }
            cout<<"Operator:"<<a<<endl;
            cin.unget();
            a.clear();
        }
        else if(ch=='-')
        {
            a+=ch;
            cin.get(ch);
            if(ch=='-'||ch=='=')
             {
                  a+=ch;
                  cin.get(ch);
             }
            cout<<"Operator:"<<a<<endl;
            cin.unget();
            a.clear();
        }
         else if(ch=='*')
        {
            a+=ch;
            cin.get(ch);
            if(ch=='=')
             {
                  a+=ch;
                  cin.get(ch);
             }
            cout<<"Operator:"<<a<<endl;
            cin.unget();
            a.clear();
        }
         else if(ch=='/')
        {
            a+=ch;
            cin.get(ch);
            if(ch=='=')
             {
                  a+=ch;
                  cin.get(ch);
             }
             else if(ch=='/')
             {
                 error=1;
                  while(1)
                {
                   cin.get(ch);
                  if(ch=='\n')
                    break;


                }
             }
            else if(ch=='*')
            {
                while(1)
                {
                    cin.get(ch);
                    if(ch=='*')
                    {
                        cin.get(ch);
                        if(ch=='/')
                        {

                            error=1;
                            break;

                        }
                    }


                }
            }

             if(error==0)
             {
                 cout<<"Operator:"<<a<<endl;
                 cin.unget();
             }

            else
                error=0;


            a.clear();
        }
        else if(ch=='%'||ch=='~'||ch=='^')
        {
             a+=ch;
             cout<<"Operator:"<<a<<endl;
            a.clear();
        }
         else if(ch=='=')
        {
            a+=ch;
            cin.get(ch);
            if(ch=='=')
             {
                  a+=ch;
                  cin.get(ch);
             }
             else if(ch=='<'||ch=='>'||ch=='*'||ch=='/')
             {
                 a+=ch;
                 cout<<"Error:"<<a<<endl;
                 error=1;
             }
             if(error==0)
              {
                  cout<<"Operator:"<<a<<endl;
                  cin.unget();
              }
              //cin.unget();
              error=0;
            a.clear();
        }
         else if(ch=='>')
        {
            a+=ch;
            cin.get(ch);
            if(ch=='>'||ch=='=')
             {
                  a+=ch;
                  cin.get(ch);
             }
            cout<<"Operator:"<<a<<endl;
            cin.unget();
            a.clear();
        }
         else if(ch=='<')
        {
            a+=ch;
            cin.get(ch);
            if(ch=='<'||ch=='=')
             {
                  a+=ch;
                  cin.get(ch);
             }
            cout<<"Operator:"<<a<<endl;
            cin.unget();
            a.clear();
        }
         else if(ch=='!')
        {
            a+=ch;
            cin.get(ch);
            if(ch=='=')
             {
                  a+=ch;
                  cin.get(ch);
             }
            cout<<"Operator:"<<a<<endl;
            cin.unget();
            a.clear();
        }
         else if(ch=='&')
        {
            a+=ch;
            cin.get(ch);
            if(ch=='&')
             {
                  a+=ch;
                  cin.get(ch);
             }
            cout<<"Operator:"<<a<<endl;
            cin.unget();
            a.clear();
        }
         else if(ch=='|')
        {
            a+=ch;
            cin.get(ch);
            if(ch=='|')
             {
                  a+=ch;
                  cin.get(ch);
             }
            cout<<"Operator:"<<a<<endl;
           cin.unget();
            a.clear();
        }
    }
 cin.close();
}

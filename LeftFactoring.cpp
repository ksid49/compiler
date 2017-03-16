#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
using namespace std;
string compare(string a , string b)
{
    int i,j,size1,size2,flag=0;
    int rec=74;
    string str;
    size1=a.length();
    size2=b.length();
    for(i=0;i<size1&&i<size2;i++)
    {
        if(a[i]==b[i])
        {
            str+=a[i];
        }
        else
            break;
    }
    return str;
}
int main()
{
    int i=0,n,j,k,flag=0,b=0,x,nol=0;
    string temp;
    fstream fin,fout;
    fin.open("output1.txt",ios::in);
    fout.open("output2.txt",ios::out);
    string str[8],tok[20][20],alpha,beta[20];
    string var[10];
    while(!fin.eof())
    {
        getline(fin,str[i]);
        if(!str[i].empty())
        {
         nol++;
         var[i]=str[i][0];
         i++;
        }

    }
   // cout<<nol;
    for(x=0;x<nol;x++)
    {
        b=0;
        k=0;
        for(j=2;str[x][j]!='\0';j++)
        {
            if(str[x][j]=='|'||str[x][j]=='>')
            {
                j++;
                for(;str[x][j]!='\0'&&str[x][j]!='|';j++)
                    tok[x][k]+=str[x][j];

                j--;
                k++;
            }
        }
       // cout<<tok[0][0]<<endl;
       // cout<<tok[0][1]<<endl;
    label:
    flag=0;
    for(k=0;(!(tok[x][k].empty()))&&flag==0;k++)
    {
        for(j=k+1;(!(tok[x][j].empty()));j++)
        {
           alpha=compare(tok[x][k],tok[x][j]);
            //cout<<alpha;
           if(!alpha.empty())
           {
              // cout<<alpha;
               flag=1;
               break;

           }
        }
        if(flag==1)
            break;
    }


    int len;

       // cout<<tok[0][1]<<endl;
    //cout<<var[x];
    if(flag==1)
    {
        for(i=0;(!(tok[x][i].empty()));i++)
        {
            len=alpha.length();
            //cout<<"len"<<len<<endl;
           temp=compare(alpha,tok[x][i]);
           //cout<<temp;
           if(temp==alpha)
           {
               tok[x][i].erase(0,len);
               //cout<<tok[x][i]<<endl;
               if(tok[x][i].empty())
                beta[b]+="e";
               else
               beta[b]+=tok[x][i];
                //cout<<"beta:"<<beta[b]<<endl;
               // cout<<beta[b]<<endl;
               b++;
               j=i;
               do{
                tok[x][j]= tok[x][j+1];
                j++;
               }while((!(tok[x][j].empty())));


               i--;
           }
           //cout<<beta[0];

         }

          for(n=0;(!(tok[x][n].empty()));n++);
           // cout<<"1:"<<tok[x][n]<<endl;

            tok[x][n]+=alpha;
            tok[x][n]+=char(74+nol);
           // tok[x][n]+="'";

            goto label;
      }

    cout<<var[x]<<"->";
    fout<<var[x]<<"->";
    for(i=0;(!(tok[x][i].empty()));i++)
    {
        cout<<tok[x][i]<<"|";
        fout<<tok[x][i]<<"|";
    }
    fout.seekg(-1,ios::cur);
    cout<<'\b';
   cout<<" "<<endl;
   fout<<" "<<endl;
    //cout<<"---"<<beta[0]<<"---"<<endl;
    if(!beta[0].empty())
    {
        var[nol]=char(74+nol);
       // var[nol]+="'";
        for(i=0;i<b;i++)
        {
             tok[nol][i]=beta[i];
             beta[i].clear();
        }

        nol++;
    }
    }
    fstream fi,fo;
     string stri;
    fi.open("output2.txt",ios::in|ios::out);
    fo.open("output3.txt",ios::in|ios::out);
    while(!fi.eof())
    {

        getline(fi,stri,' ');

         if(!stri.empty())
         {

            fo<<stri;
         }

    }

 }

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
using namespace std;
int main()
{
    int i=0,n=0,j,k,flag=1,rec=74;
    string temp;
    string str[8],tok[20][20];
    char var[10];
    fstream fin,fout;
    fin.open("input.txt",ios::in);
    fout.open("output1.txt",ios::out);
    while(!fin.eof())
    {

        getline(fin,str[i]);
        if(!str[i].empty())
        {
            n++;
         var[i]=str[i][0];
         i++;
        }
    }
    i=0;
    for(i=0;i<n;i++)
    {
        k=0;
        for(j=2;str[i][j]!='\0';j++)
        {
            if(str[i][j]=='|'||str[i][j]=='>')
            {
                j++;
                for(;str[i][j]!='\0'&&str[i][j]!='|';j++)
                    tok[i][k]+=str[i][j];
                j--;
                k++;
            }
        }
    }

     label:
        for(i=1;i<n;i++)
        {
            for(j=i-1;j>=0;j--)
            {
                for(k=0;(!(tok[i][k].empty()));k++)
                {
                      if(tok[i][k][0]==var[j]&& tok[i][k].compare(tok[j][0])!=0)
                    {
                        flag=1;
                        tok[i][k].erase(tok[i][k].begin());
                        temp=tok[i][k];
                        int x=0,y=k;
                        tok[i][k].insert(0,tok[j][x]);
                        x++;
                        while(!(tok[i][y].empty()))
                            y++;
                        while(!(tok[j][x].empty()))
                        {
                            tok[i][y]=tok[j][x]+temp;
                            y++;
                            x++;
                        }
                    }
                }
            }
        }
    if(flag==1)
    {
        flag=0;
        goto label;
    }
    string alpha[10],beta[10];
    int m=0,x=0;
     for(i=0;i<n;i++)
         {
             for(j=0;(!(tok[i][j].empty()));j++)
             {
                  if(var[i]==tok[i][j][0])
                  {
                    for(k=0;(!(tok[i][k].empty()));k++)
                    {
                        if(var[i]==tok[i][k][0])
                        {
                            alpha[m].append(tok[i][k].begin()+1,tok[i][k].end());
                            m++;
                        }
                        else
                        {
                            beta[x].append(tok[i][k]);
                            x++;
                        }
                    }
                    cout<<var[i]<<"->";
                    fout<<var[i]<<"->";
                    for(k=0;(!(beta[k].empty()));k++)
                    {
                        cout<<beta[k]<<char(74+i)<<"|";
                        fout<<beta[k]<<char(74+i)<<"|";
                        beta[k].clear();
                    }
                    if(x==0)
                       {
                         cout<<char(74+i)<<"|";
                         fout<<char(74+i)<<"|";
                       }
                    cout<<'\b';
                    cout<<" ";
                    cout<<endl;
                    cout<<char(74+i)<<"->";
                    //fout<<char(74+i)<<"->";
                    fout.seekg(-1,ios::cur);
                    fout<<" ";
                    fout<<endl;
                    fout<<char(74+i)<<"->";
                    for(k=0;(!(alpha[k].empty()));k++)
                    {
                        cout<<alpha[k]<<char(74+i)<<"|";
                         fout<<alpha[k]<<char(74+i)<<"|";
                        alpha[k].clear();
                    }
                    cout<<"e"<<endl;
                      fout<<"e"<<endl;
                    m=0,x=0;
                    var[i]='0';
                    break;
                  }
             }
         }

         for(i=0;i<n;i++)
         {
             if(var[i]!='0')
             {

                 cout<<var[i]<<"->";
                 fout<<var[i]<<"->";

                 for(k=0;(!(tok[i][k].empty()));k++)
                 {
                     cout<<tok[i][k]<<"|";
                     fout<<tok[i][k]<<"|";
                 }

                 cout<<'\b';
                 fout.seekg(-1,ios::cur);
                 cout<<" "<<endl;
                 fout<<" "<<endl;
             }
         }
 }



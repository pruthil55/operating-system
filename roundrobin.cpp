#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int prcs,tq,atr[50],bt[50],ct[50],i,j,a,b,c,prono[50],wt[50],tat[50];
    cout<<"Enter no of process:";
    cin>>prcs;
    cout<<"Enter time quotient:";
    cin>>tq;
    for(i=0;i<prcs;i++)
    {
        cout<<"Enter arriving time for "<<i<<" process:";
        cin>>atr[i];
        cout<<"Enter bus time for "<<i<<" process:";
        cin>>bt[i];
        prono[i]=(i+1);
    }
    for (int i = 0; i < prcs; ++i)
    {
        for (int j = i + 1; j < prcs; ++j)
        {
            if(atr[i]==atr[j])
            {
              continue;
            }
            if (atr[i]>atr[j])
            {
                //sorting the process by AT
                a =  atr[i];
                atr[i] = atr[j];
                atr[j] = a;
                b=bt[i];
                bt[i]=bt[j];
                bt[j]=b;
                c=prono[i];
                prono[i]=prono[j];
                prono[j]=c;
            }
        }
    }
    ct[0]=atr[0]+bt[0];
    wt[0]=0;
    for(i=1; i<prcs; i++)
    {
        if(bt[i]<tq)
        {
            ct[i]=atr[i]+bt[i]+1;
        }
        else
        {
            int temp,tm=bt[i];
            if(bt[i]%2==0)
            {
                temp=0;
                while((tm/2)!=0)
                {
                    temp++;
                    tm=tm/2;
                }
                ct[i]=atr[i]+bt[i]+(temp*tq)+1;
            }
            else
            {
                temp=1;
                while((tm/2)!=0)
                {
                    temp++;
                    tm=tm/2;
                }
                ct[i]=atr[i]+bt[i]+(temp*tq)+1;
            }
        }
    }
    for(int i=0; i<prcs; i++)
    {
        tat[i]=ct[i]-atr[i];
        wt[i]=tat[i]-bt[i];
    }
    printf("\nProcess\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT\n");
    for(int j=0; j<prcs; j++)
    {
        printf("%d\t\t",prono[j]);
        printf("%d\t\t",atr[j]);
        printf("%d\t\t",bt[j]);
        printf("%d\t\t",ct[j]);
        printf("%d\t\t",tat[j]);
        printf("%d\t\t",wt[j]);
        printf("\n");
    }
    int ttlwt=0;
    int ttltat=0;
    for(int i=0; i<prcs; i++)
    {
        ttlwt+=wt[i];
        ttltat+=tat[i];
    }
    printf("\nAverage Turn Around Time=%f",(float)ttltat/prcs);
    printf("\nAverage Waiting Time=%f",(float)ttlwt/prcs);
    printf("\n\t\t\t\tThis is done by Parth Kanani\n\t\t\t\tID No:18CE038");
    return 0;
}

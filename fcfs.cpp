#include<iostream>
using namespace std;

class fcfs
{
    int arr[3];
public:

    int getstartingtime()
    {
        return arr[0];
    }
    int getendingtime()
    {
        return arr[2];
    }
    void setstartingtime(int st)
    {
        arr[0]=st;
    }
    void setendingtime(int en)
    {
        arr[2]=en;
    }
    void setprocessnumber(int p)
    {
        arr[1]=p;
    }
};
int main()
{
    cout<<"___________________________________  FCFS SCHEDULING  ______________________________________________";
    cout<<endl<<endl;
    int n,ct,st;
    cout<<"enter number of process:";
    cin>>n;
    int p[n]={0},AT[n],BT[n],comp_time[n],tat[n],wt[n];
    fcfs process[n];
    for(int i=0;i<n;i++)
    {
        cout<<endl<<"enter arrival time for process "<<i+1<<" : ";
        cin>>AT[i];
    }

    for(int j=0;j<n;j++)
    {
        cout<<endl<<"enter burst time for process "<<j+1<<" : ";
        cin>>BT[j];
    }
    int min_index=0;
    int temp=0,lol=0;
    while(temp<n)
    {
         for(int r=0;r<n;r++)
         {
            if(p[r]==0)
            {
                min_index=r;
                break;
            }
         }
        for(int l=0;l<n;l++)
        {
            if(AT[l]<AT[min_index] && p[l]==0)
            {
                min_index=l;
            }
            if(AT[l]==AT[min_index] && p[l]==0)
            {
                if(BT[l]<BT[min_index])
                {
                    min_index=l;
                }
                else
                {
                    min_index=min_index;
                }
            }
        }
        p[min_index]++;
        if(temp==0)
        {
            st=AT[min_index];
            ct=AT[min_index] + BT[min_index];
            lol=1;
        }
        else
        {
            if(process[temp-1].getendingtime()<AT[min_index])
            {
                st=AT[min_index];
                ct=AT[min_index]+BT[min_index];
            }
            else
            {
                st=process[temp-1].getendingtime();
                ct=process[temp-1].getendingtime()+BT[min_index];
            }

        }

        process[temp].setprocessnumber(min_index);
        process[temp].setstartingtime(st);
        process[temp].setendingtime(ct);
        comp_time[min_index]=process[temp].getendingtime();
        tat[min_index]=comp_time[min_index]-AT[min_index];
        wt[min_index]=tat[min_index] - BT[min_index];
        temp++;
    }
    float avg_tat=0,avg_wt=0;
    for(int f=0;f<n;f++)
    {
        avg_tat+=tat[f];
        avg_wt+=wt[f];
    }
    avg_tat/=n;
    avg_wt/=n;

    cout<<"_____________________________ process scheduled __________________________________"<<endl<<endl;
    cout<<"process \t AT \t BT \t CT \t TAT \t WT"<<endl;
    for(int s=0;s<n;s++)
    {
        cout<<s+1<<"\t\t"<<AT[s]<<"\t"<<BT[s]<<"\t"<<comp_time[s]<<"\t"<<tat[s]<<"\t"<<wt[s]<<endl;
    }

    cout<<"average turn around time: "<<avg_tat<<endl;
    cout<<"average waiting time: "<<avg_wt;
    return 0;
}

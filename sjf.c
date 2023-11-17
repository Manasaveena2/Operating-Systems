#include<stdio.h>
#include <stdlib.h>
int cur=0;
struct pro 
{
    int p,at,bt,v,ct,tat,wt;
};

void sort(int n,struct pro ps[])
{
	int i,j;
	for(i=1;i<n;i++)
	{
		for(j=1;j<n-i;j++)
		{
			if(ps[j].at>ps[j+1].at)
			{
				struct pro temp=ps[j];
				ps[j]=ps[j+1];
				ps[j+1]=temp;
			}
			else if(ps[j].at=ps[j+1].at)
			{
				if(ps[j+1].p<ps[j].p)
				{
					struct pro temp=ps[j];
					ps[j]=ps[j+1];
					ps[j+1]=temp;
				}
			}	
		}
	}
}	

int min(int n, struct pro ps[n])
{
    int m=0;
    int min=99999;

    for(int i=1;i<=n;i++)
    {
        if(ps[i].at<=cur && ps[i].bt<min && ps[i].v==-1)
        {
            m=i;
            min=ps[i].bt;
        }
    }
    return m;
}
void sjf(int n,struct pro ps[n])
{
    int i,j=n;
    while(j>0)
    {
        i=min(n,ps);
        //printf("%d :index",i);
        while(i==0)
        {
            cur++;
            i=min(n,ps);
        }  
            ps[i].ct=cur+ps[i].bt;
            ps[i].tat=ps[i].ct-ps[i].at;
            ps[i].wt=ps[i].tat-ps[i].bt;
            cur=ps[i].ct;

        ps[i].v=0;
        j--;
    }
}
void main()
{
    int n,i;
    float avt,aw;
    printf("enter the size\n");
    scanf("%d",&n);
    struct pro *ps;
    ps=(struct pro*)malloc(n*sizeof(struct pro*));
    for(i=1;i<=n;i++)
    {
        ps[i].p=i;
        ps[i].v=-1;
        scanf("%d %d",&ps[i].at,&ps[i].bt);
    }
    sort(n,ps);
    printf("Sorted\n");
    for(i=1;i<=n;i++)
    {
        printf("%d %d %d\n",ps[i].p,ps[i].at,ps[i].bt);
    }
    sjf(n,ps);
    
    printf("Completion times \n");
    for(i=1;i<=n;i++)
    {
        printf("%d\t",ps[i].ct);
    }
    printf("\ntat times \n");
    for(i=1;i<=n;i++)
    {
        printf("%d\t",ps[i].tat);
        avt=avt+ps[i].tat;
    }
     printf("\nwaiting times \n");
    for(i=1;i<=n;i++)
    {
        printf("%d\t",ps[i].wt);
        aw=aw+ps[i].wt;
    }
    //printf("sum tat=%f",avt);
    avt=avt/n;
    aw=aw/n;
    printf("\nAvg tat=%f and Avg wt=%f\n",avt,aw);
}

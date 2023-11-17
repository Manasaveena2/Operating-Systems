#include<stdio.h>
void find_time(int n,int at[],int bt[])
{
  int ct[50],time,i,wt[50],tat[50];
  ct[0]=at[0]+bt[0];
  time=ct[0];
  for(i=1;i<n;i++)
  {
    if(time<at[i])
    {
      ct[i]=at[i]+bt[i];
      time=ct[i];
    }
    else{
      ct[i]=time+bt[i];
      time=ct[i];
   }
 }
 for(i=0;i<n;i++)
 {
   tat[i]=ct[i]-at[i];
   wt[i]=tat[i]-bt[i];
 }
 int atat=0,awt=0;
 for(i=0;i<n;i++)
 {
   atat=atat+tat[i];
   awt=awt+wt[i];
 }
 for(i=0;i<n;i++)
 {
   printf("%d   %d   %d   %d   %d",at[i],bt[i],ct[i],tat[i],wt[i]);
   printf("\n");
 }
 printf("avg turn around time is %d\n",atat);
 printf("avg waiting time is %d\n",awt);
 }
void main()
{
   int n,at[50],bt[50],i,j;
   printf("Enter no.of processes:");
   scanf("%d",&n);
   for(i=0;i<n;i++)
     scanf("%d %d",&at[i],&bt[i]);
   for(i=0;i<n;i++)
   {
     for(j=0;j<n-i-1;j++)
     {
       if(at[j]>at[j+1])
       {
         int temp1=at[j];
         int temp2=bt[j];
         at[j]=at[j+1];
         bt[j]=bt[j+1];
         at[j+1]=temp1;
         bt[j+1]=temp2;
      }
   }
 }
  find_time(n,at,bt);
}

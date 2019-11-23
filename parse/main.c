#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int r=0,c=0;
char item[50],item[50];
char a[30][30][20]={
{"S","K","$"},
{"K","int","A","$"},
{"K","for","(","Z",")","$"},
{"K","if","(","C",")","$"},
{"K","begin","$"},
{"K","end","$"},
{"A","main","(",")","$"},
{"A","L","$"},
{"L","W",",","X",",","Y",",","D","$"},
{"W","n1","$"},
{"Y","i","$"},
{"X","n2","$"},
{"D","gcd","$"},
{"C","E","R","E","$"},
{"E","n1","$"},
{"E","n2","$"},
{"E","i","$"},
{"R","=","$"},
{"R","<=","$"},
{"R","<","$"},
{"R",">=","$"},
{"R",">","$"},
{"R","<>","$"},
{"R","==","$"},
{"N","D","R","Y","$"},
{"Z","Y","R","1",";","E","R","E",";","++","Y","$"},
{"K","N","$"},
{"Y","1","$"},
};
char b[49][45][10]={
{"S","int","0"},
{"S","for","0"},
{"S","begin","0"},
{"S","end","0"},
{"S","if","0"},
{"S","gcd","0"},
{"K","int","1"},
{"K","begin","4"},
{"K","for","2"},
{"K","if","3"},
{"K","end","5"},
{"A","n1","7"},
{"A","n2","7"},
{"A","i","7"},
{"A","1","7"},
{"A","gcd","7"},
{"A","main","6"},
{"L","n1","8"},
{"L","n2","8"},
{"L","i","8"},
{"L","gcd","8"},
{"L","1","8"},
{"C","n1","13"},
{"C","n2","13"},
{"C","i","13"},
{"E","n1","14"},
{"E","n2","15"},
{"E","i","16"},
{"R","<","19"},
{"R","<=","18"},
{"R",">","21"},
{"R",">=","20"},
{"R","<>","22"},
{"R","==","23"},
{"R","=","17"},
{"N","gcd","24"},
{"Z","i","25"},
{"Z","1","25"},
{"Z","1","25"},
{"Z","n1","25"},
{"Z","n2","25"},
{"Z","++","25"},
{"W","n1","9"},
{"X","n2","11"},
{"Y","i","10"},
{"D","gcd","12"},
{"K","gcd","26"},
{"Y","1","27"},
};
int prod(int x , char str[]);
char stack[20][110];
char queue[20][100];
char *token;
int count;
int l=0,i,k,front=0,rear=-1,state=1,r;
char str[50],stp[100];
int main()
{
int x;
strcpy(stack[r],"S");
printf("Enter the string to be parsed\n (with $ at the end )\n");
while(strcmp(queue[rear],"$")!=0)
{
rear++;
scanf("%s",queue[rear]);
}
l1:
strcpy(stp,queue[front]);
if((strcmp(stp,")")==0)||(strcmp(stp,"(")==0)||(strcmp(stp,";")==0)||(strcmp(stp,",")==0)||
(strcmp(stp,"1")==0)||(strcmp(stp,"0")==0))
{
printf("%s matched\n",stp);
front++;
r++;
goto l1;
}
while(strcmp(stp,"$")!=0)
{
for(i=0;i<49;i++)
{
strcpy(str,stack[r]);
strcpy(stp,queue[front]);
if((strcmp(b[i][0],str)==0)&&(strcmp(b[i][1],stp)==0))
{
x=atoi(b[i][2]);
r=prod(x,str);
}
else if((strcmp(str,stp))==0)
{
strcpy(item,queue[front]);
printf("%s matched\n",item);
front++;
strcpy(str,queue[front]);
strcpy(item,stack[r]);
r++;
goto l1;
}
}
}
if(strcmp(stack[r],"\0")!=0)
{
printf("not correct syntax\n");
}
else{
printf("Valid syntax\n");
}
return 0;

}
int prod(int x,char str[])
{
char stq[100];
int y=1,count=0;
printf("%s ->",a[x][0]);
l2 : strcpy(stq,a[x][y]);
while(strcmp(stq,"$")!=0)
{
strcpy(str,stq);
printf("%s",str);
strcpy(stack[r],str);
count++;
r++;y++;
goto l2;
}
if(count>r)
{
r = count-r;
}
else
{
r = r-count;
}
printf("\n");
return r;
}


//This is not an completely optimized code 
//but it performs the intended functionality
//i will try to optimized the code and reduce the number of lines in up coming days 
#include <stdio.h>
#include <string.h>
char crc[]="101";
typedef enum {
    GPIO0,
    GPIO1,
    GPIO2,
    GPIO3,
    GPIO4
}reg_name;
typedef struct{
    reg_name r;
    int reg_adrs : 10;
    int reg_data : 16;
}reg;
char *int_str(reg r)
{   
    static char t[50];
    int i=0;
    while(r.reg_adrs/2!=0)
    {
        t[i]=(r.reg_adrs%2)+'0';
        r.reg_adrs/=2;
        i++;
    }
    t[i++]=(r.reg_adrs%2)+'0';
    t[i]='\0';
    int l=strlen(t);
    for(int i=0;i<l/2;i++)
    {
        int temp=t[i];
        t[i]=t[l-1-i];
        t[l-1-i]=temp;
    }
    t[i]='\0';

    return t;
}
char *int_str1(reg r)
{   
    static char t1[50];
    int i=0;
    while(r.reg_data/2!=0)
    {
        t1[i]=(r.reg_data%2)+'0';
        r.reg_data/=2;
        i++;
    }
    t1[i++]=(r.reg_data%2)+'0';
    t1[i]='\0';
    int l=strlen(t1);
    for(int i=0;i<l/2;i++)
    {
        int temp=t1[i];
        t1[i]=t1[l-1-i];
        t1[l-1-i]=temp;
    }
    t1[i]='\0';

    return t1;
}
char *int_str2(int r)
{   
    static char t8[50];
    int i=0;
    while(r/2!=0)
    {
        t8[i]=(r%2)+'0';
        r/=2;
        i++;
    }
    t8[i++]=(r%2)+'0';
    t8[i]='\0';
    int l=strlen(t8);
    for(int i=0;i<l/2;i++)
    {
        int temp=t8[i];
        t8[i]=t8[l-1-i];
        t8[l-1-i]=temp;
    }
    t8[i]='\0';

    return t8;
}
char *read(reg r)
{   
    //
    char *t2=int_str(r);
    int l=strlen(t2);
    static char temp[11];
    for(int i=0;i<10-l;i++)
    {
        temp[i]='0';
    }
    int j=0;
    for(int i=10-l;i<10;i++)
        temp[i]=t2[j++]; 
    temp[11]='\0';
    //
    char *t3=int_str1(r);
    int l1=strlen(t3);
    static char temp1[17];
    for(int i=0;i<16-l1;i++)
    {
        temp1[i]='0';
    }
    int k=0;
    for(int i=16-l1;i<16;i++)
        temp1[i]=t3[k++]; 
    temp1[17]='\0';
    //
    static char temp3[100];
    sprintf(temp3,"0|0|%s|%s|%s|0",temp,temp1,crc);
    return temp3;
}
char *write(reg r,int a)
{   
    //
    char *t2=int_str(r);
    int l=strlen(t2);
    static char tem[11];
    for(int i=0;i<10-l;i++)
    {
        tem[i]='0';
    }
    int j=0;
    for(int i=10-l;i<10;i++)
        tem[i]=t2[j++]; 
    tem[11]='\0';
    //
    char *t3=int_str2(a);
    int l1=strlen(t3);
    static char tem1[17];
    for(int i=0;i<16-l1;i++)
    {
        tem1[i]='0';
    }
    int k=0;
    for(int i=16-l1;i<16;i++)
        tem1[i]=t3[k++]; 
    tem1[17]='\0';
    //
    static char temp3[100];
    sprintf(temp3,"1|0|%s|%s|%s|0",tem,tem1,crc);
    return temp3;
}
int main()
{
    reg r[]={{GPIO0,0,10},
            {GPIO1,1,20},
            {GPIO2,2,30},
            {GPIO3,3,40},
            {GPIO4,4,50}};
    char *t=read(r[4]);
    char *p=write(r[4],45);
    printf("%s\n%s",t,p);
    printf("Change from MAIN branch\n");
return 0;
}

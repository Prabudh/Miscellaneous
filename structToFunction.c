#include<stdio.h>
struct person 
{
 int income;
 int taxrefund,sum;
};

typedef enum eHttpdLogMsgType
{
    HTTPD_LOG_OTHER,
    HTTPD_LOG_CONFIG,
    HTTPD_LOG_BP_RX,
    HTTPD_LOG_BP_TX,
    HTTPD_LOG_HTTPC_RX,
    HTTPD_LOG_HTTPC_TX,
    HTTPD_LOG_DRV_RX,
    HTTPD_LOG_DRV_TX,
    HTTPD_LOG_TIMER,
    HTTPD_LOG_CONN,
    HTTPD_LOG_PARSER,
    HTTPD_LOG_CONN_REL,
    HTTPD_LOG_CONN_HOLD,
}eHttpdLogMsgType;


typedef struct xyz 
{
   char name;
   int minNum; 
}xyz;
 
xyz a[HTTPD_LOG_BP_RX] =
{
  [HTTPD_LOG_OTHER]
  {
      .name   =   "Dfrag",
      .minNum =    0
  },
  [HTTPD_LOG_CONFI]
  {
      .name   = "Prabu"
      .minNum =   1
  },
};

printf("%c,%d",a[9][0].name,a[9][1].minNum);


main()
{

char *HttpdMsgTypeStr[] = 
{
    [HTTPD_LOG_OTHER]       "OTHER",
    [HTTPD_LOG_CONFIG]      "CONFIG",
    [HTTPD_LOG_BP_RX]       "BP_RX",
    [HTTPD_LOG_BP_TX]       "BP_TX",
    [HTTPD_LOG_HTTPC_RX]    "HTTPC_RX",
    [HTTPD_LOG_HTTPC_TX]    "HTTPC_TX",
    [HTTPD_LOG_DRV_RX]      "DRV_RX",
    [HTTPD_LOG_DRV_TX]      "DRV_TX",
    [HTTPD_LOG_TIMER]       "TIMER",
    [HTTPD_LOG_CONN]        "CONN",
    [HTTPD_LOG_PARSER]      "PARSER",
    [HTTPD_LOG_CONN_HOLD]   "CONN_HOLD",
    [HTTPD_LOG_CONN_REL]    "CONN_REL",
};

int abc[0] = 
{
   [HTTPD_LOG_OTHER]
   {
      .name   =  "Dfrag",
   },
   [HTTPD_LOG_CONFIG]
   {
      .name  = "Dfrag-ipc",
   },
};


 



printf("%s %d",HttpdMsgTypeStr[HTTPD_LOG_HTTPC_RX],HTTPD_LOG_HTTPC_RX);





struct person me;
struct person getinfo(),calcInfo();
void printInfo();
me = getinfo();
me = calcInfo(me);
printInfo(me);
}

struct person getinfo()
{
struct person you;
scanf("%d",&you.income);
scanf("%d",&you.taxrefund);
return you;
}

struct person calcInfo(you)
struct person you;
{
you.sum = you.income+you.taxrefund;
return you;
}

void printInfo(you)
struct person you;
{
printf("you.sum = %d",you.sum);
}




#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Violation{
    char code[7];
    char location[4];
    char date[11];
    int handled;
    struct Violation*next;
}Violation;

typedef struct Vehicle{
    char plate[6];
    Violation*violations;
    char model[20];
    char purchase_date[11];
    double price;
    char driver[20];
}Vehicle;

Vehicle vehicles[110];
int vehicle_count=0;

int find_vehicle(char*plate){
    for(int i=0;i<vehicle_count;i++){
        if(strcmp(vehicles[i].plate,plate)==0)return i;
    }
    return -1;
}

void add_violation(char*plate,char*code,char*loc,char*date,int handled){
    int idx=find_vehicle(plate);
    if(idx==-1)return;

    Violation*curr=vehicles[idx].violations;
    while(curr){
        if(strcmp(curr->code,code)==0&&
           strcmp(curr->location,loc)==0&&
           strcmp(curr->date,date)==0){
           curr->handled=handled;
           return;
        }
        curr=curr->next;
    }

    Violation*new_vio=(Violation*)malloc(sizeof(Violation));
    strcpy(new_vio->code,code);
    strcpy(new_vio->location,loc);
    strcpy(new_vio->date,date);
    new_vio->handled=handled;
    new_vio->next=vehicles[idx].violations;
    vehicles[idx].violations=new_vio;
}

int get_query_type(char *query){
    int len=strlen(query);
    // 检查是否为车牌号
    if(len==5){
        for(int i=0;i<5;i++){
            if(query[i]>'9'||query[i]<'0')break;
            if(i==4)return 1;
        }
    }
    //检查是否为违章代码
    if(len==3){
        for(int i=0;i<3;i++){
            if(query[i]>'9'||query[i]<'0')break;
            if(i==2)return 2;
        }
    }
    //检查是否为地点代号
    if (len==3){
        for(int i=0;i<3;i++){
        if(query[i]<'A'||query[i]>'Z')break;
        if(i==2)return 3;
        }
    }
    // 检查是否为时间（XXXX-XX-XX）
    if (len==10&&query[4]=='-'&&query[7]=='-'){
        for(int i=0;i<10;i++){
            if(i==4||i==7)continue;
            if(query[i]>'9'||query[i]<'0')return 0;
        }
        return 4;
    }
    return 0;
}

// 查询并输出结果
void process_query(char* query, int type) {
    int count = 0;
    // 第一次遍历统计数量
    for (int i = 0; i < vehicle_count; i++) {
    Violation* curr = vehicles[i].violations;
    while (curr) {
    if (curr->handled == 0) {
    int match = 0;
    switch (type) {
    case 1: match = (strcmp(vehicles[i].plate, query) == 0);
   break;
    case 2: match = (strcmp(curr->code, query) == 0); break;
    case 3: match = (strcmp(curr->location, query) == 0); break;
    case 4: match = (strcmp(curr->date, query) == 0); break;
 }
 if (match) count++;
 }
 curr = curr->next;
 }
 }
 printf("%d\n", count);
 // 第二次遍历输出详情
 for (int i = 0; i < vehicle_count; i++) {
 Violation* curr = vehicles[i].violations;
 while (curr) {
 if (curr->handled == 0) {
 int match = 0;
 switch (type) { 
 case 1: match = (strcmp(vehicles[i].plate, query) == 0);
break;
 case 2: match = (strcmp(curr->code, query) == 0); break;
 case 3: match = (strcmp(curr->location, query) == 0); break;
 case 4: match = (strcmp(curr->date, query) == 0); break; 
}
 if (match) {
 printf("%s%s%s%s\n",vehicles[i].plate,curr->code,curr->location,curr->date);
 }
 }
 curr = curr->next;
 }
 }
}
int main(){
char signword[10];//输入信号词
int n;
scanf("%s",signword);
if(strcmp(signword,"car")==0){
scanf("%d",&n);
for(int i=0; i<n; i++) {
 scanf("%s",vehicles[vehicle_count++].plate);
 }
}
scanf("%s",signword);
 if(strcmp(signword,"violation")==0) {
 int n;
 scanf("%d",&n);
 for (int i=0; i<n; i++) {
 char plate[6], code[7], loc[4], date[11];
 int handled;
 scanf("%s%s%s%s%d",plate, code, loc, date, &handled);
 add_violation(plate, code, loc, date, handled);
 }
 }
 scanf("%s",signword);
 if (strcmp(signword, "query") == 0) {
    char query[11];
    scanf("%s",query);
    int type = get_query_type(query);
    process_query(query, type);
    }
    //释放内存
    for (int i=0; i<vehicle_count; i++) {
    Violation* curr = vehicles[i].violations;
    while (curr) {
    Violation* tmp = curr;
    curr = curr->next;
    free(tmp);
    }
    }
   return 0;
}
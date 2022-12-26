//
// Created by 20663 on 2022/12/23.
//tokens 从0开始!!!!!!
//bianliang 也从0开始!!!!!!
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cut = 0;//统计bianliang个数
typedef struct tokens{
    enum {
        tokens_int,
        tokens_float,
        tokens_operater,
        tokens_valuaian,
    }tokens_type;
    int tokens_len;
    char tokens_name[250];
}Tokens;

typedef struct gettings{
    enum {
        gettings_int,
        gettings_float,
        gettings_error,
    }gettings_type;
    double gettings_fl;
    int gettings_in;
}Gettings;

typedef struct bianliang{
    Gettings gettings;
    char bianliang_name[250];
    int bianliang_len;
}Bianliang;

Tokens tokens[250];
Bianliang B[130];

//int Isalphabet(char c){
//    }
//    return 0;
//}
//int IsInteger(char c){
//    if (c >= '0' && c <= '9'){
//        return 1;
//    }
//    return 0;
//}

int fenxi(Tokens *X) {
    int len =X->tokens_len;
    if (len==0){
        return 0;
    }
    if (len == 1 && (X->tokens_name[0] == '+' ||X->tokens_name[0] == '-'||X->tokens_name[0] == '*'||X->tokens_name[0] == '/'||X->tokens_name[0] == '='||X->tokens_name[0] == '('||X->tokens_name[0] == ')')){
        X->tokens_type = tokens_operater;
        return 1;
    }
    int countalph=0;
    int countdot=0;
    int countinte=0;
    for(int i=0;i<len;i++){
        if(X->tokens_name[i] == '_'||(X->tokens_name[i] >= 'A'&&X->tokens_name[i] <='Z' )||(X->tokens_name[i] >='a'&&X->tokens_name[i] <='z'  )){
            countalph++;
        }else if(X->tokens_name[i]>='0'&&X->tokens_name[i]<='9'){
            countinte++;
        }else if(X->tokens_name[i]== '.' ){
            countdot++;
        }else{
            return 0;
        }
    }
    if(countinte == len &&len>0){
        if(len == 1){
            X->tokens_type = tokens_int;
            return 1;
        }if(len > 1){
            if (X->tokens_name[0]=='0'){
                return 0;
            }
            else{
                X->tokens_type = tokens_int;
                return 1;
            }
        }
    }
    if(countalph){
        if(!countdot&&(X->tokens_name[0]<'0'||X->tokens_name[0]>'9')){
            X->tokens_type =tokens_valuaian;
            return 1;
        }
        else{
            return 0;
        }
    }
    if(countdot == 1 && countinte == len -1){
        if(len==1){
            return 0;
        }
        else{
            if(X->tokens_name[0]=='.'||X->tokens_name[len-1]=='.'||(X->tokens_name[0]=='0'&&X->tokens_name[1]!='.')){
                return 0;
            } else{
                X->tokens_type =tokens_float;
                return 1;
            }
        }
    }
    return 0;
}
int Isbianliang(int l){
    int leen2=tokens[l].tokens_len;
    for(int w = 1 ;w<=cut;w++) {
//        if (!strcmp(s, B[w].bianliang_name)){
//            return w;
//        }
    int leen=B[w].bianliang_len;

    if(leen!=leen2){
        continue;
    }
        int boool=1;
    for(int oo=0;oo<leen;oo++){
        if(tokens[l].tokens_name[oo]!=B[w].bianliang_name[oo]){
            boool=0;
            break;
        }
    }if(boool){
            return w;
    }
    }
    return 0;
}
int kuohao(int l,int r){
    int pop=0;
    int pp2=0;
    for(int i=l;i<=r;i++){
        if(tokens[i].tokens_name[0]=='('){
            pop++;
        }
        else if(tokens[i].tokens_name[0]==')'){
            if(pop>0){
                pop--;
            }
            else{
                return -1;
            }
        }
    }
    if(pop!=0){
        return -1;
    }
    if(tokens[l].tokens_name[0]!='('||tokens[r].tokens_name[0]!=')'){
        return 1;
    }
    for(int i=l+1;i<=r-1;i++){
        if(tokens[i].tokens_name[0]=='('){
            pp2++;
        }
        else if(tokens[i].tokens_name[0]==')'){
            if(pp2>0){
                pp2--;
            }
            else{
                return 1;
            }
        }
    }if(pp2!=0){
        return 1;
    }
    return 0;
}
Gettings caozuo(Gettings x,Gettings y,char fuhao){
    Gettings teep;
    if(x.gettings_type==gettings_error||y.gettings_type==gettings_error){
        teep.gettings_type=gettings_error;
        return teep;
    }
    else if(x.gettings_type==gettings_float&&y.gettings_type==gettings_float){
        teep.gettings_type=gettings_float;
        switch (fuhao) {
            case '+':
                teep.gettings_fl=x.gettings_fl+y.gettings_fl*1.0;
                break;
            case '-':
                teep.gettings_fl=x.gettings_fl-y.gettings_fl*1.0;
                break;
            case '*':
                teep.gettings_fl=x.gettings_fl*y.gettings_fl*1.0;
                break;
            case '/':
                teep.gettings_fl=x.gettings_fl/y.gettings_fl*1.0;
                break;
            default:
                teep.gettings_type=gettings_error;
                break;


        }
    }
    else if(x.gettings_type==gettings_int&&y.gettings_type==gettings_float){
        teep.gettings_type=gettings_float;
        switch (fuhao) {
            case '+':
                teep.gettings_fl=x.gettings_in*1.0+y.gettings_fl;
                break;
            case '-':
                teep.gettings_fl=x.gettings_in*1.0-y.gettings_fl;
                break;
            case '*':
                teep.gettings_fl=x.gettings_in*1.0*y.gettings_fl;
                break;
            case '/':
                teep.gettings_fl=x.gettings_in*1.0/y.gettings_fl;
                break;
            default:
                teep.gettings_type=gettings_error;
                break;


        }
    }
    else if(x.gettings_type==gettings_float&&y.gettings_type==gettings_int){
        teep.gettings_type=gettings_float;
        switch (fuhao) {
            case '+':
                teep.gettings_fl=x.gettings_fl+y.gettings_in*1.0;
                break;
            case '-':
                teep.gettings_fl=x.gettings_fl-y.gettings_in*1.0;
                break;
            case '*':
                teep.gettings_fl=x.gettings_fl*y.gettings_in*1.0;
                break;
            case '/':
                teep.gettings_fl=x.gettings_fl/y.gettings_in*1.0;
                break;
            default:
                teep.gettings_type=gettings_error;
                break;


        }
    }
    else{
        teep.gettings_type=gettings_int;
        switch (fuhao) {
            case '+':
                teep.gettings_in=x.gettings_in+y.gettings_in;
                break;
            case '-':
                teep.gettings_in=x.gettings_in-y.gettings_in;
                break;
            case '*':
                teep.gettings_in=x.gettings_in*y.gettings_in;
                break;
            case '/':
                teep.gettings_in=x.gettings_in/y.gettings_in;
                break;
            default:
                teep.gettings_type=gettings_error;
                break;


        }
    }
    return teep;
}
Gettings deal(int l,int r){
    Gettings tem;
    if(l>r){
        tem.gettings_type = gettings_error;
        return tem;
    }
    if(l==r){
        if(tokens[l].tokens_type==tokens_int){
            int len1=tokens[l].tokens_len;
            char  *ss;
            tokens[l].tokens_name[len1]='\0';
            ss=tokens[l].tokens_name;
            tem.gettings_in= atoi(ss);
//            tem.gettings_in=0;
//            for(int h=0;h<tokens[l].tokens_len;h++){
//                tem.gettings_in=tem.gettings_in*10+(tokens[l].tokens_name[h]-'0');
//            }
            ////for (int i = 0; i < x.le; i++) res.val.ival = res.val.ival * 10 + (x.name[i] - '0');
            //tem.gettings_in=num;
            tem.gettings_type=gettings_int;
            return tem;
        }
        else if(tokens[l].tokens_type==tokens_float){
            int len2=tokens[l].tokens_len;
            tem.gettings_type=gettings_float;
            char  *sss;
            tokens[l].tokens_name[len2]='\0';
            sss=tokens[l].tokens_name;
            tem.gettings_fl= atof(sss);
//            int p = 0;
//        for (int g = 0; g < tokens[l].tokens_len; g++) {
//            if (tokens[l].tokens_name[g] == '.') {
//                p = g;
//                break;
//            }
//        }
//        for (int i = 0; i < p; i++) {
//            tem.gettings_fl = tem.gettings_fl * 10.0 + (tokens[l].tokens_name[i] - '0');
//        }
//        double pp = 0.1;
//        for (int i = p + 1; i < tokens[l].tokens_len; i++) {
//            tem.gettings_fl += pp * (tokens[l].tokens_name[i] - '0');
//            pp *= 0.1;
//        }

            return tem;
        }
        else if(tokens[l].tokens_type==tokens_valuaian){
            int yy=Isbianliang(l);
            if(yy>0){
                tem = B[yy].gettings;
                return tem;
            }
            else{
                tem.gettings_type=gettings_error;
                return tem;
            }
        }
        else{
            tem.gettings_type=gettings_error;
            return tem;
        }
    }
        int uu= kuohao(l,r);
        if(uu==-1){
            tem.gettings_type=gettings_error;
            return tem;
        }
        if(uu==0){
            return deal(l+1,r-1);
        }
            int count1 = 0;
            int count2 = -1;
            for(int iii = l ;iii<=r;iii++){
                char k = tokens[iii].tokens_name[0];
                if(k=='('){
                    count1++;
                    continue;
                }
                if(k==')'){
                    count1--;
                    continue;
                }
                if(tokens[iii].tokens_type==tokens_operater&&count1==0){
                    if(iii) {
                        char kk = tokens[iii - 1].tokens_name[0];
                        if ((kk == '+' || kk == '-' || kk == '*' || kk == '/') && iii != l) {
                            continue;
                        }
                    }
                    if(count2==-1){
                        count2=iii;
                    }
                    else{
                        if(k=='+'||k=='-'){
                            count2=iii;
                        }
                        else{
                            char kkk=tokens[count2].tokens_name[0];
                            if(kkk=='*'||kkk=='/'){
                                count2=iii;
                            }
                        }
                    }
                }
            }
            if(count2==-1){
                tem.gettings_type=gettings_error;
                return tem;
            }
            else if(count2==l){
                if(tokens[count2].tokens_name[0]=='-'){
                    tem.gettings_type=gettings_int;
                    tem.gettings_in=-1;
                    return caozuo(tem, deal(l+1,r),'*');
                }
                else{
                    tem.gettings_type=gettings_error;
                    return tem;
                }
            }
            else{
                return caozuo(deal(l,count2-1), deal(count2+1,r),tokens[count2].tokens_name[0]);
            }

}
void printt(Gettings x){
    if(x.gettings_type==gettings_float){
        printf("%.6lf\n",x.gettings_fl);
    }
    else if(x.gettings_type==gettings_int){
        printf("%d\n",x.gettings_in);
    }
    else{
        printf("Error\n");
    }
}

int main(){
//    memset(tokens,0,sizeof tokens);
//    memset(B,0, sizeof(B));
    char s[250];
    while (gets(s)){
        int len=strlen(s);
        int i=0;
        int teem=0;//每一行的输入个数
        while (i<len){
            int pp = 0;
            while (s[i] != ' ' && i < len){
                tokens[teem].tokens_name[pp]=s[i];
                pp++;
                i++;
            }tokens[teem].tokens_len=pp;
            i++;
            teem++;
        }int flag = 1;
        for (int ii=0 ; ii<teem;ii++){
            if(!fenxi(tokens+ii)){
                flag = 0;
                break;
            }
        }
        if(!flag){
            printf("Error\n");
            continue;
        }
        int judge=0;
        int last =0;
        for(int q=teem-1 ;q>=0;q--){
            if(tokens[q].tokens_name[0]=='='){
                judge=1;
                last=q;
                break;
            }
        }
//        for(int p=0;p<teem;p++){
//            printf("%d ",tokens[p].tokens_len);
//        }
//        printf("%d %d\n",last,teem);//debug 时使用
        if(!judge){
            Gettings jieguo;
            jieguo= deal(0,teem-1);
            if(jieguo.gettings_type==gettings_error){
                printf("Error\n");
                continue;
            }
            printt(jieguo);
            continue;

        }
        else{
            for (int q =0;q<last;q++){
                if((q%2==0)&&(tokens[q].tokens_type!=tokens_valuaian)){
                    printf("Error\n");
                    continue;
                }
                if((q%2)&&(tokens[q].tokens_name[0]!='=')){
                    printf("Error\n");
                    continue;
                }
            }
            Gettings finally = deal(last+1,teem-1);
            if(finally.gettings_type==gettings_error){
                printf("Error\n");
                continue;
            }
            for(int jj = 0;jj<last;jj++){
                if(tokens[jj].tokens_type!=tokens_valuaian){
                    continue;
                }
                int po= Isbianliang(jj);
                if(po){
                    B[po].gettings=finally;
//                    int leeeeen=tokens[jj].tokens_len;
//                    B[po].bianliang_len=leeeeen;
//                    for(int lll=0;lll<leeeeen;lll++){
//                        B[cut].bianliang_name[lll]=tokens[jj].tokens_name[lll];
//                    }
                }
                else{
                    cut++;
                    B[cut].bianliang_len=tokens[jj].tokens_len;
                    B[cut].gettings=finally;
                    int leeeen=tokens[jj].tokens_len;
                    for(int ll=0;ll<leeeen;ll++){
                        B[cut].bianliang_name[ll]=tokens[jj].tokens_name[ll];
                    }
                }
            }
            printt(finally);
            continue;


        }
//debug 时的数据
//        for (int ii=0 ; ii<teem;ii++){
//            printf("%d ", fenxi(tokens+ii));
//            printf("%d\n",tokens[ii].tokens_type);
//        }
        //printf("%d\n%d\n",teem,tem);





    }
    return 0;
}

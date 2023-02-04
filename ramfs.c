#include "ramfs.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/* modify this file freely */
//由于都是绝对路径,所以针对单个文件遍历文件树查找的函数可以省略


//fd从0开始!!!
//0<=fd<4096
//int fds[4096]={0};

typedef struct node {
    enum { FILE_NODE, DIR_NODE } type;
    //int id_node;//判断在第几层
    void *filecontent; // if it's a file, there's data content
    int dirnumber; // number of subentries for dir总体的,包括已删除的
    int realdirnumber;//真正存在的个数
    int size; // size of file
    char name[33]; // it's short name//只可读,可以起到节省内存的作用
    struct node **dirnext;// if it's a dir, there's subentries
    //struct node *left;
} Node;


typedef struct fd {
    int offset;
    int flags;
    Node *f;
} FD;

FD *fds[4097];
//int dirnumber[4097]

typedef struct tree {
    Node *first;
}Tree;

Tree tree;


//得到一个活跃的fd
//fd是从0开始的!!!
int getfreefd(){
    for(int i=1;i<=4096;i++){
        if(fds[i]==NULL){
            return i;
        }
    }
    return -1;
}

//看是否fd溢出或者并未活跃
int checkout(int number){
    if(number<=0||number>4096){
        return -1;
    }
    if(fds[number]!=NULL){
        return number;
    }

    return -1;
}

//该函数返回值为其后面的长条子目录
//fathername为该段的父目录
//正常最后一轮是NULL
//但是如果开头不合法，即不是以'/'开头，返回值和传入路径相同
char *pathchasing(char *pathname,char *fathername){
    if(pathname[0]=='\0'){
        return NULL;
    }
    if( pathname[0] == '/'){
        pathname++;
        while (*pathname == '/'){
            pathname++;
        }
        while (*pathname!='/'&&*pathname!='\0'){
            *fathername=*pathname;
            fathername++;
            pathname++;
        }
    }
    return pathname;
}
//计算路径深度
//不合法的情况为-1
int pathdepth(char *pathname){
    char *p=pathname;
    char tempname[33];
    if(pathname==NULL||!strcmp(pathname, pathchasing(p,tempname))){
        return -1;
    }
    int depth=0;
    memset(tempname,0,33);
    p= pathchasing(p,tempname);
    while (tempname[0]){
        depth++;
        memset(tempname,0,33);
        if(p[0]){
            p= pathchasing(p,tempname);
        }
    }
    return depth;
}

void init_node(Node *node){
    memset(node->name,0,33);
    node->dirnumber=0;
    node->realdirnumber=0;
    node->dirnext=NULL;
    node->size=0;
    node->filecontent=NULL;
    //node->left=NULL;
}
//其实并未用到该函数
//根据路径的文件名查找文件或者目录
//找到即返回对应结点指针,找不到返回NULL
//dirnumber从0开始,故最后遍历到dirnumber-1即可
//为统一形式,统一将参数变为node,当然传入的是tree.first
Node *searchnode(Node *node,char *singlepathname){
    if(node==NULL){
        return NULL;
    }
    if(!strcmp(node->name,singlepathname)){
        return node;
    }
    int nrde=node->dirnumber;
    Node *t=NULL;
    for(int i=0;i<nrde;i++) {
        if(node->dirnext[i]!=NULL){
            t = searchnode(node->dirnext[i], singlepathname);
            if (t != NULL) {
                return t;
            }
        }
    }
    return NULL;
}

//用于查找所在目录或文件的上一层目录
//若找不到则返回NULL
Node *isalineforcreateanddelete(Node *x,char *pathname){
    Node *t=x;
    int depth= pathdepth(pathname)-1;
    if(depth==0){
        return t;
    }
    if(depth==-2){
        return NULL;
    }
    int judge=0;
    char *p=pathname;

    char tempname[33]={'\0'};

    while (depth--) {
        p= pathchasing(p,tempname);
        int nrde1 = t->dirnumber;
        int i;
        for ( i = 0; i < nrde1; i++) {
            if(t->dirnext[i]!=NULL){
                if (!strcmp(t->dirnext[i]->name,tempname) && t->dirnext[i]->type==DIR_NODE) {
                    judge = 1;
                    break;
                }
            }
        }
        if (judge == 0) {
            return NULL;
        }
        judge = 0;
        memset(tempname,0,33);
        t=t->dirnext[i];
    }
    return t;
}

Node *isalineforopenandclose(Node *x,char *pathname){
    int depth= pathdepth(pathname);
    if(depth==-1){
        return NULL;
    }
    int judge=0;
    char *p=pathname;
    Node *t=x;
    char tempname[33]={'\0'};
    int temp=depth-1;
    while (temp--) {
        p= pathchasing(p,tempname);
        int nrde1 = t->dirnumber;
        int i;
        for ( i = 0; i < nrde1; i++) {
            if(t->dirnext[i]!=NULL){
                if (!strcmp(t->dirnext[i]->name,tempname) && t->dirnext[i]->type==DIR_NODE) {
                    judge = 1;
                    break;
                }
            }

        }
        if (judge == 0) {
            return NULL;
        }
        judge = 0;
        memset(tempname,0,33);
        t=t->dirnext[i];
    }
    p= pathchasing(p,tempname);
    int nrde=t->dirnumber;
    int j;
    for ( j = 0; j < nrde; j++) {
        if(t->dirnext[j]!=NULL){
            if (!strcmp(t->dirnext[j]->name,tempname)) {
                judge = 1;
                break;
            }
        }

    }
    if(judge==0){
        return NULL;
    }
    t=t->dirnext[j];
    return t;
}

bool checkyufa(char *singlenamepath){
    int len= strlen(singlenamepath);
    for(int i=0;i<len;i++){
        if(singlenamepath[i]=='.' || (singlenamepath[i]>='A'&&singlenamepath[i]<='Z') || (singlenamepath[i]>='a'&&singlenamepath[i]<='z') || (singlenamepath[i]>='0'&&singlenamepath[i]<='9')){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}

//char *getthelastname(char *pathname){
//    int depth= pathdepth(pathname);
//    char *p=pathname;
//    char rewname[32];
//    while (depth--) {
//        memset(rewname,0,32);
//        p = pathchasing(p, rewname);
//    }
//    //char *s= rewname;
//    return rewname;
//}

//O_APPEND 02000 以追加模式打开⽂件。即打开后，⽂件描述符的偏移量指向⽂件的末尾。若⽆此标志，则
//        指向⽂件的开头
//O_CREAT 0100 如果 pathname 不存在，就创建这个⽂件，但如果这个⽬录中的⽗⽬录不存在，则创建
//        失败；如果存在则正常打开
//O_TRUNC 01000 如果 pathname 是⼀个存在的⽂件，并且同时以可写⽅式 (O_WRONLY/O_RDWR) 打
//        开了⽂件，则⽂件内容被清空
//O_RDONLY 00 以只读⽅式打开
//O_WRONLY 01 以只写⽅式打开
//O_RDWR 02 以可读可写⽅式打开
//O_TRUNC | O_RDWR (可读可写，打开时清空)
//+++ O_CREAT | O_WRONLY (若不存在，创建后以只写⽅式打开；否则以只写⽅式直接打开) +++ （原来
//        写成读写了）
//+++ O_APPEND (⽂件描述符的偏移量指向⽂件末尾，并可读) +++
//修订8
//+++ O_TRUNC 但⽂件以只读⽅式打开时，在 Linux 中为 unspecified ⾏为。此处约定为正常只读打开
//⽽不清空。 （1.15 聊天记录）+++
//修订4
//+++ 注意点：+++
//+++ O_RDWR | O_WRONLY 共同存在时，取只写的语义； +++
//+++ 由于 O_RDONLY 是 0，因此若未指定任何读写⽅式时，默认是只读的； +++
//+++ 同时，易得 O_RDONLY | O_WRONLY == O_WRONLY 。因此组合只读只写得到的结果是只写。 +++
int ropen(const char *pathname, int flags) {
    Node *t= isalineforcreateanddelete(tree.first, pathname);
    if(t==NULL){
        return -1;
    }
    int nrde=t->dirnumber;
    int len1= strlen(pathname);
    char s[33]={'\0'};
    int startindex;
    int endindex;
    for(int i=len1-1;i>=0;i--){
        if(pathname[i]!='/'){
            endindex=i;
            break;
        }
    }
    for(int i=endindex;i>=0;i--){
        if(pathname[i]=='/'){
            startindex=i+1;
            break;
        }
    }
    for(int i=startindex;i<=endindex;i++){
        s[i-startindex]= pathname[i];
    }
    int len=endindex-startindex+1;//为s,即lastname的长度
    //得到了lastname
//    if(len>32 || checkyufa(s)==false){
//        return -1;
//    }
    //遍历查找
    int judge=0;
    int k;
    for( k=0;k<nrde;k++){
        if(t->dirnext[k]!=NULL){
            if(!strcmp(t->dirnext[k]->name,s)){
                judge=1;
                break;
            }
        }
    }
    //先排除错误情况
    if(judge==0){
        if(!(flags&O_CREAT)){
            return -1;
        }
        else{
            if(pathname[len1-1]=='/'|| checkyufa(s)==false || len>32){
                return -1;
            }
        }
    }
    if(judge==1){
        if(t->dirnext[k]->type==FILE_NODE && pathname[len1-1]=='/'){
            return -1;
        }
    }
    if(judge == 0){
        //创建该文件
        if(t->dirnumber==0){
            t->dirnumber++;
            t->realdirnumber++;
            t->dirnext= malloc((t->dirnumber)* sizeof(**t->dirnext));
            t->dirnext[0]= malloc(sizeof(*t->dirnext[0]));
            init_node(t->dirnext[0]);
            t->dirnext[0]->type=FILE_NODE;
            memcpy(t->dirnext[0]->name,s,len);
            //t->dirnext[0]->name=s;
        }
        else{
            int pm=t->dirnumber;
            t->dirnumber++;
            t->realdirnumber++;
            t->dirnext= realloc(t->dirnext,(t->dirnumber)* sizeof(**t->dirnext));
            t->dirnext[t->dirnumber-1]= malloc(sizeof(*t->dirnext[t->dirnumber-1]));
            init_node(t->dirnext[t->dirnumber-1]);
            t->dirnext[t->dirnumber-1]->type=FILE_NODE;
            memcpy(t->dirnext[t->dirnumber-1]->name,s,len);
        }
        t=t->dirnext[t->dirnumber-1];
        int fd = getfreefd();
        if(fd==-1){
            return -1;
        }
        fds[fd] = malloc(sizeof(*fds[fd]));
        fds[fd]->f=t;
        fds[fd]->flags=flags;
        if(flags&O_APPEND){
            fds[fd]->offset=t->size;
        }
        else{
            fds[fd]->offset=0;
        }
        if(flags&O_TRUNC){
            if(flags%4){
                t->size=0;
                t->filecontent=NULL;
            }
        }
        return fd;
    }//打开的情况
    if(judge==1){
        t=t->dirnext[k];
        //1.目录
        if(t->type==DIR_NODE){
            int fd = getfreefd();
            if(fd==-1){
                return -1;
            }
            fds[fd]= malloc(sizeof(*fds[fd]));
            fds[fd]->offset=0;
            fds[fd]->flags=flags;
            fds[fd]->f=t;
            return fd;
        }
        //2.文件
        if(t->type==FILE_NODE){
            int fd = getfreefd();
            if(fd==-1){
                return -1;
            }
            fds[fd] = malloc(sizeof(*fds[fd]));
            fds[fd]->f=t;
            fds[fd]->flags=flags;
            if(flags&O_APPEND){
                fds[fd]->offset=t->size;
            }
            else{
                fds[fd]->offset=0;
            }
            if(flags&O_TRUNC){
                if(flags%4){
                    t->size=0;
                    if(t->filecontent!=NULL){
                        free(t->filecontent);
                    }
                    t->filecontent=NULL;
                }
            }
            return fd;
        }
    }
    return -1;
}

//关闭打开的⽂件描述符，并返回 0。如果不存在⼀个打开的 fd，则返回 -1
int rclose(int fd) {
    int temp = checkout(fd);
    if(temp==-1){
        return -1;
    }
    fds[fd]=NULL;
    free(fds[fd]);
    return 0;
}


//向 fd 中的偏移量（⻢上解释）位置写⼊以 buf 开始的⾄多 count 字节，覆盖⽂件原有的数据。如果
//count 超过 buf 的⼤⼩，仍继续写⼊（数据保证不因此⽽产⽣段错误），将 fd 的偏移量后移 count，并
//返回实际成功写⼊的字节数。如果写⼊的位置超过了原来的⽂件末尾，则⾃动为该⽂件扩容。
//如果 fd 不是⼀个可写的⽂件描述符，或 fd 指向的是⼀个⽬录，则返回 -1。
//在本实验中，ramfs 中同时存在的⽂件⼤⼩不会超过限制。因此你的 rwrite 对于⼀个能够写⼊的⽂件，
//事实上总应返回 count
//0:只读
//1\3:只写
//2:可读可写
//问题1:  覆盖的意思是什么，如果最后偏移量没有到文件末尾，那原来偏移量之后的东西变不变
//问题2:  如果count大于buf里的字节数,继续读入的是什么
//问题3:  如果在read之前偏移量就超过了文件末尾,那么读出什么给buf 偏移量不变，read返回0
ssize_t rwrite(int fd, const void *buf, size_t count) {
    if(checkout(fd)==-1){
        return -1;
    }//防止溢出
    if((fds[fd]->f->type==DIR_NODE) || !(fds[fd]->flags % 4)){
        return -1;
    }
    if(fds[fd]->f->filecontent==NULL){
        if(fds[fd]->offset==0){
            fds[fd]->f->filecontent= malloc((count+1)* sizeof(*fds[fd]->f->filecontent));
            memcpy(fds[fd]->f->filecontent,buf,count);
            fds[fd]->f->size=fds[fd]->offset+count;
            fds[fd]->offset+=count;
        }
        else{
            fds[fd]->f->filecontent= malloc((count+1+fds[fd]->offset)* sizeof(*fds[fd]->f->filecontent));
            void *p = fds[fd]->f->filecontent;
            p += fds[fd]->offset;
            memcpy(p, buf, count);
//            for(int i=fds[fd]->offset ;i>fds[fd]->f->size;i--){
//                fds[fd]->f->filecontent[i]='\0';
//            }
            void *q=fds[fd]->f->filecontent;
            q+=fds[fd]->f->size;
            memset(q,0,fds[fd]->offset-fds[fd]->f->size);
            fds[fd]->f->size=fds[fd]->offset+count;
            fds[fd]->offset+=count;
        }
    }
    else{
        int offset=fds[fd]->offset;
        if(offset<=fds[fd]->f->size) {
            int size = fds[fd]->f->size - fds[fd]->offset;
            if (count <= size) {
                void *p = fds[fd]->f->filecontent;
                p += offset;
                memcpy(p, buf, count);
                fds[fd]->offset += count;
            }
            else{
                fds[fd]->f->filecontent= realloc(fds[fd]->f->filecontent,(count+1+offset)* sizeof(*fds[fd]->f->filecontent));
                void *p=fds[fd]->f->filecontent;
                p+=offset;
                memcpy(p,buf,count);
                fds[fd]->f->size=fds[fd]->offset+count;
                fds[fd]->offset+=count;
            }
        }
        else{
            fds[fd]->f->filecontent= realloc(fds[fd]->f->filecontent,(count+1+offset)* sizeof(*fds[fd]->f->filecontent));
            void *p = fds[fd]->f->filecontent;
            p += offset;
            memcpy(p, buf, count);
//            for(int i=fds[fd]->offset ;i>fds[fd]->f->size;i--){
//                fds[fd]->f->filecontent[i]='\0';
//            }
            void *q=fds[fd]->f->filecontent;
            q+=fds[fd]->f->size;
            memset(q,0,fds[fd]->offset-fds[fd]->f->size);
            fds[fd]->f->size=fds[fd]->offset+count;
            fds[fd]->offset+=count;
    }
    }


    return count;
}

ssize_t rread(int fd, void *buf, size_t count) {
    if(checkout(fd)==-1){
        return -1;
    }//防止溢出
    if((fds[fd]->f->type==DIR_NODE) || (fds[fd]->flags)==1 || (fds[fd]->flags)==3 || (fds[fd]->offset==0&&fds[fd]->f->size==0)){
        return -1;
    }
    if(fds[fd]->offset>=fds[fd]->f->size){
        return 0;
    }
    int offset=fds[fd]->offset;
    int size=fds[fd]->f->size-fds[fd]->offset;
    if(count<=size){
        void *p=fds[fd]->f->filecontent;
        p+=offset;
        memcpy(buf,p,count);
        fds[fd]->offset+=count;
        return count;
    } else{
        void *p=fds[fd]->f->filecontent;
        p+=offset;
        memcpy(buf,p,count);
        fds[fd]->offset+=size;
        return size;
    }
}



//这个函数⽤于修改 fd 表⽰的⽂件描述符的偏移量，并返回当前⽂件的实际偏移量。
//whence有三种取值：
//rseek 允许将偏移量设置到⽂件末尾之后的位置，但是并不会改变⽂件的⼤⼩，直到它在这个位置写⼊
//了数据。在 超过⽂件末尾的地⽅写⼊了数据后，原来的⽂件末尾到实际写⼊位置之间可能出现⼀个空
//隙，我们规定应当以 "\0" 填充这段空间。
//+++ 但不允许将偏移量设置到⽂件开头之前，也就是⼀个负数的绝对偏移量。这种情况下返回 -1。 +++
//SEEK_SET 0 将⽂件描述符的偏移量设置到 offset 指向的位置
//SEEK_CUR 1 将⽂件描述符的偏移量设置到 当前位置 + offset 字节的位置
//SEEK_END 2 将⽂件描述符的偏移量设置到 ⽂件末尾 + offset 字节的位置
off_t rseek(int fd, off_t offset, int whence) {
    if(checkout(fd)==-1){
        return -1;
    }//防止溢出
    switch (whence) {
        case SEEK_SET:
            fds[fd]->offset=offset;
            break;
        case SEEK_CUR:
            fds[fd]->offset+=offset;
            break;
        case SEEK_END:
            fds[fd]->offset=fds[fd]->f->size+offset;
            break;
        default:
            break;
    }
    if(fds[fd]->offset<0){
        return -1;
    }
    return fds[fd]->offset;
}

//只需在新添加文件目录时使用checkyufa即可
int rmkdir(const char *pathname) {
//    int depth = pathdepth(pathname);
//    char *p=pathname;
//    char tempname[32]={'\0'};
//    for(int i=1;i<depth;i++){
//        p= pathchasing(p,tempname);
//        Node const *t= searchnode(tree.first,tempname);
//        if(t==NULL){
//            return -1;
//        }
//    }//目前确保每个都在iNode链表内
//
//
////    p= pathchasing(p,tempname);
////    Node const *t = searchnode(tree.first,tempname);
////    if(t==NULL||t->id_node!=1||t->type!=DIR_NODE){
////        return -1;
////    }
////    //下面判断是否连成一条线
    Node *t= isalineforcreateanddelete(tree.first,pathname);//t一定是一个目录
    if(t==NULL){
        return -1;
    }
    else{
        //s即为新添加的目录名
        int len1= strlen(pathname);
        char s[33]={'\0'};
        int startindex;
        int endindex;
        for(int i=len1-1;i>=0;i--){
            if(pathname[i]!='/'){
                endindex=i;
                break;
            }
        }
        for(int i=endindex;i>=0;i--){
            if(pathname[i]=='/'){
                startindex=i+1;
                break;
            }
        }
        for(int i=startindex;i<=endindex;i++){
            s[i-startindex]= pathname[i];
        }
        int len=endindex-startindex+1;
        if(len>32 || checkyufa(s)==false){
            return -1;
        }
        else if(t->dirnumber==0){
            t->dirnumber++;
            t->realdirnumber++;
            t->dirnext= malloc((t->dirnumber)* sizeof(**t->dirnext));
            t->dirnext[0]= malloc(sizeof(*t->dirnext[0]));
            init_node(t->dirnext[0]);
            t->dirnext[0]->type=DIR_NODE;
            memcpy(t->dirnext[t->dirnumber-1]->name,s,len);
            //t->dirnext[0]->name=s;
            return 0;
        }
        else{
            int pm=t->dirnumber;
            for(int i=0;i<pm;i++){
                if(t->dirnext[i]!=NULL){
                    if(!strcmp(t->dirnext[i]->name,s)){
                        return -1;
                    }
                }
            }
            t->dirnumber++;
            t->realdirnumber++;
            t->dirnext= realloc(t->dirnext,(t->dirnumber)* sizeof(**t->dirnext));
            t->dirnext[t->dirnumber-1]= malloc(sizeof(*t->dirnext[t->dirnumber-1]));
            init_node(t->dirnext[t->dirnumber-1]);
            t->dirnext[t->dirnumber-1]->type=DIR_NODE;
            memcpy(t->dirnext[t->dirnumber-1]->name,s,len);
            return 0;
        }
    }


}
//删除⼀个空⽬录，成功则返回 0。如果⽬录不存在或不为空，或 pathname 指向的不是⽬录，返回 -1。
//测试保证不对打开的 pathname 做 rrmdir
int rrmdir(const char *pathname) {
    char s[33]={'\0'};
    int len1= strlen(pathname);
    int startindex;
    int endindex;
    for(int i=len1-1;i>=0;i--){
        if(pathname[i]!='/'){
            endindex=i;
            break;
        }
    }
    for(int i=endindex;i>=0;i--){
        if(pathname[i]=='/'){
            startindex=i+1;
            break;
        }
    }
    for(int i=startindex;i<=endindex;i++){
        s[i-startindex]= pathname[i];
    }
    Node *t= isalineforcreateanddelete(tree.first,pathname);
    if(t==NULL){
        return -1;
    }
    int mp=t->dirnumber;
    for(int i=0;i<mp;i++) {
        if (t->dirnext[i] != NULL) {
            if (!strcmp(t->dirnext[i]->name, s) && t->dirnext[i]->type == DIR_NODE && t->dirnext[i]->realdirnumber == 0) {
                t->dirnext[i] = NULL;
                t->realdirnumber--;
                free(t->dirnext[i]);
                return 0;
            }
        }
    }
    return -1;
}

//删除⼀个⽂件，成功则返回 0。如果⽂件不存在或 pathname 指向的不是⽂件，则返回 -1。测试保证不
//对打开的 pathname 做 runlink
int runlink(const char *pathname) {
    char s[33]={'\0'};
    int len1= strlen(pathname);
    int startindex;
    int endindex;
    for(int i=len1-1;i>=0;i--){
        if(pathname[i]!='/'){
            endindex=i;
            break;
        }
    }
    for(int i=endindex;i>=0;i--){
        if(pathname[i]=='/'){
            startindex=i+1;
            break;
        }
    }
    for(int i=startindex;i<=endindex;i++){
        s[i-startindex]= pathname[i];
    }
    Node *t= isalineforcreateanddelete(tree.first,pathname);
    if(t==NULL){
        return -1;
    }
    int mp=t->dirnumber;
    for(int i=0;i<mp;i++) {
        if (t->dirnext[i] != NULL) {
            if (!strcmp(t->dirnext[i]->name, s) && t->dirnext[i]->type == FILE_NODE) {
                if(t->dirnext[i]->filecontent!=NULL){
                    free(t->dirnext[i]->filecontent);
                }
                t->dirnext[i] = NULL;
                t->realdirnumber--;
                free(t->dirnext[i]);
                return 0;
            }
        }
    }
    return -1;
}
//tmp要最后free
void init_ramfs() {
    tree.first=NULL;
    Node *tmp= malloc(sizeof (*tmp));
    tmp->type=DIR_NODE;
    tmp->dirnext=NULL;
    //tmp->left=NULL;
    tmp->dirnumber=0;
    tmp->realdirnumber=0;
    tmp->size=0;
    tmp->filecontent=NULL;
    memset(tmp->name,0,33);
    sprintf(tmp->name,"/");
    //tmp->id_node=0;
    tree.first=tmp;
    //free(tmp);
    for(int i=0;i<=4096;i++){
        fds[i]=NULL;
    }
}




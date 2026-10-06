#include<sys/mman.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<regex.h>
#include<unistd.h>

int main()
{
    //打开映射文件
    int fd;
    fd=open("url.txt",O_RDWR);

    int size =lseek(fd,0,SEEK_END);

    char * mmap_ptr=NULL;
    char * copy_ptr=NULL;
    mmap_ptr=mmap(NULL,size,PROT_READ|PROT_WRITE,MAP_PRIVATE,fd,0);
    //printf("%s\n",mmap_ptr);
    close(fd);
    copy_ptr = mmap_ptr;

    //正则实现
    char * regstr="<a[^>]*href=\"\\([^\"]*\\)\"[^>]*>\\([^<]*\\)</a>";
    //<a开头[^>]*>以>开头的集合额外出现0或多
    int regnum=3;
    regmatch_t match[regnum];
    regex_t reg;
    regcomp(&reg,regstr,0);//生成正则
    //遍历
    char url[1024];
    char title[1024];

    while((regexec(&reg,mmap_ptr,regnum,match,0))==0)
    {
        //内容
        bzero(url,sizeof(url));
        bzero(title,sizeof(title));
        snprintf(url,match[1].rm_eo - match[1].rm_so + 1 , "%s",mmap_ptr + match[1].rm_so);
        snprintf(title,match[2].rm_eo-match[2].rm_so + 1 , "%s",mmap_ptr + match[2].rm_so);
        mmap_ptr += match[0].rm_eo;
        printf("地址：%s\t标题：%s\n",url,title);
    }
    regfree(&reg);
    munmap(copy_ptr,size);
    printf("done.\n");
    return 0;

}

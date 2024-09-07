#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>



int main(){
    if (chdir("/")!= 0)
    {perror("error:-");
    };
    int code0 = mkdir("sandbox", 0777);
    if (code0 == 0) {
        printf("Directory created successfully.\n");
    } else {
        perror("Failed to create directory \n \
                try running the command with elevated privelages \n \
                exiting .....\n");
                
        exit(1);
    }
    //moving to new dir "sandbox" now

    int code1=chdir("sandbox/");
    if (code1 == 1){
        perror("error moving to dir:sandbox-\n");
    };

    int code2=system("pwd");
    if (code2 != 0){
        perror("err printing working dir\n");
    }return 0;
    int code4=system("dnf install \
--installroot=/sandbox \
--releasever=40 \
--setopt=install_weak_deps=False \
--setopt=keepcache=True \
--assumeyes \
--nodocs \
systemd dnf glibc-langpack-en passwd rtkit policycoreutils \
NetworkManager audit firewalld selinux-policy-targeted kbd zchunk sudo \
vim-minimal systemd-udev rootfiles less iputils deltarpm sqlite lz4");
    if (code4!=0){
        perror("problem installing chroot into sandbox dir:-\n");
        exit(1);
}return 0;    //after the dnf install command the sandbox will now be populated with dir's like the host root




    int code5=mkdir("cd /sandbox/etc/", 0777); 
    int code6=system("touch resolv.conf");
    if (code6!=0){
        printf("error creating the resolve.conf:->");
        perror("\n");
    }
    int code7=system("cd / \
    mount --bind /etc/resolv.conf /sandbox/etc/resolv.conf"); //the success of this command is crutial as it's success guarantees that the hadware will be be abble to resolve network traffick going to the jail
    if(code7!=0){
        printf("error binding to resolve.config \n \
        exiting...\n");
        exit(1);
    }



        int code8=system(" mount --bind /dev /sandbox/dev \
    mount --bind /proc /sandbox/proc \
    mount --bind /sys /sandbox/sys ");                  //media and block devices
    if(code8!=0){
        printf("error binding to resolve.config \n \
        exiting...\n");
        exit(1);
    }

int code9=(chdir("/sandbox/sys/"));
if(code9!=0){
    perror("error cdanging dir /sandbox/sys/-\n");
    exit(1);}
    
int code10=mkdir("fs", 0777); 
    if (code10!=0){
        perror("error creating fs dir:->\n");
        exit(1);
    }


int code11=(chdir("/sandbox/sys/fs/"));
if(code11!=0){
    perror("error changing dir into /sandbox/sys/fs/-\n");
    exit(1);}


int code12=mkdir("cgroup", 0777); 
    if (code10!=0){
        perror("error creating cgroup dir:->");
        exit(1);
    }


int code11=(chdir("/sandbox/sys/fs/cgroup/"));
if(code11!=0){
    perror("error cdanging dir into /sandbox/sys/fs/cgroup/");
    exit(1);}

int code12=system("cd /sandbox/ \
mount -t cgroup cgroup /sandbox/sys/fs/cgroup");
    if(code12!=0){
        perror("error binding cgroup\n");
        exit(1);
    }

int code13=system("cd / \
unshare --fork --pid --mount /bin/bash \
chroot /sandbox/ /bin/bash");
    if(code13!=0){
        perror("error binding cgroup \n \
        exiting...\n");
        exit(1);
    }

        



}

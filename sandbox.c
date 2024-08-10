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
        perror("Failed to create directory\n");
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
    }return 0;

    int code5=mkdir("cd /sandbox/etc/", 0777);
    int code6=system("touch resolv.conf");
    int code7=system("touch resolv.conf");


    int code6=system("sudo /mnt/etc/resolv.conf");
    if (code6!=0){
        perror("problem opening chroot: \n");
        
    }return 0;


}
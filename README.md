## c for fun

* fun
* learn
* fun



Sandbox.c creates a regular chroot environment using fedora 40 it has the file \
systems and everything but you will have to install the dep files for all your \
programs and applications in order use it say for instance i'm using fish, to \
find the dep- files in your regular OS, run 
``` 
$ lddtree -l /usr/bin/fish

```
this should list all the dependancy files you would need to install before using say fish in chroot\
to remove the chroot. 
```
$ sudo rm -rf /sandbox/

```
so eachtime you run the code you will create a "container-environment" after you are done you can remove\
the dir.



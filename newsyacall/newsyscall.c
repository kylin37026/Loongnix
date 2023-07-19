#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>

asmlinkage long sys_force(int i){
    printk("new sys----:%d/n", i);
    return 0;
}
int __init rm_init(void){
    unsigned int *table_new = 0xf88f0d00; //从/proc/new_syscall中得到新系统调用表信息
    unsigned char *append_ptr=0xf88f16f0; //从/proc/new_syscall中得到当前系统调用号信息
    table_new[*(append_ptr)] = sys_force;  //初始化新系统调用号
    *(append_ptr) = *(append_ptr) + 1; //递增已经实现的系统调用号   
    return 0;
}
void __exit rm_exit(void){
}
module_init(rm_init);
module_exit(rm_exit);
MODULE_LICENSE("GPL");
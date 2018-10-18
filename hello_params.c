#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include<linux/moduleparam.h>
int param_val=0;
module_param(param_val, int, S_IRUSR|S_IWUSR); 


static int __init hello_world_init(void)
{

        printk(KERN_INFO "param_val = %d  \n",param_val);
        printk(KERN_INFO "Kernel Module Inserted Successfully...\n");
 return 0;
}



void __exit hello_world_exit(void)
{
	printk(KERN_INFO "MOdule EXITING...module Removing\n");
}


module_init(hello_world_init);
module_exit(hello_world_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("EmbeTronicX <embetronicx@gmail.com or admin@embetronicx.com>");
MODULE_DESCRIPTION("A simple hello world driver");
MODULE_VERSION("1.0");

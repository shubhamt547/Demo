#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>

dev_t dev=0;
static struct class *dev_class;

static int __init hello_world_init(void)
{
	if(alloc_chrdev_region(&dev,0,2,"inno_dev")<0)
	{
                printk(KERN_INFO "Cannot allocate major number for device\n");
                return -1;
        }
	printk(KERN_INFO"kernel allocated\n major number =%d\t minor number=%d",MAJOR(dev),MINOR(dev));
	

	if((dev_class=class_create(THIS_MODULE,"inno_class"))==NULL)
	{
            printk(KERN_INFO "Cannot create the struct class for device\n");
            goto r_class;
        }
	if((device_create(dev_class,NULL,dev,NULL,"inno_device"))==NULL)
	{
		printk(KERN_INFO"cannot create the device file\n");
		goto r_device;
	}

        printk(KERN_INFO "Kernel Module Inserted Successfully...\n");
	return 0;
r_device:
	class_destroy(dev_class);
r_class:
        unregister_chrdev_region(dev,1);
        return -1;
}

void __exit hello_world_exit(void)
{
device_destroy(dev_class,dev);
class_destroy(dev_class);
unregister_chrdev_region(dev,2);
}

module_init(hello_world_init);
module_exit(hello_world_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("INNOMINDS_TEAM");
MODULE_DESCRIPTION("A DEV FILE OPERATION CONTEMPLATE");
MODULE_VERSION("1.0.0");


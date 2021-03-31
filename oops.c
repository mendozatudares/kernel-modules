/*
 Linux Kernel Module Baseline
*/
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

static int __init test_init(void)
{
        printk("Hello World from oops\n");
	return 0;
}

static void null_reference(void)
{
        int *p = NULL;
        int  e = *p;
        printk("%d\n", e);
}

static void __exit test_exit(void)
{
	printk("Goodbye World from oops\n");
        null_reference();
}


module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Kevin Mendoza Tudares");
MODULE_DESCRIPTION("Your First Linux Kernel Module For EECS 446");
MODULE_VERSION("0.0");

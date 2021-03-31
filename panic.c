/*
 Linux Kernel Module Baseline
*/
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/timer.h>

static struct timer_list panic_timer;

static int __init test_init(void)
{
        printk("Hello World\n");
	return 0;
}

static void null_reference(struct timer_list *unused)
{
        int *p = NULL;
        int  e = *p;
        printk("%d\n", e);
}

static void __exit test_exit(void)
{
	printk("Goodbye World\n");
        timer_setup(&panic_timer, null_reference, 0);
        mod_timer(&panic_timer, jiffies + 2 * HZ);
}


module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Kevin Mendoza Tudares");
MODULE_DESCRIPTION("Your First Linux Kernel Module For EECS 446");
MODULE_VERSION("0.0");

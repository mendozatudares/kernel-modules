/*
 Linux Kernel Module Baseline
*/
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>

const int IRQ = 2;
const int ASM = 50;

static void null_reference(void)
{
        int *p = NULL;
        int  e = *p;
        printk("%d\n", e);
}

static irqreturn_t handle_irq(int irq, void *dev_id)
{
        null_reference();
        return IRQ_HANDLED;
}

static int __init test_init(void)
{
        int ret;

        printk("Hello World\n");

        ret = request_irq(IRQ, handle_irq, 0, "panic", NULL);

        if (ret) {
                printk("ERROR: Cannot request IRQ %d", IRQ);
                printk(" - code %d , EIO %d , EINVAL %d\n", ret, EIO, EINVAL);
                return -1;
        }

	return 0;
}

static void __exit test_exit(void)
{
	printk("Goodbye World\n");
        asm("int %0" : : "i" (ASM));
        free_irq(IRQ, 0);
}


module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Kevin Mendoza Tudares");
MODULE_DESCRIPTION("Your First Linux Kernel Module For EECS 446");
MODULE_VERSION("0.0");

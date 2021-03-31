/*
 Linux Kernel Module Baseline
*/
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>

typedef struct __attribute__((__packed__)) idtr {
        uint16_t limit;
        uint64_t addr;
        uint64_t xs;
} idtr_t;

static int __init test_init(void)
{
        printk("Hello World\n");
	return 0;
}

static void load_idtr(void* idtr) {
        asm("lidt %0" : : "m" (*(idtr_t *)idtr));
}

static void __exit test_exit(void)
{
	printk("Goodbye World\n");
        void* idtr = kmalloc(sizeof(idtr_t), GFP_KERNEL);
        ((idtr_t*)idtr)->limit = 0;
        load_idtr(idtr);
}


module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Kevin Mendoza Tudares");
MODULE_DESCRIPTION("Your First Linux Kernel Module For EECS 446");
MODULE_VERSION("0.0");

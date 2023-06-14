#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/platform_device.h>

static int my_pdrv_remove (struct platform_device *pdev) {
	pr_info("platform remove function invoke!\n");
}

static int my_pdrv_probe (struct platform_device *pdev) {
        pr_info("Platform probe function invoke!\n");
        return 0;
}

static struct platform_driver mypdrv = {
	.driver	= {
		.name 	= KBUILD_MODNAME,
		.owner	= THIS_MODULE,
	},

	.probe		= my_pdrv_probe,

	.remove		= my_pdrv_remove,
};

static int __init my_pdrv_init(void)
{
	pr_info("platform init function invoke!\n");

	// TODO 1.0 :  Registering platform driver with the kernel

	platform_driver_register(&mypdrv);

	return 0;
}

static void __exit my_pdrv_exit(void)
{
	pr_info("platform exit function invoke!\n");

	// TODO 1.1 : Unregister platform driver with the kernel
	
	platform_driver_unregister(&mypdrv);
}

module_init(my_pdrv_init);
module_exit(my_pdrv_exit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Krishna s");
MODULE_DESCRIPTION("Platform Hellow world module");

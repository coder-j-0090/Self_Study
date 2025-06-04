/**************************************************************
* Class::  CSC-415-01 Fall 2024
* Name:: Junyoung Kim
* Student ID:: 920303420
* GitHub-Name:: coder-j-0090
* Project:: Assignment 6 - Device Driver
*
* File:: deviceDriver.c
*
* Description:: Performs simple XOR-based encryption/decryption.
*		Allows users to write, set mode via 'ioctl', 
*		read back processed string, while managing 
*		other operation. 
**************************************************************/

#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/slab.h>

#define BUF_LEN 256
#define DEVICE_NAME "string_encryptor"
#define IOCTL_SET_MODE _IOW('a', 'a', int32_t*)

//Metadata for Kernel Module
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Encryption/Decryption Device Driver");
MODULE_AUTHOR("Junyoung Kim");

//Store major number
static int main;
//Buffer to store encrypted/decrypted message.
static char mes[BUF_LEN];
static int enc_dec_mode = 1; // 1: Encrypt, 0: Decrypt
//pointer to device class
static struct class *cls;

//Logs when device is open
static int dev_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device opened\n");
    return 0;
}

//Logs when device is close
static int dev_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device closed\n");
    return 0;
}

//Copy and paste the data from mes to buf
//Logs for success/failure of copy(Sending) operation
static ssize_t dev_read(struct file *file, char __user *buf, size_t len, loff_t *offset) {
    int n = copy_to_user(buf, mes, BUF_LEN);

    if(n != 0)
    {
        printk(KERN_ERR "Failed to send data to user\n");
        return -EFAULT;
    }

    else
    {
        printk(KERN_INFO "Sent data to user: %s\n", mes);
        return BUF_LEN;
    }
}

//copies data from user space(buf) to kernel space(temp)
static ssize_t dev_write(struct file *file, const char __user *buf, size_t len, loff_t *offset) {
    int i;
    char tmp_buf[BUF_LEN];
    
    if (copy_from_user(tmp_buf, buf, len)) {
        printk(KERN_ERR "Failed to receive data from user\n");
        return -EFAULT;
    }
    
    tmp_buf[len] = '\0';
    
    //Perform XOR encryption/decryption using the key 0x5A
    for (i = 0; i < len; i++) {
	//stores data in mes
        mes[i] = tmp_buf[i] ^ 0x5A; 
    }
    mes[len] = '\0';

    printk(KERN_INFO "%s data: %s\n", enc_dec_mode ? "Encrypted" : "Decrypted", mes);
    return len;
}

//Del with ioctl to set enc_dec_mode and updates mode
static long dev_ioctl(struct file *file, unsigned int cmd, unsigned long arg) {
    if (cmd == IOCTL_SET_MODE) {
        if (copy_from_user(&enc_dec_mode, (int32_t*)arg, sizeof(enc_dec_mode))) {
            printk(KERN_ERR "Failed to set mode\n");
            return -EFAULT;
        }
        printk(KERN_INFO "Mode set to: %s\n", enc_dec_mode ? "Encrypt" : "Decrypt");
    }
    return 0;
}

static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = dev_open,
    .release = dev_release,
    .read = dev_read,
    .write = dev_write,
    .unlocked_ioctl = dev_ioctl,
};

//Register device, create class and device node
static int __init dev_init(void) {
    main = register_chrdev(0, DEVICE_NAME, &fops);
    if (main < 0) {
        printk(KERN_ERR "Failed to register device\n");
        return main;
    }

    cls = class_create(DEVICE_NAME);
    if (IS_ERR(cls)) {
        unregister_chrdev(main, DEVICE_NAME);
        printk(KERN_ERR "Failed to create class\n");
        return PTR_ERR(cls);
    }

    device_create(cls, NULL, MKDEV(main, 0), NULL, DEVICE_NAME);
    printk(KERN_INFO "Device loaded with main number %d\n", main);
    return 0;
}

//Destory class and device and unregister character device.
static void __exit dev_exit(void) {
    device_destroy(cls, MKDEV(main, 0));
    class_destroy(cls);
    unregister_chrdev(main, DEVICE_NAME);
    printk(KERN_INFO "Device unloaded\n");
}

module_init(dev_init);
module_exit(dev_exit);

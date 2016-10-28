#include <linux/fs.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>

static int os_pagemap_proc_show(struct seq_file *m, void *v)
{
	seq_printf(m, "Hello World\n");
	return 0;
}

static int os_pagemap_proc_open(struct inode *inode, struct file *file)
{
	return single_open(file, os_pagemap_proc_show, NULL);
}

static const struct file_operations os_pagemap_proc_fops = {
	.open = os_pagemap_proc_open,
	.read = seq_read,
	.llseek = seq_lseek,
	.release = single_release,
};

static int __init proc_os_pagemap_init(void)
{
	proc_create("os_pagemap", 0, NULL, &os_pagemap_proc_fops);
	return 0;
}
fs_initcall(proc_os_pagemap_init);

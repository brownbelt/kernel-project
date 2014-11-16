#include <linux/kernel.h>
#include <linux/linkage.h>
#include <linux/sched.h>
#include <linux/string.h>
#include <linux/syscalls.h>

#define __STDOUT 1

asmlinkage int sys_project(long pid) {

	/*
	 * make sure the sys_project be called
	 */
	printk(KERN_EMERG "Hello Linux Project");

	/*
	 * TODO find a better way to replace it.
	 * using pid to find task_struct
	 */
	struct task_struct *task = current;

	/*
	 * write to stdout
	 * using sys_write
	 * TODO char comm[TASK_COMM_LEN] isn't the full name for process
	 */
	size_t len = strnlen(task->comm, TASK_COMM_LEN);
	sys_write(__STDOUT, task->comm, len);

	return 1;
}

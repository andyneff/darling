#include "sem_close.h"
#include "../base.h"
#include "../errno.h"
#include <sys/errno.h>
#include <linux-syscalls/linux.h>
#include <elfcalls.h>

extern struct elf_calls* _elfcalls;

long sys_sem_close(int sem)
{
#ifndef VARIANT_DYLD
	int ret;

	ret = _elfcalls->sem_close(sem);
	if (ret == -1)
		ret = -errno_linux_to_bsd(_elfcalls->get_errno());

	return ret;
#else
	return -ENOSYS;
#endif
}


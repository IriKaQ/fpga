#ifndef __LINUX_FPGA_REGION_H
#define __LINUX_FPGA_REGION_H

#if defined(__KERNEL) || defined(__KERNEL__)
#include <linux/types.h>
#include <linux/ioport.h>

#include <fpga.h>

struct fpga_region {
	struct fpga *parent;
	struct device *dev;

	void *priv;

	struct fpga fpga;
	struct fpga_operations ops;
};
#define to_fpga_region(_fpga) container_of(_fpga, struct fpga_region, fpga)

struct fpga_region *
fpga_region_alloc(struct fpga *parent, struct device *dev, u32 force_nr,
		  struct fpga_resource *resource, int sizeof_priv,
		  struct fpga_operations *ops);
void fpga_region_free(struct fpga_region *region);

static inline void *fpga_region_priv(struct fpga_region *region)
{
	return region->priv;
}

struct fpga *fpga_root(struct device *dev);

#endif /* __KERNEL */

#endif /* __LINUX_FPGA_REGION_H */

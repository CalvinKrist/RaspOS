.globl getCPU
getCPU:
	mrs	x0, mpidr_el1		
	and	x0, x0,#0xFF		// Check processor id
	ret
- 2.1
  - *For user*. Different services for user, such as, UI, Program Execution, I/O operations, File-system manipulation, Communications, Error detection.
  - *For system.* Services that provides efficient operation within the system itself. Resource Allocation, Accounting, Protection and security.

- 2.2
  - *By register**.* Load the parameters in the CPU registers before executing the system call.
  - *Block or table.* Store the parameters in a block or table, store the position of said parameters in a register.
  - *Stack.* Push the parameters into the stack, let the OS kernel pop them.

- 2.3
  - You could either use a tracing facility, which list each system call as it is executed, or a timer interrupts, at sufficiently frequent interrupts you can profile how much time each instruction takes. *Profiling* can be used, which periodically samples the instruction pointer to determine which code is being executed. *DTrace* can also be used to probe the time spent in each process.

- 2.4
  - Open
  - Read
  - Write
  - Create
  - Close

- 2.5
  - *Advantage.* A unified API can provide a clearer code, and protability of algorithms. Another advantage is ease to add new devices.
  - *Disadvantage.* A unified API might no provide all functionality for a devices and can't be optimized for specific devices.

- 2.6
  - Can be done(And it's done, fish, zsh...). It can execute it own code that makes the neccesary system calls or it can load different programs that do the necesary execution.o

- 2.7
  - *Shared Memory.* It allow different proccesses to access the same memory-space, which has little overhead but can be harder to sync and protect.
  - *Message passing.* Message passing is easier to synchronize and to utilize through web systems. The idea is to pass data between hosts or process, directly or through a common mailbox.

- 2.8
  - Allows evolability for the operating system, changing only policy to change behaviour. Mechanism can be also changed, in some cases, without changing policy.

- 2.9
  - As the book says, Backing-store driver and the CPU scheduler, since the Backing-store driver needs to wait for I/O and the CPU can be rescheduled during this time and the Backing-store driver needs to use virtual memory for the information of all the process.

- 2.10
  - Micro kernels allow modularility and reusability, however, since they use message passing(Through a service provided by the micro-kernel) this has a serious performance impact.

- 2.11
  - Modularity, since each of the modules can be exchanged at boot time, one could easily change one another, also the performance impact is low since the modules are linked at boot-time with the kernel.

- 2.12 
  - Both use a layered system, both designed for small devices and both using the linux kernel. The libraries supported are different, so is the kernel and iOS doesn't use Dalvik virtual machine instead it uses Objective-C through cocoa.

- 2.13
  - The Java API provided by android is designed towards small devices(memory and processing wise)

- 2.14
  - This approach is similar to the monolithic approach, meaning, it has the same advantages performance-wise as a monolithic approach. Although, with some similar disadvantages as less portability, less sustaintability and overall more convoluted code. *TODO* Read https://www.usenix.org/legacy/publications/compsystems/1988/win_pu.pdf


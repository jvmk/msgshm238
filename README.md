# msgshm238
Class project for CS238 (Advanced Operating Systems) at UC Irvine, Spring 2018.

## Abstract
In operating system design, there are two fundamental techniques for sharing information between processes, namely shared memory and message passing. Shared memory offers high performance, but at the cost of added complexity, as the application developer must handle synchronization and deal with relative pointers. In contrast, message passing offers simplicity in terms of a simple API and removes the need for synchronization, but this comes at the cost of reduced performance. The `msgshm238` software library seeks to combine the best of both worlds, i.e., the performance of shared memory and the simplicity of message passing, by implementing message passing over shared memory.

## Report
The implementation is described in the [project report](https://github.com/jvmk/msgshm238/blob/master/msgshm238_report.pdf).

## Current Limitations
- The library currently only supports *unidirectional* communication, i.e., setups in which one process is the producer and the other process is the consumer. If two processes attempt to use the same channel for bidirectional communication, things will go haywire :-).
- The size of the memory segment is hardcoded (and very small). Adjust according to your needs.

# How to disassemble the binary on MacOs

- use the `otool` program such as:

```sh
otool -vt add

#output:

add:
(__TEXT,__text) section
_main:
0000000100003fb0	pushq	%rbp
0000000100003fb1	movq	%rsp, %rbp
0000000100003fb4	xorl	%eax, %eax
0000000100003fb6	popq	%rbp
0000000100003fb7	retq
```

- or with the `objdump` utility:

```sh
objdump -d add

#output:

add:	file format mach-o 64-bit x86-64


Disassembly of section __TEXT,__text:

0000000100003fb0 <_main>:
100003fb0: 55                          	pushq	%rbp
100003fb1: 48 89 e5                    	movq	%rsp, %rbp
100003fb4: 31 c0                       	xorl	%eax, %eax
100003fb6: 5d                          	popq	%rbp
100003fb7: c3                          	retq
```

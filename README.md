# Ostep

Repo which contains my code/experiments while reading the [Ostep book](https://pages.cs.wisc.edu/~remzi/OSTEP/).

## Notes

It looks like to me that looking into the reference of a given function is not worthwile to do, since it will just show the system dependant header files.
Here is an example:
I wanted to look into the function `strdup`, naturally I tried diving deep into its source code (with jump to definition funciton), but it just led me to this:

```c
#if __DARWIN_C_LEVEL >= 200112L
__BEGIN_DECLS
int	 strerror_r(int __errnum, char *__strerrbuf, size_t __buflen);
char	*strdup(const char *__s1);
void	*memccpy(void *__dst, const void *__src, int __c, size_t __n);
__END_DECLS
#endif /* __DARWIN_C_LEVEL >= 200112L */
```

This just tells me about the function signature, nothing about what it does or anything useful, so I think looking at the `man`pages is the correct way of reading about functions. By the way it is cool to have system builtin documentation for c in a form of manpages.
So the correct way of doing it is:

```sh
man strdup
```

### Using Linux VM

Since I'm using a MacOS system I don't have every utility/program (such as `free` etc.) mentioned in the book.
In order to be able to learn and experiment with such programs I will use a local Linux box with `Vagrant`. This box is a standard base box provided by hashicorp.

To start up the vm:

```sh
# in the root of this repo
vagrant up
```

Host/vm sync is set up, so I can modify the project from the vm as well. In VS Code there is a convinient feature that allows attaching to remote machines with `ssh`.

To set it up:

1. ```sh
   vagrant ssh-config > VM_SSH_CONF
   ```
2. Install the `Remote SSH` extension for VS Code
3. press `CMD+SHIFT+P` then search for `Remote-SSH: Settings`
4. configure the `Remote.SSH: Config File` to point to the previously created `VM_SSH_CONF` file
5. press `CMD+SHIFT+P` again, search for `Remote-SSH: Connect to Host`
6. select the `defualt` from the list
7. VS Code should open a new instance connected to the VM

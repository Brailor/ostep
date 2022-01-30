# Ostep

Repo which contains my solutions for the [Ostep book](https://pages.cs.wisc.edu/~remzi/OSTEP/).

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

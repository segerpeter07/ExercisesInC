# Question Answers
1. Where is GLib from and why does it exist? Who uses it, and for what? Would it have been better if they had given it a name less likely to be confused with glibc?
    
>GLib is a bundle of three (formerly five) low-level system libraries written in C and developed mainly by GNOME. GLib's code was separated from GTK, so it can be used by software other than GNOME and has been developed in parallel ever since.

[Source](https://en.wikipedia.org/wiki/GLib)

`glibc` is the GNU Project implementation of the standard C library and doesn't actually have anything to do with GLib, so yes a different name would have been reasonable, but there's a lot about low level C that's not reasonable...so here we are.

2. What are the most important pros and cons of using GLib, as opposed to another library, or just using core C features?

    a: A huge pro of using GLib is that you don't have to manually build a lot of data structures that you would commonly use. This can save a lot of time and prevent some serious errors since they're well tested. A con is that you then potentially import a lot of functions/data sctructures that you don't actually use.

3. What do you have to do to compile and run a "Hello GLib" example?

```
$ cc hello.c `pkg-config --cflags --libs glib-2.0` -o hello
```
Combat Simulator
================

I decided to re-learn the basics of C++ for a book I'm writing, and this youtube channel that had lots of videos about it. And was also about GameDev.

So, a few videos later, [I watched this one][game challenge video] and decided that I had nothing better to do. Here is the result of that decision.

Maybe it is needlessly complicated with those `enums` and `structs`... But, hey, it works.

Needs some balancing, though. Nothing's perfect.

Instructions
------------

To compile and run this program, all you need is [CMake][cmake] and a C++ compiler that supports C++11.

If you are not familiar with CMake, the instructions are simple: make a `build` directory inside the project tree and, from inside of it, call CMake poiting to the folder above. It will generate the necessary files to build the program in your machine; in a *nix system:

```
mkdir build; cd build; cmake ..; make
```

will create the `main` executable inside the build directory.

In a Windows machine, apparently CMake generates Visual Studio files. Check the documentation.

[cmake]: http://cmake.org/
[game challenge video]: https://www.youtube.com/watch?v=TH7plF4UT_E

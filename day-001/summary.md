#### Date: September 23, 2025

##### 0.1: introduction to these tutorials
- just standard overview on what were gonna do
- goals include:
    - general programming topics, specifically in c++
    - go thru lots of examples and not pick up bad habits
    - lots of practice programs
    - have fun lol
- best ways to get the most out of these lessons
    - type out examples by hand
    - try debugging exercises by myself
    - experiment and play around
    - take the quizzes seriously
    - write my own programs

##### 0.2: introduction to programs and programming languages
- talks about what a computer program is, the hardware, blah blah blah
- the differneces between machine language, assembly languages and high level languages
    - i.e. low level vs high level languages;
    - low level languages give a lot more freedom but lack qol life things such as portability as they are specific to the architecture of the machine
    - high level languages leave a lot more up to the compiler so it may be portable but less control over what specifically is happening due to the compiler and interpreter
- in summary high level is good for high level of abstraction; low level is good for potential for optimizations and performance

##### 0.3: introduction to c/c++
- talks about how c++ was born as an extension of c which was developed by dennis ritchie at bell labs in 1972
- c++ was developed by bjarne stroustrup also at bell labs in 1979
- c++ is kinda like a superset of c, but this is not rly true anymore since c99 included features not in c++
- biggest thing over c tho is that it supports object oriented programming
- standardized in 1998 by the ISO committee
- five major updates to c++ have been made so far (c++11, c++14, c++17, c++20, c++23)
    - biggest is c++ 11 tho
- c/c++ main philosphy is that we will trust the devs not to f\*ck things up 
###### Q: what is c++ good at?
- high performance and precise memory + resource control
    - some examples include, video games, real time applications, graphics, ai and nn

##### 0.4: introduction to c++ development
- basically the steps for developing a c++ program
    1. define the problem
    - what solution do u propose to solve ur issue?
    2. determine how ur gonna solve the problem
    - how are u gonna implement this solution?
    - good solutions are usually simple, well documented, modular and have graceful recovery and/or error handling
    - usually worth scoping out the solution before actually starting to code
    3. write the program
    - usualy good rpactice to name the first/primary source code file as `main.cpp`

##### 0.5: introduction to the compiler, linker and libraries
- back to developmment steps for a c++ program
    4. compiling the source code
    - c++ compiler goes thru ur code and does 2 important things
        - makes sure it follows the rules of the c++ language
        - translates ur c++ code to machine language instructions
            - stored in an intermediate file called an object file
    5. linking object files and libraries and creating the desired output files
    - only runs if compiler throws no errors
    - linker combines all the object files and produces the desired output file aka the executable
        - first linker reads all object files and ensures they are valid
        - second linker ensures depedencies are all resolved
        - third linker links in one or more library files
        - last linker outputs executable
    - building = converting source code into an executable
    6 + 7. testing and debugging
    - create tests and use debugger to see how ur executable behaves and try to find and fix programming errors

##### 0.6: installing an ide
- blah blah blah, imma just use nvim or vs code
- recommends c++17 or higher tho
- borland turbo c++, visual studio for mac and dev c++ cant be used tho cause they dont support c++ or the right versions of c++

##### 0.7: compiling ur first program
- pro gamer tip: create a new project for each new program u write
- console projects are programs that can be run in the windows, linux or mac console

###### what are precompiled headers?
- usually only for larger projects and introduce slightly more overhead so we can improve compilation speed by avoiding redundent compilations

- build = compile + link -> executable
- clean = remove all cached objects and executables
- rebuild = clean -> build
- compile = source code to machine language instructions
- run/start = execute executable loll

- pretty much just do hello world here

##### 0.8: a few common c++ problems
- some common general run-time problems
    - if the console window blinks and closes immediately when executing a problem:
        - first make sure these imports exist
        ```
        #include <iostream>
        #include <limits>
        ```
        - then add the following code at the end of the main function
        ```
        std::cin.clear()    // resets any error flags
        std::cin.ignore(std::numeric_limited<std::streamsize>)::max(), '\n');   // ignore any characters in the input buffer until we enter a character
        std::cin.get()  // get one char from the user
        ```
        - this essentially causes the program to pause so we can see whatever was output to the console instead of it insta closing
        - works better then `system("pause")` as this doesn't work on some operatin systems
    - ran program but get a window and no output
        - might be gettting blocked by anti-virus software
- general compile-time issues
    - each program should only have no more or less than 1 `main()` function
    - make sure ur compiler isnt too old cause if it is, it wont be able to handle newer c++ features
    - cannot open .exe for writing error when compiling
        - happens commonly when .exe is already running, in this case make sure to close it
        - antivirus or malware protection software is preventing the executable from being created or replaced
        - worst case try to reboot and recompile lol
    - undeclared identifier errors usually means standard library or header not used properly
- all others 
    1. ask a search engine, find a good way to phrase ur issue and look at stack overflow
    2. ask chatGPT

##### 0.9: configuring your compiler: build configurations
- build configuration = build target
    - just a bunch of project settings that tells ur ide how to build ur project
    - basically tells ur idee what executable is called and where to find code and library files
    - usually try not to touch these settings
- debug configuration
    - helpful for debugging
    - turns off all optimizations and includes debugging information
    - makes ur program larger and slower but easier to debug
- release configuration
    - version for release
    - optimized for size and performance + no debugging info
    - most useful for performance testing code
- obvious pro gamer tip: use debug config in development and release config when releasing executable
- `-ggdb` flag in ggc and clang uses debug build options
    - `-02 -DNDEBUG` for release builds
    - `-00`: recommended optimization level for debug builds (disables optimizations)
    - `-02`: recommended for release builds as it applies optimizations that should be beneficial for all programs
    - `-03`: adds additional optimizations which may or may not be faster than `-02` depending on the program

##### 0.10: configuring your compiler: compiler extensions
- usually compilers follow the c++ standard rules but sometimes they make their own changes to the language, usually to improve compatibility with othe rversions of the language (e.g. c99)
    - this is called compiler extensions
- not really good for beginners as programs written with a non-standard extension will genearally not run on a different compiler
- these extensions are usually on in some ides so need to make sure to switch them off

##### 0.11: configuring your compiler: warning and error levels
- ill-formed program means ur program dont follow the rules of the language
- diagnostic error (diagnostic)
    - error ur compiler throws if it has decided to halt compilation
    - usually thrown if it cant proceed or an error is serious
    - diagnostic errors generated by the compiler are called compilation errors, compiler errors or compile errors
- diagnostic warning (warning)
    - compiler hasnt halted compilation and the issue is ignored
    - may not violate the rules of the language but compiler might deem that it looks wrong
- different compiles may catergorize errors and warnings differently!
- best practice is to resolve warnings as they appear and treat them like errors
    - you can also increase ur warnin level which means it can be more assertive about providing warnings vs only raising a warning for the most obvious issues
        - warning can be raised with the following flags: `-Wall -Weddc++ -Wextra -Wconversion -Wsign-conversion
    - also possible to make compiler treat warnings as errors
        - do this with this flag: `-Werror`

##### 0.12: configuring your compiler: choosing a language standard
- default language standard is usually not the most recent one, a lot default to c++14
- usually professional practice to choose the standard that is one or two versions back to give time for the compilers to resolve any defects
- for personal projects however, its usually better to choose the latest standard
- to set the standard in gcc/g++/clang add the following flag: `-std=c++XX`

##### 0.13: what language standard is my compiler using?
- the PrintStandard.cpp file outputs the cpp standard u are using

  

# ZE - Zen Explorer
[![Build](https://img.shields.io/badge/Build%20(Fedora)-passing-2a7fd5?logo=fedora&logoColor=2a7fd5)](https://github.com/ElisStaaf/ze)
[![Version](https://img.shields.io/badge/Version-1.0.0-brightgreen)](https://github.com/ElisStaaf/ze)
[![Lang](https://img.shields.io/badge/Lang-C-lightgrey?logo=c)](https://github.com/ElisStaaf/ze)  
ZE is a file explorer that runs in the terminal. It aims at making your file exploring in the terminal as pleasant as possible!

Requirements
------------
* C compiler (clang, gcc etc.)
* Make
* Git or Github CLI (optional)

Install
-------
To install, simply:
```bash
# Git
git clone https://github.com/ElisStaaf/ze ~/ze

# Gh
gh repo clone ElisStaaf/ze ~/ze
```
You could maybe install with cURL, but why bother? Because you *do* have git on your system, yes? Well, anyways, then you need to
install ZE as a binary, you would do this by using make:
```bash
cd ~/ze
sudo make install
```
You can delete the ~/ze directory at this point. Anyway, you can now open the explorer by using the `ze` command in your shell:
```bash
ze
```

Project layout
--------------
```
├── ze.c            Source code
├── LICENSE         License for source
├── Makefile        Makefile for installation
├── .gitignore      Ignoring unwanted garbage
├── .gitattributes  Giving git attributes (duh)
└── README.md       README for info
```

How to use
-----------
When ZE is opened, you will be greeted with the classic `%` prompt. It operates by using "keys" for controlling the file system.
These are the keys and their respective commands:
* 1: View files
* 2: Change directory
* 3: Create file
* 4: Delete file
* 5: Run custom command
* 6: Exit explorer
With some commands, you will be asked for further input. That's when the `>` prompt appears. If you get an error, it will
be prefixed with `[ERROR]:`.  
  
So yeah, enjoy the project!

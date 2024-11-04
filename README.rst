ZE - Zen Explorer
=================
.. image:: https://img.shields.io/badge/Build%20(Fedora)-passing-2a7fd5?logo=fedora&logoColor=2a7fd5&style=for-the-badge
   :alt: Build = Passing
   :target: https://github.com/ElisStaaf/ze
.. image:: https://img.shields.io/badge/Version-1.0.0-2dd245?style=for-the-badge
   :alt: Version = 1.0.0
   :target: https://github.com/ElisStaaf/ze
.. image:: https://img.shields.io/badge/Lang-C-lightgrey?logo=c&style=for-the-badge
   :alt: Language = C
   :target: https://github.com/ElisStaaf/ze

ZE is a file explorer that runs in the terminal. It aims at making your file exploring in the terminal as pleasant as possible! It
*also* runs on the C standard library, no depedencies here!

Requirements
------------
* `gcc`_ (or any other C compiler)
* `make`_
* `cmake`_
* `git`_ or `gh`_

Install
-------
To install, simply:

.. code:: bash

   # Git
   git clone https://github.com/ElisStaaf/ze ~/ze

   # Gh
   gh repo clone ElisStaaf/ze ~/ze

After installing it in the ~/ze directory, enter and make an install to your system:

.. code:: bash

   cd ~/ze
   cmake .
   sudo make

You can delete the ~/ze directory at this point. Anyway, you can now open the explorer by using the `ze` command in your shell:

.. code:: bash
   ze

Appearance
--------------
::

   ===================================
   |       THE ZE FILE EXPLORER      |
   ===================================
   | 1. View files                   |
   | 2. Change directory             |
   | 3. Create file                  |
   | 4. Delete file                  |
   | 5. Run custom command           |
   | 6. Exit                         |
   ===================================
   %


How to use
-----------
When ZE is opened, you will be greeted with the *classic* tcsh ``%`` prompt. It operates by using "keys" for controlling the file system.
These are the keys and their respective commands:

* 1: View files
* 2: Change directory
* 3: Create file
* 4: Delete file
* 5: Run custom command
* 6: Exit explorer

With some commands, you will be asked for further input. That's when the ``>`` prompt appears. If you get an error, it will
be prefixed with ``[ERROR]:`` & if an info message appears, it will be prefixed with ``[INFO]:``.  
  
So yeah, enjoy the project!

.. _`gcc`: https://gcc.gnu.org/install
.. _`make`: https://www.gnu.org/software/make
.. _`cmake`: https://cmake.org/download
.. _`git`: https://git-scm.com/downloads
.. _`gh`: https://github.com/cli/cli#installation

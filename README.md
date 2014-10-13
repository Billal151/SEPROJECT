SEPROJECT
=========
%% ReadMe.txt
%% for C++_gdbm_Database (Version: FINAL_VERSION)
//


Name:-              Laboratory Session III and a Project
Authors:-           B.Mabuza(487864@students.wits.ac.za) T.Matsime(thatopotter@gmail.com)

Date:-              05 June 2014

				----------------
				(1) Description
				----------------	
This program reads in an input text file with records and stores them in a gdbm data store.
The records are then read from the data store and written into an output text file of their key (quickSort() was used).
The sort order was according to a flag ASC(Ascending) and DESC(Descending).
Program can print out the first and last 15 records one per line, from 

More details are on the report (INTRODUCTION_&_PROBLEM_SPECIFICATION). 
--

				-------------------
				(2)How to git clone
				-------------------
*On the terminal/bash or command prompt type: <git clone group09@softeng.cs.wits.ac.za:./Documents/SE1> LabSession2
<git clone group09@softeng.cs.wits.ac.za:./Documents/SE2> for lab session III/Project

*Password is : <ohmaesoo>

Accessing the server you can also type in <ssh group09@softeng.cs.wits.ac.za and password <ohmaesoo>.	


				--------------------
				(3)Using the program
				--------------------	

***Minimum system requirements***
     >LINUX
	-
	-Pentium II processor or higher.
	-8MB free RAM
	-2MB free disk space.
	-800 x 600 resolution or higher.
	-internet connection reccomended

     >WINDOWS
	-Microsoft NT or higher.
	-Pentium II processor or higher.
	-8MB free RAM
	-2MB free disk space.
	-800 x 600 resolution.
	-internet connection reccomended

     >MACINTOSH
	-
	-PowerPC G5 or higher.
	-8MB free RAM
	-2MB free disk space.
	-800 x 600 resolution or higher.
	-internet conncetion reccomended

***Running***

*This program runs with a makefile and needs a terminal so as to facilitate the 
user interface.

*The command for running program:
	1. Compile using <make>
	2. Execute program using <./out>
	3. Input flag <ASC> or <DESC>
	4. Cleaning The make file <make clean>
-- 

				---------------------------			
				(4)Details and Installation
				---------------------------	

*The language used to implement this software was done in C++.

*The database used was GNU dbm (gdbm) becuase it complements C and C++ very well.

*Installations:

1.To install the gcc and g++ compilers, you will need the build-essential package:
	$ sudo apt-get update
	$ sudo apt-get upgrade
	$ sudo apt-get install build-essential
	$ gcc -v
	$ make -v

2.To install git follow the steps from this website:
	https://www.digitalocean.com/community/articles/how-to-install-git-on-ubuntu-14-04

3.To install GNU dbm database routines:
	http://www.linuxfromscratch.org/blfs/view/6.3/general/gdbm.html

Note the above steps are for a Linux based environment, for  MAC and WINDOWS use google to navigate the desired installation.
---

				--------------------------
				(5)History of the Software
				--------------------------
*A first version was first implemented, it had errors like a duplicate was printed on the Lab3Output file.

* FINAL_VERSION Duplicate keys are accounted for and program prints out the duplicate on the terminal and prints as required from
the specification, a Lab3Output file with first 15 and last 15 records. 
---


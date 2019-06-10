# Sierra College: CSCI-0046
This is a C program which cracks md5 passwords from a dictionary. 

## Lab 8: Start Cracking

This is the start of a few assignments related to cracking passwords. In this assignment you will lay the groundwork for the actual cracking of passwords. There are two objectives:

* Compile a multi-source project using a Makefile
* Produce a list of hashed passwords from a list of candidate passwords

## Fork and clone the assignment repository
1. Bring up a browser and go to https://bitbucket.org/profbbrown/crack (Links to an external site.)Links to an external site.
1. Click on Fork to make a copy of my repository into your account.
1. Click on Clone and copy the command to the clipboard.
1. Switch over to the Cloud9 terminal and paste the command. Press Enter.
1. It will create a directory called crack that contains a few starter files.
1. Use the cd command to change your directory to crack: cd crack
The files are as follows:

md5.c
Source code for a function that will compute MD5 hashes.

md5.h
Function prototype for the md5() function, plus compiling instructions.

sha256.c
Source code for the SHA256 hashing function. Not needed for this particular assignment, but may be needed in a subsequent one.

sha256.h
Function prototype for the sha256() function, plus compiling instructions.

rockyou100.txt
The top 100 passwords from the rockyou.txt file. No password in this file is longer than 15 characters.

## Hash a list of passwords
The file rockyou100.txt contains the top 100 most popular passwords, respectively, from the giant rockyou.txt file. (Available from here (Links to an external site.)Links to an external site., if you're interested. Warning: it is very large; about 140MB uncompressed.)

Write a program called hashpass.c that reads passwords from the file listed first on the command line and and writes MD5 hashes to the second file listed on the command line. Use the md5 function in md5.c to compute the hashes. The function prototype, as given in md5.h, is:

char *md5(const char *str, int length);
The md5 function is given a string to hash and its length. (Use strlen to find the length of the string.) It returns a string containing 32 hexadecimal digits. This string is malloc'd by the md5 function; the caller needs to free the memory.

To compile your program, you'll need to assemble it out of three pieces: hashpass.c, md5.c, and a pre-compiled library of cryptography functions:

clang hashpass.c md5.c -o hashpass -l crypto
However, by the end of the assignment you will create a Makefile to automate the build for you.

To run the hashpass program:

./hashpass rockyou100.txt hashes.txt
If your program is working correctly, the first five hashes in the output file will be:

e10adc3949ba59abbe56e057f20f883e
827ccb0eea8a706c4c34a16891f84e7b
25f9e794323b453885f5181f1b624d0b
5f4dcc3b5aa765d61d8327deb882cf99
f25a2fc72690b780b2a14e140ef6a9e0
If you are not getting these hashes, most likely you are not reading in the passwords correctly.

Check to make sure your output file contains 100 lines, one line for each password in the input file. Two common problems are to end up with 99 lines (missed one) or 101 lines (duplicated one of them).

## Create a Makefile
A starter Makefile has been provided for you. However, it is incomplete. It contains the targets and dependencies for the project, but does not contains the recipes to compile the md5.o and hashpass.o object files. You need to fill those in.

I have a 45-minute tutorial on Makefiles in this video:

https://www.youtube.com/watch?v=GExnnTaBELk (Links to an external site.)Links to an external site.


For both object files, compile with the -g flag (for debugging) and -Wall (to generate all warnings).

The given Makefile also contains two targets to help with the project. You don't need to change these for now.

hashes
This target runs the executable as shown in the previous sections. Use it like this: make hashes

clean
This target removes the object files, executable, and hashes.txt file, leaving only the source files. Use this when you want to compile all the source files from scratch. It's not intended to be used every time you want to compile because it negates the advantage of compiling only what has changed. Use it, when necessary, like this: make clean

## What to Turn In
You have finished when you can do the following commands to build and run the project:

make clean
make
make hashes
Once you have confirmed that everything is working, add and commit your changed files:

git add hashpass.c
git add Makefile
git commit
Finally, push your repo to BitBucket and turn in the URL for your repository. Remember to add me (profbbrown) as a collaborator.


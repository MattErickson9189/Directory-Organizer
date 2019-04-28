#Directory Organizer 

This program organizes all the files in your downloads folder by extension type. Future releases will allow the user to change the directory to be organized and will allow the user to choose if they want the files to be released by extension, date, or alphabetically. On Linux systems the setup.sh script will move all the files to where they need to be so the program will run every time you login. As of right now you need to manually set auto start up on Windows but in the future there will be a script that does it for you as well.

SETUP:

Linux: just run the setup.sh script and everything will be set up for you. The program will now run everytime you login

Windows: As of now in order to get the program to run at startup you will need to create a batch file with a link to the compiled executable in it, and then place the file in your Windows\ directory

NOTE: As of now this program does not move files without extension types.
EXAMPLE:

myFile

On windows the program will keep looping until the user closes it.
On Linux the program will terminate.

#!/bin/bash

clear

g++ DirectoryOrganizerLinux.cc -o LinuxDirectoryOrg.exe

mkdir /home/$USER/Directory-Organizer

cp DirectoryOrganizerLinux.cc /home/$USER/Directory-Organizer/
cp setup.sh /home/$USER/Directory-Organizer/
cp LinuxDirectoryOrg.exe /home/$USER/Directory-Organizer/

echo '#!/usr/bin/env xdg-open' >> Organizer.desktop
echo '[Desktop Entry]' >> Organizer.desktop
echo 'Version=1.0' >> Organizer.desktop
echo 'Type=Application' >> Organizer.desktop
echo 'Terminal=false' >> Organizer.desktop
echo 'Exec='/home/$USER/Directory-Organizer/LinuxDirectoryOrg.exe'' >> Organizer.desktop
echo 'Name=Organizer' >> Organizer.desktop

chmod u+x Organizer.desktop

cp Organizer.desktop /home/$USER/.config/autostart/ 

echo "Setup Complete!"
echo "You can now delete this folder"


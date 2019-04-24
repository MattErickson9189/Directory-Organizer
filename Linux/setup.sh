#!/bin/bash

clear
echo "Work in Progress..."

echo "/home/$USER" 

mkdir /home/$USER/Directory-Organizer

cp DirectoryOrganizerLinux.cc /home/$USER/Directory-Organizer/
cp setup.sh /home/$USER/Directory-Organizer/

echo '#!/usr/bin/env xdg-open' >> Organizer.desktop
echo '[Desktop Entry]' >> Organizer.desktop
echo 'Version=1.0' >> Organizer.desktop
echo 'Type=Application' >> Organizer.desktop
echo 'Terminal=false' >> Organizer.desktop
echo 'Exec='/home/$USER/Directory-Organizer/DirectoryOrganizerLinux.cc'' >> Organizer.desktop
echo 'Name=keyMap' >> Organizer.desktop



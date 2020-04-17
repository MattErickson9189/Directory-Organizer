all: complete

organizer.o: Organizer.cc Organizer.h
	g++ -g -c Organizer.cc

traverser.o: Traverser.cc Traverser.h
	g++ -g -c Traverser.cc

directoryOrganizer.o: DirectoryOrganizer.cc DirectoryOrganizer.h
	g++ -g -c DirectoryOrganizer.cc

extensionMover.o: ExtensionMover.cc ExtensionMover.h
	g++ -g -c ExtensionMover.cc

main.o : main.cc
	g++ -g -c main.cc

complete: main.o organizer.o traverser.o directoryOrganizer.o extensionMover.o
	g++ -g -o DirectoryOrganizerLinux main.o Organizer.o Traverser.o DirectoryOrganizer.o ExtensionMover.o

clean:
	rm -rf DirectoryOrganizerLinux
	rm -rf *.o

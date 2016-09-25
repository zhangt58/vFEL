APPNAME = vfel
IOCNAME = vfel
TOP = ./controlMachine

all: app ioc

app:
	cd $(TOP); \
		makeBaseApp.pl -t ioc $(APPNAME)

ioc:
	cd $(TOP); \
		makeBaseApp.pl -a linux-x86_64 -i -t ioc -p $(APPNAME) $(IOCNAME)

.PHONY: clean
clean:
	#cd $(TOP); \
	#	rm -rf *

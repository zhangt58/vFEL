all: tracking

soft: tracking hist data

tracking: linac.ele
	elegant linac.ele
	#elegant_p linac.ele 2

clean:
	-rm *.wA* *.w0* 2> /dev/null

hist:
	sddshist2d linac.out linac.h2d -col=x,xp -xparam=50 -yparam=50

plot:
	sddscontour -shade=100 linac.h2d
	#python plotps.py

data: hist
	sddsprintout linac.h2d linac.h2d.asc -col=frequency,format="%.8e" -notitle -nolabels

.PHONY: clean tracking hist plot

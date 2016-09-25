all: tracking

soft: tracking hist data

tracking: linac.ele
	elegant linac.ele

clean:
	-rm *.wA* *.w0* 2> /dev/null

hist:
	sddshist2d linac.out linac.h2d -col=x,xp -xparam=100 -yparam=100

plot:
	sddscontour -shade=100 linac.h2d
	#python plotps.py

data: hist
	sddsprintout linac.h2d linac.h2d.asc -col=frequency,format="%.8e" -notitle -nolabels

.PHONY: clean tracking hist plot

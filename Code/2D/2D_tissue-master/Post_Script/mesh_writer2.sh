#!/bin/sh


for i in `seq 0 2 2000`
do
	num=$(printf "%04d" $i)
	{
	if [ ! -f $1/v_$num.bin ]; then
    	echo "File not found! Num = $num"
    	#exit 0
	else
	./vtk $1/v_$num.bin $1/v_$num
	fi
	}
done


# cp make_png.py get_png.pvsm $1
# cd $1
# ~/Paraview/bin/pvbatch make_png.py

# rm *.vtk
# cd -




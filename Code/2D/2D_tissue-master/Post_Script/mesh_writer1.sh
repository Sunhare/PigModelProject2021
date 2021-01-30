#!/bin/sh

# echo $(pwd)
# echo $1
# echo $2
# echo $3

for i in `seq 0 2 10`
do
	num=$(printf "%04d" $i)
	echo $1/v_$num.bin
	{
	if [ ! -f $1/v_$num.bin ]; then
		# echo $1/v_$num.bin
    	echo "File not found! Num = $num"
    	#exit 0
	else
	~/Downloads/2D_tissue-master/Post_Script/vtk $1/v$num.bin $1/v$num
	fi
	}
done


# cp make_png.py get_png.pvsm $1
# cd $1
# ~/Paraview/bin/pvbatch make_png.py

# rm *.vtk
# cd -




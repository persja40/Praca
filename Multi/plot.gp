set term png size 500,500
set out 'multi.png'
set xlabel "Game's nr"
set ylabel 'Probability'
#plot 'multi.dat' w lines notitle
N=`awk 'NR==1 {print NF}' multi.dat`
plot for [i=2:N] "multi.dat" u 1:i w lines notitle

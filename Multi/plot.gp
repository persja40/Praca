set term png size 500,500 font "Helvetica,20"
set out 'multi.png'
set xlabel "Numer partii"
set ylabel 'Prawdopodobieństwo'
set logscale x
#plot 'multi.dat' w lines notitle
N=`awk 'NR==1 {print NF}' multi.dat`
plot for [i=2:N] "multi.dat" u 1:i w lines linewidth 3 notitle

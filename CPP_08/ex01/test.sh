min=0
max=21474

half_count=$((($max - $min + 1) / 2))

make && clear && ./Containers $(shuf -i $min-$max | head -n $half_count | tr '\n' ' ' )
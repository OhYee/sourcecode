input=./$1
output=./$1.out
g++ -g -Wall "$input" -o "$output" -O2 -std=c++17
if [ -e "$output" ]; then
    "$output" <in.txt
    rm -f "$output"
else
    echo "error"
fi
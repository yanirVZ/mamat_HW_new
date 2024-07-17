#!/bin/bash

site="https://ynetnews.com/category/3082"
data=$(wget --no-check-certificate -O - "$site" 2>/dev/null)

articles=$(echo "$data" | grep -oP "https://(www.)?ynetnews.com/article/[0-9a-zA-Z]+" | sort -u)

echo "$articles"
echo "Total: $(echo "$articles" | wc -l) articles"

count_word_occurrences() {
    local article=$1
    local word=$2
    count=$(wget --no-check-certificate -O - "$article" 2>/dev/null | grep -o -i "$word" | wc -l)
    echo "$count"
}

export -f count_word_occurrences

echo "Counting 'Netanyahu' mentions:"
netanyahu_counts=$(echo "$articles" | xargs -n 1 -P 10 -I {} bash -c 'count_word_occurrences "{}" "Netanyahu"')
total_netanyahu=$(echo "$netanyahu_counts" | awk '{s+=$1} END {print s}')
echo "$netanyahu_counts"
echo "Total Netanyahu mentions: $total_netanyahu"

echo "Counting 'Gantz' mentions:"
gantz_counts=$(echo "$articles" | xargs -n 1 -P 10 -I {} bash -c 'count_word_occurrences "{}" "Gantz"')
total_gantz=$(echo "$gantz_counts" | awk '{s+=$1} END {print s}')
echo "$gantz_counts"
echo "Total Gantz mentions: $total_gantz"
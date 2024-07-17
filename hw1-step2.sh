#!/bin/bash

site="https://ynetnews.com/category/3082"

data=$(wget --no-check-certificate -O - $site 2>/dev/null)

for name in Netanyahu Gantz; do
	echo "$data" | grep --color=always $name
	echo "----"
done

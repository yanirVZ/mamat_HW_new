#!/bin/bash

# URL of the site to fetch articles from
site="https://ynetnews.com/category/3082"

# Fetch the data from the site
data=$(wget --no-check-certificate -O - "$site" 2>/dev/null)

# Extract unique article links
articles=$(echo "$data" | grep -oP "https://(www\.)?ynetnews.com/article/[0-9a-zA-Z]+" | sort | uniq)

# Loop through each article link
for article in $articles; do
  # Fetch the content of the article
  article_content=$(wget --no-check-certificate -O - "$article" 2>/dev/null)

  # Count occurrences of "Netanyahu" and "Gantz"
  netanyahu_count=$(echo "$article_content" | grep -o "Netanyahu" | wc -l)
  gantz_count=$(echo "$article_content" | grep -o "Gantz" | wc -l)

  # Check if neither name appears
  if [ "$netanyahu_count" -eq 0 ] && [ "$gantz_count" -eq 0 ]; then
    echo "$article, -"
  else
    echo "$article, Netanyahu, $netanyahu_count, Gantz, $gantz_count"
  fi
done